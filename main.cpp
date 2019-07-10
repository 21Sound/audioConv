/*------------------------------------------------------------------*\
Implmentation of a Peak Equalizer Class
the design is based on the EQ cookbook by Robert bristow Johnson
public domain

Author: Joerg Bitzer (TGM) (Jade-Hochschule) 

Modified by Hagen Jaeger, 22.09.2014, now with all cookbook-variations of a BiQuad
(LoPass, HiPass, LoShelv, HiShelf, pEQ, ...). Modification is based on Joerg Bitzers 
'filterdesign.m', i.e. RBJ Cookbook, for MATLAB.

Version 1.0.1 (debugged and tested, 22.09.2014).
\*------------------------------------------------------------------*/

#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int width = screenGeometry.width();
    int height = screenGeometry.height();

    MainWindow mainWin(static_cast<int>(0.4*width), static_cast<int>(0.7*height));
    mainWin.move(static_cast<int>(width*0.2), static_cast<int>(height*0.1));

    mainWin.show();

    return app.exec();
}
