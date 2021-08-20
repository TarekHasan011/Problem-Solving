#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;

int base_converter(int base, int val)
{
    int sum = 0;
    while(val/base)
    {
        sum+=(val%base);
        val/=base;
    }
    sum+=(val%base);
    return sum;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    int answer = 0;
    for(int i=2;i<=n-1;i++)
    {
        answer+=base_converter(i,n);
    }
    int x = __gcd(answer,n-2);

    cout << answer/x << "/" << (n-2)/x << "\n";
    return 0;
}
