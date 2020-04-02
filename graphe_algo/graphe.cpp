#include "graphe.h"

graphe::graphe()
{}

graphe::graphe(std::vector<sommet>&sommet, std::vector<arc>&arcs):d_sommet{sommet},d_arc{arcs} {
    construitVectorRectangle(d_sommet);
    construitVectorLine(d_arc);

    fs_aps f(d_sommet,d_arc);
    d_fsaps = f;
}

graphe::graphe(std::vector<int>&fs,int nbsommet){
    int nbfois = 1;
    int j = 1;
    int compt = 0;

    for(int i=1;i<static_cast<int>(fs.size());i++){

        if(fs[i]==0||i==static_cast<int>(fs.size()-1)){
            compt++;
            if(compt<=nbsommet/2){
                sommet s(150*nbfois,100,compt,"");
                d_sommet.push_back(s);

            }else{
                if(compt==(nbsommet/2)+1){
                    nbfois=1;
                }
                sommet s(150*nbfois,300,compt,"");
                d_sommet.push_back(s);

            }
            nbfois++;
        }
    }

    construitVectorRectangle(d_sommet);


   for(int i=0;i<nbsommet;i++){


        while(fs[j]!=0&&j<static_cast<int>(fs.size())){

            sommet s1;
            sommet s2;

            for(int h=0;h<static_cast<int>(d_sommet.size());h++){
                if(d_sommet[h].getNumero()==i+1){
                    s1 = d_sommet[h];
                }else{
                    if(d_sommet[h].getNumero()==fs[j]){
                        s2 = d_sommet[h];
                    }
                }
            }



            arc a(s1,s2,1);
            d_arc.push_back(a);
            j++;


        }

        j++;

    }

    construitVectorLine(d_arc);

    fs_aps f(d_sommet,d_arc);
    d_fsaps = f;

}



graphe::graphe(fs_aps fsaps){

    std::vector<int> fs = fsaps.getFs();
    int nbsommet = fsaps.getAps()[0];
    graphe g(fs,nbsommet);
    d_sommet = g.d_sommet;
    d_arc = g.d_arc;
    d_line = g.d_line;
    d_rectangle = g.d_rectangle;
    d_fsaps = g.d_fsaps;

}

std::vector<int> graphe::getCFC(){
    return d_fsaps.Tarjan();
}

void graphe::ajouterSommet(sommet&s){
    d_sommet.push_back(s);
}
void graphe::ajouterArc(arc&a){
    d_arc.push_back(a);

}
void graphe::ajouterLigne(QLineF&l){
    d_line.push_back(l);

}
void graphe::ajouterRectangle(QRectF&r){
    d_rectangle.push_back(r);

}


sommet graphe::getS(int i){
    return d_sommet[i];
}

arc graphe::getA(int i){
    return d_arc[i];
}

QRectF graphe::getR(int i){
    return d_rectangle[i];
}

QLineF graphe::getL(int i){
    return d_line[i];
}


void graphe::clean(){

    d_sommet.clear();
    d_sommet.resize(0);
    d_arc.clear();
    d_arc.resize(0);
    d_rectangle.clear();
    d_rectangle.resize(0);
    d_line.clear();
    d_line.resize(0);
    fs_aps f;
    d_fsaps = f;
}

void graphe::construitVectorRectangle(std::vector<sommet>&s){

    std::vector <QRectF> rr;
    for(int i=0;i<static_cast<int>(s.size());i++){
        QRectF r(s[i].getX(),s[i].getY(),100,100);
        rr.push_back(r);
    }

    d_rectangle = rr;

}



void graphe::construitVectorLine(std::vector<arc>&arcs){

    bool deuxlien = false;
    std::vector <bool> utilise(arcs.size(),false);
    std::vector <QLineF> lig;

    for(int i=0;i<static_cast<int>(arcs.size());i++){
        if(!utilise[i]){
            for(int j=1;j<static_cast<int>(arcs.size());j++){
                if(arcs[i].getSommetDepart()==arcs[j].getSommetArrive() && arcs[i].getSommetArrive()==arcs[j].getSommetDepart()){
                    deuxlien = true;
                    utilise[j] = true;

                }
            }
        }

        if(!utilise[i]){

            QPointF p1(d_arc[i].getSommetDepart().getX()+60,d_arc[i].getSommetDepart().getY()+60);
            QPointF p2(d_arc[i].getSommetArrive().getX()+60,d_arc[i].getSommetArrive().getY()+60);

            if(!deuxlien){
                QLineF l(p1,p2);
                lig.push_back(l);
            }else{

                QLineF l1(p1,p2);
                QLineF l2(d_arc[i].getSommetArrive().getX()+20,d_arc[i].getSommetArrive().getY()+20,d_arc[i].getSommetDepart().getX()+20,d_arc[i].getSommetDepart().getY()+20);
                lig.push_back(l1);
                lig.push_back(l2);
                deuxlien = false;
            }

            utilise[i] = true;
        }


    }

    d_line = lig;

}

void graphe::effacerSommet(int i){

    sommet s = d_sommet[i];

    for(int j=i;j<d_sommet.size()-1;j++){
        d_sommet[j] = d_sommet[j+1];
    }

    d_sommet.pop_back();
    construitVectorRectangle(d_sommet);

    int arcsize = d_arc.size();
    for(int j=0;j<arcsize;j++){
        if(s.getNumero()==d_arc[j].getSommetDepart().getNumero()||s.getNumero()==d_arc[j].getSommetArrive().getNumero()){

            effacerArc(j);
            j--;
            arcsize--;

        }
    }
}

void graphe::effacerArc(int i){

    for(int j=i;j<d_arc.size()-1;j++){
        d_arc[j] = d_arc[j+1];
    }

    d_arc.pop_back();
    construitVectorLine(d_arc);
}



bool graphe::estValide(){

    std::vector<bool> aLiens(d_sommet.size()+1,false);
    bool exist = true;

    for(int i=0;i<d_arc.size();i++){
        aLiens[d_arc[i].getSommetDepart().getNumero()]=true;
        aLiens[d_arc[i].getSommetArrive().getNumero()]=true;
    }

    for(int i=1;i<aLiens.size();i++){
        if(aLiens[i]==false){
            exist=false;
        }
    }

    return (d_sommet.size()>=2 && d_arc.size()>=1 && exist);
}


fs_aps graphe::getfsAps(){
    return d_fsaps;
}


std::vector<sommet> graphe::getSommet(){

    return d_sommet;
}


std::vector<arc> graphe::getArc(){

    return d_arc;
}

std::vector<QLineF> graphe::getLine(){

    return d_line;

}

std::vector<QRectF> graphe::getRectangle(){
    return d_rectangle;
}

void graphe::save(std::ostream&ost){

    ost<<d_sommet.size()<<"|";
        for(int i=0;i<d_sommet.size();i++){
            ost<<d_sommet[i];
        }

    ost<<d_line.size()<<"|";
    for(int i=0;i<d_line.size();i++){
         ost<<"("<<d_line[i].p1().x()<<","<<d_line[i].p1().y()<<")"<<","<<"("<<d_line[i].p2().x()<<","<<d_line[i].p2().y()<<")";
         ost<<d_arc[i];
         ost<<"|";
     }

}



void graphe::open(std::istream&ist){

    clean();

    int nb_somm;
    char c;
    ist>>nb_somm>>c;
    d_sommet.resize(nb_somm);

    for(int i=0;i<nb_somm;i++){
        ist>>d_sommet[i];
        QRectF r(d_sommet[i].getX(),d_sommet[i].getY(),100,100);
        d_rectangle.push_back(r);
    }

    int nb_arc;
    ist>>nb_arc>>c;
    d_arc.resize(nb_arc);

    for(int i=0;i<nb_arc;i++){

        char c;
        int x1, y1, x2, y2;
        ist>>c>>x1>>c>>y1>>c>>c>>c>>x2>>c>>y2>>c;
        QLineF l(x1,y1,x2,y2);
        d_line.push_back(l);
        ist>>d_arc[i];
        ist>>c;

    }



}
