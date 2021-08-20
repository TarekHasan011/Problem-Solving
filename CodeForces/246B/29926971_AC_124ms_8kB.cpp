#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n; cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        int temp; cin >> temp;
        sum+=temp;
    }
    if(sum%n==0)
        cout << n << endl;
    else
        cout << n-1 << endl;
    return 0;
}
