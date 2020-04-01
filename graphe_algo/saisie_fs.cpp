#include "saisie_fs.h"

saisie_fs::saisie_fs(QWidget*parent):QDialog{parent}
{

    vue_creer();
}

void saisie_fs::vue_creer(){

    //Boutons
    auto closeBtn = new QPushButton("Annuler");
    auto ok = new QPushButton("Valider");
    auto boutons = new QHBoxLayout{};
    boutons->addWidget(ok);
    boutons->addWidget(closeBtn);

    connect(closeBtn, &QPushButton::clicked,this,&saisie_fs::onclose);
    connect(ok,&QPushButton::clicked,this,&saisie_fs::onValider);


    //Nb Sommet
    auto labelLigne = new QLabel{"Nombre de Sommet : "};
    editNbSommet = new QLineEdit{};
    QRegExp rx ("[0-9]");
    editNbSommet->setValidator (new QRegExpValidator (rx, this));
    auto bsomm = new QPushButton("Ok");
    auto nbsomm = new QHBoxLayout{};
    nbsomm->addWidget(labelLigne);
    nbsomm->addWidget(editNbSommet);
    nbsomm->addWidget(bsomm);

    connect(bsomm,&QPushButton::clicked,this,&saisie_fs::onValideSommet);


    //Principal

    layoutPrinc.addLayout(nbsomm);
    layoutPrinc.addLayout(&layoutsaisie);
    layoutPrinc.addLayout(boutons);




    setLayout(&layoutPrinc);

}

std::vector<int> saisie_fs::getfs()const{
    return fs;
}

int saisie_fs::nbSommet() const{
    return d_nbsommet;
}

void saisie_fs::onValider(){


    fs.push_back(0);
    for(int i=0;i<d_s.size();i++){
        QString s = d_s[i]->text();
        if(s==""){
            fs.push_back(0);
        }else{
            QStringList l = s.split(",", QString::SkipEmptyParts);
            for(int j=0;j<l.size();j++){
                fs.push_back(l[j].toInt());
            }

         }

        if(i<d_s.size()-1){
            fs.push_back(0);
        }
    }

    graphe g(fs,d_nbsommet);
    d_graphe = g;
    close();



}

void saisie_fs::setGraphe(graphe g){
    d_graphe = g;
}


graphe saisie_fs::getGraphe(){
    return d_graphe;
}

void saisie_fs::onValideSommet(){

    QString nbsommet = editNbSommet->text();

    if(nbsommet==""){

        QMessageBox msg;
        msg.setText("Veuillez saisir une valeur");
        msg.exec();

    }else{

        int nb = nbsommet.toInt();
        d_nbsommet=nb;
        d_s.resize(nb);




        auto l = new QLabel("Veuillez saisir les successeurs en les séparant d'un ','");
        layoutsaisie.addWidget(l);

        for(int i=0;i<nb;i++){
            auto l = new QLabel("Sommet "+QString::number(i+1));
            d_s[i] = new QLineEdit{};
            QRegExp rx ("(?!"+QString::number(i+1)+")([1-"+QString::number(nb)+"][,])*");
            d_s[i]->setValidator (new QRegExpValidator (rx, this));
            layoutsaisie.addWidget(l);
            layoutsaisie.addWidget(d_s[i]);
        }
    }


}

void saisie_fs::onclose(){
    close();
}
