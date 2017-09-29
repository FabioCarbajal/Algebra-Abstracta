#include <iostream>

using namespace std;

int main()
{
    int cont=0;
    int n;
    cout<<"Ingrese el tamano limite: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a=0;
        for(int j=1;j<=n;j++){
            if(i%j==0)
                a++;
        }
        if(a==2){
            cout<< " " <<i;
            cont++;
        }
        else
            cout<<" * ";
    }
    cout<<endl;
    cout<<cont;
    return 0;
}
