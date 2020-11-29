#include<bits/stdc++.h>
#include "dna.h"
using namespace std;

string analyse(int n,int t)
{
   if(!make_test("1"))return string(n,'0');
   int l=1;
   int r=n;
   int m;
   while(l<=r)
   {
      m=(l+r)/2;
      if(make_test(string(m,'1')))
      {
          l=m+1;
      }
      else
      {
          r=m-1;
      }
   }
   string rez=string(l-1,'1');
   int br=0;
   while(rez.size()<n)
   {
       if(make_test(rez+"0"))
       {
           br=0;
           rez+="0";
       }
       else
       {
           rez+="1";
           br++;
       }
       if(br>l-1)break;
   }
   l=1;
   r=n;
   while(l<=r)
   {
      m=(l+r)/2;
      if(make_test(rez.substr(0,m)))
      {
          l=m+1;
      }
      else
      {
          r=m-1;
      }
   }
   rez=rez.substr(0,l-1);
   while(rez.size()<n)
   {
       if(make_test("0"+rez))
       {
           rez="0"+rez;
       }
       else
       {
           rez="1"+rez;
       }
   }
   return rez;
}
