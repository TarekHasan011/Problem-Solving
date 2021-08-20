#include<bits/stdc++.h>
using namespace std;

const long long int INF = 1e15+7;
typedef pair< long long int , long long int > pii;

unordered_map< long long int , vector< pair< long long int , long long int > > > adjacentList;
long long int dist[107];


void dijkstra(long long int s)
{
    priority_queue< pii, vector< pii > , greater< pii > > pq;
    pq.push(make_pair(0LL,s));
    dist[s] = 0LL;

    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();

        for(auto x : adjacentList[top.second])
        {
            if(dist[x.first]>x.second+top.first)
            {
                dist[x.first] = x.second + top.first;
                pq.push(make_pair(dist[x.first],x.first));
            }
        }
    }
    return;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    long long int tt; cin >> tt;

    while(tt--)
    {
        getchar();
        adjacentList.clear();

        long long int n,e,t,m; cin >> n >> e >> t >> m;
        for(long long int i=0;i<m;i++)
        {
            long long int u,v,w; cin >> u >> v >> w;
            adjacentList[v].push_back(make_pair(u,w));
        }

        for(long long int i=1;i<=n;i++)
            dist[i] = INF;
        dijkstra(e);
        long long int counter = 0;

        for(long long int i=1;i<=n;i++)
        {
            if(dist[i]<=t)
                counter++;
        }
        cout << counter << endl;

        if(tt)
            cout << endl;
    }

    return 0;
}
