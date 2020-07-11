#include<bits/stdc++.h>
using namespace std;
string str;
int dp[1005][1005];
int lp(int left, int right)
{
    if(dp[left][right]!=-1) return dp[left][right];
    if(left==right) return dp[left][right]=1;
    else if(left+1==right)
    {
        if(str[left]==str[right])
            return dp[left][right]=2;
        else
            return dp[left][right]=1;
    }
    if(str[left]==str[right])
        return 2+lp(left+1,right-1);
    return dp[left][right]=max(lp(left,right-1),lp(left+1,right));
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    cin.ignore();
    while(tt--)
    {
        memset(dp,-1,sizeof(dp));
        getline(cin,str);
        //cin >> str;
        cout << lp(0,str.size()-1) << endl;
    }
    return 0;
}
