#include "arc.h"
#include "sommet.h"


arc::arc():d_sommetDepart{},d_sommetArrive{},d_valeur{}
{}

arc::arc(sommet s1,sommet s2,int valeur):d_sommetDepart{s1},d_sommetArrive{s2},d_valeur{valeur}
{}

sommet arc::getSommetDepart() const
{
    return d_sommetDepart;
}

sommet arc::getSommetArrive() const
{
    return d_sommetArrive;
}
int arc::getValeur() const
{
    return d_valeur;
}

int arc::setValeur(int v){
    d_valeur = v;
}

void arc::save(std::ostream&ost){

    ost<<"("<<d_sommetDepart<<","<<d_sommetArrive<<")";

}

void arc::open(std::istream&ist){

    char c;
    ist>>c>>d_sommetDepart>>c>>d_sommetArrive>>c;

}

std::ostream& operator<<(std::ostream&ost,arc&a){
    a.save(ost);
    return ost;
}

std::istream& operator>>(std::istream&ist,arc&a){
    a.open(ist);
    return ist;
}


