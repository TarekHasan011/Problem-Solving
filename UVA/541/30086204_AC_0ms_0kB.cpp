#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n!=0)
    {
        vector< vector<int> >matrix;
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                int in;
                cin >> in;
                temp.push_back(in);
            }
            matrix.push_back(temp);
        }
        vector<int>sumrow;
        int flagrow=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[i][j];
            }
            sumrow.push_back(sum);
            if(sum%2!=0)
                flagrow++;
        }
        vector<int>sumcol;
        int flagcol=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[j][i];
            }
            sumcol.push_back(sum);
            if(sum%2!=0)
                flagcol++;
        }
        if(flagcol==0 and flagrow==0)
            cout << "OK\n";
        else if(flagcol==1 && flagrow==1)
        {
            int row,col;
            for(int i=0;i<sumcol.size();i++)
            {
                if(sumcol[i]%2!=0)
                {
                    col =i;
                    for(int j=0;j<sumrow.size();j++)
                    {
                        if(sumrow[j]%2!=0)
                        {
                            row=j;
                            break;
                        }
                    }
                    break;
                }
            }
//            for(int i=0;i<sumcol.size();i++)
//                cout << sumcol[i] << " ";
//            cout << "\n";
//            for(int i=0;i<sumrow.size();i++)
//                cout << sumrow[i] << " ";
            cout << "Change bit (" << row+1 << "," << col+1 << ")\n";

        }
        else
            cout << "Corrupt\n";


        cin >> n;
    }

    return 0;
}
