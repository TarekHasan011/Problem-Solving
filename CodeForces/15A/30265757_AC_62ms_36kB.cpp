#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin >> n >> t;
    vector< pair<int,int> >house;
    for(int i=0;i<n;i++)
    {
        int x,a;
        cin >> x >> a;
        house.push_back(make_pair(x,a));
    }
    sort(house.begin(),house.end());
//    for(int i=0;i<n;i++)
//    {
//        cout << house[i].first << " " << house[i].second << endl;;
//    }
    int count=2;
    for(int i=0;i<n-1;i++)
    {
        double firstH=house[i].first+double(house[i].second)/2.0;
        double secondH=house[i+1].first-double(house[i+1].second)/2.0;
        if((secondH-firstH)==t)
            count++;
        else if((secondH-firstH)>t)
            count=count+2;


    }
    cout << count << endl;

}

