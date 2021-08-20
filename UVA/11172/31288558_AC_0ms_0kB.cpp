#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t;
    cin >> t;
    while(t--)
    {
        long int a,b;
        cin >> a >> b;
        if(a>b)
            cout << ">\n";
        if(a<b)
            cout << "<\n";
        if(a==b)
            cout << "=\n";
    }
}
