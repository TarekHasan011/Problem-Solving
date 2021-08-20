#include<bits/stdc++.h>
#define SIZE 1000007
using namespace std;
vector< int > sieve()
{
    vector< int > isPrime(SIZE+3,0);
    for(int i=2;i*i<=SIZE;i++)
    {
        if(isPrime[i]==0)
        {
            isPrime[i] = 1;
            for(int j=i*i;j<=SIZE;j+=i)
                isPrime[j] = -1;
        }
    }
    vector< int > primes;
    for(int i=3;i<=SIZE;i++)
    {
        if(isPrime[i]!=-1)
            primes.push_back(i);
    }
    return primes;
}
int less_than_index(int n, vector< int > &v)
{
    int left = 0;
    int right = v.size()-1;
    int answer = 0;
    while(left<=right)
    {
        int mid = left + ((right-left)/2);
        if(v[mid]<n)
        {
            answer = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    }
    return answer;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    vector< int > prime = sieve();
    unordered_map< int , bool > isOddPrime;
    for(int x : prime)
        isOddPrime[x] = true;
    int n;
    while(cin >> n && n)
    {
        int index = less_than_index(n,prime);
        int answer = -1;
        int a,b;

        for(int i=index;i>=0;i--)
        {
            int rem = n-prime[i];
            if(rem>2 && isOddPrime[rem] && abs(prime[i]-rem)>answer)
            {
                answer = abs(prime[i]-rem);
                b = prime[i]>rem ? prime[i] : rem;
                a = prime[i]==b ? rem : prime[i];
                break;
            }
        }

        if(answer==-1)
            cout << "Goldbach's conjecture is wrong.\n";
        else
            printf("%d = %d + %d\n",n,a,b);
    }

    return 0;
}
