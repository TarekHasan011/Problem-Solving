#include<bits/stdc++.h>
using namespace std;
long long int STOI(string str)
{
    long long int answer = 0;
    for(char c : str)
    {
        answer = (answer*10) + (c-'0');
    }
    return answer;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    getchar();
    getchar();
    while(tt--)
    {
        string str;
        getline(cin,str);
        getchar();
        stringstream ss(str);
        long long int a = -1;
        long long int b = -1;
        long long int c = -1;

        string temp;
        ss >> temp;

        if(count(temp.begin(),temp.end(),'m')==0)
            a = STOI(temp);

        ss >> temp;
        ss >> temp;
        if(count(temp.begin(),temp.end(),'m')==0)
            b = STOI(temp);
        ss >> temp;
        ss >> temp;
        if(count(temp.begin(),temp.end(),'m')==0)
            c = STOI(temp);

        if(a==-1)
        {
            cout << c-b << " + " << b << " = " << c << "\n";
        }
        else if(b==-1)
        {
            cout << a << " + " << c-a << " = " << c << "\n";
        }
        else
        {
            cout << a << " + " << b << " = " << a+b << "\n";
        }

    }
    return 0;
}
