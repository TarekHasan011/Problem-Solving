#include<bits/stdc++.h>
using namespace std;
int source_to_all_other[107];
int destination_to_all_other[107];
int visited[107];
map< int , vector< int > > adjacentList;

void bfs(int source, int control)
{
    memset(visited,0,sizeof(visited));
    queue< int > q;
    q.push(source);
    visited[source] = 1;
    if(control==0)
        source_to_all_other[source] = 0;
    else
        destination_to_all_other[source] = 0;

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(int x : adjacentList[top])
        {
            if(visited[x]==0)
            {
                visited[x] = 1;
                q.push(x);
                if(control==0)  source_to_all_other[x] = source_to_all_other[top]+1;
                else destination_to_all_other[x] = destination_to_all_other[top]+1;
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

    int tt; cin >> tt;
    int test_case = 0;
    while(tt--)
    {
        adjacentList.clear();
        int n,e; cin >> n >> e;
        for(int i=0;i<e;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }
        int source,destination; cin >> source >> destination;
        memset(source_to_all_other,0,sizeof(source_to_all_other));
        memset(destination_to_all_other,0,sizeof(destination_to_all_other));

        bfs(source,0); bfs(destination,1);
        int answer = 0;
        for(int i=0;i<n;i++)
            answer = max(answer,source_to_all_other[i]+destination_to_all_other[i]);
        cout << "Case " << ++test_case << ": " << answer << endl;
    }

    return 0;
}
