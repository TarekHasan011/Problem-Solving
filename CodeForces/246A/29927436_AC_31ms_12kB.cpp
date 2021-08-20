#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n; cin >> n;
    if(n<=2)
        cout << "-1\n";
    else
    {
        for(int i=n;i>=1;i--)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
