#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QLabel>
#include <QFileDialog>
#include <QCheckBox>
#include <QRegExpValidator>
#include "zone_dessin.h"
#include "saisie_fs.h"
#include "affichage_numerique.h"
#include "saise_valeur_arc.h"
#include "saisie_nom_sommet.h"




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void boutonSommet();
    void boutonLiens();
    void valider();
    void effacer();
    void ouvrir();
    void sauvegarder();
    void fs_apsClick();
    void boutonNumerique();
    void boutonEffacerSommet();



private:
    QMainWindow*d_win;
    zone_dessin* d_dessin;
    QLineEdit*nom;
    QLineEdit*num;
    QLineEdit*d_arc;
    void vue_creer();



};
#endif // MAINWINDOW_H
