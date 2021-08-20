#include<bits/stdc++.h>
using namespace std;
#define MAX 10000007
const long long MOD = 1e9+7;
vector< int > primes;
void sieve()
{
    vector< int > prime(MAX,0);
    for(int i=2;i*i<MAX;i++)
    {
        if(prime[i]==0)
        {
            prime[i] = 1;
            for(int j=i*i;j<MAX;j+=i)
                prime[j] = -1;
        }
    }
    for(int i=2;i<MAX;i++)
    {
        if(prime[i]!=-1)
            primes.push_back(i);
    }
}
long long Count(long long n, long long k)
{
    long long counter = 0;

    for(long long i=k;i<=n;i*=k)
    {
        counter+=(n/i);
    }
    return counter;
}

long long mod_expo(long long x,long long y,long long p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    sieve();
    int n;
    while(cin >> n && n)
    {
        int answer = 1;

        for(int x : primes)
        {
            long long temp = x;
            long long y = Count(n,temp);
            if(y&1)
                y--;
            answer = ((answer%MOD) * (mod_expo(temp,y,MOD)%MOD))%MOD;
        }
        cout << answer << "\n";
    }
    return 0;
}
