#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int n;
    cin >> n;
    cin >> str;
    int eight=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='8')
            eight++;
    }
    cout << min(eight,n/11) << endl;
    return 0;
}
