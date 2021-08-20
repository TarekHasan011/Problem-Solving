#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n,m; cin >> n >> m;
    char grid[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> grid[i][j];

    int first_row, last_row, first_column, last_column;

    bool got_first = false;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='*')
            {
                if(!got_first)
                {
                    first_row = i;
                    first_column = j;
                    last_row = i;
                    last_column = j;
                    got_first = true;
                }
                else
                {
                    first_column = min(first_column,j);
                    last_row = max(last_row,i);
                    last_column = max(last_column,j);
                }
            }
        }
    }
    for(int i=first_row;i<=last_row;i++)
    {
        for(int j=first_column;j<=last_column;j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
