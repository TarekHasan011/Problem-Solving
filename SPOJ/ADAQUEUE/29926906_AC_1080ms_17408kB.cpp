#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int tt; cin >> tt;
    bool normal = true;
    list< int > List;
    while(tt--)
    {
        string str; cin >> str;

        if(str=="back")
        {
            if(List.size()==0)
            {
                cout << "No job for Ada?\n";
                continue;
            }

            if(normal)
            {
                cout << List.back() << endl;
                List.pop_back();
            }
            else
            {
                cout << List.front() << endl;
                List.pop_front();
            }
        }
        else if(str=="front")
        {
            if(List.size()==0)
            {
                cout << "No job for Ada?\n";
                continue;
            }

            if(normal)
            {
                cout << List.front() << endl;
                List.pop_front();
            }
            else
            {
                cout << List.back() << endl;
                List.pop_back();
            }
        }
        else if(str=="reverse")
        {
            if(normal)
                normal = false;
            else
                normal = true;
        }
        else if(str=="push_back")
        {
            int n; cin >> n;

            if(normal)
                List.push_back(n);
            else
                List.push_front(n);
        }
        else if(str=="toFront")
        {
            int n; cin >> n;

            if(normal)
                List.push_front(n);
            else
                List.push_back(n);
        }
    }
    return 0;
}
