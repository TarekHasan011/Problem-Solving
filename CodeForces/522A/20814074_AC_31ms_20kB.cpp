#include<bits/stdc++.h>
using namespace std;
map < string , int > mp;
void to_upper(string &str)
{
    for(int i=0;i!=str.size();i++)
    {
        if(str[i]>='a' && str[i] <='z')
        {
            str[i]-='a';
            str[i]+='A';
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    mp["POLYCARP"]=1;
    int n,MAX=0;

    cin >> n;
    while(n--)
    {
        string str1,temp,str2;
        cin >> str1 >> temp >> str2;
        to_upper(str1); to_upper(str2);
        mp[str1]=mp[str2]+1;
        MAX=max(MAX,mp[str1]);
    }
    cout << MAX << endl;
    return 0;
}
