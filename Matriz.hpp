#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

struct Matriz
{
   int **mat;
   int filas=0;
   int columnas=0;
};

// funcion de inicializacion
Matriz matriz(string s)
{
   Matriz m;
   int col=1;int fil=1;bool flag =false;

   // Averiguo el tamaño de la matriz en cuestion
   for(int i=0; i<length(s); i++)
   {
      if(s[i]==',' && flag==false){col=col+1;}
      if(s[i]==';'){fil=fil+1;flag=true;}
   }
   m.filas=fil;m.columnas=col;

   // creo el array principal (filas)
   m.mat = new int*[fil];
   // recorro las n filas y los arrays secundarios (m columnas)
   for(int i=0;i<fil; i++)
   {
      m.mat[i] = new int[col];
   }

   // Tokenizo la cadena
   int i=0; string aux="";
   while(i<length(s))
   {
      if(s[i]=='{' || s[i]=='}')
      {
         i++;
      }
      else
      {
         if(s[i]==';')
         {
            s[i]= ',';
         }
         aux = aux + s[i];
         i++;
      }
   }
   /*
   cout << aux << endl;
   cout << "Filas: " << m.filas << endl;
   cout << "Columnas: " << m.columnas << endl;
   */
   // Cargo los elmenos en el array
   int j,k;
   for(j=0; j<m.filas; j++)
   {
      for(k=0; k<m.columnas; k++)
      {
         m.mat[j][k] = stringToInt(getTokenAt(aux,',',(m.columnas*j)+k));
      }
   }

   /*
   m.mat[0][0]=1;
   m.mat[0][1]=2;
   m.mat[0][2]=3;
   m.mat[1][0]=4;
   m.mat[1][1]=5;
   m.mat[1][2]=6;
   m.mat[2][0]=7;
   m.mat[2][1]=8;
   m.mat[2][2]=9;
   m.mat[3][0]=10;
   m.mat[3][1]=11;
   m.mat[3][2]=12;
*/
   return m;
}

void matrizImprimir(Matriz m)
{
   for(int i=0;i<m.filas; i++)
   {
      cout << "[\t";
      for(int j=0;j<m.columnas; j++)
      {
         cout << m.mat[i][j] << "\t";;
      }
      cout << "]"<< endl;
   }
}

Matriz matrizSumar(Matriz a, Matriz b)
{
   Matriz maux;
   maux.filas=a.filas;
   maux.columnas=a.columnas;

   // creo el array principal (filas)
   maux.mat = new int*[maux.filas];
   // recorro las n filas y los arrays secundarios (m columnas)
   for(int i=0;i<maux.filas; i++)
   {
      maux.mat[i] = new int[maux.columnas];
   }

   if((a.columnas==b.columnas) && (a.filas==b.filas))
   {
      for(int i=0; i<a.filas; i++)
      {
         for(int j=0; j<a.columnas; j++)
         {
            maux.mat[i][j] = a.mat[i][j] + b.mat[i][j];
         }
      }
   }
   else
   {
      maux.mat = new int*[2];
      for(int i=0;i<2; i++)
      {
         maux.mat[i] = new int[2];
      }
      string sb = "{{0,0};{0,0}}";
      Matriz maux = matriz(sb);
      return maux;
   }
   return maux;
}

Matriz matrizMultiplicar(Matriz a, Matriz b)
{
   Matriz maux;
   maux.filas=a.filas;
   maux.columnas=b.columnas;

   maux.mat = new int*[maux.filas];
   for(int i=0;i<maux.filas; i++)
   {
      maux.mat[i] = new int[maux.columnas];
   }

   if((a.columnas==b.filas))
   {
      int sum=0;
      for(int i=0; i<maux.filas; i++)
      {
         for(int j=0; j<maux.columnas; j++)
         {
            for(int k=0; k<a.columnas; k++)
            {
               sum = sum + (a.mat[i][k]*b.mat[k][j]);
            }
            maux.mat[i][j] = sum;
            sum=0;
         }
      }
   }
   else
   {
      maux.mat = new int*[2];
      for(int i=0;i<2; i++)
      {
         maux.mat[i] = new int[2];
      }
      string sb = "{{0,0};{0,0}}";
      Matriz maux = matriz(sb);
      return maux;
   }
   return maux;
}
