#include "affichage_numerique.h"

affichage_numerique::affichage_numerique(graphe g,QWidget*parent):QDialog{parent},d_graphe{g} {


    fs_aps fsaps = g.getfsAps();

    QString tabfs = "";
    QString tabaps = "";

    for(int i=0;i<fsaps.getFs().size();i++) {
        tabfs+=QString::number(fsaps.getFs()[i]);
        tabfs+="|";
    }

    for(int i=0;i<fsaps.getAps().size();i++) {
        tabaps+=QString::number(fsaps.getAps()[i]);
        tabaps+="|";
    }


    auto labelfs = new QLabel{"File des successeurs : "+tabfs};
    auto labelaps = new QLabel{"APS : "+tabaps};



    //Principal

    auto layoutPrinc = new QVBoxLayout{};
    layoutPrinc->addWidget(labelfs);
    layoutPrinc->addWidget(labelaps);
    setLayout(layoutPrinc);





}
