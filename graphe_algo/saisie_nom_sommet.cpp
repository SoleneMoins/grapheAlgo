#include "saisie_nom_sommet.h"

saisie_nom_sommet::saisie_nom_sommet(graphe g, QWidget*parent):QDialog{parent},d_graphe{g}
{
    auto layoutPrinc = new QVBoxLayout{};
    auto label = new QLabel{"Saisissez les noms des sommets"};
    QRegExp rx("[a-zA-Z]*");
    layoutPrinc->addWidget(label);
    d_n.resize(d_graphe.getSommet().size());
    for(int i=0;i<d_graphe.getSommet().size();i++){

        auto l = new QLabel{"Sommet "+ QString::number(i+1)};
        layoutPrinc->addWidget(l);
        d_n[i] = new QLineEdit{};
        d_n[i]->setValidator (new QRegExpValidator (rx, this));
        layoutPrinc->addWidget(d_n[i]);

    }
    auto ok = new QPushButton{"Valider"};
    auto close = new QPushButton{"Annuler"};

    connect(ok,&QPushButton::clicked,this,&saisie_nom_sommet::onValide);

    layoutPrinc->addWidget(ok);
    layoutPrinc->addWidget(close);

    setLayout(layoutPrinc);

}

graphe saisie_nom_sommet::getGraphe(){
    return d_graphe;
}

void saisie_nom_sommet::onValide(){
    for(int i=0;i<d_n.size();i++){
        QString n = d_n[i]->text();
        std::string n1 = n.toStdString();
        d_graphe.getS(i).setNom(n1);
    }
    close();
}
