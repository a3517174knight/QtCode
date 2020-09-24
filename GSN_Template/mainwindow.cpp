#include "mainwindow.h"
#include "ui_mainwindow.h"
#include    <QFile>
#include    <QFileDialog>
#include    <QTextStream>
#include    <QFontDialog>
#include    <QCoreApplication>
#include    <Qlabel>
#include    <QTextCharFormat>
#include "math.h"
#include "gts.h"
//#include "config.h"
//#include "inner.h"
#include "LookAheadEx.h"
#pragma comment <lib,"gts.lib">
#include <QDebug>               //调试输出类
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniUI()
{
    //状态栏
        fLabCurFile=new QLabel;  //用于显示当前文件名的标签
        fLabCurFile->setMinimumWidth(150);
        fLabCurFile->setText("当前文件：");
        ui->statusBar->addWidget(fLabCurFile);//添加到状态栏

        progressBar1=new QProgressBar;//状态栏上的进度条
        progressBar1->setMaximumWidth(200);//设置组件最大宽度
        progressBar1->setMinimum(5);
        progressBar1->setMaximum(50);
        progressBar1->setValue(ui->txtEdit->font().pointSize());//初始值
        ui->statusBar->addWidget(progressBar1); //添加到状态栏

    //工具栏
        spinFontSize = new QSpinBox;// 工具栏上的文字大小 SpinBox
        spinFontSize->setMinimum(5);
        spinFontSize->setMaximum(50);
        spinFontSize->setValue(ui->txtEdit->font().pointSize());//初始值
        spinFontSize->setMinimumWidth(50);//设置组件最小宽度

        ui->mainToolBar->addWidget(new QLabel("字体大小 ")); //不引用的Label无需定义变量
        ui->mainToolBar->addWidget(spinFontSize); //SpinBox添加到工具栏

        ui->mainToolBar->addSeparator(); //工具栏上增加分隔条
        ui->mainToolBar->addWidget(new QLabel(" 字体 "));
        comboFont = new QFontComboBox;//字体名称ComboBox
        comboFont->setMinimumWidth(150); //设置组件最小宽度
        ui->mainToolBar->addWidget(comboFont);//添加到工具栏

       // setCentralWidget(ui->txtEdit); //将txtEdit设置为中心组件，自动填充整个工作区
}

void MainWindow::on_actReset_triggered()
{
    short rtn;

    rtn = GTN_Reset(1);
}
