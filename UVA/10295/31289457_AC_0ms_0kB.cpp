#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n,m; cin >> n >> m;
    map< string , long long > mp;
    for(int i=0;i<n;i++)
    {
        string temp; long long val;
        cin >> temp >> val;
        mp[temp] = val;
    }
    long long int result = 0;

    string str;
    while(getline(cin,str))
    {
        if(str.length()==1 && str[0]=='.')
        {
            cout << result << "\n";
            result = 0;
            continue;
        }
        stringstream ss(str);
        string word;
        while(ss >> word)
        {
            result += mp[word];
        }
    }
    return 0;
}
