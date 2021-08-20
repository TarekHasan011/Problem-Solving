#include<bits/stdc++.h>
using namespace std;
int main()
{
    set < int > st;
    vector < int > v;
    int n;
    cin >> n;
    while(n--)
    {
        int id;
        int f;
        cin >> id;
        v.push_back(id);
        cin >> f;
        while(f--)
        {
            int ff;
            cin >> ff;
            st.insert(ff);
        }
    }
    for(int i=0;i!=v.size();i++)
    {
        st.erase(v[i]);
    }
    cout << st.size() << endl;
    return 0;
}
