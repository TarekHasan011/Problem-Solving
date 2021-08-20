#include<bits/stdc++.h>
using namespace std;
int a[16];
int check(int first,int last)
{
    for(int i=first;i<last-1;i++)
    {
        if(a[i]>a[i+1])
            return 0;
    }
    return 1;
}
int thanos_sort(int first,int last)
{
    if(check(first,last))
        return last-first;
    else
        return max(thanos_sort(first,(first+last)/2),thanos_sort(((first+last)/2),last));
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << thanos_sort(0,n) << endl;
    return 0;
}
