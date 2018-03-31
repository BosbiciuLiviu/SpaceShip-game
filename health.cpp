#include "health.h"
#include <QFont>

Health::Health()
{
    healthPoints = 3;
    setPlainText("Health: " + QString::number(healthPoints));
    setFont(QFont("times", 16));
    setDefaultTextColor(Qt::red);
}

void Health::loseHealth()
{
    healthPoints--;
    setPlainText("Health: " + QString::number(healthPoints));
}

int Health::getHealth()
{
    return healthPoints;
}
