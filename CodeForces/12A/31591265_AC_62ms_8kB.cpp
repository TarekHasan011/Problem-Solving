#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan


    char grid[3][3];
    for(int i=0;i<3;i++)for(int j=0;j<3;j++) cin >> grid[i][j];

    if(grid[0][0]==grid[2][2] && grid[0][1]==grid[2][1] && grid[0][2]==grid[2][0] && grid[1][0]==grid[1][2])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
