#include<bits/stdc++.h>
using namespace std;
int prime[3010]={0};
vector< int > primes;
void seive(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==0)
        {
            prime[i]=1;
            for(int j=i*i;j<=n;j+=i)
                prime[j]=-1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]!=-1) primes.push_back(i);
    }
}
int main()
{
    int n; cin >> n;
    seive(n);
    int main_counter=0;
    for(int i=1;i<=n;i++)
    {
        int counter=0;
        for(int j=0;j!=primes.size();j++)
        {
            if(i%primes[j]) continue;
            counter++;
            if(counter>2) break;
        }
        if(counter==2)
            main_counter++;
    }
    cout << main_counter << endl;
    return 0;
}
