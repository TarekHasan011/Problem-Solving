#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > diamond;
vector< vector<int> > saved;
int n;
int col1[2]={0,1};
int col2[2]={-1,0};

int total_banana(int row,int col)
{
    if(saved[row][col]!=-1)
        return saved[row][col];
    int banana=diamond[row][col];
    pair<int,int> row_col;
    vector<pair<int,int> >adjacent;//.first is row,.second is col;
    if(row<n-1)
    {
        for(int i=0;i<2;i++)
        {
            if(row+1<diamond.size() && col+col1[i]<diamond[row+1].size())
            {
                row_col.first=row+1;
                row_col.second=col+col1[i];
                adjacent.push_back(row_col);
            }
        }
    }
    else
    {
        for(int i=0;i<2;i++)
        {
            if(row+1<diamond.size() && col+col2[i]<diamond[row+1].size())
            {
                row_col.first=row+1;
                row_col.second=col+col2[i];
                adjacent.push_back(row_col);
            }
        }
    }
    if(adjacent.size()==2)
        banana=banana+max(total_banana(adjacent[0].first,adjacent[0].second),total_banana(adjacent[1].first,adjacent[1].second));
    else if(adjacent.size()==1)
        banana=banana+total_banana(adjacent[0].first,adjacent[0].second);
    saved[row][col]=banana;
    return banana;
}

int main()
{
    vector<int>data,initalize;
    int t,in,banana;
    cin >> t;
    for(int m=0;m<t;m++)
    {
        cin >> n;
        for(int i=0;i<n;i++)
        {
            data.clear();
            initalize.clear();
            for(int j=0;j<i+1;j++)
            {
                cin >> in;
                data.push_back(in);
                initalize.push_back(-1);
            }
            diamond.push_back(data);
            saved.push_back(initalize);
        }
        for(int i=n-2;i>=0;i--)
        {
            data.clear();
            initalize.clear();
            for(int j=0;j<i+1;j++)
            {
                cin >> in;
                data.push_back(in);
                initalize.push_back(-1);
            }
            diamond.push_back(data);
            saved.push_back(initalize);
        }
        banana=total_banana(0,0);
        cout << "Case " << m+1 << ": " << banana << endl;
        diamond.clear();
        saved.clear();
    }
    return 0;
}
