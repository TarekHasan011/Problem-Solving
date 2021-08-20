#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;

char arr[4][4];

bool valid(int i, int j)
{
    return i>=0 && i<4 && j>=0 && j<4;
}
bool win()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]=='x')
            {
                int first_i = i; int first_j = j-1;
                int first_ii = i; int first_jj = j+1;

                if(valid(first_i,first_j) && valid(first_ii,first_jj) && arr[first_i][first_j]=='x' && arr[first_ii][first_jj]=='x')
                    return true;

                first_i = i-1; first_j = j;
                first_ii = i+1; first_jj = j;

                if(valid(first_i,first_j) && valid(first_ii,first_jj) && arr[first_i][first_j]=='x' && arr[first_ii][first_jj]=='x')
                    return true;

                first_i = i-1; first_j = j-1;
                first_ii = i+1; first_jj = j+1;

                if(valid(first_i,first_j) && valid(first_ii,first_jj) && arr[first_i][first_j]=='x' && arr[first_ii][first_jj]=='x')
                    return true;


                first_i = i+1; first_j = j-1;
                first_ii = i-1; first_jj = j+1;

                if(valid(first_i,first_j) && valid(first_ii,first_jj) && arr[first_i][first_j]=='x' && arr[first_ii][first_jj]=='x')
                    return true;

            }
        }
    }
    return false;
}

bool solve()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]=='.')
            {
                arr[i][j] = 'x';
                if(win())
                    return true;
                arr[i][j] = '.';
            }
        }
    }
    return false;
}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan


    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin >> arr[i][j];

    cout << (solve() ? "YES" : "NO") << "\n";

    return 0;
}
