#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include "game.h"
#include <QMediaPlayer>

extern Game *game;

Bullet::Bullet()
{

	// Set the image for the bullet
    QPixmap map(":/images/bullet.png");
    heightMap = map.height();
    widthMap = map.width();
	
    // Set the bullet's position and size
    this->setPixmap(QPixmap(":/images/bullet.png"));

    timer = new QTimer(this);

    // Move the bullet each 50 ms
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
    // Move the bullet
   this->setPos(x(), y() - 5);

    //List with the objects colliding with the bullet
    QList<QGraphicsItem*> items = collidingItems();

    //If an item collides with the bullet, remove and delete it
    for(int i = 0; i < items.length(); i++)
    {
        if(typeid(*items[i]) == typeid(Enemy))
        {

            //Play sound
            QMediaPlayer *musicDestroyed = new QMediaPlayer();
            musicDestroyed->setMedia(QUrl("qrc:/images/destroyed.mp3"));
            musicDestroyed->play();


            //Increase the score
            game->score->increaseScore();


            //Remove the enemy and this bullet
            scene()->removeItem(items[i]);
            scene()->removeItem(this);

            //Delete the enemy (FIRST) and  the bullet
            delete items[i];
            delete this;

            return;
        }
    }


   // Delete the bullet if it goes out of the scene
   if(y() + heightMap < 0)
   {
       scene()->removeItem(this);
       delete this;
   }

}
