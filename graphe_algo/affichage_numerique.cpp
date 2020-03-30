#include "affichage_numerique.h"

affichage_numerique::affichage_numerique(std::vector<int>&fs,std::vector<int>&aps,QWidget*parent):QDialog{parent},d_fs{fs},d_aps{aps}
{

    //Affichage fs

    QString tabfs = "";
    QString tabaps = "";

    for(int i=0;i<d_fs.size();i++){
        tabfs+=QString::number(d_fs[i]);
        tabfs+="|";
    }

    for(int i=0;i<d_aps.size();i++){
        tabaps+=QString::number(d_aps[i]);
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
