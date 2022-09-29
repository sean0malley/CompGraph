#ifndef PLOT_H
#define PLOT_H

#include <QWidget>
#include <interfacefigure.h>
class Plot : public QWidget
{
    Q_OBJECT

public:
    Plot(QWidget *parent = nullptr);
    //~Plot();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    std::vector<std::shared_ptr<InterfaceFigure>> mFigures;
};
#endif // PLOT_H
