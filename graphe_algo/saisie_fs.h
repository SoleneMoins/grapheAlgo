#ifndef SAISIE_FS_H
#define SAISIE_FS_H


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





class saisie_fs : public QDialog
{
public:
    saisie_fs(QWidget *parent=nullptr);
    std::vector<int> getfs()const;
    int nbSommet() const;
    void vue_creer();
    graphe getGraphe();
    void setGraphe(graphe g);

private:
    std::vector<int> fs;
    QLineEdit*editNbSommet;
    QVBoxLayout layoutPrinc;
    QVBoxLayout layoutsaisie;
    std::vector<QLineEdit*> d_s;
    int d_nbsommet;
    graphe d_graphe;


private slots:
    void onValider();
    void onValideSommet();
    void onclose();
};

#endif // SAISIE_FS_H
