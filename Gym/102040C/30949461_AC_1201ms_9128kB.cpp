#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
vector< ll > primes;
const int mod = 1e7+7;
 
void sieve()
{
    vector< int > isPrime(1000007,0);
 
    for(int i=2;i*i<=1000000;i++)
    {
        if(isPrime[i]==0)
        {
            isPrime[i] = 1;
            for(int j=i*i;j<=1000000;j+=i)
                isPrime[j] = -1;
        }
    }
    for(ll i=2;i<=1000000;i++)
    {
        if(isPrime[i]!=-1)
            primes.push_back(i);
    }
    return;
}
 
ll count_occurance(ll n, ll prime)
{
    ll counter = 0;
    for(ll i=prime;(n/i)>=1;i*=prime)
        counter+=(n/i);
    return counter;
 
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
 
    sieve();
    int n;
    while(cin >> n && n)
    {
        ll answer = 1;
 
        for(int i : primes)
        {
            if(i>n)
                break;
 
            ll x = count_occurance(n,i);
            x++;
            answer *= ((x*(x+1))/2)%mod;
            answer%=mod;
        }
        cout << answer << "\n";
    }
 
    return 0;
}