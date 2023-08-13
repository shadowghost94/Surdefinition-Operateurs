/*programme de surdéfinition de l'opérateur < et de l'opérateur [] */
#include <iostream>
using namespace std;

class set_int
{
    int *adval;                             //pointeur d'entier destiné à pointer sur le premier element de tableau
    int nmax;                               //nombre max d'éléments à stocker dans le tableau
    int nelem;                              //nombre d'éléments courants

public:
    set_int(int nbr=20);                    //constructeur

    set_int( const set_int &);                //constructeur par recopie

    ~set_int(){ delete adval; };              //destructeur

    void addElem( int val );            //declaration de la fonction permettant d'ajouter un éléments au tableau

    int card();                         //deeclaration de la fonction permettant de consulter la variable nelem

    int appartenance( int verif );  //declaration de la fonction permettant de verifier l'appartenance d'un entier

    void affichage();               //declaration de la fonction d'affichage

    set_int& operator < (int n, int p); //declaration de la fonction de surdéfinition de l'operateur <

    int operator [] (int);              //declaration de la fonction de surdéfinition de l'opérateur []
};

int main()
{

}

set_int::set_int(int nbr)
{
    adval= new int [nmax=nbr];

};

set_int::set_int( const set_int &rcp)
{
    nelem=rcp.nelem;
    adval= new int [nmax=rcp.nmax];

    for(int i=0; i<nelem; i++)
    {
        adval[i]=rcp.adval[i];
    }
};

int set_int::card(){ return nelem; };

void set_int::addElem( int val )
{
    adval[card()]= val;
    nelem+= 1;  //incrémentation de l'attribut représentant le nombre d'éléments
};

int set_int::appartenance( int verif )
{
    int stocker;

    for( int i=0; i<card(); i++ )
    {
        if(adval[i]==verif)
        {
            stocker=1;
            break;
        }else
        {
            stocker=0;
        }
    }

    return stocker;
};

void set_int::affichage()
{
        for(int i=0; i<nelem; i++)
        {
            cout<<*(adval+i)<<" ";
        }
        cout<<endl;
};

set_int& operator < (int n=-1, int p=-1)
{
    if(n!=-1 && p=!-1)
    {
        return n+p;
    }else{

    }

}
