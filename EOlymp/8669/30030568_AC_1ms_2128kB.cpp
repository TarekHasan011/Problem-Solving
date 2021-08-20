#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    set< int > st;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            st.insert(i);
            st.insert(n/i);
        }
    }
    for(int x : st)
        cout << x << " ";
    cout << endl;

    return 0;
}
