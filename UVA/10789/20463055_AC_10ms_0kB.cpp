#include<bits/stdc++.h>
using namespace std;
int prime[2002]= {0};
map < int, int > prim;
map < char, int > mp;
int flag;
void prime_generator()
{
    for(int i=2; i<2001; i++)
    {
        if(prime[i]!=1 && prime[i]!=-1)
        {
            prime[i]=1;
            for(int j=i*i; j<2001; j+=i)
                prime[j]=-1;
        }
    }
}
void prime_map()
{
    for(int i=0; i<2001; i++)
    {
        if(prime[i]==1)
            prim[i]=1;
        else prim[i]=0;
    }
}
void map_initial()
{
    char n='A';
    for(int i=0; i<26; i++)
        mp[n++]=0;
    n='a';
    for(int i=0; i<26; i++)
        mp[n++]=0;
    n='0';
    for(int i=0; i<10; i++)
        mp[n++]=0;
}
void map_check()
{
    char n='0';
    for(int i=0; i<10; i++,n++)
    {
        if(prim[mp[n]])
        {
            cout << n;
            flag=0;
        }
    }
    n='A';
    for(int i=0; i<26; i++,n++)
    {
        if(prim[mp[n]])
        {
            cout << n;
            flag=0;
        }
    }
    n='a';
    for(int i=0; i<26; i++,n++)
    {
        if(prim[mp[n]])
        {
            cout << n;
            flag=0;
        }
    }

}
int main()
{
    prime_generator();
    prime_map();
    map_initial();
    int n;
    cin >> n;
    int i=1;
    while(n--)
    {
        string str;flag=1;
        cin >> str;
        cout << "Case " << i++ << ": ";
        for(int i=0; i!=str.size(); i++)
            mp[str[i]]++;
        map_check();
        if(flag)
            cout << "empty" << endl;
        else cout << endl;
        map_initial();
    }
    return 0;
}
