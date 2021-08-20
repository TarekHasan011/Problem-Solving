#include<bits/stdc++.h>
using namespace std;
int parent[200007];

void path_print(int n)
{
    if(parent[n]==n)
    {
        cout << n << " ";
        return;
    }
    path_print(parent[n]);
    cout << n << " ";
    return;
}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    parent[1] = 1;
    for(int i=2;i<=n;i++)
    {
        int temp; cin >> temp;
        parent[i] = temp;
    }
    path_print(n);
    cout << "\n";
    return 0;

}
