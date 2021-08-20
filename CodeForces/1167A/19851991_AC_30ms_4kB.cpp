#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int size_of_string,i;
        string number;
        cin >> size_of_string;
        getchar();
        getline(cin,number);
        for(i=0; i!=number.size(); i++)
        {
            if(number[i]=='8' && size_of_string-i>=11)
            {
                cout << "YES" << endl;
                break;
            }
        }
        if(i==number.size())
            cout << "NO" << endl;
    }
    return 0;
}
