#include "zone_dessin.h"

zone_dessin::zone_dessin(QWidget *parent):QWidget{parent},d_choix{3},d_num{0},graphe_valide{false}
{

}

void zone_dessin::changeChoix(int choix){
    d_choix = choix;
}


void zone_dessin::changeNum(int num){
    d_num = num;
}

std::vector<arc> zone_dessin::getArcVector(){
    return d_arc;
}

std::vector<sommet> zone_dessin::getSommetVector(){
    return d_sommet;
}


void zone_dessin::nettoie(){

    d_sommet.clear();
    d_arc.clear();
    somm.clear();
    liens.clear();
    points.clear();

}

bool zone_dessin::validationGraphe(){
    return graphe_valide;
}

void zone_dessin::changeValidation(bool v){
    graphe_valide=v;
}

void zone_dessin::mousePressEvent( QMouseEvent * event){

    xPress = event->pos().x();
    yPress = event->pos().y();

    points.push_back(event->pos());

    update();



}

void zone_dessin::paintEvent(QPaintEvent*p){


    QPainter painter(this);
    QBrush brush1("#46528C", Qt::SolidPattern);
    QPen pen1("#46528C");
    QPen pen2("#FEFEFE");
    QFont font = painter.font();
    font.setPixelSize(18);
    painter.setFont(font);
    painter.setPen(pen1);
    painter.setBrush(brush1);


if(graphe_valide==false){
      if(d_choix==0){

            sommet som(xPress-40,yPress-40,d_num);
            QRectF r(som.getX(),som.getY(),100,100);
            somm.push_back(r);
            d_sommet.push_back(som);
            points.pop_back();
            d_choix = 3;


        }else{

          if(d_choix==1){
              if(points.size()==2){

                  sommet somm1;
                  sommet somm2;

                  for(int i=0;i<static_cast<int>(somm.size());i++){

                      if(somm[i].contains(points[0])){
                          somm1 = d_sommet[i];
                          //Test
                          std::cout<<"Sommet de départ : "<<d_sommet[i].getNumero()<<std::endl;
                      }

                      if(somm[i].contains(points[1])){
                          somm2 = d_sommet[i];
                          //Test
                          std::cout<<"Sommet d'arrivée : "<<d_sommet[i].getNumero()<<std::endl;
                      }



                  }

                   arc a(somm1,somm2,0);
                   d_arc.push_back(a);

                   QLineF l(points[0],points[1]);
                   liens.push_back(l);
                   points.clear();
                   points.resize(0);


              }
          }else{



                  //Test
                  std::cout<<"Veuillez choisir"<<std::endl;
                  points.clear();


          }

        }
}

          for(int i=0; i<static_cast<int>(d_sommet.size());i++){



               painter.drawEllipse(somm[i]);
               painter.setPen(pen2);
               painter.drawText(somm[i].x()+45,somm[i].y()+40,100,50,0,QString::number(d_sommet[i].getNumero()));
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

