#include "enemy.h"
#include "game.h"
#include "dialog.h"
#include <stdlib.h>
#include <QList>

extern Game *game;

Enemy::Enemy()
{
    timer1 = new QTimer(this);

    // Move enemies
    connect(timer1, SIGNAL(timeout()), this, SLOT(move()));
    timer1->start(100);


    // Setting the enemy rect
    this->setPixmap(QPixmap(":/images/2D x-002.png"));

    //Spawning randomly inside the scene
    int randomSpawn = rand() % 700;
    this->setPos(randomSpawn, 0);
}

Enemy::~Enemy()
{
    delete timer1;
}

void Enemy::move()
{
    if(y() < 800)
    {
        this->setPos(x(), y() + 9);
    }
    else // out of the scene
    {
        //If it goes out of the scene, lose health
        game->health->loseHealth();
        if(game->health->getHealth() == 0)
        {
            game->close();
            Dialog *dialog = new Dialog;
            dialog->show();
        }

        // Release memory
        scene()->removeItem(this);
        delete this;
    }
}
