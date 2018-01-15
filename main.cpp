#include "game.h"
#include "log.h"

int main(int argc, char *argv[])
{
	qInstallMessageHandler(Log::myMessageOutput);
	QApplication app(argc, argv);
	Game::Instance().run();
	qDebug() << "Game started";
	return app.exec();
}
