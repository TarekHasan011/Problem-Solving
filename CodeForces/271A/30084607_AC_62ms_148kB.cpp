#include<bits/stdc++.h>
using namespace std;
bool possible(int n)
{
    unordered_set< int > st;

    while(n)
    {
        st.insert(n%10);
        n/=10;
    }
    return st.size()==4;

}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;

    int it = n+1;
    while(!possible(it))
    {
        it++;
    }
    cout << it << endl;

    return 0;
}
