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
		void setState(GameWidget state);
};

#endif // GAMEWIDGET_H
