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
            cercle->setStyleSheet("background:#202020;height:100px;");

            auto labelnum = new QLabel{"Numéro : "};
            num = new QLineEdit{};
            auto labelnom = new QLabel{"Nom : "};
            nom = new QLineEdit{};
            nom->setStyleSheet("background:#1E1E1E;border:1px solid #4F4F4F");
            num->setStyleSheet("background:#1E1E1E;border:1px solid #4F4F4F");
            QRegExp rx ("[0-9]");
            num->setValidator (new QRegExpValidator (rx, this));
            QRegExp rex1 ("[a-zA-Z]*");
            nom->setValidator (new QRegExpValidator (rex1, this));


            //Liens
            auto ligne = new QHBoxLayout{};
            auto layoutligne = new QVBoxLayout{};
            auto arc = new QPushButton{"ARC"};
            arc->setStyleSheet("background:#202020;height:50px;");

            auto labelligne = new QLabel{"Valeur : "};
            d_arc = new QLineEdit{};
            d_arc->setStyleSheet("background:#1E1E1E;border:1px solid #4F4F4F");
            QRegExp rex ("[0-9]*");
            d_arc->setValidator (new QRegExpValidator (rex, this));
            arc->setStyleSheet("background:#202020;height:30px;");

            layoutligne->addWidget(labelligne);
            layoutligne->addWidget(d_arc);
            ligne->addLayout(layoutligne);
            ligne->addWidget(arc);

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
        auto layoutDistance = new QHBoxLayout{};
        sommetdep = new QLineEdit{};
        sommetarr = new QLineEdit{};
        sommetdep->setStyleSheet("background:#1E1E1E;border:1px solid #4F4F4F");
        sommetarr->setStyleSheet("background:#1E1E1E;border:1px solid #4F4F4F");
        layoutDistance->addWidget(sommetdep);
        layoutDistance->addWidget(sommetarr);

        auto distance = new QPushButton{"DISTANCE"};
        layoutDistance->addWidget(distance);

        auto rang = new QPushButton{"RANG"};
        auto ordo = new QPushButton{"ORDONNANCEMENT"};
        auto tarjan = new QPushButton{"TARJAN"};
        auto djikstra = new QPushButton{"DJIKSTRA"};
        auto kruskel = new QPushButton{"KRUSKAL"};
        auto prufer = new QPushButton{"PRUFFER"};
        distance->setStyleSheet("background:#202020;height:30px;");
        tarjan->setStyleSheet("background:#202020;height:30px;");
        djikstra->setStyleSheet("background:#202020;height:30px;");
        kruskel->setStyleSheet("background:#202020;height:30px;");
        prufer->setStyleSheet("background:#202020;height:30px;");
        rang->setStyleSheet("background:#202020;height:30px;");
        ordo->setStyleSheet("background:#202020;height:30px;");



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
        layoutnum->addWidget(labelnom);
        layoutnum->addWidget(nom);
        layoutsommet->addLayout(layoutnum);
        layoutsommet->addWidget(cercle);
        layoutbouton->addLayout(layoutsommet);

        layoutbouton->addLayout(ligne);
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
        layoutbouton->addLayout(layoutDistance);
        layoutbouton->addWidget(rang);
        layoutbouton->addWidget(tarjan);
        layoutbouton->addWidget(ordo);
        layoutbouton->addWidget(djikstra);
        layoutbouton->addWidget(kruskel);
        layoutbouton->addWidget(prufer);
        layoutbouton->addStretch(6);



    menuWidget->setLayout(layoutbouton);

    //Connections boutons
    connect(cercle,&QPushButton::clicked,this,&MainWindow::boutonSommet);
    connect(arc,&QPushButton::clicked,this,&MainWindow::boutonLiens);
    connect(efface,&QPushButton::clicked,this,&MainWindow::effacer);
    connect(valider,&QPushButton::clicked,this,&MainWindow::valider);
    connect(charger,&QPushButton::clicked,this,&MainWindow::ouvrir);
    connect(sauvegarder,&QPushButton::clicked,this,&MainWindow::sauvegarder);
    connect(fs_aps,&QPushButton::clicked,this,&MainWindow::fs_apsClick);
    connect(numerique,&QPushButton::clicked,this,&MainWindow::boutonNumerique);
    connect(eff,&QPushButton::clicked,this,&MainWindow::boutonEffacerSommet);
    connect(tarjan,&QPushButton::clicked,this,&MainWindow::boutonTarjan);
    connect(distance,&QPushButton::clicked,this,&MainWindow::boutonDist);
    connect(prufer,&QPushButton::clicked,this,&MainWindow::boutonPruffer);
    connect(rang,&QPushButton::clicked,this,&MainWindow::boutonRang);
    connect(djikstra,&QPushButton::clicked,this,&MainWindow::boutonDijkstra);
    connect(kruskel,&QPushButton::clicked,this,&MainWindow::boutonKruskal);





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
    QString nomS = nom->text();

    bool existe = false;

    if(d_dessin->validationGraphe()){
        QMessageBox msg;
        msg.setText("Votre graphe a été validé, il ne peut plus être modifié.");
        msg.exec();
    }else{
        if(numS==""||nomS==""){
            QMessageBox msg;
            msg.setText("Veuillez saisir un numéro et un nom");
            msg.exec();
        }else{
            for(int i=0; i<d_dessin->getSommetVector().size();i++){
                if(d_dessin->getSommetVector()[i].getNumero()==numS.toInt()||d_dessin->getSommetVector()[i].getNom()==nomS.toStdString()){
                    existe=true;
                }
            }
            if(existe==false){
                int numSo = numS.toInt();
                std::string nomSo = nomS.toStdString();
                d_dessin->changeNum(numSo);
                d_dessin->changeNom(nomSo);
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

    QString valeur = d_arc->text();

    if(d_dessin->validationGraphe()){
        QMessageBox msg;
        msg.setText("Votre graphe a été validé, il ne peut plus être modifié.");
        msg.exec();

    }else{
        if(valeur==""){
            QMessageBox msg;
            msg.setText("Veuillez saisir une valeur.");
            msg.exec();
        }else{
             int v = valeur.toInt();
             d_dessin->changeValeur(v);
             d_dessin->changeChoix(1);
        }
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
    auto v = new saise_valeur_arc(boite->getGraphe());
    v->exec();
    auto n =new saisie_nom_sommet(v->getGraphe());
    n->exec();
    d_dessin->setGraphe(n->getGraphe());
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

void MainWindow::boutonTarjan(){

   if(d_dessin->validationGraphe()){

       std::vector<int> fs = d_dessin->getFsAps().getFs();
       std::vector<int> aps = d_dessin->getFsAps().getAps();
       fs_aps fsaps (fs,aps);

       std::vector<int> cfc = fsaps.Tarjan();
        std::cout<<"CFC : ";
       for(int i=0;i<cfc.size();i++){
            std::cout<<cfc[i]<<"|";
        }

       QMessageBox msg;
       msg.setText("Regardez la console");
       msg.exec();

    }else{
        QMessageBox msg;
        msg.setText("Votre graphe n'est pas valide");
        msg.exec();
    }

}


void MainWindow::boutonDist(){

    if(d_dessin->validationGraphe()){

        std::vector<int> pred;
        std::vector<int> fs = d_dessin->getFsAps().getFs();
        std::vector<int> aps = d_dessin->getFsAps().getAps();
        fs_aps fsaps (fs,aps);
        std::vector<int> dist;
        int s = sommetdep->text().toInt();
        int s2 = sommetarr->text().toInt();

        fsaps.calcul_dist(s,dist,pred);

        QMessageBox msg;
        msg.setText(QString::number(dist[s2]));
        msg.exec();
    }else{
        QMessageBox msg;
        msg.setText("Votre graphe n'est pas valide");
        msg.exec();
    }

}

void MainWindow::boutonPruffer(){

    if(d_dessin->validationGraphe()){
        std::vector<int> fs = d_dessin->getFsAps().getFs();
        std::vector<int> aps = d_dessin->getFsAps().getAps();

        fs_aps fsaps (fs,aps);
        matrice_Adjacence m(fsaps);
        std::vector<int> p;
        m.codage_Pruffer(p);
        std::cout<<"PRUFFER : ";
        for(int i=0;i<p.size();i++){
           std::cout<<p[i]<<"|";
        }

        QMessageBox msg;
        msg.setText("Regardez la console");
        msg.exec();
    }else{
        QMessageBox msg;
        msg.setText("Votre graphe n'est pas valide");
        msg.exec();
    }
}


void MainWindow::boutonRang(){
  
     if(d_dessin->validationGraphe()){

        std::vector<int> fs = d_dessin->getFsAps().getFs();
        std::vector<int> aps = d_dessin->getFsAps().getAps();

        fs_aps fsaps (fs,aps);
        std::vector<int> rang = fsaps.Rang();

        for(int i=0;i<rang.size();i++){
            std::cout<<rang[i]<<"|";
        }

        QMessageBox msg;
        msg.setText("Regardez la console");
        msg.exec();

     }else{

         QMessageBox msg;
         msg.setText("Votre graphe n'est pas valide");
         msg.exec();
     }

}

void MainWindow::boutonDijkstra(){

    if(d_dessin->validationGraphe()){
      
        std::vector<int> fs = d_dessin->getFsAps().getFs();
        std::vector<int> aps = d_dessin->getFsAps().getAps();

        fs_aps fsaps (fs,aps);
        std::vector<std::vector<int>> mat_dist;
        fsaps.calcul_mat_dist(mat_dist);
        std::vector<std::vector<int>> m = fsaps.Dijkstra(mat_dist);

        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                std::cout<<m[i][j]<<"|";
            }
            std::cout<<std::endl;
        }
    }

      else{
            QMessageBox msg;
            msg.setText("Votre graphe n'est pas valide");
            msg.exec();
      }

}

void MainWindow::boutonKruskal(){

    if(d_dessin->validationGraphe()){

        GrapheNonOriente g(d_dessin->getSommetVector(),d_dessin->getArcVector());
        GrapheNonOriente gk(g.kruskal());
        std::vector<sommet> s = gk.getSommet();
        std::vector<arc> a = gk.getArc();
        graphe gr(s,a);
        d_dessin->setGraphe(gr);
        d_dessin->update();
        d_dessin->changeChoix(9);
    }else{

        QMessageBox msg;
        msg.setText("Votre graphe n'est pas valide");
        msg.exec();
    }
}





