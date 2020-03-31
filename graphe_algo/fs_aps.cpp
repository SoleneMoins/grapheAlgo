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

void fs_aps::fs_aps2fp_app(std::vector<int> &fp,std::vector<int> &app)//Passe de fs aps a fp app
{
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

   for(int i=1;i<=n;i++)
        np[i]=0;
   for(int i=1; i<n;i++)
       if(d_fs[i]!=0)
           np[d_fs[i]]++;
   app[1]=1;
   for(int i=1; i<n;i++)
        app[i+1]=app[i]+np[i]+1;
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
    for(int s=2; s<=n; s++)
    { // calcule de lc[s]
        lc[s] = 0;
        appc[s] = kc+1;
        for(int k=app[s]; (t = fp[k]) != 0 ; k++)
        {
            int longueur = lc[t] + d[t];
            if(longueur >= lc[s])
             {
                if(longueur > lc[s])
                {
                    lc[s] = longueur;
                    kc = appc[s];
                    fpc[kc] = t;
                }
                else     //longueur == lc[s]
                {
                    kc++;
                    fpc[kc]=t;
                }
            }
        }// for k
        kc++;
        fpc[kc]=0;
    }//for s
    fpc[0]=kc;
}// void
