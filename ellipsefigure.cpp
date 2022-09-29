#include "ellipsefigure.h"
#include <QPainterPath>
EllipseFigure::EllipseFigure()
{

}
void EllipseFigure::draw(QPainter &painter) const{
    painter.setPen(mPen);
    painter.setBrush(mBrush);
    painter.drawEllipse(QRectF(mLeft,mTop,mWidth,mHeight));
}
bool EllipseFigure::selectTest(const QPointF &point) const
{
    QPainterPath path;
    path.addEllipse(QRectF(mLeft,mTop,mWidth,mHeight));
    return path.contains(point);
}
double EllipseFigure::left() const
{
    return mLeft;
}

void EllipseFigure::setLeft(double newLeft)
{
    mLeft = newLeft;
}

double EllipseFigure::top() const
{
    return mTop;
}

void EllipseFigure::setTop(double newTop)
{
    mTop = newTop;
}

double EllipseFigure::width() const
{
    return mWidth;
}

void EllipseFigure::setWidth(double newWidth)
{
    mWidth = newWidth;
}

double EllipseFigure::height() const
{
    return mHeight;
}

void EllipseFigure::setHeight(double newHeight)
{
    mHeight = newHeight;
}
