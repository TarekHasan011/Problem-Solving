#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    while(tt--)
    {
        int n; scanf("%d",&n);
        map< int , vector< int > > mp;
        int maximum_value = 0;

        for(int i=0;i<n;i++)
        {
            int start,finish; scanf("%d%d",&start,&finish);
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
        printf("%d\n",answer.size());
    }


    return 0;
}
