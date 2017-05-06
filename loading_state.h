#ifndef LOADING_STATE_H
#define LOADING_STATE_H

#include "gamewidget.h"

class loading_state : public GameWidget
{
	public:
		loading_state();

	public slots:
		void progBar();

	protected:
		void paintEvent(QPaintEvent *);

	private:
		QVBoxLayout main_layout;
		QLabel logo_pic;
		QProgressBar prog_bar;
		QTimer timer;
};

#endif // LOADING_STATE_H
