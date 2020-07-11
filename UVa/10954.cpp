#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan
    int n;
    while(cin >> n && n)
    {
        priority_queue< int , vector< int > , greater< int > > pq;

        for(int i=0;i<n;i++)
        {
            int temp; cin >> temp;
            pq.push(temp);
        }
        int sum = 0;
        while(pq.size()>=2)
        {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            sum+=(a+b);
            pq.push(a+b);
        }
        cout << sum << endl;
    }
}
