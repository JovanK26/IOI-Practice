#include "transfer.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> get_attachment(vector<int> source)
{
	int n=source.size();
	int br=0;
	int k=ceil(log2(n))+1;
	vector<int> rez;
	vector<int> v(n+k);
	for(int i=1;i<=n+k;i++)
    {
        if((i&(i-1)))
        {
            v[i-1]=source[br];
            br++;
        }
    }
    int cur=1;
    int x;
    while(cur<=n+k)
    {
        bool vis[n+k+1];
        memset(vis,0,sizeof(vis));
        queue<int> q;
        vis[cur]=1;
        q.push(cur);
        int par=0;
        while(!q.empty())
        {
            x=q.front();
            q.pop();
            if((x-cur))par+=v[x-1];
            for(int i=0;(x|(1<<i))<=n+k;i++)
            {
                if(!vis[(x|(1<<i))])
                {
                    vis[(x|(1<<i))]=1;
                    q.push((x|(1<<i)));
                }
            }
        }
        v[cur-1]=par%2;
        rez.push_back(abs(par%2));
        cur<<=1;
    }
    reverse(rez.begin(),rez.end());
    return rez;
}

vector<int> retrieve(vector<int> data)
{
     vector<int>rez;
     int n=data.size();
     for(int i=1;i<=n;i*=2)
     {
        data.insert(data.begin()+i-1,abs(data[n-1]));
        data.pop_back();
     }
     int err=0;
     for(int i=1;i<=n;i++)
     {
         if(data[i-1])err^=i;
     }
     if(err)
     {
         data[err-1]^=1;
     }
    for(int i=1;i<=n;i++)
    {
        if((i&(i-1)))
        {
            rez.push_back(data[i-1]);
        }
    }
    return rez;
}
/*int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    vector<int> att=get_attachment(v);
    for(int i=0;i<att.size();i++)
    {
        //cout << att[i]<<' ';
        v.push_back(att[i]);
    }
    /*for(int i=0;i<v.size();i++)
    {
        cout << v[i]<<' ';
    }

   cout << endl;

v[6]=1-v[6];

vector<int> rez=retrieve(v);
    for(int i=0;i<rez.size();i++)
    {
        cout << rez[i]<<' ';
    }

    return 0;
}
*/
