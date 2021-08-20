#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifdef TarekHasan
    freopen("input.txt","r",stdin);
#endif // TarekHasan

    int n, c, l, r;
    cin >> n >> c >> l >> r;
    if(c>=l && c<=r)
    {
        int left = l-1;
        int right = n-r;

        int ans = 0;
        if(left && right)
        {
            cout << min((c-l+1)+((r-l)+1),((r-c)+1)+((r-l)+1)) << endl;
        }
        else if(left)
            cout << (c-l)+1 << endl;
        else if(right)
            cout << (r-c)+1 << endl;
        else
            cout << "0\n";
    }
    else
    {
        if(c>r)
        {
            int ans = ((c-r)+1);
            if(l==1)
                cout << ans << endl;
            else
                cout << ans + (r-l)+1 << endl;
        }
        else
        {
            int ans = (l-c)+1;
            if(r==n)
                cout << ans << endl;
            else
                cout << ans+(r-l)+1 << endl;
        }
    }
    return 0;
}
