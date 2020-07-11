#include<bits/stdc++.h>
using namespace std;
int up(vector< int > v, int temp)
{
    int ans = -1;
    int left = 0;
    int right = v.size()-1;
    while(left<=right)
    {
        int mid = left+((right-left)/2);
        if(v[mid]>temp)
        {
            ans = v[mid];
            right=mid-1;
        }
        else left=mid+1;
    }
    return ans;
}
int down(vector< int > v, int temp)
{
    int ans = -1;
    int left = 0;
    int right = v.size()-1;
    while(left<=right)
    {
        int mid = left+((right-left)/2);
        if(v[mid]<temp)
        {
            ans = v[mid];
            left=mid+1;
        }
        else right=mid-1;
    }
    return ans;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    vector< int > v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int q; cin >> q;
    while(q--)
    {
        int temp; cin >> temp;
        int x = down(v,temp);
        x==-1 ? cout << "X " : cout << x << " ";
        x = up(v,temp);
        x==-1 ? cout << "X\n" : cout << x << endl;
    }
    return 0;
}
