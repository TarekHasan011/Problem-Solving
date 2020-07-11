//Wrong answer

#include<bits/stdc++.h>
using namespace std;
void topSort(vector< string > &order, vector< string > vertices,unordered_map< string , vector< string > > adjacentList,unordered_map< string , int > incoming_edge)
{
    queue< string > q;
    for(string s : vertices)
    {
        if(incoming_edge[s]==0)
            q.push(s);
    }

    while(!q.empty())
    {
        string top = q.front();
        q.pop();
        order.push_back(top);

        for(string x : adjacentList[top])
        {
            incoming_edge[x]--;
            if(incoming_edge[x]==0)
                q.push(x);
        }
    }

    return;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int v;
    int cases = 0;

    while(cin >> v)
    {
        vector< string > vertices(v);
        for(int i=0;i<v;i++)
            cin >> vertices[i];
        int e; cin >> e;

        unordered_map< string , vector< string > > adjacentList;
        unordered_map< string , int > incoming_edge;

        for(int i=0;i<e;i++)
        {
            string u, v;
            cin >> u >> v;
            adjacentList[u].push_back(v);
            incoming_edge[v]++;
        }

        vector< string > order;
        topSort(order,vertices,adjacentList,incoming_edge);

        cout << "Case #" << ++cases << ": Dilbert should drink beverages in this order: " ;
        for(int i=0;i!=order.size();i++)
        {
            cout << order[i];
            if(i==order.size()-1)
                cout << ".\n";
            else
                cout << " ";
        }

        getchar();
    }
}
