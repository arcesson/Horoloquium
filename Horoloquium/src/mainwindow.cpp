/**
 * @file mainwindow.cpp
 *
 * @~english
 * This file is part of the Horoloquium project, you can redistribute it
 * and/or modify it under the terms of the GNU GPL v3.
 *
 * @class MainWindow
 * @author Stefan Kleyer
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setting up the UI
    ui->setupUi(this);
    ui->labelTime->setStyleSheet( "QLabel {background-color: green; font-size: 30px; }" );

    // Initialising some variables and Objects:
    timer.start();
    QTimer *qtimer = new QTimer(this);
    countDown = 10000;
    labelTimeText = "Remaining time!";
    ui->timeEdit->setText( "00:10" );

    // About dialog box
    About *about = new About();
    QObject::connect(ui->buttonAbout, SIGNAL(clicked(bool)),
                     about, SLOT(show()));

    // Connecting the qtimer's timeout to function updateFarbe
    QObject::connect(qtimer, SIGNAL(timeout()),
            this, SLOT(updateFarbe()));

    qtimer->start(1000);        // QTimer will timeout every ~1000ms
}

/* on_buttonStart_clicked resets the QElapsedTimer timer for renewed start
 * of the countdown. If set the countdown is the text in the QLineEdit
 * timeEdit. */
void MainWindow::on_buttonStart_clicked(){
    timer.start();      // restart the timer for countdown

    // Extracts the time from ui->timeEdit and sets countdown
    QStringList stringList = ui->timeEdit->text().split( ':' );
    countDown = 0;
    if ( stringList.length() == 1 ){
        countDown += stringList.at(0).toInt()*1000*60;
    }
    else
    {
        countDown += stringList.at(0).toInt()*1000*60;
        countDown += stringList.at(1).toInt()*1000;
    }

    qDebug( "QElapsedTimer neu gestartet.");
}

/* updateFarbe updates the text and color of QLabel labelTime.
 * If the remaining time is
 * - above 1/2 of countDown it is green,
 * - above 2/3 it is yellow,
 * - above 0 it is orange,
 * - =0 (or at least <0) it is red.
 * */
void MainWindow::updateFarbe(){
    switch (ui->checkBox->checkState()){
    case Qt::Checked:
        if ( timer.elapsed()+1 < (countDown/2) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: green; font-size: 100px; }" );
            ui->labelTime->setText( convertToTime( countDown - timer.elapsed() ) );
        }
        else if ( timer.elapsed()+1 < (countDown*2/3) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: yellow; font-size: 100px; }" );
            ui->labelTime->setText( convertToTime( countDown - timer.elapsed() ) );
        }
        else if ( timer.elapsed()+1 < (countDown) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: orange; font-size: 100px; }" );
            ui->labelTime->setText( convertToTime( countDown - timer.elapsed() ) );
        }
        else
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: red; font-size: 100px; }" );
            ui->labelTime->setText( "<center>--:-- s</center>" );
        }
        break;
    case Qt::Unchecked:
        if ( timer.elapsed()+1 < (countDown/2) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: green; font-size: 100px; }" );
        }
        else if ( timer.elapsed()+1 < (countDown*2/3) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: yellow; font-size: 100px; }" );
        }
        else if ( timer.elapsed()+1 < (countDown) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: orange; font-size: 100px; }" );
        }
        else
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: red; font-size: 100px; }" );
        }
        break;
    case Qt::PartiallyChecked:
        if ( timer.elapsed()+1 < (countDown/2) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: green; font-size: 100px; }" );
            ui->labelTime->setText( convertToTime( countDown - timer.elapsed() ) );
        }
        else if ( timer.elapsed()+1 < (countDown*2/3) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: yellow; font-size: 100px; }" );
            ui->labelTime->setText( convertToTime( countDown - timer.elapsed() ) );
        }
        else if ( timer.elapsed()+1 < (countDown) )
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: orange; font-size: 100px; }" );
            ui->labelTime->setText( convertToTime( countDown - timer.elapsed() ) );
        }
        else
        {
            ui->labelTime->setStyleSheet( "QLabel {background-color: red; font-size: 100px; }" );
            ui->labelTime->setText( "<center>--:-- s</center>" );
        }
        break;
    }
}

/* convertToTime converts an integer time e.g. from QElapsedTimer::elapsed()
 * into a timeformat of mm:ss (minutes:seconds). */
QString MainWindow::convertToTime( int time ){
    time/=1000;         // Eliminates milliseconds
    QString value;

    // Fills value with the number of seconds and adds a 0 digit if its under 10.
    value = QString::number( time%60 );
    if ( time%60 < 10 ){
        value.prepend( "0" );
    }

    // Adds the seperator before the second digits
    value.prepend( ":" );

    // Fills value with the number of minutes and adds a 0 digit if its under 10.
    value.prepend( QString::number(time/60) );
    if ( time/60 < 10 ){
        value.prepend( "0" );
    }

    return value.prepend("<center>").append(" s</center>");
}

void MainWindow::on_buttonExit_clicked()
{
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0){
        ui->labelTime->setText( "" );
    }
}
