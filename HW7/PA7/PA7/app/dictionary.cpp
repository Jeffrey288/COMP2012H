#include "dictionary.h"

#include <QDebug>
#include <QFile>
#include <QDir>

Dictionary::Dictionary(int word_length): word_length(word_length)
{
    QString wordsFilename {":/dictionary/words_{}.txt"};
    wordsFilename.replace("{}", QString::number(word_length));
    QFile wordsFile(wordsFilename);
    if (wordsFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&wordsFile);
        while (!in.atEnd()) {
            QString word = in.readLine();
            words.insert(word);
        }
        if (words.empty()) {
            throw DictionaryException("No valid English words with this length.");
        }
    }
    else {
        throw DictionaryException("Something went wrong reading words.");
    }

    /**
     * TODO: BONUS TASK 5
     *
     * Read the word frequency list from answers_{}.csv and put into 'answers'.
     *
     * Hint: You can reference the code above to read from a file
     * and throw exceptions if file is unavailable or there are no answers.
     */
    QString answersFilename {":/dictionary/answers_{}.csv"};
    answersFilename.replace("{}", QString::number(word_length));
    QFile answersFile(answersFilename);
    if (answersFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&answersFile);
        in.readLine();
        while(!in.atEnd()) {
            QString data = in.readLine();
            QList<QString> temp = data.split(",");
            answers.append((WordFrequency) {.word = temp[0], .count = temp[1].toULongLong()});
        }
        if (answers.empty()) {
            throw DictionaryException("No valid English words with this length.");
        }
    } else {
        throw DictionaryException("Something went wrong reading answers.");
    }

}

/**
 * TODO: BONUS TASK 5
 *
 * Return a random word from the answer list.
 * The word count should reflect how likely this word would be picked as an answer.
 *
 * Hint: You can generate 2 random 32-bit numbers and combine into a 64-bit random unsigned long long.
 */
QString Dictionary::getRandomAnswer() const {

    long long randNum = ((((unsigned long long) rand()) << 32) | (rand())) >> 1;
    unsigned long long total = 0;
    int length = answers.length();
    for (int i = 0; i<length; i++) total += answers[i].count;
    randNum %= total;
    int j = -1;
    do { randNum -= answers[++j].count; } while ( randNum >= 0 );
    return answers[j].word;

    // Default behaviour
    int i = rand() % words.size();
    return *std::next(words.begin(), i);
}

/**
 * TODO: BONUS TASK 5
 *
 * Return a word set using 'answers' instead of 'words'
 */
QSet<QString> Dictionary::getAllAnswers() const {

    QSet<QString> answerSet {};
    int length = answers.length();
    for (int i = 0; i<length; i++) {
        answerSet.insert(answers[i].word);
    }
    return answerSet;
//    return words;
}

bool Dictionary::isValidWord(const QString& word) const {
    QSet<QString>::const_iterator it = words.find(word);
    return it != words.end();
}
