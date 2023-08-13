/*programme de surdéfinition de l'opérateur d'égalité*/
#include <iostream>
using namespace std;

class set_int
{
    int *adval;         //adresse du tableau des valeurs
    int nmax;          //nombre maximum d'éléments
    int nelem=0;      //nombre courant d'éléments

public:
    set_int(int );

    set_int( const set_int &);

    ~set_int(){};

    void addElem( int val );

    int card();

    int appartenance( int verif );
    void affichage();

    //surdéfinition de l'opérateur "=" et possibilité de faire de l'affectation multiple
    set_int& operator = ( set_int &e )
    {
        if(this!=&e)
        {
            delete adval;
            adval= new int [nmax= e.nmax];

            nelem= e.nelem;

            for(int i=0; i<nelem; i++)
            {
                adval[i]=e.adval[i];
            }

        }
        return *this;
    };
};

int main()
{
    cout<<"debut du test mon_instance..."<<endl;
    set_int mon_instance(5);                 //création d'une instance

    mon_instance.addElem(2);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur
    mon_instance.addElem(1);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur
    mon_instance.addElem(3);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur
    mon_instance.addElem(7);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur
    mon_instance.addElem(3);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur

    //recuperation du nombre d'éléments
    cout<<"les éléments ont été ajouté et crée avec succès..."<<endl;
    cout<<"le nombre d'éléments courant dans l'objet est: "<<mon_instance.card()<<endl;

    //affichage du contenu de l'objet
    cout<<"Affichage..."<<endl;
    mon_instance.affichage();

    //test de la fonction d'appartenance
    int appartient= mon_instance.appartenance(3);
    if(appartient ==1)cout<<"le nombre appartient"<<endl;
        else cout<<"le nombre n'appartient pas..."<<endl;


    cout<<"début du tes de la seconde instance..."<<endl;
    set_int mon_instance1(5);                 //création d'une deuxieme instance instance

    mon_instance1.addElem(10);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur
    mon_instance1.addElem(9);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur
    mon_instance1.addElem(8);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur
    mon_instance1.addElem(7);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur
    mon_instance1.addElem(3);                 //on ajoute 2 au tableau crée dynamiquement par le constructeur

    //recuperation du nombre d'éléments
    cout<<"le nombre d'éléments courant dans l'objet est: "<<mon_instance1.card()<<endl;

    //affichage du contenu de l'objet
    cout<<"Affichage..."<<endl;
    mon_instance1.affichage();

    //test de la fonction d'appartenance
    appartient= mon_instance1.appartenance(8);
    if(appartient ==1)cout<<"le nombre appartient"<<endl;
        else cout<<"le nombre n'appartient pas..."<<endl;

    cout<<"début de l'affectation de l'objet mon_instance1 à l'objet mon_instance"<<endl;
    mon_instance=mon_instance1;
    mon_instance.affichage();

};

set_int::set_int(int nbr=20)
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
