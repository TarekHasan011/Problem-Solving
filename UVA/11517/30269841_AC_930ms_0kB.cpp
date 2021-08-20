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

typedef pair<int, int> pr;
typedef pair<int, pr> d_pr;

vector<int> g_coins;
pair<int, int> cache[10101][10101];
int cache_checker[10101][10101];

pair<int, int> take_change(int change, int last_used){
    if(change <= 0){
        return make_pair(0, 0);
    }

    if(last_used != -1 && cache_checker[change][last_used] == 1){
        return cache[change][last_used];
    }

    pair<int, int> min_change = make_pair(99999999, 99999999);

    for(int i=last_used + 1; i<g_coins.size(); i++){
        pair<int, int> min_change_now = take_change(change - g_coins[i], i);
        if((min_change_now.first + g_coins[i]) < min_change.first){
            min_change.first = min_change_now.first + g_coins[i];
            min_change.second = min_change_now.second + 1;
        }
        else if((min_change_now.first + g_coins[i]) == min_change.first && ((min_change_now.second + 1) < min_change.second)){
            min_change.second = min_change_now.second + 1;
        }
    }
    cache[change][last_used] = min_change;
    cache_checker[change][last_used] = 1;
    return min_change;
}

int main(){

//    read_auto();
//    write_auto();

    int t;
    cin>>t;

    while(t--){
        int change;
        cin>>change;

        int n;
        cin>>n;

        vector<int> coins;
        int coin;

        while(n--){
            cin>>coin;
            coins.push_back(coin);
        }

        g_coins = coins;
        int used[g_coins.size() + 10] = {0};
//        for(int i=0; i<10101; i++){
//            cache[i] = make_pair(-1, -1);
//        }

        memset(cache_checker, 0, sizeof(cache_checker));

        pair<int, int> min_change = take_change(change, -1);
        cout<<min_change.first<<" "<<min_change.second<<"\n";
    }

    return 0;
}

