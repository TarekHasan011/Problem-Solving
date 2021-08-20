#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    while(tt--)
    {
        int n; cin >> n;
        int sum = 0;
        string temp = "";
        char x = 'a';
        for(int i=1;sum!=n;i++)
        {
            if(sum+i>n)
            {
                i = 0;
                x++;
                if(x>'z')
                    x = 'a';
                continue;
            }
            sum+=i;
            temp+=x;
        }

        cout << temp << "\n";

    }
    return 0;

}
