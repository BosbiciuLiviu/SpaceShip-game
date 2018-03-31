#include "score.h"
#include <QFont>

Score::Score()
{
    score = 0;

    // Setting the text and the font of it
    setPlainText("Score: " + QString::number(score));
    setFont(QFont("times", 16));
    setDefaultTextColor(Qt::blue);
}

void Score::increaseScore()
{
    score++;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
