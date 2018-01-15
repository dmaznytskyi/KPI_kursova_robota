#include "log.h"

void Log::myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QFile fMessFile("/Users/dmaznytskyi/univer/OOP/labs/tetris_game/log.txt");
	if(!fMessFile.open(QIODevice::Append | QIODevice::Text))
	{
		return;
	}
	QString sCurrDateTime = "[" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + "]";
	QTextStream tsTextStream(&fMessFile);
	switch(type)
	{
		case QtDebugMsg:
			tsTextStream << QString("Debug%1: %2\n").arg(sCurrDateTime).arg(msg);
			break;

		case QtWarningMsg:
			tsTextStream << QString("Warning%1: %2\n").arg(sCurrDateTime).arg(msg);
			break;

		case QtCriticalMsg:
			tsTextStream << QString("Critical%1: %2\n").arg(sCurrDateTime).arg(msg);
			break;

		case QtFatalMsg:
			tsTextStream << QString("Fatal%1: %2\n").arg(sCurrDateTime).arg(msg);
			abort();
	}
	tsTextStream.flush();
	fMessFile.flush();
	fMessFile.close();
}
