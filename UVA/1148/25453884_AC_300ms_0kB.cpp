#include<bits/stdc++.h>
using namespace std;
int dist[100010];
unordered_map< int , vector< pair<int , int > > > adjacentList;
void dijkstra(int source)
{
    memset(dist,-1,sizeof(dist));
    priority_queue< pair< int , int > , vector< pair< int , int > > , greater< pair< int , int > > > pq;
    pq.push(make_pair(0,source));
    dist[source]=0;

    while(!pq.empty())
    {
        pair< int , int > top = pq.top();
        pq.pop();

        for(pair< int , int > x : adjacentList[top.second])
        {
            if(dist[x.first]==-1 || dist[x.first]>top.first+x.second)
            {
                dist[x.first]=top.first+x.second;
                pq.push(make_pair(dist[x.first],x.first));
            }
        }
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
        getchar();
        adjacentList.clear();

        int vertices; cin >> vertices;

        for(int i=0;i<vertices;i++)
        {
            int u; cin >> u;
            int nodes; cin >> nodes;
            while(nodes--)
            {
                int v; cin >> v;
                adjacentList[u].push_back(make_pair(v,1));
            }
        }
        int source, destination; cin >> source >> destination;

        dijkstra(source);
        cout << source << " " << destination << " " << dist[destination]-1 << endl;
        if(tt) cout << endl;
    }

    return 0;
}
