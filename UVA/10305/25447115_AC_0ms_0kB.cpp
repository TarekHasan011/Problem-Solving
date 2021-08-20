#include<bits/stdc++.h>
using namespace std;
unordered_map< int , int > incoming_edges;
unordered_map< int , vector< int > > adjacentList;
vector< int > order;
int vertices , edges;

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

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    while(cin >> vertices >> edges)
    {
        if(!vertices && !edges) break;

        order.clear();
        incoming_edges.clear();
        adjacentList.clear();

        for(int i=0;i<edges;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
            incoming_edges[v]++;
        }

        topologicalSort();

        for(int x : order)
            cout << x <<  " ";
        cout << endl;

    }

    return 0;
}
