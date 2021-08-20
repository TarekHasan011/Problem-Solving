#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n; cin >> n;
    set< int > st;
    int minimum_element = INF;
    for(int i=0;i<n;i++)
    {
        int temp; cin >> temp;
        minimum_element = min(minimum_element,temp);
        st.insert(temp);
    }
    st.erase(minimum_element);
    if(st.size()==0)
        cout << "NO\n";
    else
        cout << *st.begin() << "\n";
    return 0;

}
