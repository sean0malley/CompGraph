#ifndef ELLIPSEFIGURE_H
#define ELLIPSEFIGURE_H
#include "interfacefigure.h"

class EllipseFigure: public InterfaceFigure
{
public:
    EllipseFigure();
    void draw(QPainter &painter) const override;
    bool selectTest(const QPointF &point) const override;

    double left() const;
    void setLeft(double newLeft);

    double top() const;
    void setTop(double newTop);

    double width() const;
    void setWidth(double newWidth);

    double height() const;
    void setHeight(double newHeight);

protected:
    double mLeft=0;
    double mTop=0;
    double mWidth=100;
    double mHeight=100;
};



#endif // ELLIPSEFIGURE_H
