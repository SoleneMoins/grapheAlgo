#include "graphe.h"

graphe::graphe()
{}

graphe::graphe(std::vector<sommet> sommet, std::vector<arc> arcs):d_sommet{sommet},d_arc{arcs}
{
    construitVectorRectangle(d_sommet);
    construitVectorLine(d_arc);
}

graphe::graphe(std::vector<int>fs,int nbsommet)
{
    int nbfois = 1;
    int j = 1;
    int compt = 0;

    for(int i=1;i<fs.size();i++){

        if(fs[i]==0||i==fs.size()-1){
            compt++;
            if(compt<=nbsommet/2){
                sommet s(150*nbfois,100,compt);
                d_sommet.push_back(s);

            }else{
                if(compt==(nbsommet/2)+1){
                    nbfois=1;
                }
                sommet s(150*nbfois,300,compt);
                d_sommet.push_back(s);

            }
            nbfois++;
        }
    }

    construitVectorRectangle(d_sommet);


   for(int i=0;i<nbsommet;i++){


        while(fs[j]!=0&&j<fs.size()){

            sommet s1;
            sommet s2;

            for(int h=0;h<d_sommet.size();h++){
                if(d_sommet[h].getNumero()==i+1){
                    s1 = d_sommet[h];
                }else{
                    if(d_sommet[h].getNumero()==fs[j]){
                        s2 = d_sommet[h];
                    }
                }
            }



            arc a(s1,s2,0);
            d_arc.push_back(a);
            j++;


        }

        j++;

    }

    construitVectorLine(d_arc);

}



void graphe::construitVectorRectangle(std::vector<sommet>&s){

    for(int i=0;i<s.size();i++){
        QRectF r(s[i].getX(),s[i].getY(),100,100);
        d_rectangle.push_back(r);
    }

}



void graphe::construitVectorLine(std::vector<arc>&arcs){

    bool deuxlien = false;
    std::vector <bool> utilise(arcs.size(),false);

    for(int i=0;i<arcs.size();i++){
        if(!utilise[i]){
            for(int j=1;j<arcs.size();j++){
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
                d_line.push_back(l);
            }else{

                QLineF l1(p1,p2);
                QLineF l2(d_arc[i].getSommetArrive().getX()+20,d_arc[i].getSommetArrive().getY()+20,d_arc[i].getSommetDepart().getX()+20,d_arc[i].getSommetDepart().getY()+20);
                d_line.push_back(l1);
                d_line.push_back(l2);
                deuxlien = false;
            }

            utilise[i] = true;
        }


    }

}


std::vector<sommet> graphe::getSommet()const{

    return d_sommet;
}


std::vector<arc> graphe::getArc()const{

    return d_arc;
}

std::vector<QLineF> graphe::getLine()const{

    return d_line;

}

std::vector<QRectF> graphe::getRectangle()const{
    return d_rectangle;
}

void graphe::save(std::ostream&ost){

    for(int i=0;i<d_sommet.size();i++){
        ost<<d_sommet[i];
    }

    for(int i=0;i<d_line.size();i++){
        ost<<"("<<d_line[i].p1().x()<<","<<d_line[i].p1().y()<<")"<<","<<"("<<d_line[i].p2().x()<<","<<d_line[i].p2().y()<<")";;
    }

}



void graphe::open(std::istream&ist){

    d_sommet.clear();
    d_arc.clear();
    d_rectangle.clear();
    d_line.clear();

    int nb_somm;
    char c;
    ist>>nb_somm>>c;
    d_sommet.resize(nb_somm);

    for(int i=0;i<nb_somm;i++){
        ist>>d_sommet[i];
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
