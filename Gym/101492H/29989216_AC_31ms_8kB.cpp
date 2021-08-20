#include<bits/stdc++.h>
using namespace std;
map< pair<char, char > , int > mp;
void __init__()
{
    mp[{'N','E'}] = 1;
    mp[{'N','S'}] = 2;
    mp[{'N','W'}] = 3;

    mp[{'E','S'}] = 1;
    mp[{'E','W'}] = 2;
    mp[{'E','N'}] = 3;

    mp[{'S','W'}] = 1;
    mp[{'S','N'}] = 2;
    mp[{'S','E'}] = 3;

    mp[{'W','N'}] = 1;
    mp[{'W','E'}] = 2;
    mp[{'W','S'}] = 3;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    __init__();

    int sx,sy;
    char curr_pos;

    int dx,dy;
    cin >> sx >> sy >> curr_pos >> dx >> dy;

    if(curr_pos=='O') curr_pos = 'W';

    vector< int > first_one;
    char pos = curr_pos;

    if(sy>dy)
    {
        for(int i=0;i<mp[{pos,'S'}];i++)
            first_one.push_back(-1);
        pos = 'S';
        first_one.push_back(sy-dy);
    }
    else if(sy<dy)
    {
        for(int i=0;i<mp[{pos,'N'}];i++)
            first_one.push_back(-1);
        pos = 'N';
        first_one.push_back(dy-sy);
    }


    if(sx>dx)
    {
        for(int i=0;i<mp[{pos,'W'}];i++)
            first_one.push_back(-1);
        pos = 'W';
        first_one.push_back(sx-dx);
    }
    else if(sx<dx)
    {
        for(int i=0;i<mp[{pos,'E'}];i++)
            first_one.push_back(-1);
        pos = 'E';
        first_one.push_back(dx-sx);
    }

    vector< int > second_one;
    pos = curr_pos;

    if(sx>dx)
    {
        for(int i=0;i<mp[{pos,'W'}];i++)
            second_one.push_back(-1);
        pos = 'W';
        second_one.push_back(sx-dx);
    }
    else if(sx<dx)
    {
        for(int i=0;i<mp[{pos,'E'}];i++)
            second_one.push_back(-1);
        pos = 'E';
        second_one.push_back(dx-sx);
    }

    if(sy>dy)
    {
        for(int i=0;i<mp[{pos,'S'}];i++)
            second_one.push_back(-1);
        pos = 'S';
        second_one.push_back(sy-dy);
    }
    else if(sy<dy)
    {
        for(int i=0;i<mp[{pos,'N'}];i++)
            second_one.push_back(-1);
        pos = 'N';
        second_one.push_back(dy-sy);
    }


    if(first_one.size()<second_one.size())
    {
        cout << first_one.size() << endl;
        for(int x : first_one)
        {
            if(x==-1)
                cout << "D\n";
            else
                cout << "A " << x << endl;
        }
    }
    else
    {
        cout << second_one.size() << endl;
        for(int x : second_one)
        {
            if(x==-1)
                cout << "D\n";
            else
                cout << "A " << x << endl;
        }
    }

    return 0;
}
