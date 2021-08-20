#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int a, x, y;
    cin >> a >> x >> y;

    if (y < 0 || y % a == 0)
    {
        cout << -1 << endl;
        return 0;
    }


    int y_temp = y / a;
    if ((y_temp == 0) || (y_temp % 2 != 0))
    {
        if (-a < 2*x && 2*x < a)
        {
            if (y_temp == 0) cout << 1;
            else cout << (3*y_temp-1) / 2 + 1;
        }
        else cout << -1;
    }
    else
    {
        int answer = (3*y_temp-1)/2;
        if (-a < x && x < 0) cout << ++answer;
        else if (0 < x && x < a) cout << answer+2;
        else cout << -1;
    }

    cout << "\n";


    return 0;
}
