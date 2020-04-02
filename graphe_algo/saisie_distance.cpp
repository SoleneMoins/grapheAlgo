#include "saisie_distance.h"

saisie_distance::saisie_distance(graphe g, QWidget*parent):QDialog{parent},d_graphe{g}
{

    auto layoutsom = new QHBoxLayout{};

    auto layouts1 = new QVBoxLayout{};
    auto layouts2 = new QVBoxLayout{};

    auto labs1 = new QLabel{"Sommet départ :"};
    auto labs2 = new QLabel{"Sommet arrivé :"};
    so1 = new QLineEdit{};
    so2 = new QLineEdit{};

    auto ok = new QPushButton{"Valider"};
    auto ann = new QPushButton{"Fermer"};

    connect(ok,&QPushButton::clicked,this,&saisie_distance::boutonOk);

    connect(ann,&QPushButton::clicked,this,&saisie_distance::boutonClose);


    layouts1->addWidget(labs1);
    layouts1->addWidget(so1);
    layouts2->addWidget(labs2);
    layouts2->addWidget(so2);

    layoutsom->addLayout(layouts1);
    layoutsom->addLayout(layouts2);

    layoutPrinc.addLayout(layoutsom);
    layoutPrinc.addLayout(&affiche);
    layoutPrinc.addWidget(ok);
    layoutPrinc.addWidget(ann);

    setLayout(&layoutPrinc);
}


void saisie_distance::boutonOk(){

    std::vector<int> dist;
    std::vector<int> pred;
    std::vector<int> fs = d_graphe.getfsAps().getFs();
    std::vector<int> aps = d_graphe.getfsAps().getAps();
    fs_aps f(fs,aps);

    QString s1 = so1->text();
    QString s2 = so2->text();

    f.calcul_dist(s1.toInt(),dist,pred);

   for(int i=0;i<dist.size();i++){
        std::cout<<dist[i]<<"|";
    }

    auto l = new QLabel{"Distance du sommet "+s1+" au sommet "+s2+" : "+QString::number(dist[s2.toInt()])};
    affiche.addWidget(l);


}

void saisie_distance::boutonClose(){
    close();
}
