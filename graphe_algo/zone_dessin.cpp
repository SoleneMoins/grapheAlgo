#include "zone_dessin.h"

zone_dessin::zone_dessin(QWidget *parent):QWidget{parent},d_choix{3},d_num{0}
{

}

void zone_dessin::changeChoix(int choix){
    d_choix = choix;
}


void zone_dessin::changeNum(int num){
    d_num = num;
}

void zone_dessin::nettoie(){
    d_sommet.clear();
    d_sommet.resize(0);
    liens.clear();
    liens.resize(0);
    points.clear();
    points.resize(0);
}

void zone_dessin::mousePressEvent( QMouseEvent * event){

    xPress = event->pos().x();
    yPress = event->pos().y();

    points.push_back(event->pos());

    update();



}

void zone_dessin::paintEvent(QPaintEvent*p){

    QPainter painter(this);
    QBrush brush1("#4F54D9", Qt::SolidPattern);
    QPen pen1("#4F54D9");
    QPen pen2("#FEFEFE");
    QFont font = painter.font();
    font.setPixelSize(18);
    painter.setFont(font);
    painter.setPen(pen1);
    painter.setBrush(brush1);



      if(d_choix==0){

            sommet som(xPress-40,yPress-40,d_num);
            d_sommet.push_back(som);
            points.pop_back();
            d_choix = 3;


        }else{

          if(d_choix==1){
              if(points.size()==2){
                   QLineF l(points[0],points[1]);
                   liens.push_back(l);
                   points.clear();
                   points.resize(0);


              }
          }else{
              std::cout<<"Veuillez choisir";
              points.clear();
          }

        }

          for(int i=0; i<static_cast<int>(d_sommet.size());i++){


               QRectF r(d_sommet[i].getX(),d_sommet[i].getY(),100,100);
               painter.drawEllipse(r);
               painter.setPen(pen2);
               painter.drawText(r.x()+45,r.y()+40,100,50,0,QString::number(d_sommet[i].getNumero()));
               painter.setPen(pen1);


          }

          for(int i=0; i<static_cast<int>(liens.size());i++){

              painter.drawLine(liens[i]);
              QPointF center = liens[i].center();
              QLineF l(liens[i]);
              l.translate(20,20);
              QLineF l2(liens[i]);
              l2.translate(-20,-20);

              QLineF second(center,l.p1());
              QLineF third(center,l2.p1());
              second.setLength(20);
              third.setLength(20);
              painter.drawLine(second);
              painter.drawLine(third);


        }

  }

