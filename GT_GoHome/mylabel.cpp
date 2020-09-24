#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

MyLabel::~MyLabel()
{

}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{



    this->setText(QString("<center><h1>mouseMove: (%1, %2)</h1></center>")
                  .arg(QString::number(ev->x()),
                  QString::number(ev->y())));

}
void MyLabel::mousePressEvent(QMouseEvent *ev)
{

    if(ev->button()==  Qt::LeftButton)
    {

        qDebug()<<"left";

    }
    if(ev->button()==  Qt::RightButton)
    {
        qDebug()<<"right";


    }
    if(ev->button()==  Qt::MidButton)
    {

        qDebug()<<"mid";

    }


    this->setText(QString("<center><h1>mousePressed: (%1, %2)</h1></center>")
                  .arg(QString::number(ev->x()),
                  QString::number(ev->y())));


}
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    this->setText(QString("<center><h1>mouseRelease: (%1, %2)</h1></center>")
                  .arg(QString::number(ev->x()),
                  QString::number(ev->y())));
}
