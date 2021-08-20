#include<bits/stdc++.h>
using namespace std;
void answer(string &str)
{
    if(str.size()<5)
    {
        cout << "OMG>.< I don't know!\n";
        return;
    }

    string freda = str.substr(str.size()-5);
    string rainbow = str.substr(0,5);

    if(freda=="lala." && rainbow=="miao.")
        cout << "OMG>.< I don't know!\n";
    else if(freda=="lala.")
        cout << "Freda's\n";
    else if(rainbow=="miao.")
        cout << "Rainbow's\n";
    else
        cout << "OMG>.< I don't know!\n";
    return;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    getchar();
    while(tt--)
    {
        string str; getline(cin,str);
        answer(str);
    }

    return 0;
}
