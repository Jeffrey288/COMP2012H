#include "solver.h"
#include "letterbox.h"

#include <cmath>
#include <QColor>

Solver::Solver(const QSet<QString>& allWords)
{
    this->allWords = possibleAnswers = allWords;
}

void Solver::reset(const QSet<QString>& allWords) {
    possibleAnswers = allWords;
}

// Reuse this function in wordleround.cpp
QColor* analyzeGuess(const QString& guess, const QString& answer);

// Helper function to convert color to bin index
int colorToInt(const QColor* const colors, const int length) {
    int index = 0;
    for (int i=0; i<length; ++i) {
        if (colors[i] == GREY) index += 0 * pow(3, i);
        else if (colors[i] == YELLOW) index += 1 * pow(3, i);
        else if (colors[i] == GREEN) index += 2 * pow(3, i);
    }
    return index;
}

/**
 * TODO: BONUS TASK 4
 *
 * @brief Calculate the average entropy for guessing this word
 * @param word: word to compute entropy
 * @param possibleAnswers: set of remaining possible answers
 * @return double: average entropy associated with this guess
 *
 * - Generate a bin (int array) of size 3^length for each possible QColor arrangement
 * - For each possible answer:
 *      + Get the QColor arrangement if 'word' was a guess for 'answer' using analyzeGuess(),
 *      + Convert to bin index using colorToInt(), add 1 to that bin
 * - Calculate entropy using the formula:
 *      entropy = Sum(- p * log2(p));
 *   where p is the probability each QColor arrangement would be the actual result (= bin[i] / number of answers)
 */
double computeEntropy(const QString& word, const QSet<QString>& possibleAnswers) {
    int length = word.length();
//    if (length == 0) return 0.0; // assume won't happen?

    int binLength = pow(3, length);
    int* bin = new int[binLength]; // for each possible QColor arrangement that an answer could give
    for (int i = 0; i < binLength; i++) bin[i] = 0; // initialize the bin

    QSet<QString>::const_iterator iter = possibleAnswers.constBegin();
    while (iter != possibleAnswers.constEnd()) { // loop through all answers and increment frequencies
        QString answer = *iter; // a possible answer;
        QColor* colors = analyzeGuess(word, answer); // get the QColor arragement
        bin[colorToInt(colors, length)]++;

        delete [] colors;
        iter++;
    }

    double entropy = 0;
    for (int i = 0; i < binLength; i++) {
        if (bin[i] == 0) continue; // i.e. add 0
        double p = (double) bin[i] / possibleAnswers.size();
        entropy += - p * log2(p);
    }

    delete [] bin;
    return entropy;
}

/**
 * TODO: BONUS TASK 4
 *
 * If only 1 possible answer left, return that answer.
 *
 * Else, for each word in all possible words,
 * calculate its entropy with computeEntropy().
 * Return the word with the highest entropy.
 */
QString Solver::hint() {
    if (!enabled) return "";

    if (possibleAnswers.size() == 1)
        return *(possibleAnswers.constBegin());

    double maxEntropy = 0.0;
    QString word;

    QSet<QString>::const_iterator iter = allWords.constBegin();
    while (iter != allWords.constEnd()) { // loop through all answers and increment frequencies
        double entropy = computeEntropy(*iter, possibleAnswers);
        if (entropy > maxEntropy) {
            maxEntropy = entropy;
            word = *iter;
        }
//        qDebug() << *iter << entropy;

        iter++;
    }

//    qDebug() << word;
    return word;
}

/**
 * TODO: BONUS TASK 4
 *
 * For each word in remaining possible answers,
 * calculate the color sequence if 'guess' was used as a guess.
 * If the color does not match with the provided colors,
 * the word must not be a possible solution,
 * remove it from the set of possible answers.
 */
void Solver::updateAnswers(const QString& guess, QColor* const colors) {
    if (!enabled) return;

//    qDebug() << possibleAnswers;
    QSet<QString> updatedAnswers = possibleAnswers;
    int length = guess.length();
    QSet<QString>::const_iterator iter = possibleAnswers.constBegin();
    while (iter != possibleAnswers.constEnd()) {
        QString answer = *iter; // a possible answer;
        QColor* analysis = analyzeGuess(guess, answer); // get the QColor arragement

        int i = 0;
        for (; i < length && (analysis[i] == colors[i]); i++);
        if (i != length) updatedAnswers.remove(answer);

        delete [] analysis;
        iter++;
    }

    possibleAnswers = updatedAnswers;
//    qDebug() << possibleAnswers;

}
