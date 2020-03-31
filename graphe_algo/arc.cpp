#include "arc.h"
#include "sommet.h"

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
