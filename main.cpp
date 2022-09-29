#include "plot.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>
#include <QFileDialog>
#include <QSvgGenerator>
#include <QPrinter>
#include <QPicture>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget mainWidget;
    auto *plot=new Plot(&mainWidget);
    auto *button=new QPushButton("Сохранить", &mainWidget);
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    auto *layout = new QHBoxLayout;
    layout->addWidget(plot);
    layout->addWidget(button);
    mainWidget.setLayout(layout);
    mainWidget.resize(800,600);
    mainWidget.show();
    QObject::connect(button,&QPushButton::clicked, plot,[plot](){
        QString fileName=QFileDialog::getSaveFileName(
                    nullptr,
                    "Сохранение в файл-изображение",
                    "",
                    "PNG (*.png);;JPG (*.jpg);;SVG (*.svg);;PDF (*.pdf)"
                    );
       if(fileName.isEmpty())
       {
           return;
       }
       else if(fileName.endsWith(".png"))
       {
           QPixmap pixmap(plot->size());
           plot->render(&pixmap);
           pixmap.save(fileName,"PNG");
       }
       else if(fileName.endsWith(".jpg"))
       {
           QPixmap pixmap(plot->size());
           plot->render(&pixmap);
           pixmap.save(fileName,"JPG");
       }
       else if(fileName.endsWith(".svg"))
       {
           QSvgGenerator svgGenerator;
           svgGenerator.setSize(plot->size());
           svgGenerator.setViewBox(QRect(QPoint(0,0), plot->size()));
           svgGenerator.setFileName(fileName);
           plot->render (&svgGenerator);
       }
       else if(fileName.endsWith(".pdf"))
       {
           QPicture picture;
           plot->render(&picture);
           QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName(fileName);
           printer.setPageSize(QPageSize(plot->size()*72/96));
           printer.setPageMargins(QMargins(0,0,0,0));
           QPainter painter(&printer);
           picture.play(&painter);
       }
    });
    return a.exec();
}
