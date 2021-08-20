#include<bits/stdc++.h>
using namespace std;

#define __test int tt; int Case=0; cin >> tt; while(tt--)
#define Cases  cout << "Case " << ++Case << ": ";

#define MEM(a, x) memset(a,x,sizeof(a))
#define MAX 100010
#define ll long long

const int mod = 1000000007;

struct BIT_PURQ {
    ll bit[MAX];
    int N;

    void init(int n) {
        MEM(bit, 0);
        N = n;
    }
    // add value to bit[i]
    void add(int i, ll value) {
        for (; i < N; i |= i + 1) bit[i] += value;
    }
    // sum[0..i]
    ll sum(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res = (res+bit[i])%mod;
        return res;
    }
    // sum[a..b]
    ll sum(int a, int b) {
        return sum(b) - ((a < 1) ? 0 : sum(a-1));
    }
    // bit[i] = value
    void assign(int i, ll value) {
        add(i, value -sum(i, i));
    }
};

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    __test
    {
        int n; cin >> n;
        vector< pair< int , int > > v(n);
        for(int i=0;i<n;i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(),v.end(),[&](pair< int , int > &a, pair< int , int > &b)
             {
                return a.first==b.first ? a.second > b.second : a.first < b.first;
             });
        BIT_PURQ bit_purq;
        bit_purq.init(n);

        int answer = 1;
        bit_purq.assign(v[0].second,1);

        for(int i=1;i<v.size();i++)
        {
            int x = bit_purq.sum(v[i].second);
            x += 1;

            answer = (answer+x)%mod;
            bit_purq.assign(v[i].second,x);
        }
        Cases
        cout << answer << "\n";

    }


    return 0;
}

