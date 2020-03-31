#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow():d_win(this){
    setWindowTitle("GRAPHE-ALGO");
    setStyleSheet("background:#323232;color:#FDFEFE");
    vue_creer();
}

void MainWindow::vue_creer(){


    //Zone de dessin
    d_dessin = new zone_dessin();
    d_dessin->setFixedSize(1000,900);



    //Menu
    auto menuWidget = new QWidget{};
    menuWidget->setStyleSheet("background:#2A2A2A");

        //Layout principal menu
        auto layoutbouton = new QVBoxLayout{};




        //Menu save-open
        auto layoutb = new QHBoxLayout{};
        auto sauvegarder = new QPushButton{"SAUVG"};
        sauvegarder->setStyleSheet("background:#503461;height:30px;");
        auto charger = new QPushButton{"OUVRIR"};
        charger->setStyleSheet("background:#503461;height:30px;");
        layoutb->addWidget(sauvegarder);
        layoutb->addWidget(charger);


        // Menu Graphique
        auto labeltitre1 = new QLabel{"SAISIE GRAPHIQUE"};
        labeltitre1->setMargin(10);
        labeltitre1->setStyleSheet("font-size:15px;background:#161616");

            //Sommet
            auto layoutsommet = new QHBoxLayout{};
            auto layoutnum = new QVBoxLayout{};
            auto cercle = new QPushButton{"SOMMET"};
            cercle->setStyleSheet("background:#202020;height:40px;");

            auto labelnum = new QLabel{"Numéro : "};
            num = new QLineEdit{};
            num->setStyleSheet("background:#1E1E1E;border:1px solid #4F4F4F");
            QRegExp rx ("[0-9]");
            num->setValidator (new QRegExpValidator (rx, this));


            //Liens
            auto ligne = new QPushButton{"ARC"};
            ligne->setStyleSheet("background:#202020;height:30px;");

            //Effacer Sommet
            auto eff = new QPushButton{"EFFACER SOMMET"};
            eff->setStyleSheet("background:#202020;height:30px;");






        // Menu Numerique
        auto labeltitre4 = new QLabel{"SAISIE NUMERIQUE"};
        auto fs_aps = new QPushButton{"SAISIE DE FS"};
        auto numerique = new QPushButton{"AFFICHAGE NUMERIQUE"};
        fs_aps->setStyleSheet("background:#202020;height:30px;");
        numerique->setStyleSheet("background:#202020;height:30px;");




        labeltitre4->setMargin(10);
        labeltitre4->setStyleSheet("font-size:15px;background:#161616");


        //Menu Calculs
        auto labeltitre3 = new QLabel{"FAITES  VOS  CALCULS"};
        labeltitre3->setMargin(10);
        labeltitre3->setStyleSheet("font-size:15px;background:#161616");

        auto layoutdistance = new QHBoxLayout{};
        auto sommet1Layout = new QVBoxLayout{};
        auto sommet2Layout = new QVBoxLayout{};
        auto sommet1Label = new QLabel{"Sommet 1 :"};
        auto sommet2Label = new QLabel{"Sommet 2 :"};
        auto somm1 = new QLineEdit{};
        somm1->setStyleSheet("background:#1E1E1E;border:1px solid #4F4F4F");
        auto somm2 = new QLineEdit{};
        somm2->setStyleSheet("background:#1E1E1E;border:1px solid #4F4F4F");
        auto distance = new QPushButton{"DISTANCE"};
        auto ccourt = new QPushButton{"CHEMIN COURT"};
        auto clong = new QPushButton{"CHEMIN LONG"};
        distance->setStyleSheet("background:#202020;height:30px;");
        ccourt->setStyleSheet("background:#202020;height:30px;");
        clong->setStyleSheet("background:#202020;height:30px;");

        sommet1Layout->addWidget(sommet1Label);
        sommet1Layout->addWidget(somm1);

        sommet2Layout->addWidget(sommet2Label);
        sommet2Layout->addWidget(somm2);

        layoutdistance->addLayout(sommet1Layout);
        layoutdistance->addLayout(sommet2Layout);

        // Menu valider-effacer
        auto layoutv = new QHBoxLayout{};
        auto valider = new QPushButton{"VALIDER"};
        valider->setStyleSheet("background:#503461;height:30px;");
        auto efface = new QPushButton{"EFFACER"};
        efface->setStyleSheet("background:#503461;height:30px;");
        layoutv->addWidget(valider);
        layoutv->addWidget(efface);

        //Structure Menu

        layoutbouton->addWidget(labeltitre1);
        layoutnum->addWidget(labelnum);
        layoutnum->addWidget(num);
        layoutsommet->addLayout(layoutnum);
        layoutsommet->addWidget(cercle);
        layoutbouton->addLayout(layoutsommet);
        layoutbouton->addWidget(ligne);
        layoutbouton->addWidget(eff);

        layoutbouton->addStretch(1);
        layoutbouton->addWidget(labeltitre4);
        layoutbouton->addWidget(numerique);
        layoutbouton->addWidget(fs_aps);
        layoutbouton->addStretch(1);
        layoutbouton->addLayout(layoutv);
        layoutbouton->addLayout(layoutb);
        layoutbouton->addStretch(1);
        layoutbouton->addWidget(labeltitre3);
        layoutbouton->addLayout(layoutdistance);
        layoutbouton->addWidget(distance);
        layoutbouton->addWidget(ccourt);
        layoutbouton->addWidget(clong);
        layoutbouton->addStretch(6);



    menuWidget->setLayout(layoutbouton);

    //Connections boutons
    connect(cercle,&QPushButton::clicked,this,&MainWindow::boutonSommet);
    connect(ligne,&QPushButton::clicked,this,&MainWindow::boutonLiens);
    connect(efface,&QPushButton::clicked,this,&MainWindow::effacer);
    connect(valider,&QPushButton::clicked,this,&MainWindow::valider);
    connect(charger,&QPushButton::clicked,this,&MainWindow::ouvrir);
    connect(sauvegarder,&QPushButton::clicked,this,&MainWindow::sauvegarder);
    connect(fs_aps,&QPushButton::clicked,this,&MainWindow::fs_apsClick);
    connect(numerique,&QPushButton::clicked,this,&MainWindow::boutonNumerique);
    connect(eff,&QPushButton::clicked,this,&MainWindow::boutonEffacerSommet);



    //Layout central
    auto horizontale = new QHBoxLayout{};
    horizontale->addWidget(menuWidget);
    horizontale->addWidget(d_dessin,Qt::AlignCenter);


    //Principale
    auto layout = new QVBoxLayout{};
    layout->addLayout(horizontale);


    auto Wid = new QWidget;
    Wid->setLayout(layout);


    setCentralWidget(Wid);


}

void MainWindow::boutonSommet(){

    QString numS = num->text();
    bool existe = false;
    if(d_dessin->validationGraphe()){
        QMessageBox msg;
        msg.setText("Votre graphe a été validé, il ne peut plus être modifié.");
        msg.exec();
    }else{
        if(numS==""){
            QMessageBox msg;
            msg.setText("Veuillez saisir un numéro");
            msg.exec();
        }else{
            for(int i=0; i<d_dessin->getSommetVector().size();i++){
                if(d_dessin->getSommetVector()[i].getNumero()==numS.toInt()){
                    existe=true;
                }
            }
            if(existe==false){
                int numSo = numS.toInt();
                d_dessin->changeNum(numSo);
                d_dessin->changeChoix(0);
            }else{
                QMessageBox msg;
                msg.setText("Ce sommet existe déjà");
                msg.exec();
            }

        }
    }

}


void MainWindow::boutonLiens(){
    if(d_dessin->validationGraphe()){
        QMessageBox msg;
        msg.setText("Votre graphe a été validé, il ne peut plus être modifié.");
        msg.exec();
    }else{
         d_dessin->changeChoix(1);
    }
}

void MainWindow::effacer(){
    d_dessin->changeValidation(false);
    d_dessin->changeChoix(3);
    d_dessin->nettoie();
    d_dessin->update();
}

void MainWindow::valider(){

    QMessageBox msg;
    if(!d_dessin->validationGraphe()&&!d_dessin->estValide()){
        msg.setText("Votre graphe n'est pas valide.");
        msg.exec();
    }else{

        if(d_dessin->validationGraphe()){
            msg.setText("Votre graphe est déjà validé.");
            msg.exec();
        }else{
            std::vector<sommet> s = d_dessin->getSommetVector();
            std::vector<arc> a = d_dessin->getArcVector();
            graphe g(s,a);
            d_dessin->setGraphe(g);
            d_dessin->changeValidation(true);
            msg.setText("Graphe validé !");
            msg.exec();

        }
    }

    d_dessin->changeChoix(3);
}

void MainWindow::ouvrir(){

    d_dessin->changeChoix(4);
    QString chemin = QFileDialog::getOpenFileName(0, "Ouvrir un fichier", QString(), "text (*.txt)");
    std::ifstream ifs;
    ifs.open(chemin.toStdString());
    d_dessin->open(ifs);
    ifs.close();

}

void MainWindow::sauvegarder(){

    if(d_dessin->getSommetVector().size()==0){
        QMessageBox msg;
        msg.setText("Vous n'avez rien à sauvegarder");
        msg.exec();
    }else{

        QString chemin = QFileDialog::getSaveFileName(0, "Enregistrer un fichier", QString(), "text (*.txt)");
        std::ofstream of;
        of.open(chemin.toStdString());
        d_dessin->save(of);
        of.close();
    }

}

void MainWindow::fs_apsClick(){
    auto boite = new saisie_fs();
    boite->exec();
    std::vector<int> d_fs = boite->getfs();
    graphe g(d_fs,boite->nbSommet());
    d_dessin->setGraphe(g);
    d_dessin->changeValidation(false);

}

void MainWindow::boutonNumerique(){
    if(d_dessin->validationGraphe()){
        auto boite = new affichage_numerique(d_dessin->getGraphe());
        boite->exec();
    }else{
        QMessageBox msg;
        msg.setText("Votre graphe n'a pas été validé");
        msg.exec();
    }

}

void MainWindow::boutonEffacerSommet(){
    if(d_dessin->validationGraphe()){
        QMessageBox msg;
        msg.setText("Votre graphe a été validé, il ne peut plus être modifié.");
        msg.exec();
    }else{
        d_dessin->changeChoix(6);
    }

}





