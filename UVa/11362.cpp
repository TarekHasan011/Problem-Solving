#include<bits/stdc++.h>
using namespace std;
bool compare(string a, string b)
{
    return a.size()<b.size();
}
struct node{
    bool end_mask;
    node* next[10+1];
    node()
    {
        end_mask = false;
        for(int i=0;i<10;i++)
            next[i]=NULL;
    }
}* root;
bool insertion(string str)
{
    node* curr = root;

    for(int i=0;i!=str.size();i++)
    {
        int id = str[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr = curr->next[id];
        if(curr->end_mask) return true;
    }
    curr->end_mask = true;
    return false;
}

void del(node* curr)
{
    for(int i=0;i<10;i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan
    int tt ; cin >> tt;

    while(tt--)
    {
        int n; cin >> n;
        vector< string > v(n);
        for(int i=0;i<n;i++) cin >> v[i];

        sort(v.begin(),v.end(),compare);

        root = new node();

        bool possible = true;
        for(string s : v)
        {
            if(insertion(s))
            {
                possible = false;
                break;
            }
        }

        possible ? cout << "YES\n" : cout << "NO\n";

        del(root);
    }

    return 0;

}
