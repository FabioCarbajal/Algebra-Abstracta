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
    respuestas.push_back(r1);
    respuestas.push_back(modulo(u1,b));
    respuestas.push_back(v1);
    return respuestas;
}

void chino()
{
    int con;
    int mult=1;
    int x;
    cout<<"Ingrese la cantidad de valores y modulos: ";
    cin>>con;
    int mod[con];
    int val[con];
    int M[con];
    int inv[con];
    for(int i=0;i<con;i++)
    {
        cout<<"Ingrese los valores: ";
        cin>> val[i];
        cout<<"Ingrese los modulos: ";
        cin>> mod[i];
    }
    for(int j=0;j<con;j++)
    {
        mult*=mod[j];
    }
    cout<<"La multiplicacion es: " << mult<< endl;
    for(int k=0;k<con;k++)
    {
        M[k]=mult/mod[k];
        cout<<M[k]<<endl;
    }
    for(int j=0;j<con;j++)
    {
        inv[j]=inversa(M[j],mod[j])[1];
        cout<<inv[j]<<endl;
    }
    for(int j=0;j<con;j++)
    {

        x+=val[j]*M[j]*inv[j];
    }
    cout<<modulo(x,mult);
}

int main()
{
    chino();
    return 0;
}
