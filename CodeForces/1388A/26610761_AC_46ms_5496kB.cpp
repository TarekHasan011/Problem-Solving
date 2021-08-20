#include<bits/stdc++.h>
using namespace std;
int prime[200007]={0};
void sieve(vector< int > &primes)
{
    for(int i=2;i*i<=200000;i++)
    {
        if(prime[i]==0)
        {
            prime[i]=1;
            for(int j=i*i;j<=200000;j+=i)
                prime[j]=-1;
        }
    }
    for(int i=2;i<=200000;i++)
    {
        if(prime[i]!=-1)
            primes.push_back(i);
    }
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    vector< int > primes;
    sieve(primes);

    int elements[200007]={0};
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            long long int a = primes[i];
            long long int b = primes[j];
            if(a*b>200000LL) break;
            elements[primes[i]*primes[j]]=1;
        }
    }

    int counter = 0;
    vector< int > num;

    for(int i=1;i<=200000;i++)
    {
        if(elements[i]==1)
        {
            counter++;
            num.push_back(i);
        }
        if(counter==11)
            break;
    }

    int tt; cin >> tt;
    while(tt--)
    {
        int n; cin >> n;

        bool answer = false;

        for(int i=0;i<num.size();i++)
        {
            for(int j=i+1;j<num.size();j++)
            {
                for(int k=j+1;k<num.size();k++)
                {
                    int x = n-num[i]-num[j]-num[k];
                    if(x>0 && x!=num[i] && x!=num[j] && x!=num[k])
                    {
                        answer = true;
                        cout << "YES\n";
                        cout << num[i] << " " << num[j] << " " << num[k] << " " << x << endl;
                        break;
                    }
                }
                if(answer) break;
            }
            if(answer) break;
        }
        if(answer) continue;
        cout << "NO\n";
    }

    return 0;

}
