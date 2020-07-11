#include<bits/stdc++.h>
using namespace std;
int vertices , edges;
unordered_map< int , vector< int > > adjacentList;
unordered_map< int , int > incoming_edges;
vector< int > order;

void topologicalSort()
{
    queue< int > q;
    for(int i=1;i<=vertices;i++)
    {
        if(incoming_edges[i]) continue;
        q.push(i);
    }

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        order.push_back(top);

        for(int x : adjacentList[top])
        {
            incoming_edges[x]--;

            if(incoming_edges[x]==0)
                q.push(x);
        }
    }
}

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

        order.clear();incoming_edges.clear();adjacentList.clear();

        cin >> vertices >> edges;
        for(int i=0;i<edges;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
            incoming_edges[v]++;
        }
        topologicalSort();

        memset(visited,false,sizeof(visited));
        int counter = 0;

        for(int x : order)
        {
            if(!visited[x])
            {
                dfs(x);
                counter++;
            }
        }
        cout << counter << endl;
    }
}
