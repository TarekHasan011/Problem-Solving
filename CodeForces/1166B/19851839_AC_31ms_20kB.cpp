#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char vowels[6]="aeiou";
    cin>>n;
    int d=5;
    while (d<n && n%d )
        d++;
    if (n%d==0&&n/d>=5)
    {
        for (int i=0; i<d; i++)
        {
            for (int j=0; j<n/d; j++)
                printf("%c",(vowels[(i+j)%5]));
        }
    }
    else
        cout << "-1" << endl;
    return 0;
}