#include<bits/stdc++.h>
using namespace std;
bool visited[100010];
unordered_map< int , vector< int > > adjacentList;
vector< int > order;
void dfs(int u)
{
    visited[u]=true;
    for(int v : adjacentList[u])
    {
        if(!visited[v])
            dfs(v);
    }
    order.push_back(u);
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int tt; cin >> tt;

    while(tt--)
    {
        adjacentList.clear();
        order.clear();

        int v,e; cin >> v >> e;

        for(int i=0;i<e;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
        }

        memset(visited,false,sizeof(visited));

        for(int i=1;i<=v;i++)
        {
            if(!visited[i])
                dfs(i);
        }
        reverse(order.begin(),order.end());

        memset(visited,false,sizeof(visited));

        int counter = 0;
        for(int i=0;i<v;i++)
        {
            if(!visited[order[i]])
            {
                dfs(order[i]);
                counter++;
            }
        }
        cout << counter << endl;
    }
}
