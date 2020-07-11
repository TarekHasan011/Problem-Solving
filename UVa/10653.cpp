#include<bits/stdc++.h>
using namespace std;
int grid[1002][1002];
int visited[1002][1002];
int dist[1002][1002];
int row,column;

int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

typedef pair< int ,  int > pii;

bool valid(int i, int j)
{
    if(i<0 || i>=row || j<0 || j>=column || grid[i][j]==1)
        return false;
    else return true;
}

int bfs(pii source, pii destination)
{
    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));

    queue< pii> q;
    q.push(source);
    visited[source.first][source.second]=1;

    while(!q.empty())
    {
        pii top = q.front();
        q.pop();

        if(top.first==destination.first && top.second==destination.second)
            return dist[top.first][top.second];

        for(int i=0;i<4;i++)
        {
            int new_i = top.first+dx[i];
            int new_j = top.second+dy[i];

            if(valid(new_i,new_j) && visited[new_i][new_j]==0)
            {
                q.push(make_pair(new_i,new_j));
                dist[new_i][new_j]=1+dist[top.first][top.second];
                visited[new_i][new_j]=1;
            }
        }
    }

    return -1;

}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan

    while(cin >> row >> column && row && column)
    {
        memset(grid,0,sizeof(grid));

        int r; cin >> r;

        while(r--)
        {
            int temp_r,n_bombs; cin >> temp_r >> n_bombs;
            for(int i=1;i<=n_bombs;i++)
            {
                int p;
                cin >> p;
                grid[temp_r][p]=1;
            }
        }

        pii source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        cout << bfs(source,destination) << endl;
    }
}
