#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("overcode.in","r",stdin);

    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    while(tt--)
    {
        int n; cin >> n;
        vector< int > v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(),v.end());
        if(n<6)
        {
            cout << "0\n";
            continue;
        }
        int left = 0;
        int right = 5;
        int counter = 0;
        while(right<n)
        {
            int diff = abs(v[left]-v[right]);
            if(diff<=1000)
            {
                counter++;
                left = right+1;
                right = left+5;
            }
            else
            {
                left++;
                right++;
            }
        }
        cout << counter << endl;
    }
    return 0;
}
