#include <bits/stdc++.h>

using namespace std;
bool vis[200001];
int n,k;
vector< pair<int,int> > v(100001);
int cnt[100001];
ofstream fout("10.txt");
pair<int,int> bound(int cap)
{
    int rez=-1;
    for(int i=0;i<n;i++)
    {
        if(!vis[v[i].second] && v[i].first==cap)
        {
            rez=i;
            break;
        }
    }
    if(rez==-1)
    {
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(v[l].first+v[r].first>cap)
            {
                l++;
            }
            else if(v[l].first+v[r].first<cap)
            {
                r--;
            }
            else
            {
                if(!vis[v[l].second] && !vis[v[r].second])
                {
                    return make_pair(l,r);
                }
                else if(!vis[v[l].second])
                {
                    r--;
                }
                else if(!vis[v[r].second])
                {
                    l++;
                }
                else
                {
                    l++;
                    r--;
                }
            }
        }
        for(int i=0;i<n;i++)
    {
        if(!vis[v[i].second] && v[i].first<cap)
        {
            return make_pair(i,-1);
        }
    }
    }
    else
    {
        return make_pair(rez,-1);
    }
    return make_pair(-1,-1);
}
int main()
{
    ifstream fin("10.in");


    fin >> n >> k;

    int a;
    for(int i=0;i<n;i++)
    {
        fin >> a;
        v[i]=make_pair(a,i);
    }
    int p[n];
    sort(v.rbegin(),v.rend());
    int cur=1;
    int cap=20;
    for(int i=2*n;i>=0;i--)
    {
        pair<int,int>pr=bound(cap);
        int ind1=pr.first;
        int ind2=pr.second;
        //cout << ind << endl;
        if(ind1==-1)
        {
            cur++;
            cap=20;
            continue;
        }
        if(ind2==-1)
        {
            if(vis[v[ind1].second])continue;
            cap-=v[ind1].first;
            p[v[ind1].second]=cur;
           vis[v[ind1].second]=1;
          if(cap==0)
          {
            cap=20;
            cur++;
          }
        }
        else
        {
            if(vis[v[ind1].second]||vis[v[ind2].second])continue;
           p[v[ind1].second]=cur;
           vis[v[ind1].second]=1;
           p[v[ind2].second]=cur;
           vis[v[ind2].second]=1;
           cap=20;
           cur++;
        }
    }
    int rez=0;
    for(int i=0;i<n;i++)
    {
        if(cnt[p[i]-1]==0)rez++;
        cnt[p[i]-1]++;
    }
    fout << rez <<'\n';
    for(int i=0;i<n;i++)
    {
        fout << p[i]-1 <<' ';
    }
    return 0;
}
