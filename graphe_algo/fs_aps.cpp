#include "fs_aps.h"
#include <iostream>
#include <vector>

fs_aps::fs_aps()
{}

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


fs_aps::fs_aps(std::vector<sommet>&d_sommet,std::vector<arc>&d_arc){

    std::vector<int> fs;
    fs.push_back(0);
    int nb = 1;
    int nbsuc = 0;

    while(nb<d_sommet.size()+1){

        nbsuc = 0;

        for(int i=0;i<d_arc.size();i++){
            if(d_arc[i].getSommetDepart().getNumero()==nb){
                fs.push_back(d_arc[i].getSommetArrive().getNumero());
                nbsuc++;

                if(fs.size()>1){
                    if(fs[fs.size()-2]>fs[fs.size()-1]){
                        std::swap(fs[fs.size()-2],fs[fs.size()-1]);
                    }
                }
            }

        }



        if(nbsuc==0){
            fs.push_back(0);
        }

        if(nb<d_sommet.size()){
            fs.push_back(0);
        }



        nb++;
    }



    std::vector<int> aps;

    aps.push_back(d_sommet.size());
    aps.push_back(1);

    for(int i=1;i<fs.size();i++){

        if(i!=fs.size()-1&&fs[i]==0){
            aps.push_back(i+1);
        }
    }

    d_fs = fs;
    d_aps = aps;
    d_nbSommet = d_sommet.size();
    d_nbArcs = d_arc.size();


}

fs_aps::fs_aps(std::vector<int>&fs, std::vector<int>&aps,int nbSommet,int nbArc):d_fs{fs},d_aps{aps},d_nbSommet{nbSommet},d_nbArcs{nbArc}
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

std::vector<int> fs_aps::getFs(){

    return d_fs;

}

std::vector<int> fs_aps::getAps(){
    return d_aps;
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
