#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int adj[20];
int ok[1<<18];
int ans[1<<18];
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     fill(ans,ans+(1<<18),1e17);
     cin>>n>>m;
     for(int i=0; i<m; i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x-1]|=(1<<(y-1));
         adj[y-1]|=(1<<(x-1));
     }
     ok[0]=1;
    for(int msk=1; msk<(1<<n); msk++)
    {
        for(int j=0; j<n; j++)
        {
            int x=(1<<j);
            if((x&msk))
            {
                if(!ok[msk^x]) break;
                if((adj[j]&(msk^x))!=(msk^x)) break;
                ok[msk]=1;
                break;
            }
        }
    }
    for(int msk=1; msk<(1<<n); msk++)
    {
        int s=msk;
        if(ok[s]) ans[s]=1;
        while(1)///iterating over submasks
        {
            int rem=(msk^s);
            ans[msk]=min(ans[msk],ans[s]+ans[rem]);
            if(s==0) break;
            s=((s-1)&msk);
        }
    }
    cout<<ans[(1<<n)-1]<<endl;
}
