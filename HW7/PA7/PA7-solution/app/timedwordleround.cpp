#include "timedwordleround.h"
#include "timedroundwindow.h"

TimedWordleRound::TimedWordleRound(QWidget *parent, const int len, bool hardMode):
    WordleRound(parent, len, hardMode)
{
    initGuesses(parent);

    /**
     * TODO: BONUS TASK 3
     *
     * Disconnect the invalidWord, invalidHardWord, roundWin, roundLose signals
     * from the RoundWindow popup slots, since we don't want popups during game.
     * Connect them to TimedRoundWindow's msg slots instead.
     * Also connect scoreUpdated() signal with scoreUpdate() slot.
     */
    disconnect(this, &WordleRound::invalidWord, nullptr, nullptr);
    disconnect(this, &WordleRound::invalidHardWord, nullptr, nullptr);
    disconnect(this, &WordleRound::roundWin, nullptr, nullptr);
    disconnect(this, &WordleRound::roundLose, nullptr, nullptr);

    connect(this, &WordleRound::invalidWord, static_cast<TimedRoundWindow*>(parent), &TimedRoundWindow::msgInvalidWord);
    connect(this, &WordleRound::invalidHardWord, static_cast<TimedRoundWindow*>(parent), &TimedRoundWindow::msgInvalidHardWord);
    connect(this, &TimedWordleRound::roundWin, static_cast<TimedRoundWindow*>(parent), &TimedRoundWindow::msgRoundWin);
    connect(this, &TimedWordleRound::roundLose, static_cast<TimedRoundWindow*>(parent), &TimedRoundWindow::msgRoundLose);
    connect(this, &TimedWordleRound::scoreUpdated, static_cast<TimedRoundWindow*>(parent), &TimedRoundWindow::scoreUpdate);

}

/**
 * TODO: BONUS TASK 3
 *
 * Same as base class endRound(), except:
 * - Don't change numTries and curGuess, since we are only ending the round for one word
 * - If round was won, add 1 to score and emit scoreUpdated
 * - Finally, call resetRound() to go to next word
 */
void TimedWordleRound::endRound(const bool win) {

    if (win) {
        emit roundWin();
    }
    else {
        emit roundLose();
    }

    if (win) {
        score++;
        emit scoreUpdated();
    }

    resetRound();
}

/**
 * TODO: BONUS TASK 3
 *
 * Reset score to 0 (remember to emit signal) and resetRound() to go to a new word
 */
void TimedWordleRound::resetTimedRound() {
    score = 0;
    emit scoreUpdated();
    resetRound();
}

void TimedWordleRound::endTimedRound() {
    // Do this to stop user input
    curGuess = numGuesses;
}

/**
 * TODO: BONUS TASK 3
 *
 * resetRound() to go to a new word, unless the timed game is over
 */
void TimedWordleRound::skipCurrentWord() {
    resetRound();
}
