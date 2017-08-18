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

int main()
{
	int a,b;
	cin>> a;
	cin>> b;
	cout<< "M.C.D: " << euclides(a,b);
	return 0;
}
