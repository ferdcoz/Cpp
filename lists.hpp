#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;
   Node<T>* sig;
};

template <typename T>
Node<T>* add(Node<T>*& p, T x)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = x;
   nuevo->sig = NULL;

   if(p!=NULL)
   {
      Node<T>* aux = p;
      while(aux->sig != NULL)
      {
         aux = aux->sig;
      }
      aux->sig = nuevo;
   }
   else
   {
      p = nuevo;
   }
   return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;

   if(p!=NULL)
   {
      Node<T>* aux = p;
      p = nuevo;
      nuevo->sig = aux;
   }
   else
   {
      p = nuevo;
   }
   return nuevo;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   Node<T>* aux = p->sig;
   T ret = p->info;
   delete p;
   p = aux;
   return ret;
}

template <typename T, typename K>
void remove(Node<T>*& p, K v, int cmpTK(T,K))
{
   Node<T>* aux=p;
   Node<T>* ant=NULL;

   while( aux!=NULL && cmpTK(aux->info,v)!=0)
   {
      ant=aux;
      aux=aux->sig;
   }
   if(ant==NULL)
   {
      p = aux->sig;
   }
   else
   {
      ant->sig = aux->sig;
   }
   delete aux;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p, K v, int cmpTK(T,K))
{
   Node<T>* aux = p;
   Node<T>* ret = NULL;
   bool found = false;
   /*
   while( aux!=NULL && cmpTK(aux->info,v)!=0)
   {
      if(cmpTK(aux->info,v)==0)
      {
         ret = aux;
      }
      aux = aux->sig;
   }
   */
   while( aux!=NULL && found!=true)
   {
      int comp = cmpTK(aux->info,v);
      if(comp==0)
      {
         ret = aux;
         found = true;
      }
      else
      {
         found = false;
      }
      aux = aux->sig;
   }
   return ret;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T v, int cmpTT(T,T) )
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = v;
   Node<T>* ant=NULL;
   Node<T>* aux=p;

   while( aux!=NULL && cmpTT(aux->info,v)<0)
   {
      ant = aux;
      aux = aux->sig;
   }
   if( ant==NULL )
   {
      nuevo->sig = p;
      p = nuevo;
   }
   else
   {
      ant->sig = nuevo;
      if( aux==NULL )
      {
         nuevo->sig = NULL;
      }
      else
      {
         nuevo->sig=aux;
      }
   }
   return nuevo;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   Node<T>* ret = find(p,e,cmpTT);
   if(ret==NULL)
   {
      ret = orderedInsert(p,e,cmpTT);
      enc = false;
   }
   else
   {
      enc = true;
   }
   return ret;
}

template <typename T>
void sort(Node<T>*& p, int cmpTT(T,T))
{
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   bool flag = true;
   Node<T>* aux = p;
   while( aux!=NULL )
   {
      aux = aux->sig;
      flag = false;
   }
   return flag;
}

template <typename T>
void free(Node<T>*& p)
{
   while( p != NULL)
   {
      Node<T>* aux = p->sig;
      delete p;
      p = aux;
   }
}

template <typename T>
void push(Node<T>*& p, T v)
{
}

template <typename T>
T pop(Node<T>*& p)
{
   T t;
   return t;
}

template <typename T>
void enqueue(Node<T>*& p, Node<T>*& q, T v)
{
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t;
   return t;
}

template <typename T>
void mostrarLista(Node<T> * p)
{
   Node<T>* aux = p;
   while( aux!=NULL )
   {
      cout << aux->info;
      cout << endl;
      aux = aux->sig;
   }
}

#endif
