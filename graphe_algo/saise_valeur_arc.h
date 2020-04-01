#ifndef SAISE_VALEUR_ARC_H
#define SAISE_VALEUR_ARC_H

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


class saise_valeur_arc : public QDialog
{
public:
    saise_valeur_arc(graphe g,QWidget *parent=nullptr);
    graphe getGraphe();

private:
    std::vector<QLineEdit*> d_v;
    graphe d_graphe;

private slots:
    void onValide();
};

#endif // SAISE_VALEUR_ARC_H
