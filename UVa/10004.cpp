#include<bits/stdc++.h>
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

bool bicoloring(unordered_map< int , vector< int > > adjacentList,int source, int vertices)
{
    int color[vertices]={WHITE};

    queue< int > q;
    q.push(source);
    color[source]=RED;

    while(!q.empty())
    {
        int top =q.front();
        q.pop();

        for(int x : adjacentList[top])
        {
            if(color[x]==WHITE)
            {
                if(color[top]==RED)
                    color[x]=BLUE;
                else
                    color[x]=RED;
                q.push(x);
            }

            if(color[x]==color[top]) return false;
        }
    }
    return true;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan

    int n;
    while(cin >> n && n)
    {
        int edges; cin >> edges;

        unordered_map< int , vector< int > > adjacentList;

        for(int i=0;i<edges;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }

        bicoloring(adjacentList,0,n) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
