#ifndef ZONE_DESSIN_H
#define ZONE_DESSIN_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
#include <QPoint>
#include "arc.h"
#include <iostream>
#include "sommet.h"

class zone_dessin:public QWidget
{
    Q_OBJECT
public:

    //Constructor
    zone_dessin(QWidget *parent=nullptr);

    /**
      Return vector of arc
      @return vector of arc
    */
    std::vector<arc> getArcVector();

    /**
      Return vector of sommet
      @return vector of sommet
    */
    std::vector<sommet> getSommetVector();


    /**
      Change choice to draw
      @param choix int for choice
    */
    void changeChoix(int choix);

    /**
      Change number of sommet
      @param num int for number
    */
    void changeNum(int num);

    void changeValidation(bool v);

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
    std::vector<sommet> d_sommet;
    std::vector<arc> d_arc;
    std::vector<QRectF> somm;
    std::vector<QLineF> liens;
    std::vector<QPoint> points;
    void paintEvent(QPaintEvent *p);
    void mousePressEvent(QMouseEvent * event);
};


#endif // ZONE_DESSIN_H
