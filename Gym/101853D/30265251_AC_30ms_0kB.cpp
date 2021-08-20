#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    while(tt--)
    {
        int n; cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        int counter = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                counter++;
        }
        cout << counter << endl;
    }
    return 0;
}
