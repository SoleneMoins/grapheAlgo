#include "fs_aps.h"
#include <iostream>
#include <vector>
#include <QTextStream>
#include<iostream>
#include<QDebug>
#include<stack>

fs_aps::fs_aps(): d_nbSommet{0}, d_nbArcs{0}
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
            i++;
        }
    }

    d_fs = fs;
    d_aps = aps;
    d_nbSommet = d_sommet.size();
    d_nbArcs = d_arc.size();


}

fs_aps::fs_aps(std::vector<int>&fs, std::vector<int>&aps,int nbSommet,int nbArc):d_fs{fs},d_aps{aps},d_nbSommet{nbSommet},d_nbArcs{nbArc}
{}
fs_aps::fs_aps(std::vector<int> &fs, std::vector<int> &aps):d_fs{fs},d_aps{aps}
{
    d_nbSommet = d_aps.size()-1;
    d_nbArcs = d_fs.size()-d_nbSommet-1;
}



/*fs_aps::fs_aps(matrice_Adjacence matriceAdj)
{
    //IL FAUT D ABORD FAIRE LA SURCHARGE D'OPERATEUR NUMERO1
    int d_nbSommet = matriceAdj[0][0];
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
    }



}*/
std::vector<int> fs_aps::getFs(){
    return d_fs;
}

std::vector<int> fs_aps::getAps(){
    return d_aps;
}

int fs_aps::GetLongAps()const {
    return d_aps.size();
}
int fs_aps::GetLongFs()const {
    return d_fs.size();
}

int fs_aps::nbSommets() const {
    return d_nbSommet;
}

int fs_aps::getNbArc() const {
    return d_nbArcs;
}

std::vector<int> fs_aps::fs() const {
    return d_fs;
}

std::vector<int> fs_aps::aps() const {
    return d_aps;
}

int fs_aps::getAps(int i) const {
    return d_aps[i];
}
int fs_aps::getFs(int i) const{
    return d_fs[i];
}


/*void fs_aps::ajouterSommet()
{
    int s=1, t;
    for(int i=1; i<=d_nbSommet; i++)
    {
        std::cout<<"Donner le nombre de successeurs du sommet "<<i;
        std::cin>>t;
        d_aps[i]=s;
        for(int i=1; i<=t; i++)
        {
            std::cout<<"Donner le successeur "<<i;
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

//Distance + rang 
void fs_aps::determiner_rang(int *&rang, int *&num) const {
    int n=d_aps[0], r=0, pas=-1, e=0, d=n+1, x, s, t=0; rang = new int[n+1];
    num = new int[n+1];
    rang[0]=n;
    int *ddi=new int[n+1];
    for(int i=1; i<=n; i++) {
        rang[i]=0;
        ddi[i]=0;
    }
    int *pile = new int[n+1];
    for(int i=1; i<d_fs[0]; i++){
        if(d_fs[i]!=0){
            ddi[d_fs[i]]++;
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
            for(int l=d_aps[s]; d_fs[l]>0; l++) {
                ddi[d_fs[l]]--;
                if(ddi[d_fs[l]] == 0) {
                    e+=pas;
                    pile[e] = d_fs[l];
                }
            }

        }
        r++;
        pas=-pas;
    }
}

std::vector<int> fs_aps::distance() {
    int m=d_aps[0];
    std::vector<int> dist;
    dist.clear();
    dist.resize(m+1);
    dist[0]=m;
    for(int i = 1; i<=m; i++)
        dist[i]=-1;
    dist[d_nbSommet]=0;
    int d=0;
    std::vector<int> fileAttente;
    fileAttente.clear();
    fileAttente.resize(m);
    fileAttente[0]=d_nbSommet;
    int t=-1;
    int q=0;
    int p=0;
    while(t<q){
     for(int i=t+1;i<=q;i++){
      int u=fileAttente[i];
      int v;
      for(int k=d_aps[u]; (v=d_fs[k])!=0;k++){
    // v est un successeur de u, on teste sa distance
        
            if( dist[v] ==-1 ){
                dist[v]=d;
                fileAttente[++p]=v;
            }
       }
      t = q;
      q = p;
      } 
    }
    return dist;
}




//Tarjan + Dijkstra
void fs_aps::traverse(int s, std::vector<int>& num, std::vector<int> &mu,std::vector<int> &prem, std::vector<int> &pilch,
                std::vector<int> &cfc,std::stack<int> &tarj,std::vector<bool> &entarj,int &p, int &nbr)const
{
    mu[s]=num[s]=++p;

    tarj.push(s);
    entarj[s]=true;
    int t;
    for(int k= d_aps[s];(t=d_fs[k])!=0;++k)
    {
        if(num[t]==0)
        {
            traverse(t,num,mu,prem,pilch,cfc,tarj,entarj,p,nbr);
            if(mu[t]<mu[s])
                mu[s]=mu[t];

        }
        else
            if((entarj[t]==true) && (num[t]<mu[s]))
                    mu[s]=num[t];


    }

    if(mu[s]==num[s])
    {
        int x=tarj.top();
        tarj.pop();
        entarj[x]=false;
        prem.push_back(x);

        cfc[x]=++nbr;
        int indice =x;
        while(x!=s)
        {
            x=tarj.top();
            tarj.pop();
            entarj[x]=false;
            pilch[indice]=x;
            indice=x;
            cfc[x]=nbr;
        }
        pilch[x]=0;
    }

}

void fs_aps::Tarjan()const
{
     int n = d_nbSommet;
     std::vector<int> num(n+1,0);
     std::vector<int> mu(n+1,0);
     std::vector<int> prem(1,0);
     std::vector<int> pilch(n+1,0);
     std::vector<int> cfc(n+1,0);
     std::stack<int> tarj;
     std::vector<bool> entarj(n+1,false);
     num[0]=mu[0]=pilch[0]=cfc[0]=n;
     entarj[0]=false;
     int p=0,nbr=0;
     for(int s=1;s<=n;s++)
     {
         if(num[s]==0)
         {
             traverse(s,num,mu,prem,pilch,cfc,tarj,entarj,p,nbr);
         }
     }



     for(int i=0; i<n+1; i++)
     {
         QTextStream(stdout)<<num[i]<<" ";
     }
        QTextStream(stdout)<<"\n";


     for(int i=0; i<n+1; i++)
     {
         QTextStream(stdout)<<"CFC :"<<cfc[i]<<" ";
     }
     QTextStream(stdout)<<"\n";
}

void fs_aps::neoDijkstra(const std::vector<std::vector<int>>&C,std::vector<int> &d, std::vector<int> &pred,std::vector<bool> &S, int s) const
{
    int n=d_nbSommet,v,j,max;
     d.resize(n+1);
     pred.resize(n+1);
     S.resize(n+1);

    for(int i=1; i<=n; i++)
    {
        d[i]=C[s][i];
        pred[i]=0;
        S[i]=true;
    }

    S[s]=false;
    d[s]=0;

    for(int i=0; i<n; i++)
    {
        max=MAXPOIDS;
        for(int i=1; i<=n; i++)
        {
            if(S[i]&&d[i]<max)
            {
                max=d[i];
                j=i;
            }
        }
        if(d[j]!=MAXPOIDS)
        {
            S[j]=false;
            int k;
            for(int l=d_aps[j]; (k=d_fs[l])!=0; l++)
                if(S[k])
                {
                    v=d[j]+C[j][k];
                    if(v<d[k])
                    {
                        d[k]=v;
                        pred[k]=j;
                    }

                }
        }

    }

    for(int i=1; i<=n; i++)
        QTextStream(stdout)<<d[i]<<" ";
    QTextStream(stdout)<<"\n";
}

void fs_aps::Dijkstra(const std::vector<std::vector<int> > &C, std::vector<int> &d, std::vector<int> &pred, std::vector<bool> &S) const
{
    for(int s=1; s<= d_nbSommet; s++)
        neoDijkstra(C,d,pred,S,s);
}
