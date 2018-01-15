#include "gamewidget.h"
#include "game.h"
#include "loading.h"
#include "menu.h"
#include <QPainter>
#include <QTimer>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
	setFixedSize(500,500);
	timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(update()));
	timer->start(5);
}

GameWidget::~GameWidget()
{}

void GameWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	foreach (GameObject *obj, Game::Instance().current->objects())
	{
		painter.drawPixmap(obj->pos(),obj->img());
	}
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
	Game::Instance().current->keyPress(event);
}

void GameWidget::keyReleaseEvent(QKeyEvent *event)
{
	Game::Instance().current->keyRelease(this, event, timer);
}

void GameWidget::timerEvent(QTimerEvent *)
{

}

void GameWidget::moveImg()
{

}

void GameWidget::moveImgInst()
{

}

void GameWidget::mousePressEvent(QMouseEvent *event)
{

}

//LOADING STATE
/*	bckg:
	QPoint p0;
	QImage bckg(":/main_menu/00.jpg");
	painter.drawImage(p0, bckg);

	//setWindowTitle("TETRIS. Now loading");
	//setState(new loading_state);

	setWindowTitle("TETRIS");
	setFixedSize(500,500);

	QImage logo(":/main_menu/TetrisLogo.png");
	QPixmap logomap = QPixmap::fromImage(logo);
	logo_pic.setPixmap(logomap.scaledToWidth(400));
	logo_pic.setHidden(true);
	logo_pic.setAlignment(Qt::AlignHCenter);
	main_layout.addWidget(&logo_pic);
	main_layout.addStretch(true);
	main_layout.addWidget(&prog_bar);
	setLayout(&main_layout);
	prog_bar.setMinimum(0);
	prog_bar.setMaximum(100);
	connect(&timer,SIGNAL(timeout()),SLOT(progBar()));
	timer.start();

*/
