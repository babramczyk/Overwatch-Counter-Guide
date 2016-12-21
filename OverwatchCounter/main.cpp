///////////////////////////////////////////////////////////////////////////////
// File Name:      main.cpp
//
// Author0:        Richard Wollack
// CS email:       wollack@cs.wisc.edu
//
// Author1:        Brett Abramczyk
// CS email:       babramczyk@wisc.edu
//
// Description:    Application entry point
///////////////////////////////////////////////////////////////////////////////

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
