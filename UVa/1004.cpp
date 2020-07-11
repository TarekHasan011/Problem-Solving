#include<bits/stdc++.h>
using namespace std;
bool valid(int i , int j, vector< vector< int >> &v)
{
    if(i>=0 && i<v.size() && j>=0 && j<v[i].size()) return true;
    else return false;
}
int dp[107][107];
int ansLow(int i, int j, vector< vector< int >> &x)
{
    if(dp[i][j]!=-1) return dp[i][j];

    int result = 0;

    if(valid(i+1,j-1,x))
        result = max(result,ansLow(i+1,j-1,x));
    if(valid(i+1,j,x))
        result = max(result,ansLow(i+1,j,x));

    return dp[i][j] = result+x[i][j];
}
int ansUp(int i , int j, vector<vector< int >> &x)
{
    if(dp[i][j]!=-1) return dp[i][j];

    int result = 0;

    if(valid(i+1,j,x))
        result = max(result,ansUp(i+1,j,x));
    if(valid(i+1,j+1,x))
        result = max(result,ansUp(i+1,j+1,x));

    return dp[i][j] = result+x[i][j];
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan

    int tt; cin >> tt;
    int Cases = 0;

    while(tt--)
    {


        int n; cin >> n;

        cout << "Case " << ++Cases << ": ";

        if(n==1)
        {
            int temp; cin >> temp;
            cout << temp << endl;
            continue;
        }

        vector< vector< int > > upper, lower;

        for(int i=0;i<n;i++)
        {
            vector< int > rest;
            for(int j=0;j<=i;j++)
            {
                int temp; cin >> temp;
                rest.push_back(temp);
            }
            upper.push_back(rest);
            if(i==n-1)
                lower.push_back(rest);
        }

        for(int i=n-1;i>=0;i--)
        {
            vector< int > rest;
            for(int j=1;j<=i;j++)
            {
                int temp; cin >> temp;
                rest.push_back(temp);
            }
            lower.push_back(rest);
        }


        memset(dp,-1,sizeof(dp));

        for(int i=0;i<lower[0].size();i++)
        {
            int x = lower[0][i];
            if(valid(1,i-1,lower))
                lower[0][i]=max(lower[0][i],x+ansLow(1,i-1,lower));
            if(valid(1,i,lower))
                lower[0][i]=max(lower[0][i],x+ansLow(1,i,lower));
        }

        for(int i=0;i!=upper[upper.size()-1].size();i++)
        {
            upper[upper.size()-1][i]=lower[0][i];
        }


        memset(dp,-1,sizeof(dp));


        for(int i=0;i<upper[0].size();i++)
        {
            int x = upper[0][i];
            if(valid(1,i,upper))
                upper[0][i]=max(upper[0][i],x+ansUp(1,i,upper));
            if(valid(1,i+1,upper))
                upper[0][i]=max(upper[0][i],x+ansUp(1,i+1,upper));
        }

        cout << upper[0][0] << endl;

    }


    return 0;
}
