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
int n,m;
#define boundary(i,j) (i>=1 && i<=n && j>=1 && j<=m)
int X[]={1,0,0};
int Y[]={0,1,-1};
int col[505][505];
int row[505][505];
int cost[505][505];
void dijkstra(int x,int y)///Greedy+dijkstra
{
    priority_queue<pair<int,pii>>pq;
    pq.push({0,{x,y}});
    cost[x][y]=0;

    while(!pq.empty())
    {
        pair<int,pii>p=pq.top();
        pq.pop();
        int i=p.second.first;
        int j=p.second.second;
        int val=p.first;
        if(i==n && j==m)
        {
            cout<<-val<<endl;
            return;
        }
       if(boundary(i,j-1) && cost[i][j-1]>-val+col[i][j-1])
       {
           cost[i][j-1]=-val+col[i][j-1];
           pq.push({-cost[i][j-1],{i,j-1}});
       }
       if(boundary(i+1,j) && cost[i+1][j]>-val+row[i][j])
       {
           cost[i+1][j]=-val+row[i][j];
            pq.push({-cost[i+1][j],{i+1,j}});
       }
       if(boundary(i,j+1) && cost[i][j+1]>-val+col[i][j])
       {
           cost[i][j+1]=-val+col[i][j];
           pq.push({-cost[i][j+1],{i,j+1}});
       }
        for(int k=1; k<i; k++)///take greedily
          {

              if(cost[i-k][j]<-val+k+1) break;///if cost[i-k][j] is small then we can get or has already got
              /// a better answer from (i-k,j)  instead of (i,j)
              ///to any upper square..

           cost[i-k][j]=-val+k+1;
           pq.push({-cost[i-k][j],{i-k,j}});
          }
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>m;
     for(int i=1; i<=n; i++)
        for(int j=1; j<m; j++)
        cin>>col[i][j];

      for(int i=1; i<n; i++)
        for(int j=1; j<=m; j++)
        cin>>row[i][j];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            cost[i][j]=1e17;
        dijkstra(1,1);
}
