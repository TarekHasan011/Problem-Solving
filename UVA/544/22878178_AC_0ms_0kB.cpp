#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int source;
    int destination;
    int weight;
};
vector< Edge > temp;
bool compare(Edge a, Edge b)
{
    return a.weight>b.weight;
}
int parent[220];
void make_set(int n)
{
    for(int i=0;i<=n;i++)
        parent[i]=i;
}
int Find(int x)
{
    if(parent[x]==x) return x;
    else return parent[x] = Find(parent[x]);
}
bool Union(int a, int b)
{
    int u=Find(a);
    int v= Find(b);
    if(u==v) return false;
    else parent[u]=v;
    return true;
}
void MST(vector< Edge > v, int vartex)
{
    int counter=0;
    for(int i=0;i!=v.size();i++)
    {
        if(Union(v[i].source,v[i].destination))
        {
            counter++;
            Edge e; e.source=v[i].source;
            e.destination=v[i].destination;
            e.weight=v[i].weight;
            temp.push_back(e);
            if(counter==vartex-1) break;
        }
    }
}

int extract_min_load(map<int,vector<pair<int,int> > > adjList,int parent,int current_node,int destination,int min_so_far = INT_MAX){

//    cout<<"P: "<<parent<<" C: "<<current_node<<" D: "<<destination<<" M: "<<min_so_far<<endl;

    if(current_node==destination){
        return min_so_far;
    }

    vector<pair<int,int> > adjs = adjList[current_node];

    for(pair<int,int> e : adjs){

        if(e.first == parent){
            continue;
        }

        int t_m = min(min_so_far, e.second);

        int m = extract_min_load(adjList,current_node,e.first,destination,t_m);

        if(m!=-1){
            return m;
        }
    }

    return -1;
}

int main()
{
//    #ifdef TarekHasan
//        freopen("in.txt","r",stdin);
//    #endif // TarekHasan

    int vartices, edges, c = 1;
    while(cin >> vartices >> edges && vartices && edges)
    {
        temp.clear();
        make_set(vartices);
        vector<Edge> v(edges);
        unordered_map< string , int > mp;
        int k=1;
        for(int i=0;i<edges;i++)
        {
            string s; string d; int w;
            cin >> s >> d >> w;
            if(!mp[s]) { mp[s]=k;v[i].source = k++; }
            else v[i].source=mp[s];
            if(!mp[d]){  mp[d]=k; v[i].destination= k++;}
            else v[i].destination=mp[d];
            v[i].weight=w;
        }
        string str1;string str2;  cin >> str1 >> str2;
        int source = mp[str1]; int destination=mp[str2];
        sort(v.begin(),v.end(),compare);
        MST(v,vartices);
        map< int , vector< pair < int , int > > > mp2;
        for(int i=0;i!=temp.size();i++)
        {
            mp2[temp[i].source].push_back(make_pair(temp[i].destination,temp[i].weight));
            mp2[temp[i].destination].push_back(make_pair(temp[i].source,temp[i].weight));
        }

        int max_load = extract_min_load(mp2, -1, source, destination);

        cout<<"Scenario #"<<c++<<endl;

        cout<<max_load<<" tons\n"<<endl;

    }
    return 0;
}
