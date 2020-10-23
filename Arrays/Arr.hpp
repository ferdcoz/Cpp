#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

int cmpInt(int a,int b)
{
   return a<b?-1:a>b?1:0;
}

int cmpString(string a, string b)
{
   return a<b?-1:a>b?1:0;
}

template<typename T>
int _cmpTT(T a, T b)
{
   return a<b?-1:a>b?1:0;
}

////////////////////////////////////////////////

template<typename T>
struct Arr
{
  T* arr;
  int cap;
  int len;
};

template<typename T>
Arr<T> arr(int size)
{
   Arr<T>a;
   a.arr = new T[size];
   a.cap=size;
   a.len=0;
   return a;
}

template<typename T>
Arr<T> arr()
{
   Arr<T>a;
   a.arr = new T[100];
   a.cap=100;
   a.len=0;
   return a;
}

template<typename T>
void redimensionar(Arr<T>& a)
{
   Arr<T> b = arr<T>(a.cap*2);

   for( int i=0; i<a.cap; i++ )
   {
      add<T>(b.arr,b.len,a.arr[i]);
   }
   delete a.arr;

   a = b;
}

template<typename T>
int arrAdd(Arr<T>& a,T v)
{
   if(a.len == a.cap)
   {
      redimensionar<T>(a);
   }
   return add<T>(a.arr,a.len,v);
}

template<typename T>
T* arrGet(Arr<T> a,int p)
{
   T* pa = NULL;
   int pos = find<T>(a.arr,a.len,a.arr[p],_cmpTT);
   if(pos>=0)
   {
      pa = &a.arr[p];
   }
   return pa;
}

template<typename T>
void arrSet(Arr<T>& a,int p,T t)
{
   a.arr[p]=t;
}

template<typename T>
void arrInsert(Arr<T>& a,T v,int p)
{
   insert<T>(a.arr,a.len,v,p);
}

template<typename T>
int arrSize(Arr<T> a)
{
   return a.len;
}

template<typename T>
T arrRemove(Arr<T>& a,int p)
{
   return removeA<T>(a.arr,a.len,p);
}

template<typename T>
void arrRemoveAll(Arr<T>& a)
{
   while(arrSize(a)>0)
   {
      arrRemove(a,0);
   }
}

template<typename T,typename K>
int arrFind(Arr<T>& a,K k, int cmpTK(T,K))
{
   return find(a.arr,a.len,k,cmpTK);
}

template<typename T>
int arrOrderedInsert(Arr<T>& a,T t,int cmpTT(T,T))
{
   return orderedInsert<T>(a.arr,a.len,t,cmpTT);
}

template<typename T>
void arrSort(Arr<T>& a,int cmpTT(T,T))
{
   sort(a.arr,a.len,cmpTT);
}

template<typename T>
void arrPrint(Arr<T>& a)
{
   for(int i = 0; i<a.len; i++)
   {
    cout << a.arr[i];
    cout <<  endl;
   }
}

#endif
