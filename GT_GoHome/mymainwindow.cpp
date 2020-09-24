#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include "gts.h"
#include <QDebug>
#include <QString>
#include <cstring>
#include <string.h>
#include <QCloseEvent>
#include <Qmovie>
#include <QMenu>
#include <QTimerEvent>
#include <QMenuBar>
#include <QAction>
#include <QKeyEvent>
#include <QEvent>
#include <QWidget>
#include <QPainter>

#include <QMessageBox>
#pragma comment <lib,"gts.lib">

#define TIMER_TIMEOUT   (1*100)



bool OpenFlagSuccess = false;
TrapMotionParam trapMotionParam;  //运动参数


void Error(int rtn, QString cmdStr)
{

      if (rtn)
      {

            qDebug("%s执行出错返回值为%d\n",qPrintable(cmdStr),rtn);

      }
}
//绘图事件
void MyMainWindow::paintEvent(QPaintEvent *)
{

    QPainter p;
    p.begin(this);

   // p.drawPixmap(0,0,width(),height(),QPixmap("../image/Frame.jpg"));
  //  p.drawPixmap(rect(),QPixmap("../image/Frame.jpg"));


    p.drawArc(50,50,width(),height(),10,5);
    p.end();

}

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    ui->label_16->setMouseTracking(true);
    on_InitCard_clicked();
    m_nTimerID = this->startTimer(TIMER_TIMEOUT);

    ui->checkBox_StartP->setChecked(true);
    ui->checkBox_CaptchN->setChecked(true);
    ui->checkBox_IndexN->setChecked(true);


    //ui->label_pixMap->setPixmap(QPixmap("://OnePiece.png"));
//样式表
     ui->label_pixMap->setStyleSheet("QLabel{"
                                     "background-color:red;"
                                     "border-image:url(://OnePiece.png)}"
                                     "QLabel:hover{"


                                      "border-image:url(://Luffy.png)}"

                                     );





     QMovie  *m_movie =  new QMovie ("://lufu.gif");
//     ui->label_movie->setStyleSheet("QLabel{"
//                                    "background-color:red;"
//                                     "border-image:url(://lufu.gif)}" );

    ui->label_movie->setMovie(m_movie);
    m_movie->start();
    ui->label_movie->setScaledContents(true);




    ui-> label_Url ->setText("<h1><a href=\"https://www.baidu.com\"> 百度一下</a></h1>");
    ui-> label_Url ->setText("<h1><a href=\"http://www.googoltech.com.cn/product-9.html\"> 固高科技 </a></h1>");
    ui-> label_Url->setOpenExternalLinks(true);




   //处理菜单栏操作
    QMenuBar *mBar = menuBar();
    QMenu *pFile =  mBar->addMenu("控制");
    QAction  *action_Reset = pFile->addAction("复位");
    connect(action_Reset,&QAction::triggered,
            [=](){

                qDebug()<<"按键被按下";
                }

            );
        QAction  *action_Timer = pFile->addAction("定时器打开");
        connect(action_Timer,&QAction::triggered,
                [=](){

                    m_nTimerID = this->startTimer(TIMER_TIMEOUT);
                    }
                );

        QAction  *action_KillTimer = pFile->addAction("定时器关闭");
        connect(action_KillTimer,&QAction::triggered,
                [=](){

                    killTimer(m_nTimerID);
                    }
                );







}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::on_pushButton_9_clicked()
{

}

void MyMainWindow::on_pushButton_11_clicked()
{

}

void MyMainWindow::on_pushButton_Enable_clicked()
{

   short rtn;

    rtn=GT_AxisOn(trapMotionParam.axis);				Error(rtn,"GT_AxisOn");
    if (rtn)
    {
        return;
    }



}

void MyMainWindow::on_InitCard_clicked()
{
    short sRtn;
    OpenFlagSuccess = false;

    sRtn = GT_Open();
    if(sRtn!=0)
    {
            Error(sRtn,"GT_Open");
           OpenFlagSuccess = true;
    }
    sRtn = GT_Reset();   Error(sRtn,"GT_Reset");
    sRtn = GT_LoadConfig("GT800_test.cfg");    Error(sRtn,"GT_LoadConfig");
    sRtn = GT_ClrSts(1, 8);    Error(sRtn,"GT_ClrSts");

}

void MyMainWindow::on_CBM_axis_currentIndexChanged(int index)
{
    trapMotionParam.axis = ui->CBM_axis->currentText().toInt();
}
void MyMainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){
            handleTimeout();
        }

}


void MyMainWindow::handleTimeout()
{

    QString tempStr,tempStr1,tempStr2;
            short axis = ui->CBM_axis->currentText().toInt();

        short sRtn;
           THomeStatus tHomeSts;
            //qDebug()<<"按键被按下";
            sRtn= GT_GetHomeStatus(axis,&tHomeSts);
             Error(sRtn,"GT_GetHomeStatus");
                 if (tHomeSts.run == 1)
                 {
                     tempStr = "正在回原点";
                     ui->label_Sts->setText(tempStr);

                 }
                 else
                 {
                     tempStr = "已停止运动";
                     ui->label_Sts->setText(tempStr);

                 }


             switch(tHomeSts.stage)

             {
                 case 0 :
                     tempStr1 = "未启动Smart Home回原点";
                     ui->label_Stage->setText(tempStr1);
                    break;

                 default:

                     break;

             }
             if (tHomeSts.stage == 0 )
             {


             }
             else if(tHomeSts.stage == 1)
             {
                 tempStr1 = "启动Smart Home回原点";
                 ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 10)
             {
                 tempStr1 = "正在寻找限位";
                ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 11)
             {
                 tempStr1 = "触发限位停止";
                 ui->label_Stage->setText(tempStr1);
             }

             else if(tHomeSts.stage == 13)
             {
                 tempStr1 = "反方向运动脱离限位";
                 ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 15)
             {
                 tempStr1 = "重新回到限位";
                 ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 16)
             {
                 tempStr1 = "重新回到限位停止";
                 ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 20)
             {
                 tempStr1 = "正在搜索Home";
                ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 25)
             {
                 tempStr1 = "搜索到Home后运动到捕获的Home位置";
                ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 30)
             {
                 tempStr1 = "正在搜索Index";
                ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 80)
             {
                 tempStr1 = "正在执行回原点过程";
                 ui->label_Stage->setText(tempStr1);
             }
             else if(tHomeSts.stage == 100)
             {
                 tempStr1 = "回原点结束";
                 ui->label_Stage->setText(tempStr1);
             }

             switch(tHomeSts.error)
             {
             case 0:
                 tempStr2 = "未发生错误";
                 ui->label_Error->setText(tempStr2);
                 break;
             case 1:
                 tempStr2 = "执行回原点轴不是处于点位模式";
                 ui->label_Error->setText(tempStr2);
                 break;
             case 2:
                 tempStr2 = "执行轴未使能";
                 ui->label_Error->setText(tempStr2);
                 break;
             case 3:
                 tempStr2 = "执行轴报警";
                  ui->label_Error->setText(tempStr2);
                 break;
             case 4:
                 tempStr2 = "未完成回原点，轴停止运动";
                 ui->label_Error->setText(tempStr2);
                 break;
             case 5:
                 tempStr2 = "回原点阶段错误";
                ui->label_Error->setText(tempStr2);
                 break;
             case 6:
                 tempStr2 = "模式错误（例：轴已经启动Smart Home）";
                  ui->label_Error->setText(tempStr2);
                 break;
             case 7:
                 tempStr2 = "设置Home捕获模式失败";
                  ui->label_Error->setText(tempStr2);
                 break;
             case 8:
                 tempStr2 = "未找到Home";
                 ui->label_Error->setText(tempStr2);
                 break;
             case 9:
                 tempStr2 = "设置Index捕获模式失败";
                 ui->label_Error->setText(tempStr2);
                 break;
             case 10:
                 tempStr2 = "未找到Index";
                 ui->label_Error->setText(tempStr2);
                 break;
             default:
                 tempStr2 = "未发生错误";
                  ui->label_Error->setText(tempStr2);
                 break;

             }
             long IAxisStatus;
             sRtn = GT_GetSts(axis,&IAxisStatus);
             if (IAxisStatus & 0x200)
             {
                  ui->pushButton_Enable->setText("关闭使能");
             }
             else
             {
                 ui->pushButton_Enable->setText("开启使能");
             }

     }

  //killTimer(m_nTimerID);
void  MyMainWindow::keyPressEvent(QKeyEvent *ev)
{

   // qDebug()<<ev->key();

    if(ev->key()==Qt::Key_A)
    {
        qDebug()<<"Qt::Key_A";

    }
}
void MyMainWindow::closeEvent(QCloseEvent *e)
{

    if(QMessageBox::question(this,"GoHome","是否需要返回")==QMessageBox::Yes)
    {

        //关闭窗口
        e->accept();
    }
    else
    {
        //不关闭窗口
        e->ignore();
    }

}
//事件分发器
bool MyMainWindow::event(QEvent *e)
{


//定时器重写
    if(e->type()==QEvent::Timer)
    {

        QTimerEvent *env = static_cast<QTimerEvent *>(e);
        timerEvent(env);

         return true;//已经改写
    }
    else
    {

        return QWidget::event(e);
    }
  return QWidget::event(e);
}

void MyMainWindow::on_action_Reset_triggered()
{
    short sRtn;
    sRtn = GT_Reset();
}
