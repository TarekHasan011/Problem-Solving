#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        if(n==0)
            return 0;
        string str;
        cin >> str;
        int row=str.size()/n;
        int k=0,flag=1;
        char arr[row][n];
        for(int i=0; i<row; i++)
        {
            if(flag)
            {
                for(int j=0; j<n; j++)
                    arr[i][j]=str[k++];
                flag=0;
            }
            else
            {
                for(int j=n-1; j>=0; j--)
                    arr[i][j]=str[k++];
                flag=1;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<row; j++)
            {
                cout << arr[j][i];
            }
        }
        cout << endl;
    }
}
