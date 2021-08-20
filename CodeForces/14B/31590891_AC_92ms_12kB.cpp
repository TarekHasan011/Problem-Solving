#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n,x0; cin >> n >> x0;
    int arr[1007]={0};
    for(int i=0;i<n;i++)
    {
        int a,b; cin >> a >> b;
        if(a>b)swap(a,b);
        arr[a]+=1;
        arr[b+1]-=1;
    }
    for(int i=1;i<=1001;i++) arr[i] = arr[i]+arr[i-1];

    vector< int > v;
    for(int i=0;i<=1000;i++)
    {
        if(arr[i]==n)
            v.push_back(i);
    }
    if(v.size()==0)
    {
        cout << "-1\n";
        return 0;
    }

    int answer = INF;
    for(int x : v)
    {
        answer = min(answer,abs(x0-x));
    }
    cout << answer << "\n";
    return 0;
}
