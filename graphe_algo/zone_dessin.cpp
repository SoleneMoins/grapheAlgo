#include "zone_dessin.h"

zone_dessin::zone_dessin(QWidget *parent):QWidget{parent},d_choix{3},d_num{0},graphe_valide{false}
{}

void zone_dessin::changeChoix(int choix){
    d_choix = choix;
}


void zone_dessin::changeNum(int num){
    d_num = num;
}

std::vector<arc> zone_dessin::getArcVector(){
    return d_graphe.getArc();
}

std::vector<sommet> zone_dessin::getSommetVector(){
    return d_graphe.getSommet();
}


fs_aps zone_dessin::getFsAps(){

    return d_graphe.getfsAps();

}

graphe zone_dessin::getGraphe(){
    return d_graphe;
}

void zone_dessin::setGraphe(graphe g){
    d_graphe = g;
}

void zone_dessin::nettoie(){
    d_graphe.clean();
    points.clear();
    points.resize(0);
    graphe_valide = false;
}

bool zone_dessin::estValide(){
    return d_graphe.estValide();
}

bool zone_dessin::validationGraphe(){
    return graphe_valide;
}


void zone_dessin::save(std::ostream&ost){
    d_graphe.save(ost);
}


void zone_dessin::open(std::istream&ist){
    nettoie();
    d_graphe.open(ist);
    update();
}


void zone_dessin::changeValeur(int v){
    d_valeur = v;
}

void zone_dessin::changeValidation(bool v){
    graphe_valide=v;
}

void zone_dessin::effacerSommet(int i){
    d_graphe.effacerSommet(i);
}

void zone_dessin::effacerArc(int i){
    d_graphe.effacerArc(i);
}

void zone_dessin::changeNom(std::string nom){
    d_nom=nom;
}

std::vector<int> zone_dessin::getCFC(){
    return d_graphe.getCFC();
}

void zone_dessin::mousePressEvent( QMouseEvent * event){
    xPress = event->pos().x();
    yPress = event->pos().y();

    points.push_back(event->pos());
    update();
}

void zone_dessin::mouseMoveEvent(QMouseEvent*e){
   /* QPoint f(xPress,yPress);
    for(int i=0;i<d_graphe.getRectangle().size();i++){
        if(d_graphe.getR(i).contains(f)){
            setMouseTracking(true);
            d_choix = 4;
            QRect r(e->pos().x(),e->pos().y(),100,100);
            d_graphe.getR(i) = r;
        }
    }*/
}




void zone_dessin::paintEvent(QPaintEvent*p){


    QPainter painter(this);
    QBrush brush1("#945BB5", Qt::SolidPattern);
    QPen pen1("#945BB5");
    QPen pen2("#FEFEFE");
    QFont font = painter.font();
    font.setPixelSize(18);
    painter.setFont(font);
    painter.setPen(pen1);
    painter.setBrush(brush1);


    if(d_choix!=4){

        if(d_choix==6){
            QPointF p(xPress,yPress);
            for(int i=0;i<d_graphe.getRectangle().size();i++){
                if(d_graphe.getR(i).contains(p)){
                    effacerSommet(i);
                }
            }
            points.clear();
            points.resize(0);

        }else{


              if(d_choix==0){

                    sommet som(xPress-40,yPress-40,d_num,d_nom);
                    QRectF r(som.getX(),som.getY(),100,100);
                    d_graphe.ajouterRectangle(r);
                    d_graphe.ajouterSommet(som);
                    points.pop_back();
                    d_choix = 3;


                }else{

                  if(d_choix==1){
                      if(points.size()==2){

                          sommet somm1;
                          sommet somm2;

                          for(int i=0;i<d_graphe.getSommet().size();i++){

                              if(d_graphe.getR(i).contains(points[0])){
                                  somm1 = d_graphe.getSommet()[i];
                              }

                              if(d_graphe.getR(i).contains(points[1])){
                                  somm2 = d_graphe.getSommet()[i];
                              }



                          }

                          if(somm1.estVide()==false&&somm2.estVide()==false){

                              bool exist = false;

                              for(int i=0;i<d_graphe.getArc().size();i++){
                                  if(d_graphe.getA(i).getSommetDepart()==somm1 && d_graphe.getA(i).getSommetArrive()==somm2){
                                      exist = true;
                                  }
                              }

                              if(exist==false){

                                  arc a(somm1,somm2,d_valeur);
                                  d_graphe.ajouterArc(a);


                                  QLineF l(points[0],points[1]);
                                  d_graphe.ajouterLigne(l);
                              }

                          }
                          d_choix = 3;
                          points.clear();
                          points.resize(0);


                      }
                  }else{

                          points.clear();
                          points.resize(0);



                }

            }

        }
    }


    if(d_choix!=5){


          for(int i=0; i<d_graphe.getRectangle().size();i++){



               painter.drawEllipse(d_graphe.getR(i));
               painter.setPen(pen2);
               painter.drawText(d_graphe.getR(i).x()+45,d_graphe.getR(i).y()+40,100,50,0,QString::number(d_graphe.getS(i).getNumero()));
               painter.setPen(pen1);


          }

          for(int i=0; i<d_graphe.getLine().size();i++){

              QLineF l1 = d_graphe.getL(i);
              painter.drawLine(l1);

              if(d_choix!=9){
                  QPointF center = l1.center();
                  QLineF l(l1);
                  l.translate(20,20);
                  QLineF l2(l1);
                  l2.translate(-20,-20);

                  QLineF second(center,l.p1());
                  QLineF third(center,l2.p1());
                  second.setLength(20);
                  third.setLength(20);
                  painter.drawLine(second);
                  painter.drawLine(third);
              }


        }

    }



}

