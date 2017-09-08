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

int multi(int a, int b, int c)
{
    return modulo(modulo(a,b)*modulo(a,b),c);
}

int main()
{
    cout<<"La respuesta es: " << multi(4,7,6);
    return 0;
}
