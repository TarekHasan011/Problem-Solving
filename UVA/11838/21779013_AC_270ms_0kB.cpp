#include<bits/stdc++.h>
using namespace std;
bool Check(map < int , vector < int > > adjacentList,int start,int n)
{
    int visited[n+1]={0};
    stack < int > st;
    vector < int > visit;
    st.push(start);
    while(!st.empty())
    {
        int x= st.top();
        st.pop();
        if(!visited[x])
        {
            visited[x]=1; visit.push_back(x);
            vector < int > temp = adjacentList[x];
            for(int a : temp)
            {
                if(!visited[a])
                    st.push(a);
            }
        }

    }
    if(visit.size()==n) return true;
    else return false;

}
int main()
{
    //freopen("input.txt","r",stdin);
    int m,n;

    while(cin >> m >> n && m && n)
    {
        map < int , vector < int > > adjacentList;
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if(c==1) adjacentList[a].push_back(b);
            else
            {
                adjacentList[a].push_back(b);
                adjacentList[b].push_back(a);
            }
        }
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(!Check(adjacentList,i,m))
            {
                flag=false;
                break;
            }
        }
        if(flag)    cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
