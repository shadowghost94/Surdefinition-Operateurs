/*Surdéfinition des opérateurs <<, >>, ++, -- */

#include <iostream>
using namespace std;

class stack_int
{
    int *adr;                       //pointeur sur pile dynamique
    int maxval;                     //nombre maximum d'éléments dans la pile
    int nelem=0;                    //nombre d'éléments courant

public:
    stack_int(int =20);             //constructeur
    ~stack_int();                   //destrcuteur

    stack_int& operator << (int);   //déclaration de la fonction de surdéfinition de l'opérateur <<
    stack_int& operator >> (int&);  //déclaration de la fonction de surdéfinition de l'opérateur >>
    void affichage();               //fonction d'affichage de pile
};



int main()
{
    stack_int object1(5);
    object1<<2<<3<<1<<4<<0;
    object1.affichage();

    int a,b,c,d;
    object1>>a>>b>>c>>d;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    object1.affichage();

}

//constructeur
stack_int::stack_int(int n)
{
    /**
        *constructeur par défaut
        *création de la pile
        * affectation de 0 à chaque cylindre de la pile
     */

    adr= new int [maxval=n];
    for(int i=0; i<nelem; i++)adr[i]=0;
}

//destructeur
stack_int::~stack_int(){ delete adr; }

//Surdéfinition de l'opérateur <<
stack_int& stack_int::operator << (int n)
{
    /**
     * on vérifie si la pile n'est pas pleine
     * Si oui alors on ne fait rien et on retourne simplement la pile d'origine
     * sinon on affecte à au cylindre d'indice suivant  la valeur transmis en argument
     */
    if(nelem<maxval)
    {
        adr[nelem]= n;
        nelem++;
    }
    return *this;
}

stack_int& stack_int::operator >> (int& n)
{
    n=adr[nelem];
    adr[nelem]= 0;
    nelem--;

    return *this;
}

void stack_int::affichage()
{
    for(int i=0; i<nelem; i++)
    {
        cout<<*(adr+i)<<" ";
    }
    cout<<endl;
}
