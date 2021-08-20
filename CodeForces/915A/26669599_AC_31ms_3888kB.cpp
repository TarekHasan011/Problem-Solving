#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n,k; cin >> n >> k;
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        int temp; cin >> temp;
        if(k%temp==0)
        {
            ans = min(ans,k/temp);
        }
    }
    cout << ans << endl;
    return 0;
}
