#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow():d_win(this){
    setWindowTitle("GRAPHE-ALGO");
    vue_creer();
}

void MainWindow::vue_creer(){

    //Zone de dessin
    d_dessin = new zone_dessin();
    d_dessin->setFixedSize(1000,900);


    //texte explication
    auto labelExpli = new QLabel{"EXPLICATIONS <br> Créer un sommet : Saisissez d'abord le numéro du sommet puis cliquez sur SOMMET et enfin cliquez où vous souhaitez placer votre sommet.<br> Créer un lien : Cliquez sur LIEN, puis un clique sur le départ et un clique sur l'arrivée <br> Veuillez valider votre graphe pour faire vos calculs."};


    //Menu
    auto menuWidget = new QWidget{};
    menuWidget->setStyleSheet("background:#2A2A2A");

        //Layout principal menu
        auto layoutbouton = new QVBoxLayout{};

        // Menu Dessiner
        auto labeltitre1 = new QLabel{"DESSINEZ  VOTRE  GRAPHE"};
        labeltitre1->setMargin(10);
        labeltitre1->setStyleSheet("font-size:15px;background:#161616");

            //Sommet
            auto layoutsommet = new QHBoxLayout{};
            auto layoutnum = new QVBoxLayout{};
            auto cercle = new QPushButton{"SOMMET"};
            cercle->setStyleSheet("background:#202020;height:40px;");

            auto labelnum = new QLabel{"Numéro du sommet : "};
            num = new QLineEdit{};
            QRegExp rx ("[0-9]");
            num->setValidator (new QRegExpValidator (rx, this));


            //Liens
            auto ligne = new QPushButton{"LIEN"};
            ligne->setStyleSheet("background:#202020;height:30px;");

            //Validation
            auto valider = new QPushButton{"VALIDER LE GRAPHE"};
            valider->setStyleSheet("background:#202020;height:30px;");

            //Effacer
            auto efface = new QPushButton{"EFFACER"};
            efface->setStyleSheet("background:#202020;height:30px;");

            //Sauvegarder
            auto sauvegarder = new QPushButton{"SAUVEGARDER"};
            sauvegarder->setStyleSheet("background:#202020;height:30px;");



        // Menu Changer affichage
        auto labeltitre4 = new QLabel{"AFFICHAGE"};

        auto numerique = new QPushButton{"NUMERIQUE"};
        numerique->setStyleSheet("background:#202020;height:30px;");




        labeltitre4->setMargin(10);
        labeltitre4->setStyleSheet("font-size:15px;background:#161616");



        // Menu Générer
        auto labeltitre2 = new QLabel{"GENEREZ  UN  GRAPHE"};
        auto charger = new QPushButton{"OUVRIR UN GRAPHE"};
        auto fs_aps = new QPushButton{"SAISIR FS"};
        charger->setStyleSheet("background:#202020;height:30px;");
        fs_aps->setStyleSheet("background:#202020;height:30px;");
        labeltitre2->setMargin(10);
        labeltitre2->setStyleSheet("font-size:15px;background:#161616");

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
        auto somm2 = new QLineEdit{};
        auto distance = new QPushButton{"DISTANCE"};
        distance->setStyleSheet("background:#202020;height:30px;");

        sommet1Layout->addWidget(sommet1Label);
        sommet1Layout->addWidget(somm1);

        sommet2Layout->addWidget(sommet2Label);
        sommet2Layout->addWidget(somm2);

        layoutdistance->addLayout(sommet1Layout);
        layoutdistance->addLayout(sommet2Layout);



        //Structure Menu
        layoutbouton->addWidget(labeltitre1);
        layoutnum->addWidget(labelnum);
        layoutnum->addWidget(num);
        layoutsommet->addLayout(layoutnum);
        layoutsommet->addWidget(cercle);
        layoutbouton->addLayout(layoutsommet);
        layoutbouton->addWidget(ligne);
        layoutbouton->addWidget(sauvegarder);
        layoutbouton->addWidget(valider);
        layoutbouton->addWidget(efface);

        layoutbouton->addStretch(1);
        layoutbouton->addWidget(labeltitre4);
        layoutbouton->addWidget(numerique);

        layoutbouton->addStretch(1);
        layoutbouton->addWidget(labeltitre2);
        layoutbouton->addWidget(charger);
        layoutbouton->addWidget(fs_aps);

        layoutbouton->addStretch(1);
        layoutbouton->addWidget(labeltitre3);
        layoutbouton->addLayout(layoutdistance);
        layoutbouton->addWidget(distance);

        layoutbouton->addStretch(5);



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


    //Layout central
    auto horizontale = new QHBoxLayout{};
    horizontale->addWidget(menuWidget);
    horizontale->addWidget(d_dessin,Qt::AlignCenter);


    //Principale
    auto layout = new QVBoxLayout{};
    layout->addWidget(labelExpli);
    layout->addLayout(horizontale);


    auto Wid = new QWidget;
    Wid->setLayout(layout);


    setCentralWidget(Wid);


}

void MainWindow::boutonSommet(){

    QString numS = num->text();
    bool existe = false;

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
            d_dessin->changeChoix(3);
        }

    }

}


void MainWindow::boutonLiens(){
    d_dessin->changeChoix(1);
}

void MainWindow::effacer(){
    d_dessin->changeValidation(false);
    d_dessin->changeChoix(3);
    d_dessin->nettoie();
    d_dessin->update();
}

void MainWindow::valider(){

    QMessageBox msg;
    if(d_dessin->getSommetVector().size()<2||d_dessin->getArcVector().size()==0){
        msg.setText("Votre graphe n'est pas valide.");
        msg.exec();
    }else{

        if(d_dessin->validationGraphe()){
            msg.setText("Votre graphe est déjà validé.");
            msg.exec();
        }else{
            d_dessin->changeValidation(true);
            msg.setText("Graphe validé !");
            msg.exec();
            d_fs = d_dessin->getfs();
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
    d_fs = boite->getfs();
    d_dessin->genereGrapheFSAPS(d_fs,boite->nbSommet());

}

void MainWindow::boutonNumerique(){
    if(d_dessin->validationGraphe()){
      std::vector<int> aps = d_dessin->getaps();
     auto boite = new affichage_numerique(d_fs,aps);
     boite->exec();
    }else{
        QMessageBox msg;
        msg.setText("Votre graphe n'a pas été validé");
        msg.exec();
    }

}


