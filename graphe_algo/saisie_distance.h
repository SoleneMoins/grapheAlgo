#ifndef SAISIE_DISTANCE_H
#define SAISIE_DISTANCE_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QRegExpValidator>
#include <QMessageBox>
#include <vector>
#include <iostream>
#include "graphe.h"


class saisie_distance : public QDialog
{
public:
    saisie_distance(graphe g,QWidget*parent=nullptr);
private:
    graphe d_graphe;
    QVBoxLayout layoutPrinc;
    QHBoxLayout affiche;
    QLineEdit*so1;
    QLineEdit*so2;

private slots:
    void boutonOk();
    void boutonClose();
};

#endif // SAISIE_DISTANCE_H
