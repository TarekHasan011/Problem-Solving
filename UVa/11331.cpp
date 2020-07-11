#include<bits/stdc++.h>
#define EMPTY 0
#define BULL 1
#define COW 2
using namespace std;

int color[2010];

bool bicoloring(unordered_map< int , vector< int > > adjacentList, int source)
{
    queue< int > q;
    q.push(source);
    color[source] = BULL;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(int x : adjacentList[top])
        {
            if(color[x]==EMPTY)
            {
                if(color[top]==BULL)
                    color[x] = COW;
                else color[x] = BULL;

                q.push(x);
            }
            else if(color[x]==color[top]) return false;
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

    int tt; cin >> tt;

    while(tt--)
    {
        int bull,cow,edge; cin >> bull >> cow >> edge;
        unordered_map< int , vector< int > > adjacentList;
        for(int i=0;i<edge;i++)
        {
            int u,v; cin >> u >> v;
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }
        for(int i=1;i<=bull+cow;i++) color[i]=EMPTY;

        bool peace = true;

        for(int i=1;i<=bull+cow;i++)
        {
            if(color[i]==EMPTY && adjacentList[i].size()!=0)
            {
                if(bicoloring(adjacentList,i)) continue;
                else
                {
                    peace = false;
                    break;
                }
            }
        }

        if(peace)
        {
            int b = 0 , c = 0;
            for(int i=1;i<=bull+cow;i++)
            {
                if(color[i]==BULL) b++;
                else if(color[i]==COW) c++;
            }

            if(b<c) swap(b,c);
            if(bull<cow) swap(bull,cow);

            if(b<=bull && c<=cow) cout << "yes\n";
            else cout << "no\n";
        }
        else cout << "no\n";


    }
}
