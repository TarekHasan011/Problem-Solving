#include<bits/stdc++.h>
using namespace std;
void SWAP(int &a, int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);


    int n,m,k; cin >> n >> m >> k;
    int current_position = 1;
    bool hole[n+1]={false};

    for(int i=0;i<m;i++)
    {
        int temp; cin >> temp;
        hole[temp] = true;
    }

    bool move_hobe_naki = hole[current_position] ? false : true;
    for(int i=0;i<k;i++)
    {
        int u,v; cin >> u >> v;
        if(current_position==v)
            SWAP(u,v);

        if(current_position==u && move_hobe_naki)
        {
            current_position = v;
            move_hobe_naki = hole[current_position] ? false : true;
        }
    }
    cout << current_position << "\n";

    return 0;

}
