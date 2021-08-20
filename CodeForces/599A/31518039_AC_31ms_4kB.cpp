#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int d1,d2,d3; cin >> d1 >> d2 >> d3;
    cout << min({(2*d1)+(2*d2), (d1+d3+d2),(2*d1)+(2*d3),(2*d2)+(2*d3)}) << "\n";
    return 0;

}
