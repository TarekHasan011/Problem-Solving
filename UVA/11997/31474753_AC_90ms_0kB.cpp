#include<bits/stdc++.h>
using namespace std;


int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    while(cin >> n)
    {
        vector< int > v(n);

        for(int &i : v) cin >> i;
        sort(v.begin(),v.end());

        for(int it=1;it<n;it++)
        {
            vector< int > temp(n);
            for(int &i : temp) cin >> i;
            sort(temp.begin(),temp.end());

            priority_queue< pair< int , int > , vector< pair< int , int > > , greater< pair< int , int > > > pq;
            for(int i=0;i<n;i++) pq.push({v[i]+temp[0],0});
            for(int i=0;i<n;i++)
            {
                auto x = pq.top(); pq.pop();
                v[i] = x.first;
                if(x.second+1<n)
                {
                    pq.push({x.first-temp[x.second]+temp[x.second+1],x.second+1});
                }

            }
        }
        for(int i=0;i<n;i++)
        {
            cout << v[i];
            if(i==n-1)
                cout << "\n";
            else
                cout << " ";
        }

    }
    return 0;

}
