#include<bits/stdc++.h>
using namespace std;
char left_shift(char c , int n)
{
    c-=n;
    if(c<'a')
        c = ('z'+1) - ('a'-c);
    return c;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    getchar();
    while(tt--)
    {
        string str; getline(cin,str);
        string word; cin >> word;
        getchar();
        for(int i=0;i<26;i++)
        {
            string temp = "";
            for(char c : str)
            {
                if(c>='a' && c<='z') temp+=left_shift(c,i);
                else temp+=c;
            }
            stringstream ss(temp);
            string test;
            bool flag = false;
            while(ss >> test)
            {
                if(test==word)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                cout << char('a'+i);
        }


        cout << "\n";
    }
    return 0;
}
