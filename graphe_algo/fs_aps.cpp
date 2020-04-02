#include "fs_aps.h"
#include <iostream>
#include <vector>
#include <QTextStream>
#include<iostream>
#include<QDebug>
#include<stack>

fs_aps::fs_aps(): d_nbSommet{0}, d_nbArcs{0}
{}

fs_aps::fs_aps(int nbS): d_nbSommet(nbS) {
    d_aps.clear();
    d_fs.clear();
    d_aps.resize(d_nbSommet+1);
    d_aps[0]=d_nbSommet;
    d_aps[1]=1;
    d_fs.resize(1);
    d_fs[0]=0;
}


fs_aps::fs_aps(std::vector<sommet>&d_sommet,std::vector<arc>&d_arc) {

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

   fs[0] = fs.size();

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

fs_aps::fs_aps(std::vector<int> &fs, std::vector<int> &aps):d_fs{fs},d_aps{aps} {
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

void fs_aps::calcul_dist(int s, std::vector<int>&d,std::vector<int>& pred ) {

    int t =-1;  // t l’indice avant celui de début du bloc courant
    int q=0; //q l’indice du dernier élément du bloc courant
    int k=0;
    int x=0;
    int dist=0;
    int m=d_aps[0];
    pred.clear();
    pred.resize(m+1);
    d.clear();
    d.resize(m+1);
    int fatt[m+1];
    fatt[0]=s;

    for(int i=0;i<m+1;i++) {
        d[i]=-1;
        pred[i]=-1;
        d[s]=0; // distance de s à lui même est égal à 0
        pred[s]=0;
    }
    d[0]=m;

    while(t<q) {
        dist++;

        for(int i=t+1 ; i<=q ; i++){
            x=fatt[i];
            int temp;

            for(int j=d_aps[x]; (temp=d_fs[j])!=0; j++){
                // temp est un successeur de u, on teste sa distance
                pred[j]=x;

                if( d[temp] == -1 ) {
                    d[temp]=dist;
                    fatt[++k]=temp;
                }
             temp=d_fs[j];
            }
        }
        t = q;
        q = k;
    } // while

}




//Tarjan + Dijkstra
void fs_aps::traverse(int s, std::vector<int>& num, std::vector<int> &mu,std::vector<int> &prem, std::vector<int> &pilch,
                std::vector<int> &cfc,std::stack<int> &tarj,std::vector<bool> &entarj,int &p, int &nbr)const {
    mu[s]=num[s]=++p;

    tarj.push(s);
    entarj[s]=true;
    int t;
    for(int k= d_aps[s];(t=d_fs[k])!=0;++k) {
        if(num[t]==0) {
            traverse(t,num,mu,prem,pilch,cfc,tarj,entarj,p,nbr);
            if(mu[t]<mu[s]) {
                mu[s]=mu[t];
            }
        }
        else {
            if((entarj[t]==true) && (num[t]<mu[s])) {
                    mu[s]=num[t];
            }
        }
    }

    if(mu[s]==num[s]) {
        int x=tarj.top();
        tarj.pop();
        entarj[x]=false;
        prem.push_back(x);

        cfc[x]=++nbr;
        int indice =x;
        while(x!=s) {
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

std::vector<int> fs_aps::Tarjan()const {
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
     for(int s=1;s<=n;s++) {
         if(num[s]==0) {
             traverse(s,num,mu,prem,pilch,cfc,tarj,entarj,p,nbr);
         }
     }

    return cfc;
}

std::vector<int> fs_aps::neoDijkstra(const std::vector<std::vector<int>>&C,std::vector<int> &d, std::vector<int> &pred,std::vector<bool> &S, int s) const {
    int n=d_nbSommet,v,j,max;
     d.resize(n+1);
     pred.resize(n+1);
     S.resize(n+1);

    for(int i=1; i<=n; i++) {
        d[i]=C[s][i];
        pred[i]=0;
        S[i]=true;
    }

    S[s]=false;
    d[s]=0;

    for(int i=0; i<n; i++) {
        max=MAXPOIDS;
        for(int i=1; i<=n; i++) {
            if(S[i]&&d[i]<max) {
                max=d[i];
                j=i;
            }
        }
        if(d[j]!=MAXPOIDS) {
            S[j]=false;
            int k;
            for(int l=d_aps[j]; (k=d_fs[l])!=0; l++) {
                if(S[k]) {
                    v=d[j]+C[j][k];
                    if(v<d[k]) {
                        d[k]=v;
                        pred[k]=j;
                    }

                }
            }
        }

    }

    return d;
}

std::vector<std::vector<int> > fs_aps::Dijkstra(const std::vector<std::vector<int> > &C) const {
    std::vector<int> d;
    std::vector<int> pred;
    std::vector<bool> S;
    std::vector<std::vector<int>> matD(d_nbSommet+1,std::vector<int>(d_nbSommet+1,0));
    for(int s=1; s<= d_nbSommet; s++) {
       matD[s]= neoDijkstra(C,d,pred,S,s);
    }
    return matD;
}
// Problème d'ordonnance
void fs_aps::fs_aps2fp_app(std::vector<int> &fp,std::vector<int> &app) { //Passe de fs aps à fp app
    int n=d_aps[0];
    int m=d_fs[0];
    fp.clear();
    fp.resize(m+1);
    fp[0]=m;
    app.clear();
    app.resize(m+1);
    app[0]=n;
    std::vector<int> np;
    np.clear();
    np.resize(n);

   for(int i=1;i<=n;i++){
        np[i]=0;
   }
   for(int i=1; i<n;i++) {
       if(d_fs[i]!=0) {
           np[d_fs[i]]++;
       }
   }
   app[1]=1;
   for(int i=1; i<n;i++){
        app[i+1]=app[i]+np[i]+1;
   }
   int k=1;
   for(int i=1; i<=n; i++) {
        while(d_fs[k]!=0) {
            fp[app[d_fs[k]]]=i;
            app[d_fs[k]]++;
            k++;
        }
        k++;
   }
   d_fs[app[n]]=0;
   for(int i=n-1; i>=1; i--) {
        fp[app[i]]=0;
        app[i+1]=app[i]+1;
   }
   app[1]=1;


}

/*void fs_aps::chemin_critique(std::vector<std::vector<int>> fp, std::vector<int> app, std::vector<int> &fpc, std::vector<int> &appc, std::vector<int>& lc)
{
    int kc, k, lon, j;
    int n=app[0];
    int m=fp[0][0];
    lc.clear();
    lc.resize(n+1);
    fpc.clear();
    fpc.resize(m+1);
    fpc[0]=m;
    fpc[1]=0; //le sommet 1 n'a pas de prédécesseur
    appc.clear();
    appc.resize(n+1);
    appc[0]=n;
    appc[1]=1;
    lc[1]=0;
    kc=1;
    for(int i=2; i<n; i++) {
    //calcul de lc[i] en fonction des prédécesseurs
        lc[i]=0;
        appc[i]=kc+1;
        k=app[i];
        while(j=(fs[0][k])!=0) {
            lon=lc[j]+fp[1][k];
            if(lon>=lc[i]){
                if(lon>lc[i]) {
                    lc[i]=lon;
                        kc=appc[i];
                        fpc[kc]=j;
                }
                else { //egalité
                    kc++;
                    fpc[kc]=j;
                }
            }
                k++;
                fpc[kc]=0;
        }
    }
}*/

void ordonnancement(std::vector<int> fp, std::vector<int> app, std::vector<int> d, std::vector<int>&lc, std::vector<int> &fpc, std::vector<int> &appc)
{
    int n = app[0];
    int m = fp[0];
    appc.clear();
    appc.resize(n+1);
    appc[0]=n;
    lc.clear();
    lc.resize(n+1);
    lc[0]=n;
    fpc.clear();
    fpc.resize(m+1);
    fpc[0]=m;
    int kc; //dernière case à remplir dans fpc
    int t;
    fpc[1]=0;
    lc[1] =0;
    appc[1]=1;
    kc=1;
    for(int s=2; s<=n; s++) {
        // calcule de lc[s]
        lc[s] = 0;
        appc[s] = kc+1;
        for(int k=app[s]; (t = fp[k]) != 0 ; k++) {
            int longueur = lc[t] + d[t];
            if(longueur >= lc[s]) {
                if(longueur > lc[s]) {
                    lc[s] = longueur;
                    kc = appc[s];
                    fpc[kc] = t;
                }
                else { //longueur == lc[s]
                    kc++;
                    fpc[kc]=t;
                }
            }
        }// for k
        kc++;
        fpc[kc]=0;
    }//for s
    fpc[0]=kc;
}
