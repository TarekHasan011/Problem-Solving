#include<bits/stdc++.h>
using namespace std;
int visited[10000];
void DFS(map < int , vector < int > > adjacent, int start)
{
    stack < int > st;
    st.push(start);
    while(!st.empty())
    {
        int top = st.top();
        st.pop();
        if(!visited[top])
        {
            visited[top]=1;
            vector< int > temp_adj= adjacent[top];
            for(int x : temp_adj)
            {
                if(!visited[x])
                    st.push(x);
            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test; cin >> test;
    char ch;
    cin >> ch;
    while(test--)
    {
        string tt;
        map < int , vector < int > > adjacent;
        while(cin >> tt && tt.size()>1)
        {
            adjacent[tt[0]-65].push_back(tt[1]-65);
            adjacent[tt[1]-65].push_back(tt[0]-65);
        }
        memset(visited,0,sizeof(visited));
        /*for(int i=0;i<=ch-65;i++)
        {
            cout << i << " ->> ";
            vector < int > temp = adjacent[i];
            for(int j=0;j!=temp.size();j++)
                cout << temp[j] << " ";
            cout << endl;
        }*/
        int counter=0;
        for(int i=0;i<=ch-65;i++)
        {
            if(!visited[i])
            {
                DFS(adjacent,i);
                counter++;
            }
        }
        if(test) cout << counter << "\n\n";
        else cout << counter << "\n";
        ch=tt[0];
    }
    return 0;
}
