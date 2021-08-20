#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tabs.in","r",stdin);

    int tt; cin >> tt;
    while(tt--)
    {
        int n,k; cin >> n >> k;
        int right = n-k;
        int left = k-1;
        if(right>0)
            right = 1;
        if(left>0)
            left = 1;
        cout << right+left << endl;
    }
    return 0;
}
