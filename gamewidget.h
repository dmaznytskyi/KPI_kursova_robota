#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QtWidgets>

class GameWidget : public QWidget
{
    Q_OBJECT

	public:
		GameWidget(QWidget *parent = 0);
		~GameWidget();
		QTimer *timer;
		void paintEvent(QPaintEvent *);
		void timerEvent(QTimerEvent *);
		int move;

	private:
		void keyPressEvent(QKeyEvent *);
		void keyReleaseEvent(QKeyEvent *);
		void mousePressEvent(QMouseEvent *);

	private slots:
		void moveImg();
		void moveImgInst();
};


#endif // GAMEWIDGET_H
