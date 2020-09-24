#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include    <QLabel>
#include    <QProgressBar>
#include    <QSpinBox>
#include    <QFontComboBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actReset_triggered();

private:
    Ui::MainWindow *ui;


private:
    QString     fCurFileName;//当前文件名
    QLabel      *fLabCurFile;//状态栏里显示当前文件的Label
    QProgressBar    *progressBar1;//状态栏上的进度条

    QSpinBox        *spinFontSize;//   字体大写
    QFontComboBox   *comboFont;//字体名称
    void    updateCurFile(QString aFile);//更新当前文件名，并更新状态栏提示
    void    iniUI(); //程序设计的UI初始化
};

#endif // MAINWINDOW_H
