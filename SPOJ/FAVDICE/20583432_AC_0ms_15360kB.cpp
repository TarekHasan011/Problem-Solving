#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        double sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=(1.0/i);
        }
        printf("%.2lf\n",n*sum);
    }
    return 0;
}
