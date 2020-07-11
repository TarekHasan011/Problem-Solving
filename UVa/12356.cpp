#include<bits/stdc++.h>
using namespace std;
struct List{
    int data;
    List *next, *prev;
};
typedef struct List node;
node *root,*tail;
void add(int data,unordered_map< int , node* >& mp)
{
    if(root==NULL)
    {
        root = new node();
        root->data=data;
        root->next=NULL;
        root->prev=NULL;
        tail = root;
    }
    else
    {
        node* temp = new node();
        temp->data = data;
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    mp[data]=tail;
}
void print()
{
    node* temp = root;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int s,b;

    while(cin >> s >> b && s && b)
    {
        root=NULL;
        unordered_map< int , node* > mp;
        for(int i=1;i<=s;i++)
            add(i,mp);
        while(b--)
        {
            int l,r; cin >> l >> r;

            if(root==NULL)
            {
                cout << "* *\n";
                continue;
            }

            if(mp[l]->prev!=NULL)
                cout << mp[l]->prev->data << " ";
            else
                cout << "* ";

            if(mp[r]->next!=NULL)
                cout << mp[r]->next->data << "\n";
            else
                cout << "*\n";

            if(mp[l]->prev!=NULL && mp[r]->next!=NULL)
            {
                mp[l]->prev->next = mp[r]->next;
                mp[r]->next->prev = mp[l]->prev;
            }
            else if(mp[r]->next==NULL && mp[l]->prev!=NULL)
            {
                mp[l]->prev->next = NULL;
            }
            else if(mp[l]->prev==NULL && mp[r]->next!=NULL)
            {
                mp[r]->next->prev = NULL;
            }
            else
            {
                root=NULL;
            }
        }
        cout << "-\n";
    }



    return 0;
}
