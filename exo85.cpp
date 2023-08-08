//surdéfinition de l'opérateur d'addition et de multiplication
#include <iostream>
using namespace std;

class vecteur3d
{
    float x, y, z;
public:
    vecteur3d ( float c1=0.0, float c2=0.0, float c3=0.0 )
    {
        x=c1;
        y=c2;
        z=c3;
    }

    friend vecteur3d operator + ( vecteur3d objet1, vecteur3d objet2 );
    friend vecteur3d operator * ( vecteur3d objet1, vecteur3d objet2 );

    float getterX(){ return x; }
    float getterY(){ return y; }
    float getterZ(){ return z; }
};

vecteur3d operator + ( vecteur3d objet1, vecteur3d objet2 )
{
    objet1.x+= objet2.x;
    objet1.y+= objet2.y;
    objet1.z+= objet2.z;

    return objet1;
};

vecteur3d operator * (vecteur3d objet1, vecteur3d objet2)
{
    objet1.x*=objet2.x;
    objet1.y*=objet2.y;
    objet1.z*=objet2.z;

    return objet1;
}
int main()
{
    vecteur3d stocker;
    vecteur3d objet1(3,4,5);
    vecteur3d objet2(2,2,2);

    stocker= objet1+objet2;
    cout<<"test de l'addition de deux objets..."<<endl;
    cout<<"x: "<<stocker.getterX()<<"; y: "<<stocker.getterY()<<"; z: "<<stocker.getterZ()<<endl;

    cout<<"test de la multiplication de deux valeurs "<<endl;
    stocker=objet1*objet2;
    cout<<"x: "<<stocker.getterX()<<"; y: "<<stocker.getterY()<<"; z: "<<stocker.getterZ()<<endl;

    return 0;
}
