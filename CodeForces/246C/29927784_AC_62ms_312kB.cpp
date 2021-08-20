#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n,k; cin >> n >> k;
    vector< int > v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    vector< vector< int > > answers;

    for(int i=0;i<v.size();i++)
        answers.push_back({v[i]});

    vector< int > temp;
    for(int i=v.size()-1;i>0;i--)
    {
        temp.push_back(v[i]);
        for(int j=i-1;j>=0;j--)
        {
            temp.push_back(v[j]);
            answers.push_back(temp);
            temp.pop_back();
        }
    }

    for(int i=0;i<k;i++)
    {
        cout << answers[i].size() << " ";
        int sum = 0;
        for(int x : answers[i])
            cout << x << " ";
        cout << endl;

    }

    return 0;
}
