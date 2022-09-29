#ifndef INTERFACEFIGURE_H
#define INTERFACEFIGURE_H
#include <QPainter>

class InterfaceFigure
{
public:
    InterfaceFigure();
    virtual void draw(QPainter &painter) const =0;
    void regenerateColorSettings();
    void regenerateGradient();
    virtual bool selectTest(const QPointF &point) const=0;
    const QPen &pen() const;
    void setPen(const QPen &newPen);
    const QBrush &brush() const;
    void setBrush(const QBrush &newBrush);

protected:
    QPen mPen=QPen(Qt::red);
    QBrush mBrush=QBrush(Qt::green);
};

#endif // INTERFACEFIGURE_H
