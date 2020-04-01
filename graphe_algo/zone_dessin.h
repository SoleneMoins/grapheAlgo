#ifndef ZONE_DESSIN_H
#define ZONE_DESSIN_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
#include <QPoint>
#include <QLabel>
#include "arc.h"
#include <iostream>
#include "graphe.h"

class zone_dessin:public QWidget
{
    Q_OBJECT
public:

    //Constructor
    zone_dessin(QWidget *parent=nullptr);

    std::vector<arc> getArcVector();
    std::vector<sommet> getSommetVector();

    fs_aps getFsAps();
    graphe getGraphe();

    void setGraphe(graphe g);

   // std::vector<int> getNumTarjan();


    void changeChoix(int choix);

    void effacerSommet(int i);
    void effacerArc(int i);


    void changeNum(int num);
    void changeValeur(int v);
    void changeNom(std::string nom);
    void changeValidation(bool v);
    bool estValide();
    bool validationGraphe();

    void save(std::ostream&ost);

    void open(std::istream&ist);

    //Clean all vector
    void nettoie();


private:
    int xPress;
    int yPress;
    int d_choix;
    int d_num;
    int d_valeur;
    bool graphe_valide;
    std::string d_nom;
    graphe d_graphe;
    std::vector<QPoint> points;
    void paintEvent(QPaintEvent *p);
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent*e);
};


#endif // ZONE_DESSIN_H
