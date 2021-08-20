#include<bits/stdc++.h>
using namespace std;
bool IsPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)  return false;
    }
    return true;
}
int main()
{
    /*#ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan*/
    int n; cin >> n;
    if(IsPrime(n))
        cout << (n*2)+(1*2) << endl;
    else
    {
        int MINIMUM = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)  MINIMUM = min(MINIMUM,(i*2)+((n/i)*2));
        }
        cout << MINIMUM << endl;
    }
    return 0;
}