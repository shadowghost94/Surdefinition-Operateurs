/*Surdéfinition de l'opérateur () */

#include <iostream>
using namespace std;

class int2d
{
    int nligne;                             //nombre de ligne
    int ncol;                               //nombre de colonne
    int *adr;                               //pointeur sur tableau dynamique

public:
    int2d(int nl, int nc)
    {
        nligne=nl;                          //affectation du nombre de ligne transmis à nligne
        ncol=nc;                            //affectation du nombre de colonne transmis à ncol
        adr= new int [nligne*ncol];         //allocation dynamique d'un tableau de nl*nc cellule

        //affectation des zéros dans chaque cellule du tableau allouer
        for(int i=0; i<nl*nc; i++)adr[i]=0;
    }

    ~int2d(){ delete adr; }

    int& operator ()(int nbr1, int nbr2)
    {
        if(nbr1*nbr2<0 || nbr1*nbr2>nligne*ncol){nbr1=0; nbr2=0;}
        return adr[nbr1*nbr2];
    }
};

int main()
{
    int2d instance0(2,2);
    for(int i=1; i<=2; i++)
    {
        for(int j=1; j<=2; j++)
        {
            instance0(i,j)=i+j;
        }
    };
    cout<<instance0(1,2)<<endl;
}
