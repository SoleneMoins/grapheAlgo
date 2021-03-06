#ifndef ARC_H
#define ARC_H
#include "sommet.h"

class arc {
    public:
        arc();
        arc(sommet s1, sommet s2,int valeur);
       
        sommet getSommetDepart() const;
        sommet getSommetArrive()const ;
  
        int getValeur()const ;
        void setValeur(int v);
        void save(std::ostream&ost);
        void open(std::istream&ist);


        void setArc(const arc& a);



    private:
        sommet d_sommetDepart;
        sommet d_sommetArrive;
        int d_valeur;
        bool estCritique;

};

std::ostream& operator<<(std::ostream&ost,arc&a);

std::istream& operator>>(std::istream&ist,arc&a);

#endif // ARC_H
