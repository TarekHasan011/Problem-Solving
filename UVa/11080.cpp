#include<bits/stdc++.h>
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;
int color[201];
int bicoloring(unordered_map< int , vector< int > > adjacentList, int source)
{
    queue< int > q;
    color[source]=RED;
    q.push(source);

    int red = 0;
    int blue = 0;

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        if(color[top]==RED) red++;
        else blue++;

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
                return -1;
        }
    }

    if(blue==0) return red;
    else if(red==0) return blue;
    else return min(red,blue);

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
        memset(color,WHITE,sizeof(color));

        int vertices , edges ; cin >> vertices >> edges;
        unordered_map< int , vector< int > > adjacentList;

        for(int i=0;i<edges;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }

        bool possible = true;

        int min_guard = 0;

        for(int i=0;i<vertices;i++)
        {
            if(color[i]==WHITE)
            {
                int temp = bicoloring(adjacentList,i);
                if(temp==-1)
                {
                    possible = false;
                    break;
                }
                else
                    min_guard+=temp;
            }
        }

        possible ? cout << min_guard << "\n" : cout << "-1\n";
    }
    return 0;
}
