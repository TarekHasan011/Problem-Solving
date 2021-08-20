#include<bits/stdc++.h>
using namespace std;
void all_lower(string &str)
{
    for(char &c : str)
    {
        if(c>='A' && c<='Z')
        {
            c-='A';
            c+='a';
        }
    }
}
int compare(string first, string second)
{
    for(int i=0;i<first.size();i++)
    {
        if(first[i]==second[i]) continue;

        if(first[i]<second[i]) return -1;
        else return 1;
    }
    return 0;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    string str1,str2; cin >> str1 >> str2;
    all_lower(str1);
    all_lower(str2);
    cout << compare(str1,str2) << endl;

    return 0;
}
