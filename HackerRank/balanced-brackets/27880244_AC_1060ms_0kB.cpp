#include<bits/stdc++.h>
using namespace std;
bool is_balanced(string str)
{
    stack< char > st;
    for(char c : str)
    {
        if(c=='(' || c=='{' || c=='[') st.push(c);
        else
        {
            if(st.empty()) return false;

            if(c==')')
            {
                if(st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            else if(c=='}')
            {
                if(st.top()=='{')
                    st.pop();
                else return false;
            }
            else
            {
                if(st.top()=='[')
                    st.pop();
                else return false;
            }
        }
    }

    return st.size()==0 ? true : false;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    while(tt--)
    {
        string str; cin >> str;

        is_balanced(str) ? cout << "YES\n" : cout << "NO\n";
    }
}
