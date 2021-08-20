#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int a,b,c; cin >> a >> b >> c;
    int n; cin >> n;
    int counter = 0;
    for(int i=0;i<n;i++)
    {
        int temp; cin >> temp;
        if(temp>b && temp<c)
            counter++;
    }
    cout << counter << endl;
    return 0;

}
