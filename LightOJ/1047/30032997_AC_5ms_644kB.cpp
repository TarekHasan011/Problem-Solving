#include<bits/stdc++.h>
using namespace std;
int dp[27][3];
int answer(int it, vector< vector< int > > &v, int parent)
{
    if(it==v.size()) return 0;
    if(dp[it][parent]!=-1) return dp[it][parent];

    int result = INT_MAX;
    for(int i=0;i<3;i++)
    {
        if(i!=parent)
            result = min(result,v[it][i]+answer(it+1,v,i));
    }
    return dp[it][parent] = result;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int tt; cin >> tt;
    int test_case = 0;
    while(tt--)
    {
        getchar();
        int n; cin >> n;
        vector< vector< int > > v;
        for(int i=0;i<n;i++)
        {
            int r,g,b; cin >> r >> g >> b;
            v.push_back({r,g,b});
        }
        memset(dp,-1,sizeof(dp));
        int final_answer = INT_MAX;
        for(int i=0;i<3;i++)
        {
            final_answer = min(final_answer,v[0][i]+answer(1,v,i));
        }
        cout << "Case " << ++test_case << ": " <<final_answer << endl;
    }

    return 0;
}
