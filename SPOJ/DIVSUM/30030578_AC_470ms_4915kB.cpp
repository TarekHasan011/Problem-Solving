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
        long long int n; cin >> n;
        long long int sum = 0;
        for(long long int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sum+=i;

                if(n/i!=i)
                    sum+=(n/i);
            }
        }
        cout << sum-n << endl;
    }

    return 0;
}
