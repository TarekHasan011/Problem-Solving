#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    int S[13]={0}; int H[13]={0}; int C[13]={0}; int D[13]={0};
    int n; cin >> n;
    while(n--)
    {
        char c; int x;
        cin >> c;
        cin >> x;
        if(c=='S') S[x-1]=1;
        else if(c=='H') H[x-1]=1;
        else if(c=='C') C[x-1]=1;
        else if(c=='D') D[x-1]=1;
    }
    for(int i=0;i<13;i++)
    {
        if(S[i]==0)
            cout << "S " << i+1 << "\n";
    }
    for(int i=0;i<13;i++)
    {
        if(H[i]==0)
            cout << "H " << i+1 << "\n";
    }
    for(int i=0;i<13;i++)
    {
        if(C[i]==0)
            cout << "C " << i+1 << "\n";
    }
    for(int i=0;i<13;i++)
    {
        if(D[i]==0)
            cout << "D " << i+1 << "\n";
    }
}
