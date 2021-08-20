#include<bits/stdc++.h>
using namespace std;
int intrev(int n)
{
    int result = 0;
    while(n)
    {
        result = (result*10) + (n%10);
        n/=10;
    }
    return result;
}
bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n;
    while(cin >> n)
    {
        bool a = isPrime(n);

        if(a)
        {
            int new_number = intrev(n);
            a = isPrime(new_number);
            if(a && n!=new_number)
                cout << n << " is emirp.\n";
            else
                cout << n << " is prime.\n";
        }
        else
            cout << n << " is not prime.\n";
    }

    return 0;
}
