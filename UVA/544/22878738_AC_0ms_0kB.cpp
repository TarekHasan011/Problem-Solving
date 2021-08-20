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

int parent[210];

void resetParents(int nodes){
    for(int i=0;i<nodes;i++){
        parent[i]=i;
    }
}

int findR(int node){
    if(parent[node]==node){
        return node;
    }
    parent[node] = findR(parent[node]);
    return parent[node];
}

bool valid(int nodeA,int nodeB){

    int rA = findR(nodeA);
    int rB = findR(nodeB);

    if(rA!=rB){
        parent[rA]=rB;
    }

    return !(rA==rB);
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

bool cmp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
    return a.first>b.first;
}

int main(){

//    read_auto();

    int n,r,c=1;

    while(cin>>n>>r && n+r!=0){

        vector<pair<int,pair<int,int> > > edges;
        int w,s,t,total_node = 0,tree_edge = 0;
        map<string, int> node_map;
        string u,v;

        while(r--){

            cin>>u>>v>>w;

            if(!node_map[u]){
                node_map[u] = total_node++;
            }

            if(!node_map[v]){
                node_map[v] = total_node++;
            }

            edges.push_back(make_pair(w, make_pair(node_map[u], node_map[v])));
        }

        sort(edges.begin(),edges.end(), cmp);

        resetParents(total_node);

        map<int,vector<pair<int,int> > > adjList;

        FEO(edges){
            s = ith.second.first;
            t = ith.second.second;
            w = ith.first;

            if(valid(ith.second.first,ith.second.second)){
                adjList[s].push_back(make_pair(t,w));
                adjList[t].push_back(make_pair(s,w));
                if(++tree_edge == total_node-1){
                    break;
                }
            }
        }

        cin>>u>>v;

        s = node_map[u];
        t = node_map[v];

        int max_load = extract_min_load(adjList,-1,s,t);

        cout<<"Scenario #"<<c++<<endl;

        cout<<max_load<<" tons\n"<<endl;
    }


    return 0;
}
