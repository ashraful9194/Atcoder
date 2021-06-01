#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int cnt[1000007];
const int p=998244353;
int ans[1000005];
int power(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        b=b/2;
        a=(a*a)%p;
    }
    return res;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin>>n;
     for(int i=0; i<n; i++)
     {
         int x;
         cin>>x;
         ++cnt[x];
     }
     ///First of all store the sum of the multiplication of  all pairs whose common factor is i......
     ///ans[4]=4+8+12+16+20+.........
     for(int i=1; i<=1000000; i++)
     {
         int pref=0;///Summation of elements whose factor is (i) found so far.....
         for(int j=i; j<=1000000; j+=i)
         {
              int x=(pref*j)%p;
              x=(x*cnt[j])%p;
             ans[i]=(ans[i]+x)%p;
             int y=(cnt[j]*(cnt[j]-1))/2;
             y%=p;
             x=(j*j)%p;
             x=(x*y)%p;
             ans[i]=(ans[i]+x)%p;///For own-self....(i,i,i,i,i,i)..
             pref+=(cnt[j]*j)%p;
             pref%=p;
         }
     }
     int res=0;
     for(int i=1000000; i>=1; i--)
     {
         for(int j=i*2; j<=1000000; j+=i)
         {
             ans[i]=(ans[i]-ans[j]+p)%p;///substract those summation who are the multiple of i ...
             ///And thus we will only left with summation of gcd==i.....
         }
         res+=(ans[i]*power(i,p-2))%p;///divide by gcd i.....
         res%=p;
     }
     cout<<res%p<<endl;
}
