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
#include<time.h>

using namespace std;

#define read_auto() freopen("in.txt","r",stdin)
#define write_auto() freopen("out.txt","w",stdout)
#define lint long long int
#define all_of(container) container.begin(), container.end()
#define MOD 1000000009
#define BASE 6959
#define PI 3.14159265359

int main(){

//    read_auto();
//    write_auto();
//    clock_t __start_time = clock();

    int n_prob;
    scanf("%d", &n_prob);

    int prob_min_time_req = 0;
    int prob_time;
    while(n_prob--){
        cin>>prob_time;
        prob_min_time_req+=prob_time;
    }

    int m;
    scanf("%d", &m);

    int lj, rj;

    bool solved = false;

    while(m--){
        scanf("%d%d", &lj, &rj);
        if(prob_min_time_req>=lj && prob_min_time_req<=rj && !solved){
            printf("%d\n", prob_min_time_req);
            solved = true;
        }
        else if(prob_min_time_req<lj && !solved){
            printf("%d\n", lj);
            solved = true;
        }
    }

    if(!solved){
        printf("-1\n");
    }

//    cout<<"[+] Time taken: "<<clock()-__start_time<<" ms"<<endl;
    return 0;
}