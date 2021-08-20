#include<bits/stdc++.h>
using namespace std;
int dist(int a, int b)
{
    return (a*a)+(b*b);
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int x;
    cin >> x;
    long long int result = 0;
    int a,b;

    while(cin >> a >> b)
    {
        int distance = dist(a,b);
        bool flag = false;

        for(int i=1;i<=10;i++)
        {
            if(distance<=(x*i)*(x*i))
            {
                result+=(11-i);
                flag = true;
                break;
            }
        }

        if(!flag)
            result+=0;
    }

    cout << result << endl;

    return 0;
}