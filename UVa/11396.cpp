#include<bits/stdc++.h>
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;
int color[310];
bool bicoloring(unordered_map< int , vector< int > > adjacentList, int source)
{
    queue< int > q;
    q.push(source);
    color[source] = RED;

    while(!q.empty())
    {
        int top = q.front();
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
            else if(color[x]==color[top])
                return false;
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

    int vertex;
    while(cin >> vertex && vertex)
    {
        int u,v;
        unordered_map< int, vector< int > > adjacentList;

        while(cin >> u >> v && u && v)
        {
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }

        memset(color,WHITE,sizeof(color));

        bool possible = true;
        for(int i=1;i<=vertex;i++)
        {
            if(color[i]==WHITE)
            {
                if(!bicoloring(adjacentList,i))
                {
                    possible = false;
                    break;
                }
            }
        }

        possible ? cout << "YES\n" : cout << "NO\n";

    }
}
