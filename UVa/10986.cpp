#include<bits/stdc++.h>
using namespace std;
int dist[20010];
typedef pair< int , int > pii;
void dijkstra(unordered_map<int , vector< pii > > adjacentList, int source)
{
    memset(dist,-1,sizeof(dist));
    priority_queue< pii, vector<pii> , greater<pii> > pq;
    pq.push(make_pair(0,source));
    dist[source]=0;

    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();

        for(pii x : adjacentList[top.second])
        {
            if(dist[x.first]==-1 || dist[x.first]>x.second+top.first)
            {
                dist[x.first]=x.second+top.first;
                pq.push(make_pair(dist[x.first],x.first));
            }
        }
    }
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int Cases = 0;

    int tt; cin >> tt;

    while(tt--)
    {
        int n,e,s,d; cin >> n >> e >> s >> d;

        unordered_map< int , vector< pii > > adjacentList;

        for(int i=0;i<e;i++)
        {
            int u,v,w; cin >> u >> v >> w;
            adjacentList[u].push_back(make_pair(v,w));
            adjacentList[v].push_back(make_pair(u,w));
        }
        dijkstra(adjacentList,s);

        cout << "Case #" << ++Cases << ": ";
        dist[d]==-1? cout << "unreachable\n" : cout << dist[d] << endl;
    }

    return 0;
}
