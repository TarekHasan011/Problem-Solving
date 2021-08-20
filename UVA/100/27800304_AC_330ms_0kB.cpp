#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int a,b;
    while(cin >> a >> b)
    {
        bool flag = false;
        if(a>b)
        {
            swap(a,b);
            flag = true;
        }

        int max_len = 0;
        for(int i=a;i<=b;i++)
        {
            int temp = i;
            int length = 0;

            while(temp!=1)
            {
                if(temp&1) temp = (3*temp)+1;
                else temp/=2;
                length++;
            }

            length+=1;
            max_len = max(max_len,length);
        }
        if(flag) swap(a,b);
        cout << a << " " << b << " " << max_len << endl;
    }
    return 0;

}
