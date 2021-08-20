#include<bits/stdc++.h>
using namespace std;
struct result{
    int person_number, day;
};

bool compare(result a, result b)
{
    if(a.person_number==b.person_number)
        return a.day<b.day;
    else
        return a.person_number>b.person_number;
}


int dist[2505];
int employees;
unordered_map< int , vector< pair< int , int > > > adjacentList;

void dijkstra(int start)
{
    memset(dist,-1,sizeof(dist));

    priority_queue< pair< int , int > , vector< pair < int , int > > , greater< pair< int , int >> > pq;
    pq.push(make_pair(0,start));
    dist[start]=0;

    while(!pq.empty())
    {
        pair< int , int > top = pq.top();
        pq.pop();

        for(pair< int , int > x : adjacentList[top.second])
        {
            if(dist[x.first]==-1 || dist[x.first]>x.second+top.first)
            {
                dist[x.first] = x.second + top.first;
                pq.push(make_pair(dist[x.first],x.first));
            }
        }
    }

}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    cin >> employees;

    for(int i=0;i<employees;i++)
    {
        int f; cin >> f;
        while(f--)
        {
            int v; cin >> v;
            adjacentList[i].push_back(make_pair(v,1));
        }
    }

    int tt; cin >> tt;

    while(tt--)
    {
        int source; cin >> source;
        dijkstra(source);
        unordered_map< int , int > mp;
        for(int i=0;i<employees;i++)
        {
            if(dist[i]>0)
            {
                mp[dist[i]]++;
            }
        }

        if(mp.size()==0)
        {
            cout << "0\n";
            continue;
        }


        vector< result > v;
        for(auto x : mp)
        {
            result r;
            r.day=x.first;
            r.person_number=x.second;
            v.push_back(r);
        }
        sort(v.begin(),v.end(),compare);



        cout << v[0].person_number << " " << v[0].day << endl;

    }


}
