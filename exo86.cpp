#include <iostream>
using namespace std;

class vecteur3d
{
    float v[3];
public:
    vecteur3d( float c1=0.0, float c2=0.0, float c3=0.0 )
    {
        v[0]=c1;
        v[1]=c2;
        v[2]=c3;
    }

    float operator [] (int indice)
    {
        return v[indice];
    }
};

int main()
{
    vecteur3d objet(3, 5, 8);
    cout<<objet[1]<<endl;

    return 0;
}
