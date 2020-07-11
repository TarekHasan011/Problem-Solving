#include<bits/stdc++.h>
using namespace std;
unordered_map< int , vector< int > > adjacentList;
bool visited[100010];
void dfs(int u)
{
    visited[u]=true;
    for(int v : adjacentList[u])
    {
        if(!visited[v])
            dfs(v);
    }
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan

    int tt; cin >> tt;
    while(tt--)
    {
        adjacentList.clear();
        int v,e; cin >> v >> e;

        for(int i=0;i<e;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }

        memset(visited,false,sizeof(visited));
        int counter = 0;

        for(int i=1;i<=v;i++)
        {
            if(!visited[i])
            {
                dfs(i);
                counter++;
            }
        }
        cout << counter << endl;
    }
}
