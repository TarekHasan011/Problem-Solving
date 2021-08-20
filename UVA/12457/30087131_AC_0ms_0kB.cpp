#include<bits/stdc++.h>
using namespace std;

long long nCr(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;
    return p;
}

int main()
{
//    cout << nCr(10,5) << endl;
    int t;
    cin >> t;
    while(t--)
    {
        double n,p;
        cin >> n >> p;
        double prob=0;
        for(int i=n;i<=2*n-1;i++)
        {
            //cout << i << " " << 2*n-1-i << " ";
            double tempprob=nCr(2*n-1,i)*pow(p,i)*pow(1-p,2*n-1-i);
            //cout << tempprob << endl;
            prob+=tempprob;
        }
        cout.precision(2);
        cout << fixed << prob << "\n";
    }
    return 0;
}

