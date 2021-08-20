#include<bits/stdc++.h>
using namespace std;
long long sum_of_digits(long long n)
{
    long long sum=0;
    while(n!=0)
    {
        int y=n%10;
        sum+=y;
        n=n/10;
    }
    return sum;
}
long long convert_string_to_number(char str[])
{
    long long num=0;
    for(int i=0;str[i];i++)
    {
        num=(num*10)+(str[i]-'0');
    }
    return num;
}
int main()
{
    char str[100];
    cin >> str;
    char temp[100]={'\0'};
    int j=0;
    if(str[0]=='1')
    {
        temp[j++]='9';
        for(int i=2;str[i];i++)
        {
            temp[j++]='9';
        }
    }
    else
    {
        temp[j++]=str[0]-1;
        for(int i=1;str[i];i++)
            temp[j++]='9';
    }
    long long a=convert_string_to_number(temp);
    long long b=convert_string_to_number(str)-a;
    cout << sum_of_digits(a)+sum_of_digits(b) << endl;
    return 0;
}
