#include "fs_aps.h"
#include <iostream>
#include <vector>

fs_aps::fs_aps(int nbS): d_nbSommet(nbS)
{
    d_aps.clear();
    d_fs.clear();
    d_aps.resize(d_nbSommet+1);
    d_aps[0]=d_nbSommet;
    d_aps[1]=1;
    d_fs.resize(1);
    d_fs[0]=0;
}

fs_aps::fs_aps(std::vector<int> fs, std::vector<int> aps,int nbSommet,int nbArc):d_fs{fs},d_aps{aps},d_nbSommet{nbSommet},d_nbArcs{nbArc}
{}


fs_aps::fs_aps(matrice_Adjacence matriceAdj)
{
    //IL FAUT D ABORD FAIRE LA SURCHARGE D'OPERATEUR NUMERO1
    /*int d_nbSommet = matriceAdj[0][0];
    int d_nbArcs= matriceAdj[0][1];
    std::vector<int> fs(d_nbSommet+d_nbArcs+1);
    std::vector<int> aps(nbSommet+1);
    fs[0]=d_nbSommet+d_nbArcs;
    aps[0]=d_nbSommet;
    int k=1;

    for(int i = 1; i <= d_nbSommet; i++)
    {
        aps[i]=k;
        for(int j = 1; j < d_nbSommet; j++)
        {
            if((matriceAdj[i][j] == 1)//dans a y a que 0 ou 1
            {
                 fs[k]=j; // se remplace par fs[k++]=j;
                 k++;
            }

        }
    fs[k]=0;
    k++;
    }*/

}


int fs_aps::GetLongAps()const
{
    return d_aps.size();
}
int fs_aps::GetLongFs()const
{
    return d_fs.size();
}

int fs_aps::nbSommets() const
{
    return d_nbSommet;
}

int fs_aps::getNbArc() const
{
    return d_nbArcs;
}

/*void fs_aps::ajouterSommet()
{
    int s=1, t;
    for(int i=1; i<=d_nbS; i++)
    {
        std::cout<<"Donner le nombre de successeurs du sommet "<<i<<std::endl;
        std::cin>>t;
        d_aps[i]=s;
        for(int i=1; i<=t; i++)
        {
            std::cout<<"Donner le successeur "<<i<<std::endl;
            int sc;
            std::cin>>sc;
            if(sc!=0)
            {
                d_fs.push_back(sc);
                s++;
            }
            else{d_fs.push_back(0);}
        }
        d_fs.push_back(0);
        s++;
        d_aps.push_back(s);
        d_fs[0]=d_fs.size()-1;
    }

}*/

void fs_aps::determiner_rang(std::vector<int> fs, std::vector<int> aps, int *&rang, int *&num) const {
    int n=aps[0], r=0, pas=-1, e=0, d=n+1, x, s, t=0; rang = new int[n+1];
    num = new int[n+1];
    rang[0]=n;
    int *ddi=new int[n+1];
    for(int i=1; i<=n; i++) {
        rang[i]=0;
        ddi[i]=0;
    }
    int *pile = new int[n+1];
    for(int i=1; i<fs[0]; i++){
        if(fs[i]!=0){
            ddi[fs[i]]++;
        }
    }
    for(int i=1; i<=n; i++){
        if(ddi[i]==0){
            pile[++e]=i;
        }
    }
    while((e!=0) && (e!=n+1)) {
        x=e;
        e=d;
        d=x;
        while((d!=0) && (d!=n+1)) {
            s=pile[d];
            d+=pas;
            rang[s]=r;
            num[s]=++t;
            for(int l=aps[s]; fs[l]>0; l++) {
                ddi[fs[l]]--;
                if(ddi[fs[l]] == 0) {
                    e+=pas;
                    pile[e] = fs[l];
                }
            }

        }
        r++;
        pas=-pas;
    }
}
