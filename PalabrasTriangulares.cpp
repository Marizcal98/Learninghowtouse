#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string Nombres[2000], Auxiliar;

int main(){
    FILE *fp;
    int p = 0, l = 0, vp=0, vt=0, contador = 0;
    float total=0, n;
    char c;
    fp = fopen("Palabras.txt", "r");

    while((c=fgetc(fp)) != EOF){ //Metodo para meterlo en arreglos
        if (c != '"'){
            if(c==','){
                p++;
            }else{
                Nombres[p] += c;
            }
        }
    }

   for(p=0;p<2000;p++){ // metodo para darle valor a las palabras y letras
        vp=0;
        for(l=0;l<Nombres[p].length();l++){
                vp += (Nombres[p][l] - 64);
            }
        total = 0;
        for(n=1;total<vp;n++){
            total = (n*(n+1))/2;
            if(total == vp){
                contador ++;
            }
        }
    }
    cout << contador;
    fclose(fp);
}
