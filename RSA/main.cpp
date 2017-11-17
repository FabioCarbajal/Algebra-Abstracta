#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>

using namespace std;

int modulo(int a,int b)
{
	int q=a/b;
	int r=a-q*b;
	if(r<0)
		r+=b;
	return r;
}

int euclides(int a, int b)
{
	int res=modulo(a,b);
	while(res!=0)
	{
		a=b;
		b=res;
		res=modulo(a,b);
	}
	return b;
}

int potencia(int a, int b, int c)
 {
     int exp=1;
     int x=modulo(a,c);
     while(b>0)
     {
         if(b&1)
         {
             exp=modulo((exp*x),c);
         }
         x=modulo((x*x),c);
         b=b/2;
     }
     return exp;
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
    respuestas.push_back(r1);
    respuestas.push_back(u1);
    respuestas.push_back(v1);
    return respuestas;
}

int phi(int n)
{
    float result = n;
    for (int p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (float) p));
        }
    }

    if (n > 1)
        result *= (1.0 - (1.0 / (float) n));

    return result;
}

int cifrar_rsa(int m,int &l,int &o)
{
    int pub=rand()%100+1;
    cout<<"pub: "<<pub<<endl;
    int p,q;
    p=rand()%100+1;
    q=rand()%100+1;
    cout<<"p: "<<p<<", q: "<<q<<endl;
    int priv;
    int n=p*q;
    cout<<"phi(n): "<<phi(n)<<endl;
    priv=inversa(pub,phi(n))[1];
    cout<<"priv: "<<priv<<endl;
    l=priv;
    o=phi(n);
    return potencia(m,pub,n);
}

int descifrar_rsa(int m)
{
    int p;
    int o;
    int des = cifrar_rsa(m,p,o);
    return potencia(des,p,o);
}

int main()
{
    int o,p;
    cout<<"cifrado: "<<cifrar_rsa(1234,o,p)<<endl;
    cout<<"descifrar: "<<descifrar_rsa(1234);
    return 0;
}
