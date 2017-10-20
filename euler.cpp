#include <iostream>

using namespace std;
//
//int factorizar(int numero)
//{
//  int i;
//  if (numero<=1)
//    return 1;
//  for (i=2;i<=numero;i++)
//    if (numero%i==0){
//      cout<<i<<endl;
//      factorizar(numero/i);
//      break;
//    }
//}
//
//int main ()
//{
//  int num;
//  factorizar(20);
//  return 0;
//}

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

void phimcd(int n)
{
    int result = 0;
    for (int i=1; i < n; i++){
        if (euclides(i, n) == 1){
            cout<<i<<" ";
            result++;
        }
    }
}

int main()
{
    int n=24;
    cout<<char(157)<<"("<<n<<")"<<"="<<phi(n)<<endl;
    phimcd(n);
    return 0;
}
