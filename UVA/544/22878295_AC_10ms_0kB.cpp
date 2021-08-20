///*** author: HM Imu SC ***\\\

#include<bits/stdc++.h>

using namespace std;

#define tillEnd() int t,testCase=1;scanf("%d",&t);while(t--)
#define FEO(container) for(auto ith : container)
#define FEIO(container) for(int i=0; i<container.size();i++)
#define showCase(str) cout<<"Case "<<testCase<<": "<<str<<endl;testCase++
#define read_auto() freopen("in.txt","r",stdin)
#define write_auto() freopen("out.txt","w",stdout)
#define read_write_auto() read_auto();write_auto()
#define to_order() ofstream order("test_cases.txt")
#define space << " " <<
#define get_random(a,b) rand()%(b-a+1)+a
#define lint long long int
#define INF(x) INT_MAX-x
#define boost_io() ios_base::sync_with_stdio(false);cin.tie(false)

map<string,string> parent;

void resetParents(vector<string> nodes){
    map<string,string> t_parent;
    for(string node : nodes){
        t_parent[node]=node;
    }
    parent = t_parent;
}

string findR(string node){
    if(parent[node]==node){
        return node;
    }
    parent[node] = findR(parent[node]);
    return parent[node];
}

bool valid(string nodeA,string nodeB){

    string rA = findR(nodeA);
    string rB = findR(nodeB);

    if(rA!=rB){
        parent[rA]=rB;
    }

    return !(rA==rB);
}

int extract_min_load(map<string,vector<pair<string,int> > > adjList,string parent,string current_node,string destination,int min_so_far){

//    cout<<"P: "<<parent<<" C: "<<current_node<<" D: "<<destination<<" M: "<<min_so_far<<endl;

    if(current_node==destination){
        return min_so_far;
    }

    vector<pair<string,int> > adjs = adjList[current_node];

    for(pair<string,int> e : adjs){

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

int main(){

//    read_auto();

    int n,r,c=1;

    while(cin>>n>>r && n+r!=0){

        vector<pair<int,pair<string,string> > > edges;
        map<string, bool> old_node;
        vector<string> nodes;
        string u,v,s,t;
        int w;

        while(r--){

            cin>>u>>v>>w;

            edges.push_back(make_pair(w,make_pair(u,v)));

            if(!old_node[u]){
                old_node[u] = true;
                nodes.push_back(u);
            }

            if(!old_node[v]){
                old_node[v] = true;
                nodes.push_back(v);
            }
        }

        int total_node = nodes.size();
        int tree_edge = 0;

        sort(edges.begin(),edges.end(), greater<pair<int,pair<string,string> > >());

        resetParents(nodes);

        map<string,vector<pair<string,int> > >adjList;

        FEO(edges){
            u = ith.second.first;
            v = ith.second.second;
            w = ith.first;

            if(valid(ith.second.first,ith.second.second)){
                adjList[u].push_back(make_pair(v,w));
                adjList[v].push_back(make_pair(u,w));
                if(++tree_edge == total_node-1){
                    break;
                }
            }
        }

        cin>>s>>t;

        int max_load = extract_min_load(adjList,"<no parent>",s,t,edges[0].first);

        cout<<"Scenario #"<<c++<<endl;

        cout<<max_load<<" tons\n"<<endl;
    }


    return 0;
}
