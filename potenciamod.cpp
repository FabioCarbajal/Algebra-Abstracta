#include <iostream>

using namespace std;

int modulo(int a,int b)
{
	int q=a/b;
	int r=a-q*b;
	if(r<0)
		r+=b;
	return r;
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

int main()
{
    cout << "La respuesta es: " << potencia(5,117,19);
    return 0;
}
