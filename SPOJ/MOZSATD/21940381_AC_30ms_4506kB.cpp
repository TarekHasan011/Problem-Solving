#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    long long int n;
    cin >> n;
    long long int temp;
    long long int poor=99999999999,sum=0;
    while(n--)
    {
        cin >> temp;
        sum+=temp;
        if(temp%2 && poor>temp)
            poor= temp;
    }
    if(sum%2)   sum-=poor;
    cout << sum/2 << endl;
    return 0;
}
