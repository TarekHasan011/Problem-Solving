#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    vector< int > answers;
    map< int , bool > mp;
    for(int i=n-1;i>=0;i--)
    {
        int an = (i+i)%n;
        if(mp[an])
        {
            cout << "-1\n";
            return 0;
        }
        mp[an] = true;
        answers.push_back(an);
    }

    for(int i=n-1;i>=0;i--)
        cout << i << " ";
    cout << endl;
    for(int i=n-1;i>=0;i--)
        cout << i << " ";
    cout << endl;
    for(int x : answers)
        cout << x << " ";
    cout << endl;


    return 0;
}
