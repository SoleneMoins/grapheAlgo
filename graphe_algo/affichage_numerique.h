#ifndef AFFICHAGE_NUMERIQUE_H
#define AFFICHAGE_NUMERIQUE_H

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

class affichage_numerique : public QDialog
{
public:
    affichage_numerique(graphe g,QWidget *parent=nullptr);

private:
    graphe d_graphe;


private slots:
    void onValider();
    void onValideSommet();
};


#endif // AFFICHAGE_NUMERIQUE_H
