#include "arc.h"
#include "sommet.h"

arc::arc():d_sommetDepart(),d_sommetArrive(),d_valeur(0)
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

void arc::setValeur(int i)
{
    d_valeur=i;
}

void arc::setArc(const arc& a)
{
    d_sommetDepart = a.getSommetDepart();
    d_sommetArrive = a.getSommetArrive();
    d_valeur = a.getValeur();
}
