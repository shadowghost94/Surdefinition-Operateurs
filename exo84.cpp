/* ce programme surdéfinit les opérateurs d'égalités et de non égalités*/
#include <iostream>
using namespace std;


class vector3d
{
    float x,y,z;
public:
    vector3d( float c1=0.0, float c2=0.0, float c3=0.0 )
    {
        x=c1;
        y=c2;
        z=c3;
    }

    friend int operator == (vector3d objet1, vector3d objet2);
    friend int operator != (vector3d objet1, vector3d objet2);
//utilisation de fonction membre de classe
   /*int operator == (vector3d objet)
    {
        if( (x== objet.x) && (y == objet.y) && (z == objet.z) ){return 1;}else return 0;
    }

    int operator != ( vector3d objet )
    {
        if(x != objet.x || y != objet.y || z != objet.z ){ return 1; }else return 0;
    }*/
};

//utilisation de fonctions hors classes (fonctions indépendante)

int operator == (vector3d objet1, vector3d objet2)
{
    if( objet1.x == objet2.x && objet1.y==objet2.y && objet1.z==objet2.z){ return 1;}else return 0;
};

int operator != (vector3d objet1, vector3d objet2)
{
    if( objet1.x!=objet2.x || objet1.y!=objet2.y || objet1.z!=objet2.z)return 1;else return 0;
};


int main()
{
    int stocker;
    vector3d d1(0.1, 0.2, 0.3);
    vector3d d2(0.1, 0.2, 0.4);
    stocker= (d1==d2);
    cout<<stocker<<endl;

    stocker= d1!=d2;
    cout<<stocker<<endl;
}
