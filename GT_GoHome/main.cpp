#include "mymainwindow.h"
#include <QApplication>

#include <QtDebug>
 #include <QFile>
 #include <QTextStream>
 #include <QDebug>
 #include <QDateTime>
 #include <QMutex>
 #include <QString>
 #include <qapplication.h>
void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
     // 加锁
     static QMutex mutex;
     mutex.lock();

     QString text;

     switch(type)
     {
     case QtDebugMsg:
         text = QString("Debug:");
         break;

     case QtWarningMsg:
         text = QString("Warning:");
         break;

     case QtCriticalMsg:
         text = QString("Critical:");
         break;

     case QtFatalMsg:
         text = QString("Fatal:");
     }

     // 设置输出信息格式
     QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
     QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
     QString current_date = QString("(%1)").arg(current_date_time);
     QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

     // 输出信息至文件中（读写、追加形式）
     QFile file("log.txt");
     file.open(QIODevice::WriteOnly | QIODevice::Append);
     QTextStream text_stream(&file);
     text_stream << message << "\r\n";
     file.flush();
     file.close();

     // 解锁
     mutex.unlock();
 }
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
      qInstallMessageHandler(outputMessage);
    MyMainWindow w;

    w.show();

    return a.exec();
}
