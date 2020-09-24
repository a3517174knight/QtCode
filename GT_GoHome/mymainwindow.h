#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QCloseEvent>
#include <QEvent>

#include <QByteArray>
#include <cstdio>
#include <QMessageLogContext>
#include <QString>
#include <QCoreApplication>
#include <QFile>
#undef QT_MESSAGELOG_FILE
#undef QT_MESSAGELOG_LINE
#undef QT_MESSAGELOG_FUNC
#undef qDebug
#undef qInfo
#undef qWarning
#undef qCritical
#undef qFatal

#define QT_MESSAGELOG_FILE __FILE__
#define QT_MESSAGELOG_LINE __LINE__
#define QT_MESSAGELOG_FUNC Q_FUNC_INFO
#define qDebug QMessageLogger(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).debug
#define qInfo QMessageLogger(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).info
#define qWarning QMessageLogger(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).warning
#define qCritical QMessageLogger(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).critical
#define qFatal QMessageLogger(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).fatal

static FILE* g_printHandle = nullptr;
inline void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(g_printHandle, "Debug:(%s:%u, %s): %s \n", context.file, context.line, context.function, localMsg.constData());
        break;
//    case QtInfoMsg:
//        fprintf(g_printHandle, "Info:(%s:%u, %s): %s \n", context.file, context.line, context.function, localMsg.constData());
//        break;
    case QtWarningMsg:
        fprintf(g_printHandle, "Warning:(%s:%u, %s): %s \n", context.file, context.line, context.function, localMsg.constData());
        break;
    case QtCriticalMsg:
        fprintf(g_printHandle, "Critical:(%s:%u, %s): %s \n", context.file, context.line, context.function, localMsg.constData());
        break;
    case QtFatalMsg:
        fprintf(g_printHandle, "Fatal:(%s:%u, %s): %s \n", context.file, context.line, context.function, localMsg.constData());
       // abort();
        break;
    }
}

inline void installMessageHandler()
{
#ifdef QT_NO_DEBUG
    QString fileName(QCoreApplication::applicationDirPath()+"/"+QCoreApplication::applicationName()+".log");
    g_printHandle = nullptr;
    fopen_s(&g_printHandle, fileName.toStdString().c_str(),"a");
    if (g_printHandle == nullptr)
        g_printHandle = stderr;
#else
    g_printHandle = stderr;
#endif

    qInstallMessageHandler(myMessageOutput);
}

typedef struct TrapMotionParam
{
    short crd;
    short dimension;
    short fifo;
    short core;
    short axis;
    long pos;
    double vel;
    double acc;
    double dec;
    int delayTime;
    int smoothTime;
    int repeateCount;
    double velStart;
}TrapMotionParam;



 void handleTimeout();

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    void on_InitCard_clicked();
     void on_pushButton_Enable_clicked();

     void on_pushButton_9_clicked();

     void on_pushButton_11_clicked();

    void paintEvent(QPaintEvent *);



    void  handleTimeout();  //超时处理函数
    virtual void timerEvent( QTimerEvent *event);
    ~MyMainWindow();

 protected:
    void keyPressEvent(QKeyEvent *);
    void closeEvent(QCloseEvent *);
   bool event(QEvent *);








private slots:


     void on_CBM_axis_currentIndexChanged(int index);

     void on_action_Reset_triggered();

private:
    Ui::MyMainWindow *ui;
    QTimer *m_pTimer;
     int m_nTimerID;
};

#endif // MYMAINWINDOW_H
