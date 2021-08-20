#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
};
int parent[200007];
void SET(int n)
{
    for(int i=0;i<n;i++)
        parent[i] = i;
}
int FIND(int x)
{
    if(parent[x]==x) return x;
    else return parent[x] = FIND(parent[x]);
}
bool UNION(int u, int v)
{
    int a = FIND(u);
    int b = FIND(v);

    if(a!=b)
    {
        parent[a] = b;
        return true;
    }
    else
        return false;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    while(cin >> n >> m && n && m)
    {
        vector< edge > v(m);
        long long int prev = 0;
        for(int i=0;i<m;i++)
        {
            cin >> v[i].u >> v[i].v >> v[i].w;
            prev+=v[i].w;

        }
        sort(v.begin(),v.end(),[&](edge a, edge b)
             {
                return a.w<b.w;
             });
        SET(n);
        long long int sum = 0;
        for(edge e : v)
            sum += (UNION(e.u,e.v) ? e.w : 0);
        cout << prev-sum << endl;
    }


    return 0;
}
