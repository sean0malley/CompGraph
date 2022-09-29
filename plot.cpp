#include "plot.h"
#include <QPainter>
#include <ellipsefigure.h>
#include <QMouseEvent>
#include <QFileDialog>
Plot::Plot(QWidget *parent)
    : QWidget(parent)
{
    for(int i=0;i<10;i++){
    auto ellipsePtr= std::make_shared<EllipseFigure>();
    ellipsePtr->setLeft(i*100);
    ellipsePtr->setTop(i*100);
    ellipsePtr->regenerateColorSettings();
    ellipsePtr->regenerateGradient();
    mFigures.emplace_back(ellipsePtr);
    }
}

void Plot::paintEvent(QPaintEvent *event)
{
 QPainter painter(this);
 painter.setRenderHint(QPainter::Antialiasing, true);
 painter.fillRect(rect(),Qt::darkGray);
 painter.setPen(Qt::yellow);
 painter.drawText(
             rect(),
             Qt::AlignCenter,
             "Hello widget"
             );

 for(const auto &figure: mFigures)
 {
     figure->draw(painter);
 }
}
void Plot::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    for(int i=mFigures.size()-1;i>-1;--i)
    {
        if(mFigures[i]->selectTest(event->position())){
            if(event->button()==Qt::LeftButton)
            {
                mFigures[i]->regenerateColorSettings();
            } else
             if(event->button()==Qt::MiddleButton){
                 mFigures[i]->regenerateGradient();
             }
            else if (event->button() == Qt::RightButton){
            QString filename=QFileDialog::getOpenFileName(nullptr,"open image as texture","","PNG (*.png);;JPG (*.jpg)");
            if(filename.isEmpty()){
            continue;
            }else if(filename.endsWith(".png")){
            mFigures[i]->setBrush(QBrush(QImage(filename, "PNG")));
            }else if(filename.endsWith(".jpg")){
            mFigures[i]->setBrush(QBrush(QImage(filename, "JPG")));
        }
             }



            update();
            break;
        }
    }
}


