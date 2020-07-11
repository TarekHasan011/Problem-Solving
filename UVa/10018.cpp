#include<bits/stdc++.h>
using namespace std;
long long int reverse_integer(long long int n)
{
    long long int temp = 0;
    while(n)
    {
        temp = (temp*10) + (n%10);
        n/=10;
    }
    return temp;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan

    long long int tt; cin >> tt;

    while(tt--)
    {
        long long int n; cin >> n;
        long long int counter = 1;
        n+=reverse_integer(n);
        while(n!=reverse_integer(n))
        {
            n+=reverse_integer(n);
            counter++;
        }
        cout << counter << " " << n << endl;
    }
    return 0;
}
