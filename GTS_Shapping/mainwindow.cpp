#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"
#include "gts.h"
//#include "config.h"
#include "inner.h"
#include "LookAheadEx.h"
#include <QDebug>               //调试输出类
#include <QPushButton>
#include <QMessageBox>
#include <QCloseEvent>
#include <Qmovie>
#include <QMenu>
#include <QTimerEvent>
#include <QMenuBar>
#include <QAction>
#include <QKeyEvent>
#include <QEvent>
#include <QSettings>
#include <QDir>         //目录浏览类
#include <QFileInfo>    //文件信息类
#include <QFileDialog>

//#include <QScrollArea>  //为标签添加滚动区域
//#include <QObject>
#pragma comment <lib,"gts.lib">
#define TIMER_TIMEOUT   (1*100)
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // InitialCtrlCard();

   // LoadSettings();
    //iniMenuBar();


}
bool OpenFlagSuccess = false;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitialCtrlCard()
{
  on_pushButton_clicked();
}
void Error(QWidget *parent,short rtn, QString cmdStr)
{
\
    if(OpenFlagSuccess == true)
        return;
    if (rtn)
        QMessageBox::information(parent,"调试信息", cmdStr.arg(rtn));

}
void MainWindow::on_pushButton_clicked()
{

    short sRtn ;
    OpenFlagSuccess = false;
     sRtn = GT_Open();

    Error(this,sRtn,"GT_Open = %1");
    if(sRtn!=0)
    {
        OpenFlagSuccess = true;
    }
    sRtn = GT_Reset();    Error(this,sRtn,"GT_Reset = %1");
    sRtn = GT_LoadConfig("GT800.cfg");     Error(this,sRtn,"GT_LoadConfig = %1");
    sRtn = GT_ClrSts(1, 8);    Error(this,sRtn,"GT_Open = %1");

}


void MainWindow::on_pushButton_Axis_On_clicked()
{
    short rtn;
    QPushButton*btn = qobject_cast<QPushButton*>(sender());//获取发射信号的对象
  //  QPushButton *btn = this->findChild("button1", Qt::FindDirectChildOnly);

  if("使能"==btn->text()){//如果获取到控件的名称

      for(int i = 1;i<=6;i++)
              {
                  rtn = GT_AxisOn(i);
              }
      btn->setText("使能关闭");
      //btn->setStyle("background-color: rgb(0, 255, 127);");
  }
  else if("使能关闭" == btn->text())
      {
          for(int i = 1;i<=6;i++)
          {
              rtn = GT_AxisOff(i);
          }
           btn->setText("使能");
      }
}

void MainWindow::on_pushButton_2_clicked()
{short sRtn;
    sRtn = GT_ClrSts(1,8);
    Error(this,sRtn,"GT_ClrSts = %1");

}

void MainWindow::on_pushButton_3_clicked()
{
    short sRtn;
        for(int i = 1;i<=12;i++)
        {
            sRtn = GT_ZeroPos(i,1);
        }
}

void MainWindow::on_pushButton_4_clicked()
{
    short sRtn;
        sRtn = GT_ClearWatch();
        sRtn = GT_LoadWatchConfig("watchTimer.ini");
}

void MainWindow::on_pushButton_5_clicked()
{
    short sRtn;
        sRtn = GT_WatchOff();
        sRtn = GT_PrintWatch("watchData.txt");
}
void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){
            handleTimeout();
        }

}

//事件分发器
bool MainWindow::event(QEvent *e)
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
//定时器响应
void MainWindow::handleTimeout()
{

    QString tempStr,tempStr1,tempStr2;
      //      short axis = ui->CBM_axis->currentText().toInt();
    //qDebug()<<"按键被按下";

    tempStr = "enc1 = %1\t,enc2 = %2\t\n"
          "enc3 = %3\t,enc4 = %4\n"
          "enc5 = %5\t,enc6 = %6\n"
          "enc7 = %7\t,enc8 = %8\n";

    tempStr1 = "prf1 = %1\t,prf2 = %2\t\n"
          "prf3 = %3\t,prf4 = %4\n"
          "prf5 = %5\t,prf6 = %6\n"
          "prf7 = %7\t,prf8 = %8\n";

        short sRtn;
        short rtn;
        double pValue[8];

        rtn = GT_GetEncPos(1,&pValue[0],8);
        ui->label->setText(tempStr.arg(pValue[0]).arg(pValue[1])
                                  .arg(pValue[2]).arg(pValue[3])
                                  .arg(pValue[4]).arg(pValue[5])
                                  .arg(pValue[6]).arg(pValue[7]));
        rtn = GT_GetPrfPos(1,&pValue[0],8);
        ui->label_2->setText(tempStr1.arg(pValue[0]).arg(pValue[1])
                                  .arg(pValue[2]).arg(pValue[3])
                                  .arg(pValue[4]).arg(pValue[5])
                                  .arg(pValue[6]).arg(pValue[7]));



}
void MainWindow::closeEvent(QCloseEvent *e)
{


    if(QMessageBox::question(this,"GoHome","是否需要返回")==QMessageBox::Yes)
    {
        on_MainWindow_destroyed();
        //关闭窗口
        e->accept();
    }
    else
    {
        //不关闭窗口
        e->ignore();
    }

}
void MainWindow::on_action_Reset_triggered()
{
    short sRtn;
    sRtn = GT_Reset();
    Error(this,sRtn,"GT_Reset = %1");
}


void MainWindow::on_pushButton_6_clicked()
{
    TCrdPrm crdprm;
        //CString strTemp;
    short rtn;
        rtn = GT_CrdClear(1,0);                 //清除坐标系1FIFO 0中的数据
        memset(&crdprm,0,sizeof(crdprm));
        crdprm.dimension = 2;         //建立二维坐标系
        crdprm.synVelMax = 5000;       //最大合成速度500pulse/ms
        crdprm.synAccMax = 1000;        //最大合成加速度10pulse/ms^2
        crdprm.evenTime = 5;          //每个插补段最小匀速时间5ms
        crdprm.profile[0] = 1;
        //crdprm.profile[1] = 2;        //1、2通到建立XY坐标系
        crdprm.profile[1] = 2;        //1、2通到建立XY坐标系
        crdprm.setOriginFlag = 1;     //指定坐标系原点位置为（0，0）
        crdprm.originPos[0] = 0;
        crdprm.originPos[3] = 0;
        rtn = GTN_SetCrdPrm(1,1,&crdprm);
        if (rtn!=0)
        {
            Error(this,rtn,"GT_Reset = %1");
        }

        //*****************************************************新前瞻标准使用方法*************************************************************
        //初始化多轴前瞻模块
        EMachineMode machineMode; //机床类型
        int axisLimitMode[8]; //轴限制模式
        EWorkLimitMode workLimitMode; //工件坐标系限制模式
        int axisFollowMode[8]; //轴跟随模式
        TLookAheadParameter lookAheadPara; //前瞻参数

        machineMode = NORMAL_THREE_AXIS; //标准三轴机床

        lookAheadPara.lookAheadNum = 200;    //前瞻段数，建议设置200段

        lookAheadPara.time = 1;  //时间常数

        lookAheadPara.radiusRatio = 0.001;      //曲率限制调节参数

        for (int i=0;i<8;++i)
        {
            lookAheadPara.vMax[i] = 50000;//各轴的最大速度mm/s
            lookAheadPara.aMax[i] = 50000;//各轴的最大加速度mm/s^2
            lookAheadPara.DVMax[i] = 5000;//各轴的最大速度变化量mm/s^2
            lookAheadPara.axisRelation[i] = i+1;//设置输入坐标轴号和内部前瞻规划坐标轴号的对应关系
            lookAheadPara.scale[i] = 4000;//各轴的,冲当量（1mm对应1000pluse）
        }
        rtn = GT_SetupLookAheadCrd(1,machineMode);//建立前瞻1坐标系，并指定该坐标系的机床类型
       Error(this,rtn,"GT_SetupLookAheadCrd = %1");
        rtn = GTN_InitLookAheadEx(1,1,&lookAheadPara,0);//设置前瞻参数（需要放在最后设置）
        Error(this,rtn,"GTN_InitLookAheadEx = %1");

        double smoothTime;
       // GetDlgItemText(IDC_EDIT1,strTemp);
       // smoothTime = _wtof(strTemp);
        for(int i =  1;i<=2;i++)
        {
            rtn = GTN_SetAxisMotionSmooth(1,i,30,15);//设置平滑滤波时间，单位：ms，乘以周期即为滤波合数
             Error(this,rtn,"GTN_SetAxisMotionSmooth = %1");
        }
        //GetDlgItemText(IDC_EDIT3,strTemp);

        rtn = GTN_SetCrdJerk(1,1,1);
         Error(this,rtn,"GTN_SetCrdJerk = %1");

//        rtn = GTN_CrdHsOn(1,1,0,1,200,0);//打开DMA功能
//         Error(this,rtn,"GTN_SetCrdJerk = %1");

//        if(0 != SetCompareEquidistantParma())
//        {
//              Error(this,rtn,"SetCompareEquidistantParma = %1");
//        }
        //double dccAngle;
        //GetDlgItemText(IDC_EDIT4,strTemp);
        //dccAngle = _wtof(strTemp);
         //rtn = GTN_SetMinDccAngle(1,1,dccAngle);
}

void MainWindow::iniMenuBar()
{
    //处理菜单栏操作
     QMenuBar *mBar = menuBar();
     QMenu *pFile =  mBar->addMenu("控制");
    QAction  *action_Reset = pFile->addAction("复位");
     connect(action_Reset,&QAction::triggered,
             [=](){

                 on_action_Reset_triggered();
                }

             );
    // connect(action_Reset,&QAction::triggered,MainWindow::on_action_Reset_triggered());
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

void MainWindow::SaveSettings()
{
    //机构或公司名设为 QtGoogoltech，应用程序名设为 GTS_Shapping
        QSettings settings("QtGoogoltech", "GTS_Shapping");
        //主窗口状态信息
        QByteArray baMainWidget = this->saveGeometry();
        //分裂器状态信息
       // QByteArray baSplitter = ui->splitter->saveState();
        //源文件 URL
       // QUrl urlSrc = ui->textBrowser->source();

        //保存为配置项，键名自己随便取
        settings.setValue("MainWidget", baMainWidget);
        //settings.setValue("Splitter", baSplitter);
        //settings.setValue("URL", urlSrc);
        //搞定，settings 对象在栈里面，该对象析构时自动存储所有配置
}

void MainWindow::LoadSettings()
{
    //机构或公司名设为 QtGuide，应用程序名设为 SimpleBrowser
        //settings 的构造函数自己会去读取上次保存的注册表或配置文件信息
        QSettings settings("QtGuide", "SimpleBrowser");

        //判断键名是否存在，然后取出各个键名对应的键值，还原以前保存的状态
        //主窗口
        if(settings.contains("MainWidget"))
        {
            QByteArray baMainWidget = settings.value("MainWidget").toByteArray();
            this->restoreGeometry(baMainWidget);
        }
        //分裂器
//      //  if(settings.contains("Splitter"))
//        {
//            QByteArray baSplitter = settings.value("Splitter").toByteArray();
//            ui->splitter->restoreState(baSplitter);
//        }
//        //源文件URL
//        if(settings.contains("URL"))
//        {
//            QUrl urlSrc = settings.value("URL").toUrl();
//            ui->textBrowser->setSource(urlSrc);
//        }
}

//void MainWindow::on_actLoadConfig_toggled(bool arg1)
//{
    //short rtn;

//   // QString path = QFileDialog::getOpenFileName(this,tr("Open File"), ".", tr("Text Files(*.txt)"));

//    //获取将要打开的文件名
//        QString path = QFileDialog::getOpenFileName(
//                    this,
//                    tr("打开配置文件"),
//                    tr("."),
//                    tr("Text files(*.txt);;All files(*)")
//                    );





//}

void MainWindow::on_actReset_triggered()
{
    short rtn;


    QMessageBox msgBox;
    msgBox.setText(tr("GTS has been modified."));
    msgBox.setInformativeText(tr("Do you want to Reset your control?"));
   // msgBox.setDetailedText(tr("Differences here..."));
    msgBox.setStandardButtons(QMessageBox::Yes
                              | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    switch (ret)
    {
    case QMessageBox::Yes:
       rtn = GT_Reset();
        break;

    case QMessageBox::Cancel:

        break;
    }

}

void MainWindow::on_actLoadConfig_triggered(bool checked)
{
    short rtn;

   // QString path = QFileDialog::getOpenFileName(this,tr("Open File"), ".", tr("Text Files(*.txt)"));

    //获取将要打开的文件名
        QString path = QFileDialog::getOpenFileName(
                    this,
                    tr("打开配置文件"),
                    tr("."),
                    tr("Text files(*.cfg);;All files(*)")
                    );
        if(!path.isEmpty())
            {

                    //获取程序当前工作路径
                   // QString strWorkPath = QDir::currentPath();



                    char *ch=path.toLatin1().data();
                    rtn = GT_LoadConfig(ch);
                    Error(this,rtn,"GT_LoadConfig");
                    rtn = GT_ClrSts(1,8);

              }
              else
                 {
                   QMessageBox::warning(this, tr("Path"),tr("You did not select any file."));
                 }
}

void MainWindow::on_MainWindow_destroyed()
{

    QSettings *configIniWrite = new QSettings("hahaya.ini", QSettings::IniFormat);
       //向ini文件中写入内容,setValue函数的两个参数是键值对
       //向ini文件的第一个节写入内容,ip节下的第一个参数
       configIniWrite->setValue("/ip/first", "192.168.0.1");
       //向ini文件的第一个节写入内容,ip节下的第二个参数
       configIniWrite->setValue("ip/second", "127.0.0.1");
       //向ini文件的第二个节写入内容,port节下的第一个参数
       configIniWrite->setValue("port/open", "2222");
       //写入完成后删除指针
       delete configIniWrite;
}
