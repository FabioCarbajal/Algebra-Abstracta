#include <iostream>
#include <vector>

using namespace std;

int modulo(int a,int b)
{
	int q=a/b;
	int r=a-q*b;
	if(r<0)
		r+=b;
	return r;
}

vector<int> inversa(int a, int b)
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
    cout << "La inversa es: " << modulo(u1,b) << endl;
    respuestas.push_back(r1);
    respuestas.push_back(u1);
    respuestas.push_back(v1);
    return respuestas;
}

int main()
{
    inversa(7,3);
    return 0;
}
