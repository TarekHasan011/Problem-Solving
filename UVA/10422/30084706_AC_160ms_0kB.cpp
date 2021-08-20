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

int dx[]= {2,-2,2,-2,-1,1,-1,1};
int dy[]= {1,1,-1,-1,2,2,-2,-2};

struct source
{
    int src[5][5];
    int x;
    int y;
    int dist;
};

int ar[5][5]= {1,1,1,1,1,
               0,1,1,1,1,
               0,0,9,1,1,
               0,0,0,0,1,
               0,0,0,0,0
              };

bool target_check(source x)
{
    int i,j;
    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            if(x.src[i][j]!=ar[i][j])
                return false;
    if(i+j==10)
        return true;
}

bool validity(int x,int y)
{
    if(x>=0 && x<5 && y>=0 && y<5)
        return true;
    else
        return false;
}

int main()
{
    int t=2;

    char test[2];

    cin>>t;
    gets(test);

    while(t--)
    {
        source s;
        for(int i=0; i<5; i++)
        {
            char temp[5];
            gets(temp);
            for(int j=0; j<5; j++)
            {
                if(temp[j]!=' ')
                    s.src[i][j]=temp[j]-'0';
                else
                {
                    s.src[i][j]=9;
                    s.x=i;
                    s.y=j;
                }
            }
        }

        if(target_check(s))
        {
            cout<<"Solvable in 0 move(s).\n";
            continue;
        }

        s.dist=0;
        bool ck=false;
        queue<source> bfs;
        bfs.push(s);

        while(!bfs.empty())
        {
            source top;
            top=bfs.front();
            bfs.pop();


            for(int i=0; i<8; i++)
            {
                if(validity(top.x+dx[i],top.y+dy[i]))
                {
                    source temp;
                    temp=top;
                    temp.src[temp.x][temp.y]=temp.src[top.x+dx[i]][top.y+dy[i]];
                    temp.src[top.x+dx[i]][top.y+dy[i]]=9;
                    temp.x=top.x+dx[i];
                    temp.y=top.y+dy[i];
                    temp.dist=top.dist+1;

                    if(target_check(temp))
                    {
                        cout<<"Solvable in "<<temp.dist<<" move(s)."<<endl;
                        //cout<<bfs.size()<<endl;
                        ck=true;
                        break;
                    }

                    if(temp.dist<10)
                        bfs.push(temp);

                }
            }
            if(ck)
                break;
        }
        if(!ck)
        {
            cout<<"Unsolvable in less than 11 move(s)."<<endl;
        }
    }
    return 0;
}
