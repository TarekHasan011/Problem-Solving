#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan


    string str;
    unordered_map< int , string > mp;
    mp[0]="063"; mp[1]="010"; mp[2]="093";
    mp[3]="079"; mp[4]="106"; mp[5]="103";
    mp[6]="119"; mp[7]="011"; mp[8]="127";
    mp[9]="107";

    unordered_map< string , int > mp2;
    mp2["063"] = 0;mp2["010"] = 1;mp2["093"] = 2;
    mp2["079"] = 3;mp2["106"] = 4;mp2["103"] = 5;
    mp2["119"] = 6;mp2["011"] = 7;mp2["127"] = 8;
    mp2["107"] = 9;
    while(cin >> str && str!="BYE")
    {
        int a=0;
        int __plus;
        for(int i=0;i!=str.size();i++)
        {
            if(str[i]=='+')
            {
                __plus=i;
                break;
            }
        }
        for(int i=0;i<__plus;i+=3)
        {
            string temp = "";
            for(int j=0;j<3;j++)
            {
                temp+=str[i+j];
            }
            a= (a*10)+mp2[temp];
        }
        int b=0;
        for(int i=__plus+1;str[i]!= '=' ;i+=3)
        {
            string temp = "";
            for(int j=0;j<3;j++)
            {
                temp+=str[i+j];
            }
            b=(b*10)+mp2[temp];
        }
        int answer = a+b;
        string result="";
        while(answer)
        {
            int y = answer%10;
            answer/=10;
            result= mp[y]+result;
        }
        cout << str;
        cout << result << endl;
    }
}
