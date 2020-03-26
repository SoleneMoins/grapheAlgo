#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow():d_win(this){
    setWindowTitle("GRAPHE-ALGO");
    vue_creer();
}

void MainWindow::vue_creer(){

    //Zone de dessin
    d_dessin = new zone_dessin();
    d_dessin->setFixedSize(1000,1000);


    //texte explication
    auto labelExpli = new QLabel{"EXPLICATIONS <br> Créer un sommet : Saisissez d'abord le numéro du sommet puis cliquez sur SOMMET et enfin cliquez où vous souhaitez placer votre sommet.<br> Créer un lien : Cliquez sur LIEN, puis un clique sur le départ et un clique sur l'arrivée"};


    //Boutons
    auto menuWidget = new QWidget{};
    menuWidget->setStyleSheet("background:#2A2A2A");
    auto layoutbouton = new QVBoxLayout{};
    auto cercle = new QPushButton{"SOMMET"};
    auto ligne = new QPushButton{"LIEN"};
    auto efface = new QPushButton{"EFFACER"};
    auto labelnum = new QLabel{"Numéro du sommet : "};
    num = new QLineEdit{};




    //layoutbouton->addStretch(1);
    layoutbouton->addWidget(labelnum);
    layoutbouton->addWidget(num);
    layoutbouton->addWidget(cercle);
    layoutbouton->addWidget(ligne);
    layoutbouton->addWidget(efface);
    layoutbouton->addStretch(1);

    QRegExp rx ("[0-9]");
    num->setValidator (new QRegExpValidator (rx, this));

    menuWidget->setLayout(layoutbouton);


    connect(cercle,&QPushButton::clicked,this,&MainWindow::boutonSommet);
    connect(ligne,&QPushButton::clicked,this,&MainWindow::boutonLiens);
    connect(efface,&QPushButton::clicked,this,&MainWindow::effacer);


    //Layout
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

    if(numS==""){
        QMessageBox msg;
        msg.setText("Veuillez saisir un numéro");
        msg.exec();
    }else{
        int numSo = numS.toInt();
        d_dessin->changeNum(numSo);
        d_dessin->changeChoix(0);
    }

}


void MainWindow::boutonLiens(){
    d_dessin->changeChoix(1);
}

void MainWindow::effacer(){
    d_dessin->nettoie();
    d_dessin->update();
}

