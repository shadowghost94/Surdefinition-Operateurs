/*Surdéfinition de l'opérateur << et [] */
#include <iostream>
using namespace std;

class histo
{
    float min;            //borne inférieure
    float max;            //borne supérieure
    int nint;             //nombre de tranche utiles

    int* adc;             //pointeur sur les compteurs associés à chaque intervalle
                          //adc[i-1]= compteur valeur de la tranche de rang i
    float ecart;           //la largeur d'une tranche
public:
    histo(float=0.0, float=1.0, int=10);    //constructeur
    ~histo();                               //destructeur
    histo& operator << (float);             //declaration de la fonction de Surdéfinition de <<
    int operator [](int);                   //déclaration de la fonction de surdéfinition de []
};

histo::histo(float mini, float maxi, int ninter)
{
    //protection contre arguments non admise
    if(maxi<min){ float temp=maxi; maxi=mini; mini=temp; }
    if(maxi==mini){ maxi=mini+1.0; }
    if(ninter<1)nint=1;
    min=mini;
    max=maxi;
    nint=ninter;

    adc= new int [nint];
    for(int i=0; i<nint-1; i++)adc[i]=0;
        ecart= (max-min)/nint;
}

//defiinition du destructeur
histo::~histo(){ delete adc; }

//defintion de la fonction de surdéfinition de <<
histo& histo::operator << (float v)
{
    int nt= (v-min)/ecart;
    //protection: on ne comptabilise que les valeurs convenables
    if( (nt>=0) && (nt<=nint-1) )adc[nt]++;

    return (*this);
}

int histo::operator [](int n)
{
    if((n<1) || (n>nint))n=1;
    return adc[n-1];
}

int main()
{
    const int nint=4;
    int i;
    histo h(0.0, 5.0, nint);
    h<<1.5<<2.4<<3.8<<3.0<<2.0<<3.5<<2.8<<4.6;
    h<<12.0<<-3.5;
    for(int i=0; i<10; i++)h<<i/2.0;
    cout<<"numéro "<<i<<" : "<<h[i]<<endl;
 /*   histo object0;
    histo object1(4,5,6);
    object0=object1<<3;
    //object1[0]=1;
    cout<<object0[1]<<endl; */
}
