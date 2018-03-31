#include "dialog.h"
#include "ui_dialog.h"
#include "game.h"
#include <QString>

extern Game *game;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
	
    ui->setupUi(this);
	
	// Show the score
    ui->label_score->setText("Score: " + QString::number(game->score->getScore()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    exit(0);
}
