#include<bits/stdc++.h>
using namespace std;
struct list{
    int a;
    int b;
    int c;
}a[4];
int main()
{
    int flag=-1;
    vector < int > v;
    for(int i=0;i<4;i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    a[0].a=v[0],a[0].b=v[1],a[0].c=v[2];
    a[1].a=v[0],a[1].b=v[1],a[1].c=v[3];
    a[2].a=v[0],a[2].b=v[2],a[2].c=v[3];
    a[3].a=v[1],a[3].b=v[2],a[3].c=v[3];

    for(int i=0;i<4;i++)
    {
        if(a[i].a+a[i].b > a[i].c && a[i].a+a[i].c > a[i].b && a[i].b+a[i].c > a[i].a)
        {
            flag=0;
            break;
        }
        else if(a[i].a+a[i].b == a[i].c || a[i].a+a[i].c == a[i].b || a[i].b+a[i].c == a[i].a)
        {
            flag=1;
        }
    }
    if(flag==0)
        cout << "TRIANGLE" << endl;
    else if(flag==1)
        cout << "SEGMENT" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
