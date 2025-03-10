#include "absurdwordleround.h"

#include <QList>

AbsurdWordleRound::AbsurdWordleRound(QWidget *parent, const int len):
    WordleRound(parent, len, false)
{
    initGuesses(parent);
    solver.setEnabled(false);
}

// Add extra guesses for this mode
int AbsurdWordleRound::calculateNumGuesses(const int len) {
    return WordleRound::calculateNumGuesses(len) + 5;
}

/**
 * TODO: BONUS TASK 1
 *
 * @brief Change the 'answer' by one letter, so that it still belongs to 'allAnswers'.
 * @param answer: original answer word
 * @param allAnswers: all possible answers, new answer must come from this set
 * @return a word from 'allAnswers' that differs from 'answer' by (at most) one letter.
 *
 * Create a list of words considered "adjacent" to the current answer:
 * words that differ by the answer by exactly one letter.
 *
 * For each possible answer, loop over each letter
 * and count the number of times the letter is different
 * for the current answer and possible answer.
 * If this value is 1, add the possible answer to the "adjacent" list.
 *
 * Finally, select a random word from the "adjacent" list to be the new answer.
 * If this list is empty, return the original answer.
 */
QString alterAnswer(const QString& answer, const QSet<QString>& allAnswers) {

    if (allAnswers.empty()) return answer;

    int strLength = answer.length();

    QList<QString> answers;
    QSet<QString>::const_iterator iter = allAnswers.constBegin();
    while (iter != allAnswers.constEnd()) {
        int changes = 0;
        for (int i = 0; i < strLength; i++) {
            if (answer[i] != (*iter)[i]) changes++;
        }
        if (changes == 1) answers.append(*iter);
        ++iter;
    }

    if (answers.empty())
        return answer;
    else
        return answers[rand() % answers.length()];
}


void AbsurdWordleRound::endGuessAttempt(const bool correctGuess) {
    // Perform endGuess tasks like normal
    WordleRound::endGuessAttempt(correctGuess);

    // If incorrect guess and game has not ended, change the answer by one letter
    if (!correctGuess && curGuess != numGuesses) {
        answer = alterAnswer(answer, dict.getAllAnswers());
    }
//    qDebug() << "The current answer is:" << answer;
}
