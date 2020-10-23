/*
 * BigInt.hpp
 *
 *  Created on: Aug 29, 2020
 *      Author: fernando.coz
 */

#ifndef BIGINT_HPP_
#define BIGINT_HPP_
#include <iostream>
#include <stdio.h>
#include "../funciones/strings.hpp"
using namespace std;


struct BigInt
{
   string s;
};

// funcion de inicializacion
BigInt bigInt(string num)
{
   BigInt bint;
   bint.s = num;
   return bint;
}

// retorna una cadena que representa al numero
string bigIntToString(BigInt b)
{
  return b.s;
}

// similar a la funcion de inicializacion
BigInt bigIntFromString(string s)
{
   BigInt bint;
   bint.s = s;
   return bint;
}

// operaciones: suma y resta
BigInt bigIntSumar(BigInt a,BigInt b)
{
   int sizea = length(a.s);
   int sizeb = length(b.s);
   int carry = 0;
   int sum = 0;
   int max = 0;
   string aux="";
   char auxa='0';
   char auxb='0';

   int dif = sizea-sizeb;

   if(dif>0)
   {
      b.s = lpad(b.s,sizea,'0');
      max = sizea;
   }
   else
   {
      if(dif<0)
      {
         a.s = lpad(a.s,sizeb,'0');
         max = sizeb;
      }
      else
      {
         max = sizea;
      }
   }

   for(int i = max-1; i>=0; i--)
   {
      auxa = a.s[i];
      auxb = b.s[i];
      sum = charToInt(auxa) + charToInt(auxb) + carry;
      if(sum>9)
      {
         carry=1;
         aux = aux + intToString(sum-10);
         if(i==0)
         {
            aux = aux + '1';
         }
      }
      else
      {
         aux = aux +intToString(sum);
         carry=0;
      }
   }

   //Invierto el orden de la cadena
   string auxfinal="";
   for(int i=length(aux)-1; i>=0; i--)
   {
     auxfinal = auxfinal + aux[i];
   }

   return bigIntFromString(auxfinal);
}


BigInt bigIntRestar(BigInt a,BigInt b)
{
   BigInt baux,caux,daux;
   string aux="";
   char auxch='0';
   int suma = 0;

   // convertir b a complemento a10

   b.s = lpad(b.s,length(a.s),'0');
   int sizeb = length(b.s);

   //cout << "bs pad" << b.s << endl;
   for(int i=0; i<sizeb; i++)
   {
      auxch = b.s[i];
      suma = 9 - charToInt(auxch);
      aux = aux + intToString(suma);
   }
   BigInt bigIntFromString(string s);
   //cout << "aux: " << aux << endl;
   baux = bigIntSumar(bigIntFromString(aux),bigIntFromString("1"));
   //cout << "1: " << baux.s << endl;
   //cout << "1: " << a.s << endl;

   caux = bigIntSumar(a,baux);
   //cout << "2: " << bigIntToString(caux) << endl;
   daux.s = substring(caux.s,1,length(caux.s));
   //cout << "3: " << bigIntToString(daux) << endl;
   //------------------------------
   return daux;
}

#endif /* BIGINT_HPP_ */
