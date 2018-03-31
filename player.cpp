#include "player.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QMediaPlayer>

Player::Player()
{
   keyLeft = keyRight = false;
   QPixmap map(":/images/fighterbb.png");
   setPixmap(map);

   widthMap = map.width();
   heightMap = map.height();
}

// If left or right keys are pressed
void Player::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
        {
            keyLeft = true;

        }

        else if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
        {
            keyRight = true;
        }
        else if(event->key() == Qt::Key_Space || event->key() == Qt::Key_Up)
        {
            space = true;

            // Create the bullet in the middle of the player rect and add it to the scene
            Bullet *bullet = new Bullet();
            bullet->setPos(this->x() + this->widthMap / 2 - 8, 660);
            scene()->addItem(bullet);

            // Add shot music

            QMediaPlayer *musicBullet = new QMediaPlayer(this);
            musicBullet->setMedia(QUrl("qrc:/images/shoot.wav"));
			
            // If another bullet is shot
            if(musicBullet->state() == QMediaPlayer::PlayingState)
                musicBullet->setPosition(0);
            else if(musicBullet->state() == QMediaPlayer::StoppedState)
                musicBullet->play();
        }
    }
}


// When the key is realeased
void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
        {
            keyLeft = false;

        }

        else if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
        {
            keyRight = false;
        }
        else if(event->key() == Qt::Key_Space || event->key() == Qt::Key_Up)
        {
            space = false;
        }
    }
}

// Moving player with the keys
void Player::movePlayer()
{
    if(keyLeft && x() > 0)
    {
        setPos(x() - 10, y());
    }
    if(keyRight && x() < 730)
    {
        setPos(x() + 10, y());
    }
}


// Spawning an enemy (adding it to the scene)
void Player::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
