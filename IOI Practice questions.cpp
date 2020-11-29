#include <bits/stdc++.h>

using namespace std;
vector<int> fact[300001];
void add(int x)
{
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            fact[i].push_back(x);
            int y=x/i;
            if(y>i)
            {
                fact[y].push_back(x);
            }
            else
            {
                break;
            }
        }
    }
}
int query(int a,int b,int m)
{
    int r=upper_bound(fact[m].begin(),fact[m].end(),b)-fact[m].begin();
    int l=lower_bound(fact[m].begin(),fact[m].end(),a)-fact[m].begin();
    return r-l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q,a,b,m;
    string s;
    cin >> q;
   for(int i=0;i<q;i++)
   {
       cin >> s;
       if(s=="ADD")
       {
           cin >> a;
           add(a);
       }
       else
       {
           cin >> a >> b >> m;
           cout << query(a,b,m)<<'\n';
       }
   }
    return 0;
}
