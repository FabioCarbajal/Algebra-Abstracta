#include <iostream>
#include <vector>

using namespace std;

vector<int> extendido(int a, int b)
{
    vector<int> respuestas;
    int r1=a;
    int r2=b;
    int u,v,q,r;
    int u1=1;
    int u2=0;
    int v1=0;
    int v2=1;

    while(r2>0)
    {
        q=r1/r2;
        r=r1-q*r2;
        r1=r2;
        r2=r;
        u=u1-q*u2;
        u1=u2;
        u2=u;
        v=v1-q*v2;
        v1=v2;
        v2=v;
    }
    cout << "M.C.D(" << a << "," << b << ") = " << r1 << endl;
    cout << "u= " << u1 << "  " << "v= " << v1;
    respuestas.push_back(r1);
    respuestas.push_back(u1);
    respuestas.push_back(v1);
    return respuestas;
}

int main()
{
    extendido(141,96);
    return 0;
}
