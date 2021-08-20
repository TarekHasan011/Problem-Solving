#include<bits/stdc++.h>
using namespace std;
bool valid(vector< int > &v, int b,int max_people)
{
    for(int x : v)
    {
        int need = x%max_people ? (x/max_people)+1 : (x/max_people);
        if(b>=need)
            b-=need;
        else
            return false;
    }
    return true;
}
int answer(vector< int > &v, int b)
{
    int left = 1;
    int right = *max_element(v.begin(),v.end());
    int answer = right;
    while(left<=right)
    {
        int mid = left + ((right-left)/2);
        if(valid(v,b,mid))
        {
            answer = mid;
            right = mid-1;
        }
        else
            left = mid+1;
    }
    return answer;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n,m;
    while(cin >> n >> m && n!=-1 && m!=-1)
    {
        vector< int > v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        cout << answer(v,m) << "\n";


        getchar();
    }
    return 0;
}
