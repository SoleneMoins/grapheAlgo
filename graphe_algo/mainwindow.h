#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QLabel>
#include <QRegExpValidator>
#include "zone_dessin.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void boutonSommet();
    void boutonLiens();
    void effacer();

private:
    QMainWindow*d_win;
    zone_dessin* d_dessin;
    QLineEdit*num;
    void vue_creer();



};
#endif // MAINWINDOW_H
