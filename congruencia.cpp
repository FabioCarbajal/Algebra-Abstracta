#include <iostream>
#include <vector>
//#DEFINE

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
		cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
		a=b;
		b=res;
		res=modulo(a,b);
	}
	cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
	return b;
}

vector<int> congruencia(int a, int b, int m)
{
    vector<int> respuestas;
    int x;
    int r1=a;
    int r2=m;
    int u,v,q,r;
    int u1=1;
    int u2=0;
    int v1=0;
    int v2=1;
    int c=modulo(x,m);

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
    x=(u1*b)/(euclides(a,m));
    cout << "Ecuacion: " << a << "x" << char(240) << b << "mod" << m << endl;
    cout << "x= " << modulo(x,m);
    respuestas.push_back(r1);
    respuestas.push_back(u1);
    respuestas.push_back(v1);
    return respuestas;
}


int main()
{
    congruencia(3,5,7);
    return 0;
}
