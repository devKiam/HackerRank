#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void bfs(ll start, vector<ll> adjList[], vector<ll> &dis, vector<ll> &parent)
{
    queue<ll> q;
    q.push(start);
    dis[start] = 0;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        for(int i=0; i < adjList[u].size(); i++)
        {
            int v = adjList[u][i];

            if(dis[v]==-1)
            {
                dis[v] = dis[u] + 6;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));

   ll tc; cin>>tc;

   while(tc--)
   {
       vector<ll> adjList[1010];
       vector<ll> dis(1010, -1);
       vector<ll> parent(1010, -1);

       ll nodes, edges; cin>>nodes>>edges;

       for(int i=1; i<=edges; i++)
       {
           ll u, v; cin>>u>>v;
           adjList[u].push_back(v);
           adjList[v].push_back(u);
       }

       ll start; cin>>start;

       bfs(start, adjList, dis, parent);

       for(int i = 1; i <= nodes; i++)
       {
           if(dis[i] == 0) continue;
           cout<<dis[i]<<" ";
       }
       cout<<endl;
   }

}
