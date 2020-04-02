#include "graphenonoriente.h"
#include<iostream>
#include"arc.h"
#include"sommet.h"
#include <QTextStream>


GrapheNonOriente::GrapheNonOriente()
{}

GrapheNonOriente::GrapheNonOriente(const std::vector<sommet> &sommets, const std::vector<arc> &aret):d_n(sommets.size()), d_m(aret.size()),d_sommet(sommets),d_aret(aret){}

/*void GrapheNonOriente::affiche() const
{
    for(int i=0; i<d_m; i++)
    {
GrapheNonOriente::GrapheNonOriente(int n, int m, const std::vector<arc> &aret):d_n(n),d_m(m),d_aret(aret)
{}

void GrapheNonOriente::affiche() const {
    for(int i=0; i<d_m; i++) {
        QTextStream(stdout)<< d_aret[i].getValeur()<<" "<<d_aret[i].getSommetDepart().getNumero()<<" "<<d_aret[i].getSommetArrive().getNumero()<<"\n";
    }
}*/

void GrapheNonOriente:: trier() {
    arc x;
    for(int i=1; i<=d_m ; i++) {
        for(int j=0; j<d_m-1;j++) {
            if((d_aret[j+1].getValeur()<d_aret[j].getValeur())
                || ((d_aret[j+1].getValeur()==d_aret[j].getValeur()) && (d_aret[j+1].getSommetDepart().getNumero()<d_aret[j].getSommetDepart().getNumero()) )
                || ((d_aret[j+1].getValeur()==d_aret[j].getValeur()) && (d_aret[j+1].getSommetArrive().getNumero()<d_aret[j].getSommetArrive().getNumero())) ) {

                x.setArc(d_aret[j]);
                d_aret[j].setArc(d_aret[j+1]);
                d_aret[j+1].setArc(x);
            }

        }
    }

}

void GrapheNonOriente::fusionner(int i, int j, std::vector<int> prem, std::vector<int> pilch, std::vector<int> cfc, std::vector<int>NbElem) {
    if (NbElem[i] < NbElem[j]) {
        int aux = i;
        i = j;
        j = aux;
    }

    int s = prem[j];
    cfc[s] = i;

    while (pilch[s] != 0) {
        s = pilch[s];
        cfc[s] = i;
    }

    pilch[s] = prem[i];
    prem[i] = prem[j];
    NbElem[i] += NbElem[j];
}

GrapheNonOriente GrapheNonOriente::kruskal() {
  GrapheNonOriente t;
  std::vector<int> prem(d_n+1);
  std::vector<int> pilch(d_n+1);
  std::vector<int> cfc(d_n+1);
  std::vector<int> NbElem(d_n+1);
  for(int i=1; i<=d_n;i++) {
    prem[i] = i;
    pilch[i] = 0;
    cfc[i] = i;
    NbElem[i] = 1;
  }
  trier();
  t.d_aret.resize(d_n-1);
  t.d_sommet.resize(d_n);
  for(int i=0; i<d_n; i++) {
    t.d_sommet[i]=d_sommet[i];
  }
  int x;
  int y;
  int i = 0, j = 0;
  while (j < d_n-1) {
    arc ar = d_aret[i];
    x = cfc[ar.getSommetDepart().getNumero()];
    y = cfc[ar.getSommetArrive().getNumero()];
    if (x != y) {
            t.d_aret[j++].setArc(d_aret[i]);
            fusionner(x, y, prem, pilch, cfc, NbElem);
    }
    i++;
  }
}
/*void GrapheNonOriente::kruskal(GrapheNonOriente &t) {
     std::vector<int> prem(d_n+1);
     std::vector<int> pilch(d_n+1);
     std::vector<int> cfc(d_n+1);
     std::vector<int> NbElem(d_n+1);
     for(int i=1; i<=d_n;i++) {
        prem[i] = i;
        pilch[i] = 0;
        cfc[i] = i;
        NbElem[i] = 1;
     }
    //this->trier();
    t.d_aret.resize(d_n-1);
    int x;
    int y;
    int i = 0, j = 0;//respectivement indice dans g et t
    while (j < d_n-1) {
        arc ar = d_aret[i];
        x = cfc[ar.getSommetDepart().getNumero()];
        y = cfc[ar.getSommetArrive().getNumero()];
        if (x != y){
            t.d_aret[j++].setArc(d_aret[i]);
            fusionner(x, y, prem, pilch, cfc, NbElem);
        }
        i++;
    }

    t.d_n = d_n;
    t.d_m = d_n-1;

    return t;

}*/

void GrapheNonOriente::affichage()const {
   for (int i = 0; i < d_m; i++) {
       QTextStream(stdout)<< "Arete No " << i + 1 << " : (" << d_aret[i].getSommetDepart().getNumero() << " , " <<
       d_aret[i].getSommetArrive().getNumero() << ") --- " << d_aret[i].getValeur() << endl;
   }
}
