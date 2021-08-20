#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;

typedef pair< int , int > pii;
unordered_map< int , vector< pii > > adjacentList;
bool visited[30007];

int maximum_distance, node_maximum;

void dfs(int x, long long int dist)
{
    visited[x] = true;
    if(dist>maximum_distance)
    {
        maximum_distance = dist;
        node_maximum = x;
    }
    for(auto v : adjacentList[x])
    {
        if(!visited[v.first])
            dfs(v.first,dist+v.second);
    }
}


int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    int test_cases = 0;
    while(tt--)
    {
        adjacentList.clear();

        int n; cin >> n;
        for(int i=0;i<n-1;i++)
        {
            int u,v,w; cin >> u >> v >> w;
            adjacentList[u].push_back(make_pair(v,w));
            adjacentList[v].push_back(make_pair(u,w));
        }
        maximum_distance = -INF;
        memset(visited,false,sizeof(visited));
        dfs(0,0LL);

        memset(visited,false,sizeof(visited));

        maximum_distance = -INF;
        //cout << node_maximum << endl;
        cout << "Case " << ++test_cases << ": ";
        dfs(node_maximum,0LL);

        cout << maximum_distance << endl;
    }
    return 0;
}
