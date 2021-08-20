#include<bits/stdc++.h>
using namespace std;
map< long long , int > occurance;
void init(vector< long long  > &v)
{
    occurance.clear();
    for(long long  x : v)
        occurance[x]++;
    return;
}
bool possible_left(vector< long long > &v, long long need)
{
    long long temp_sum = 0;
    for(int i=0;i<v.size()-1 && temp_sum<need;i++)
    {
        temp_sum+=v[i];
        occurance[v[i]]--;
        if(need>temp_sum && occurance[need-temp_sum]>0)
            return true;
    }
    return temp_sum==need;
}
bool possible_right(vector< long long > & v, long long need)
{
    long long temp_sum = 0;
    for(int i=v.size()-1;i>=0 && temp_sum<need;i--)
    {
        temp_sum+=v[i];
        occurance[v[i]]--;
        if(need>temp_sum && occurance[need-temp_sum]>0)
            return true;
    }
    return temp_sum==need;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    vector< long long > v(n);
    long long sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        sum+=v[i];
    }
    if(sum&1)
        cout << "NO\n";
    else
    {
        init(v);
        long long need = sum/2LL;

        if(occurance[need]>0)
        {
            cout << "YES\n";
            return 0;
        }
        bool possible = possible_left(v,need);
        if(possible)
        {
            cout << "YES\n";
            return 0;
        }


        init(v);
        possible = possible_right(v,need);
        if(possible)
        {
            cout << "YES\n";
            return 0;
        }
        cout << "NO\n";
    }
    return 0;

}
