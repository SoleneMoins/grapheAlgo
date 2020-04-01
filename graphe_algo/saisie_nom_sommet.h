#ifndef SAISIE_NOM_SOMMET_H
#define SAISIE_NOM_SOMMET_H


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


class saisie_nom_sommet : public QDialog
{
public:
    saisie_nom_sommet(graphe g,QWidget*parent=nullptr);
    graphe getGraphe();

private:
    graphe d_graphe;
    std::vector<QLineEdit* > d_n;

private slots:
    void onValide();
    void onFerme();
};

#endif // SAISIE_NOM_SOMMET_H
