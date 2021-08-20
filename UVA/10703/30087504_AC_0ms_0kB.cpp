#include<bits/stdc++.h>
using namespace std;
int grid[507][507];

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int w,h,n;

    while(cin >> w >> h >> n)
    {
        if(w==0 && h==0 && n==0)
            return 0;
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                grid[i][j] = 0;
        for(int it=0;it<n;it++)
        {
            int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            if(x2<x1)
                swap(x1,x2);
            if(y2<y1)
                swap(y1,y2);

            for(int i=y1;i<=y2;i++)
                for(int j=x1;j<=x2;j++)
                    grid[i][j] = 1;
        }

        int counter = 0;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(grid[i][j]==0)
                    counter++;
            }
        }
        if(counter==0)
            cout << "There is no empty spots.\n";
        else if(counter==1)
            cout << "There is one empty spot.\n";
        else
            cout << "There are " << counter << " empty spots.\n";
    }

}
