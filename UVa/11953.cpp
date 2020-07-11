#include<bits/stdc++.h>
using namespace std;
char grid[102][102];
int n;
void dfs(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j]=='.') return;
    grid[i][j]='.';
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);

}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    int cases = 0;

    while(tt--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> grid[i][j];
        int counter = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='x')
                {
                    counter++;
                    dfs(i,j);
                }
            }
        }
        cout << "Case " << ++cases << ": " << counter << endl;
    }

    return 0;
}
