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


    void changeNum(int num);

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
    bool graphe_valide;
    graphe d_graphe;
    std::vector<QPoint> points;
    void paintEvent(QPaintEvent *p);
    void mousePressEvent(QMouseEvent * event);
};


#endif // ZONE_DESSIN_H
