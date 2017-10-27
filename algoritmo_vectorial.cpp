#include <iostream>
#include <math.h>

using namespace std;

//int vectores()
//{
//    int n;
//    int nv;
//    int elem;
//    cout<<"Cantidad de vectores: ";
//    cin>>nv;
//    cout<<"Cantidad de elementos: ";
//    cin>>n;
//    for(int p=0;p<nv;p++)
//    {
//        for(int q=0;q<n;q++)
//        cin>>elem;
//        cout<<endl;
//    }
//}

void normal(int* mat,int tam)
{
    int norma=0;
    for(int i=0;i<tam;i++)
    {
        norma+=pow(*(mat+i),2);
    }
    cout<<norma;
}

//int escalar(int* mat,int tam)
//{
//    int multi=0;
////    int *a=*mat;
////    int *b=*(mat+1);
//    for(int i=0;i<tam;i++)
//    {
//        multi+=(**a)*(**b);
//    }
//}

int mu(int* mat,int tam)
{
    int result;
    int i=2;
    int j=1;
    for(i;i<tam;i++)
        for(j;j<i;j++)
            result=((*mat)*(*(mat+i))/(normal(*mat,tam));
}

int main()
{
    int* mat[3]={{1,2,3},{-1,3,2}};
    normal(*mat,3);
    //escalar(*mat,3);
    return 0;
}
