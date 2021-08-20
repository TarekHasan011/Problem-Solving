#include<bits/stdc++.h>
using namespace std;
char G[100][100];
int visited[100][100];

void grid_row_column(vector< string > inputs, int &row, int &column, int &query)
{
    column = inputs[0].size();
    row = 0;
    for(int i=0;i!=inputs.size();i++)
    {
        if(inputs[i][0]=='L' || inputs[i][0]=='W') row++;
    }
    query = inputs.size()-row;
    return;
}

int string_to_integer(string str)
{
   int result = 0;
   for(char c : str)
   {
       result= (result*10)+(c-'0');
   }
   return result;
}

void separate_integers(string str, int &a, int &b)
{
    string temp="";
    for(int i=0;i!=str.size();i++)
    {
       if(str[i]!=' ')
       {
           temp+=str[i];
       }
       else
       {
           a = string_to_integer(temp);
           temp="";
       }
    }
    b=string_to_integer(temp);
    return;
}

void separate_query(vector< string > inputs, vector< pair< int , int > > &queries, int row)
{
    for(int i=row;i!=inputs.size();i++)
    {
        int a,b;
        separate_integers(inputs[i],a,b);
        queries.push_back(make_pair(a-1,b-1));
    }
    return;
}

void make_grid(vector< string > inputs, int row, int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            G[i][j]=inputs[i][j];
        }
    }
}

int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
int counter = 0;
void dfs(int i, int j, int row, int column)
{
    if(i<0 || i>=row || j<0 || j>=column || G[i][j]=='L' || visited[i][j]) return;

    visited[i][j]=1;
    counter++;

    for(int k=0;k<8;k++)
    {
        dfs(i+dx[k],j+dy[k],row,column);
    }

}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int tt; cin >> tt;
    getchar();
    getchar();

    while(tt--)
    {
        vector< string >  inputs;
        string str;
        while(getline(cin,str) && str.size())
        {
            inputs.push_back(str);
        }

        int row, column, query;
        grid_row_column(inputs,row,column,query);

        vector< pair< int , int > > queries;
        separate_query(inputs,queries,row);

        make_grid(inputs,row,column);

        for(auto x : queries)
        {
            counter = 0;
            memset(visited,0,sizeof(visited));
            dfs(x.first, x.second,row, column);
            cout << counter << endl;
        }

        if(tt) cout << endl;
    }

    return 0;
}
