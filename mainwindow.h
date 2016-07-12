/**
 * @file mainwindow.h
 *
 * @~english
 * This file is part of the Horoloquium project, you can redistribute it
 * and/or modify it under the terms of the GNU GPL v3.
 *
 * @class MainWindow
 * @author Stefan Kleyer
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QString>
#include <QStringList>
#include <QElapsedTimer>
#include <QTimeEdit>
#include <QMessageBox>

#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_buttonStart_clicked();
    void updateFarbe();

    void on_buttonExit_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    QString convertToTime( int time );

    Ui::MainWindow *ui;
    QElapsedTimer timer;
    QString labelTimeText;  // String that inherits the remaining time.
    int countDown;          // global variable in MainWindow for length of CountDown in ms.
    About *about;

};

#endif // MAINWINDOW_H
