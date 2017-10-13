#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

using namespace std;

//int modulo(int a,int b)
//{
//	int q=a/b;
//	int r=a-q*b;
//	if(r<0)
//		r+=b;
//	return r;
//}
//
//int main(int k, char** cadena)
//{
//    int a=atoi(cadena[1]);
//    int b=atoi(cadena[2]);
//    int i=0;
//    int m=27;
//    int len=strlen(cadena[3]);
//    char* texto;
//    texto=(char*) malloc(len);
//    strcpy(texto,cadena[3]);
//
//    char cifrado,x;
//
//    i=0;
//
//    while(i<len)
//    {
////        int res=a*x+b;
//        x=toupper(texto[i])-65;
//        if(x>14)
//            x++;
//        cifrado=((a*x+b)%m)+64;
//        cout<< cifrado;
//        i++;
//    }
//    free(texto);
//    return 0;
//}
//
//int main()
//{
//    int k;
//    cout << "Introduce el numero de desplazamiento deseado: ";
//    cin >> k;
//
//    ifstream cadena("mensaje.txt");
//    string temp;
//    getline(cadena,temp);
//
//    codificar(k,temp);
//}


//Funcion codifica
string codifica(int n, string & cadena)
{
    for (int i = 0; i < cadena.length(); i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            if (cadena[i] + n > 'z') {
                cadena[i] = 'a' - 'z' + cadena[i] + n - 1;
            } else if (cadena[i] + n < 'a') {
                cadena[i] = 'z' - 'a' + cadena[i] + n + 1;
            } else {
                cadena[i] += n;
            }
        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            if (cadena[i] + n > 'Z') {
                cadena[i] = 'A' - 'Z' + cadena[i] + n - 1;
            } else if (cadena[i] + n < 'A') {
                cadena[i] = 'Z' - 'A' + cadena[i] + n + 1;
            } else {
                cadena[i] += n;
            }
        }
    }
    return cadena;
}

//Funcion descodificar
string descodifica(int n, string & cadena)
{
    return codifica(-n, cadena);
}

//Programa principal
int main()
{
    int n;
    cout << "Introduce el numero de desplazamiento deseado: ";
    cin >> n;

    ifstream cadena("mensaje.txt");
    string temp;
    getline(cadena,temp);


//    cout << "Introduce el mensaje a codificar" << endl;
//    getline(cin, cadena);

    codifica(n, temp);
    cout << temp << endl;

    descodifica(n, temp);
    cout << temp << endl;
}
