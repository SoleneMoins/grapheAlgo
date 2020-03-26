#ifndef ZONE_DESSIN_H
#define ZONE_DESSIN_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <Qtransform>
#include <iostream>
#include "sommet.h"

class zone_dessin:public QWidget
{
    Q_OBJECT
public:
    zone_dessin(QWidget *parent=nullptr);
    void changeChoix(int choix);
    void changeNum(int num);
    void nettoie();
private:
    int xPress;
    int yPress;
    int d_choix;
    int d_num;
    std::vector<sommet> d_sommet;
    std::vector<QLineF> liens;
    std::vector<QPoint> points;
    void paintEvent(QPaintEvent *p);
    void mousePressEvent(QMouseEvent * event);
};


#endif // ZONE_DESSIN_H
