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

std::vector<int> zone_dessin::getfs(){

    std::vector<int> fs;

    int nb = 1;
    int nbsuc = 0;

    while(nb<d_sommet.size()+1){

        nbsuc = 0;

        for(int i=0;i<d_arc.size();i++){
            if(d_arc[i].getSommetDepart().getNumero()==nb){
                fs.push_back(d_arc[i].getSommetArrive().getNumero());
                nbsuc++;

                if(fs.size()>1){
                    if(fs[fs.size()-2]>fs[fs.size()-1]){
                        std::swap(fs[fs.size()-2],fs[fs.size()-1]);
                    }
                }
            }

        }



        if(nbsuc==0){
            fs.push_back(0);
        }

        if(nb<d_sommet.size()){
            fs.push_back(0);
        }



        nb++;
    }

    return fs;

}




std::vector<int> zone_dessin::getaps(){

    std::vector<int> aps;
    std::vector<int> fs = getfs();

    aps.push_back(1);

    for(int i=1;i<fs.size();i++){

        if(i!=fs.size()-1;fs[i]==0){
            aps.push_back(i+2);
        }
    }

    for(int i=0;i<aps.size();i++){
        std::cout<<aps[i]<<"|";
    }

    return aps;
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


void zone_dessin::save(std::ostream&ost){

    ost<<d_sommet.size()<<"|";
    for(int i=0;i<d_sommet.size();i++){
        ost<<d_sommet[i];
    }

    ost<<liens.size()<<"|";
    for(int i=0;i<liens.size();i++){
        ost<<"("<<liens[i].p1().x()<<","<<liens[i].p1().y()<<")"<<","<<"("<<liens[i].p2().x()<<","<<liens[i].p2().y()<<")";
        ost<<d_arc[i];
        ost<<"|";
    }

}


void zone_dessin::open(std::istream&ist){

    nettoie();
    int nb_somm;
    char c;
    ist>>nb_somm>>c;
    d_sommet.resize(nb_somm);

    for(int i=0;i<d_sommet.size();i++){

        ist>>d_sommet[i];

        QRectF r(d_sommet[i].getX(),d_sommet[i].getY(),100,100);
        somm.push_back(r);

    }

    int nb_arc;
    ist>>nb_arc>>c;
    d_arc.resize(nb_arc);

    for(int i=0;i<nb_arc;i++){

        char c;
        int x1, y1, x2, y2;
        ist>>c>>x1>>c>>y1>>c>>c>>c>>x2>>c>>y2>>c;
        QLineF l(x1,y1,x2,y2);
        liens.push_back(l);
        ist>>d_arc[i];
        ist>>c;

    }

    update();

}


std::vector<int> zone_dessin::getNumTarjan(){

    int nbSommet= d_sommet.size();
    std::vector<int> num(nbSommet+1,0);

    int depart = 1;
    int ok;
    int fois = 0;
    std::vector<bool> exist(nbSommet+1,false);
    bool ex = false;
    int nbvalide = 0;



    while(!ex){

        ok = nbSommet;
        fois++;

        if(exist[depart]){
            for(int i=1;i<exist.size();i++){
                if(exist[i]==false){
                    depart = i;
                    break;
                }
            }
        }

         exist[depart] = true;



        for(int i=0;i<d_arc.size();i++){

            if(d_arc[i].getSommetDepart().getNumero()==depart){
                if(!exist[d_arc[i].getSommetArrive().getNumero()] && d_arc[i].getSommetArrive().getNumero()<ok ){
                    ok = d_arc[i].getSommetArrive().getNumero();
                }
            }

        }




        for(int i=1;i<exist.size();i++){
            if(exist[i]==true){
                nbvalide++;
            }
        }

        if(nbvalide==nbSommet){
            ex=true;
        }else{
            nbvalide=0;
        }



        num[depart] = fois;
        depart = ok;





    }

   return num;

}



void zone_dessin::calculFS(){

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


if(graphe_valide==false || d_choix!=4){
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

                  if(somm1.estVide()==false&&somm2.estVide()==false){

                      bool exist = false;

                      for(int i=0;i<d_arc.size();i++){
                          if(d_arc[i].getSommetDepart()==somm1 && d_arc[i].getSommetArrive()==somm2){
                              exist = true;
                          }
                      }

                      if(exist==false){

                          arc a(somm1,somm2,0);
                          d_arc.push_back(a);

                          QLineF l(points[0],points[1]);
                          liens.push_back(l);
                      }

                  }

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

if(graphe_valide){

    getaps();

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

