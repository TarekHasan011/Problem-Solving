#include<bits/stdc++.h>
using namespace std;
unordered_map< int , vector< int > > adjacentList;
bool visited[10007];
void dfs(int n)
{
    visited[n] = true;
    for(int x : adjacentList[n])
    {
        if(!visited[x])
            dfs(x);
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
        getchar();
        adjacentList.clear();
        int n,e; cin >> n >> e;
        for(int i=0;i<e;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
        }
        for(int i=1;i<=n;i++) visited[i] = false;
        vector< int > candidate_roots;

        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                dfs(i);
                candidate_roots.push_back(i);
            }
        }
        reverse(candidate_roots.begin(),candidate_roots.end());
        for(int i=1;i<=n;i++) visited[i] = false;
        int counter = 0;
        for(int x : candidate_roots)
        {
            if(!visited[x])
            {
                dfs(x);
                counter++;
            }
        }
        cout << "Case " << ++test_cases << ": ";
        cout << counter << endl;
    }

    return 0;
}
