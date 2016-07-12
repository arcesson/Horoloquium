/**
 * @file main.cpp
 *
 * @~english
 * This file is part of the Horoloquium project, you can redistribute it
 * and/or modify it under the terms of the GNU GPL v3.
 *
 * @author Stefan Kleyer
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
