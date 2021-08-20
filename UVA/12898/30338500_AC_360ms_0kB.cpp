#include<bits/stdc++.h>
using namespace std;
long long int count_one(long long int a,long long int i)
{
    a+=1LL;
    long long int prod = 2LL << i;
    long long int ones = (a/prod) * (prod/2);
    if((a%prod) > (prod/2))
        ones+=((a%prod)-(prod/2));
    return ones;
}
pair< long long int , long long int > answer(long long int a, long long int b)
{
    long long int prod = 1;

    long long int or_result = 0;
    long long int and_result = 0;

    for(long long int i=0;i<=61;i++)
    {
        long long int number_of_one = count_one(b,i) - count_one(a-1,i);
        long long int number_of_zero = (b-a+1) - number_of_one;

        if(number_of_one>0)
            or_result+=prod;
        if(number_of_zero==0)
            and_result+=prod;
        prod<<=1;
    }
    return make_pair(or_result,and_result);
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int tt; cin >> tt;
    int test_Cases = 0;
    while(tt--)
    {
        long long int a,b; cin >> a >> b;
        auto result = answer(a,b);
        printf("Case %d: ",++test_Cases);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}
