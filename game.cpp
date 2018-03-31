#include "game.h"
#include <QObject>
#include <QBrush>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QWidget>

Game::Game()
{
    // Playing sound in a loop
    QMediaPlaylist *playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/images/Dark Space Music - Dark Spaceships.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer(this);
    music->setPlaylist(playlist);
    music->play();


    // Initialising pointers
    scene = new QGraphicsScene();
    rect = new Player();
    score = new Score();
    health = new Health();

    // Set the background
    setBackgroundBrush(QBrush(Qt::black));

    // Adding the items to the scene
    scene->addItem(rect);

    // Adding the enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), rect, SLOT(spawn()));
    timer->start(1500);

    //Makes moving the player smooth
    QTimer *timer2 = new QTimer(this);
    QObject::connect(timer2, SIGNAL(timeout()), rect, SLOT(movePlayer()));
    timer2->start(50);

    // Adding the score and the health to the scene
    scene->addItem(score);
    health->setPos(health->x(), health->y() + 27);
    scene->addItem(health);

    //Make the rect focusable and focused
    //connect(rect, SIGNAL())
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // Making the size fixed
    scene->setSceneRect(0, 0, 800, 800);
    setFixedSize(800, 800);

    // Adding the scene to the view
    setScene(scene);

    // No scrollBar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Placing the player rectangle in the middle of the view
    rect->setPos(width() / 2 - rect->widthMap / 2, height() - rect->heightMap);

    // Showing the view
    show();
}

Game::~Game()
{
    delete rect;
    delete scene;
}
