#include "saise_valeur_arc.h"

saise_valeur_arc::saise_valeur_arc(graphe g,QWidget *parent):QDialog{parent},d_graphe{g}
{
    auto layoutPrinc = new QVBoxLayout{};
    auto label = new QLabel{"Saisissez les valeurs des arcs"};
    QRegExp rx("[0-9]*");
    layoutPrinc->addWidget(label);
    d_v.resize(d_graphe.getArc().size());
    for(int i=0;i<d_graphe.getArc().size();i++){

        auto l = new QLabel{"ARC "+ QString::number(d_graphe.getA(i).getSommetDepart().getNumero()) + " - "+QString::number(d_graphe.getA(i).getSommetArrive().getNumero())};
        layoutPrinc->addWidget(l);
        d_v[i] = new QLineEdit{};
        d_v[i]->setValidator (new QRegExpValidator (rx, this));
        layoutPrinc->addWidget(d_v[i]);

    }
    auto ok = new QPushButton{"Valider"};
    auto close = new QPushButton{"Annuler"};

    connect(ok,&QPushButton::clicked,this,&saise_valeur_arc::onValide);
    connect(close,&QPushButton::clicked,this,&saise_valeur_arc::onFerme);

    layoutPrinc->addWidget(ok);
    layoutPrinc->addWidget(close);

    setLayout(layoutPrinc);
}

graphe saise_valeur_arc::getGraphe(){
    return d_graphe;
}

void saise_valeur_arc::onValide(){
    bool ok = true;
    for(int i=0;i<d_v.size();i++){
        QString v = d_v[i]->text();
        if(v==""){
            ok = false;

        }else{

            int v1 = v.toInt();
            d_graphe.getA(i).setValeur(v1);
        }
    }
    if(ok){
        close();
    }else{
        QMessageBox msg;
        msg.setText("Veuillez saisir toutes les valeurs");
        msg.exec();
    }

}

void saise_valeur_arc::onFerme(){
    d_graphe.clean();
    close();
}
