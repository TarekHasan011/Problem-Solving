#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    long long int n; cin >> n;
    long long int result = (n*(n+1))/2;
    if(result%2)
    {
        cout << "-1\n";
        return 0;
    }
    else
    {
        vector< int > v(n+7,0);
        result = result/2;
        long long int it = n;
        while(result)
        {
            result -= it;
            v[it] = 1;
            it = min((it-1),result);
        }

        for(int i=1;i<=n;i++)
        {
            if(v[i]==1)
                cout << "-";
            else
                cout << "+";
        }
        cout << endl;
    }
    return 0;
}
