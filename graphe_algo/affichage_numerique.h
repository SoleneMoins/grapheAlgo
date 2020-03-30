#ifndef AFFICHAGE_NUMERIQUE_H
#define AFFICHAGE_NUMERIQUE_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QRegExpValidator>
#include <QMessageBox>
#include <vector>
#include <iostream>

class affichage_numerique : public QDialog
{
public:
    affichage_numerique(std::vector<int>&fs,std::vector<int>&aps,QWidget *parent=nullptr);

private:
    std::vector<int> d_fs;
    std::vector<int> d_aps;


private slots:
    void onValider();
    void onValideSommet();
};


#endif // AFFICHAGE_NUMERIQUE_H
