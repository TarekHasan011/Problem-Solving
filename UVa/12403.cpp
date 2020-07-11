#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan
    int n; cin >> n;
    getchar();
    long long int result = 0;
    while(n--)
    {
        string str;
        int amount;
        cin >> str >> amount;
        cout << str << endl;
        if(str=="donate") result+=amount;
        else cout << result << endl;
    }

}
