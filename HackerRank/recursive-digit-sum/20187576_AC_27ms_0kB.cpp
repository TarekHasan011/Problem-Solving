#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    long long n;
    cin >> str;
    cin >> n;
    long long sum=0;
    for(long long i=0;i!=str.size();i++)
        sum+=((str[i]-'0')*n);
    if(sum%9)
        cout << sum%9 << endl;
    else cout << "9" << endl;
    return 0;
}
