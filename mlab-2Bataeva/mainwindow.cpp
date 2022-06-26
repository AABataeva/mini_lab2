#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "point.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter (this);
        for(int i=0; i < p.size() ; i++){
            Point *point = p[i];
           point->draw(&painter);
//           int x = point->getX();                                                                              //2.1
//           int y = point-> getY();
//           painter.drawLine(x-point->getSize(),y-point->getSize(),x+point->getSize(),y+point->getSize());
//           painter.drawLine(x+point->getSize(),y-point->getSize() ,x-point->getSize(),y+point->getSize());
        }

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
//   static int s;                                                    // 2.2 и 2.3
//   s = (cnt ? p[cnt-1]->getSize() : 3);
//  int width;
//  width = (cnt < 5 ? 1 : 2);
//    Point *point = new Point(event->x(), event->y(), s+1, width);
//    if(cnt < 10)
//        p[cnt++] = point;
//    else
//        delete point;
    QPoint cPoint;
    cPoint.setX(event->x());
    cPoint.setY(event->y());
    for(int i = 0; i < p.size(); i++){
        if(p[i]->distance2(cPoint) <= 5){                                // 2.8
            p[i]-> setWidth(p[i]->getWidth() * 2);
            p[i]-> setWidth(p[i]->getWidth() * 2);
            break;
        }
    }
    Point *point = new Point (event->x(), event->y(), 3, 1);
    p.append(point);
    repaint();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    for(int i = 0; i < p.size(); i++){                                // 2.9 и 2.10
        if(p[i]->getPressed()){
            p[i]->setX(event->x());
            p[i]->setY(event->y());
            p[i]->setPressed(false);
            break;

        }
    }
    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    for(int i = 0; i < p.size(); i++){
        if(p[i]->getPressed()){
            p[i]->setX(event->x());
            p[i]->setY(event->y());
        }
    }
    repaint();
}

