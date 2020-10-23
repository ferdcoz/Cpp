#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>
using namespace std;

template <typename T>
int add(T arr[], int& len, T v)
{
   arr[len] = v;
   len++;
   return len-1;
}

template <typename T, typename K>
int find(T arr[], int len, K v, int cmpTK(T,K))
{
   int i=0;

   while( i<len && cmpTK(arr[i],v) )
   {
      i++;
   }
   return i<len?i:-1;
}

template <typename T>
T removeA(T arr[], int& len, int pos)
{
   T ret = arr[pos];
   for(int i = pos+1; i<len; i++)
   {
      arr[i-1] = arr[i];
   }
   len--;
   return ret;
}

template <typename T>
void insert(T arr[], int& len, T v, int pos)
{
   for(int i=len; i>pos; i--)
   {
      arr[i]=arr[i-1];
   }
   arr[pos]=v;
   len++;
}

template <typename T>
int orderedInsert(T arr[], int& len, T v, int cmpTT(T,T))
{
   int pos = 0;
   bool flag = true;

   if (len == 0)
   {
      arr[len] = v;
      len++;
   }

   for(int i = 0; i<len ; i++)
   {
      int c = cmpTT(arr[i],v);

      if(c > 0 && flag==true)
      {
         insert(arr,len,v,i);
         pos = i;
         flag = false;
      }
   }
   return pos;
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T,T))
{
   for(int i=0; i < len-1; i++)
   {
      for(int k=i+1; k<len ;k++)
      {
         int comp = cmpTT(arr[i],arr[k]);
         if(comp>0)
         {
            T aux = arr[i];
            arr[i] = arr[k];
            arr[k] = aux;
         }
      }
   }
   return;
}

template<typename T, typename K>
int binarySearch(T a[], int len, K v, int cmpTK(T,K), bool& enc)
{
   return 0;
}

void heapSort(int arr[],int len)
{
   int aux,cont=0;
   int padre = (len/2)-1;
   while(cont<(padre+1))
   {
      for(int i = padre; i>=0; i--)
      {
      int hizq = (2*i)+1;
      int hder = (2*i)+2;
      int hmay;
         if((arr[i] < arr[hizq])||(arr[i] < arr[hder]))
         {
            arr[hizq] > arr[hder] ? hmay=hizq: hmay=hder;
            aux = arr[i];
            arr[i] = arr[hmay];
            arr[hmay] = aux;
            cont=0;
         }
         else
         {
            cont++;
         }
      }
   }
   while(len>0)
   {
      // Muevo el elemento mas pesado al final
      aux = arr[len-1];
      arr[len-1]=arr[0];
      arr[0]=aux;
      len--; //Decremento el tamaño del array
      padre = (len/2)-1; //Recalculo la cantidad de padres

      for(int i = 0; i<=padre; i++)
      {
         int hizq = (2*i)+1;
         int hder = (2*i)+2;
         int hmay;
         if(hder>=len)
         {
            if(arr[i] < arr[hizq])
            {
               aux = arr[i];
               arr[i] = arr[hizq];
               arr[hizq] = aux;
            }
         }
         else
         {
            if((arr[i] < arr[hizq])||(arr[i] < arr[hder]))
            {
               arr[hizq] > arr[hder] ? hmay=hizq: hmay=hder;
               aux = arr[i];
               arr[i] = arr[hmay];
               arr[hmay] = aux;
            }
         }
      }

   }
}

void radixSort(int arr[],int len)
{

}

#endif
