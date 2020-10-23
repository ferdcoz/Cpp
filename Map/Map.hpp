
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "../tads/Arr.hpp"

using namespace std;

template<typename K,typename V>
struct Map
{
   Arr<K> keys;
   Arr<V> values;
   int curr=-1;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.keys = arr<K>();
   m.values = arr<V>();
   return m;
}

template<typename K>
int _cmpKK(K a, K b)
{
   return a<b?-1:a>b?1:0;
}

template<typename K,typename V>
V* mapGet(Map<K,V>& m,K k)
{
   V* ret = NULL;
   int pos = arrFind<K>(m.keys,k,_cmpKK);

   if( pos>= 0)
   {
      ret = arrGet<V>(m.values,pos);
   }
   return ret;
}


template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   int p = arrFind<K>(m.keys,k,_cmpKK);
   if( p<0 )
   {
      arrAdd<K>(m.keys,k);
      arrAdd<V>(m.values,v);
   }
   else
   {
      arrSet<V>(m.values,p,v);
   }

   return mapGet<K,V>(m,k);
}

template<typename K,typename V>
bool mapContains(Map<K,V>& m,K k)
{
   int p = arrFind<K>(m.keys,k,_cmpKK);
   return p>0?false:p<0?false:true;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   int p = arrFind<K>(m.keys,k,_cmpKK);
   if( p<0 )
   {
      //error
   }
   arrRemove<K>(m.keys,p);
   return arrRemove<V>(m.values,p);
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrRemoveAll<K>(m.keys);
   arrRemoveAll<V>(m.values);
}

template<typename K,typename T>
int mapSize(Map<K,T> m)
{
   return arrSize(m.keys);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V>& m)
{
   m.curr++;
   return m.curr < arrSize(m.keys);
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   return m.keys.arr[m.curr];
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   return &m.values.arr[m.curr];
}

template<typename K,typename T>
void mapReset(Map<K,T>& m)
{
   m.curr=-1;
}

template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
   Map<K,V> aux = map<K,V>();
   // Recorro el map viejo y copio keys al map aux
   mapReset<K,V>(m);
   while( mapHasNext<K,V>(m) )
   {
      add<K>(aux.keys.arr,aux.keys.len,mapNextKey<K,V>(m));
   }
   // Ordeno el array por key
   arrSort<K>(aux.keys,cmpKK);
   // Recorro map aux y coloco values map viejo
   mapReset<K,V>(aux);
   while( mapHasNext<K,V>(aux) )
   {
      K k = mapNextKey<K,V>(aux);
      V* v = mapGet<K,V>(m,k);
      mapPut<K,V>(aux,k,*v);
   }
   // Libero memoria arrays y direcciono aux
   delete m.keys.arr;
   delete m.values.arr;
   m.keys.arr = aux.keys.arr;
   m.values.arr = aux.values.arr;
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
   Map<V,K> aux = map<V,K>();
   // Copio los valores invertidos
   for(int i=0; i<mapSize(m); i++)
   {
      arrAdd<V>(aux.keys,m.values.arr[i]);
      arrAdd<K>(aux.values,m.keys.arr[i]);
   }
   // Ordeno el aux por key-value
   mapSortByKeys<V,K>(aux,cmpVV);
   // Libero memoria arrays y direcciono aux
   delete m.keys.arr;
   delete m.values.arr;
   m.values.arr = aux.keys.arr;
   m.keys.arr = aux.values.arr;
}

#endif
