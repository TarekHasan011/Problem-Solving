#include<iostream>
using namespace std;
int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

char G[110][110];
int visited[110][110];
int m,n;

void dfs(int i, int j)
{
    if((i>=0 && i<m) && (j>=0 && j<n))
    {
        if(G[i][j]!='*')
        {
            if(visited[i][j])
                return;
            else
                visited[i][j]=1;

            for(int k=0; k<8; k++)
            {
                dfs(i+dx[k],j+dy[k]);
            }
        }
    }
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    while(cin >> m >> n && m && n)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> G[i][j];
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                visited[i][j] = 0;
            }
        }

        int counter = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(G[i][j]=='@' && visited[i][j]!=1)
                {
                    dfs(i,j);
                    counter++;
                }
            }
        }
        cout << counter << endl;
    }
    return 0;
}

