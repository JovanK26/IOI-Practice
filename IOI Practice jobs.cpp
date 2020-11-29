#include "job.h"
#include <bits/stdc++.h>
using namespace std;
int U[200001];
int D[200001];
int P[200001];
int prt[200001];
double q[200001];
int e[200001];
vector<int>v[200001];
vector<int>order;
priority_queue< pair<double,int> >pq;
bool vis[200001];
int findd(int x)
{
   while(prt[x]!=x)
   {
       x=prt[x];
   }
   return x;
}
void unionn(int x,int y)
{
    x=findd(x);
    y=findd(y);
    prt[y]=x;
}
long long scheduling_cost(vector<int> p,vector<int> u,vector<int> d)
{
        for(int i=1;i<p.size();i++)
        {
            v[p[i]].push_back(i);
        }
        U[0]=-1000000000;
        D[0]=d[0];
        q[0]=-1000000000;
        e[0]=0;
        prt[0]=0;
        P[0]=p[0];
        for(int i=1;i<p.size();i++)
        {
            e[i]=i;
            P[i]=p[i];
            prt[i]=i;
            U[i]=u[i];
            D[i]=d[i];
            q[i]=(double)U[i]/(double)D[i];
        }
    for(int i=0;i<p.size();i++)
    {
        pq.push(make_pair(q[i],i));
    }
   int br=p.size();
   while(br)
   {
       pair<double,int> x=pq.top();
       pq.pop();
       int j=x.second;
       if(vis[j])continue;
       vis[j]=1;
       int f=P[j];
       int i=findd(f);
       //cout << i+1 <<' '<<j+1<<endl;
       U[i]+=U[j];
       D[i]+=D[j];
       q[i]=(double)U[i]/(double)D[i];
      // cout << q[i]<<endl;
       P[j]=e[i];
       e[i]=e[j];
       unionn(i,j);
       pq.push(make_pair(q[i],i));
       br--;
   }
   order.push_back(e[0]);
   int gg=e[0];
   int sz=p.size()-1;
   while(sz)
   {
       gg=P[gg];
       order.push_back(gg);
       sz--;
   }
   //cout << q[2]<<endl;
   long long rez=0;
   long long t=0;
   for(int i=p.size()-1;i>=0;i--)
   {
       //cout << order[i]+1 <<endl;
       t+=d[order[i]];
       rez+=t*u[order[i]];
   }
   return rez;
}
/*int main()
{
    int nn;
    cin >> nn;
    vector<int> pp,dd,uu;
    int p,u,d;
    for(int i=0;i<nn;i++)
    {
        cin >> p;
        pp.push_back(p);
    }
    for(int i=0;i<nn;i++)
    {
        cin >> u;
        uu.push_back(u);
    }
    for(int i=0;i<nn;i++)
    {
        cin >> d;
        dd.push_back(d);
    }
   cout << scheduling_cost(pp,uu,dd);
   return 0;
}
*/
