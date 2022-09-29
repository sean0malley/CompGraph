#include "interfacefigure.h"
#include <QRandomGenerator>
#include <QGradient>
InterfaceFigure::InterfaceFigure()
{

}
void InterfaceFigure::regenerateColorSettings(){
    mPen.setColor(
                QColor(
                    QRandomGenerator::global()->bounded(256),
                     QRandomGenerator::global()->bounded(256),
                     QRandomGenerator::global()->bounded(256)
                   )
                );
    mBrush.setColor(
                QColor(
                    QRandomGenerator::global()->bounded(256),
                     QRandomGenerator::global()->bounded(256),
                     QRandomGenerator::global()->bounded(256)
                   )
                );
    mBrush.setStyle(
                Qt::BrushStyle(1+QRandomGenerator::global()->bounded(14))
                );
}
void InterfaceFigure::regenerateGradient(){
    auto x=QRandomGenerator::global()->bounded(3);
    QGradient gradient;
    if (x==0){
        gradient=QLinearGradient();
        }

    else if(x==1){
        gradient=QRadialGradient();
    }
    else if(x==2){
        gradient=QConicalGradient();
    }
    for(int i=0;i<12;i++){
        gradient.setColorAt(
                    0+i*(1.0/(12.0-1.0)),
                    QColor(
                        QRandomGenerator::global()->bounded(256),
                        QRandomGenerator::global()->bounded(256),
                        QRandomGenerator::global()->bounded(256)
                        )
                    );
    }

    gradient.setCoordinateMode(QGradient::CoordinateMode(3));
    QBrush gradientBrush(gradient);
    mBrush=gradientBrush;

}
const QPen &InterfaceFigure::pen() const
{
    return mPen;
}

void InterfaceFigure::setPen(const QPen &newPen)
{
    mPen = newPen;
}
const QBrush &InterfaceFigure::brush() const
{
    return mBrush;
}

void InterfaceFigure::setBrush(const QBrush &newBrush)
{
    mBrush = newBrush;
}
