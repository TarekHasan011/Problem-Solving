#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int tt; cin >> tt;
    while(tt--)
    {
        int n; cin >> n;
        map< int , vector< int > > mp;
        int maximum_value = 0;

        for(int i=0;i<n;i++)
        {
            int start,finish; cin >> start >> finish;
            mp[start].push_back(i+1);
            mp[finish+1].push_back((i+1)*-1);
            maximum_value = max({maximum_value,start,finish});
        }
        set< int > st;
        unordered_set< int > answer;
        for(auto x : mp)
        {
            for(int y : x.second)
            {
                if(y>0)
                    st.insert(y);
                else
                    st.erase(abs(y));
            }

            if(st.size())
                answer.insert(*st.rbegin());
        }
        cout << answer.size() << "\n";
    }


    return 0;
}
