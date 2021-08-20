///*** author: HM Imu SC ***\\\

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<list>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>

using namespace std;

#define tillEnd() int t;scanf("%d",&t);while(t--)
#define _fr(n) while(n--)
#define _for(i, n) for(int i=0; i<n; i++)
#define _fore(x, container) for(auto x : container)
#define read_auto() freopen("in.txt","r",stdin)
#define write_auto() freopen("out.txt","w",stdout)
#define space << " " <<
#define lint long long int
#define INF(x) INT_MAX-x
#define boost_io() ios_base::sync_with_stdio(false);cin.tie(false)
#define all_of(container) container.begin(), container.end()
#define pr3(a, b, c) d_pr(a, pr(b, c))
#define _first first
#define _second second.first
#define _third second.second
#define MOD 1000000009
#define BASE 6959
#define INT_MAX 2000000000

typedef pair<int, int> pr;
typedef pair<int, pr> d_pr;

struct edge{
    int u,v,w;
};

int main(){

//    read_auto();

    int t;
    cin>>t;
    while(t--){
        vector<edge> edges;
        vector<int> dist;
        int n,m;
        cin>>n>>m;
        dist.resize(n,INT_MAX);
        dist[0]=0;

        while(m--){
            edge e;
            cin>>e.u>>e.v>>e.w;
            edges.push_back(e);
        }

        bool possible=false;
        for(int i=1;i<n;i++){
            for(edge e : edges){
                if(dist[e.v]>dist[e.u]+e.w){
                    dist[e.v]=dist[e.u]+e.w;
                }
            }
        }

        for(edge e : edges){
            if(dist[e.v]>dist[e.u]+e.w){
                possible=true;
                break;
            }
        }

        if(possible){
            cout<<"possible"<<endl;
        }
        else{
            cout<<"not possible"<<endl;
        }
    }

    return 0;
}
