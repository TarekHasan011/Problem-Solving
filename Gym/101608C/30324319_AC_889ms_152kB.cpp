#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("scoreboard.in","r",stdin);

    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    while(tt--)
    {
        int n; cin >> n;
        string str; cin >> str;
        map< char , bool > mp;
        for(char c : str)
            mp[c] = true;

        int answer = INT_MIN;
        char next_problem;

        for(char i ='A';i<='M';i++)
        {
            int temp; cin >> temp;
            if(mp[i])
                continue;
            if(temp>answer)
            {
                answer = temp;
                next_problem = i;
            }
        }
        cout << next_problem << endl;
    }
    return 0;
}
