#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();

signals:

  protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
     void mouseReleaseEvent(QMouseEvent *);
public slots:
};

#endif // MYLABEL_H
