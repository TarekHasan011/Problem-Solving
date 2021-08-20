#include<bits/stdc++.h>
using namespace std;
int btod(string str)
{
    int k = 1;
    int answer = 0;
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='1')
            answer+=k;
        k<<=1;
    }
    return answer;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan


    int tt; cin >> tt;
    while(tt--)
    {
        int n; cin >> n;
        string str = "1001";
        string number = "";
        for(int i=0;i<n;i++) number+=str;

        int start = 0;
        for(int i=number.size()-1;start<n && i>=0;i--)
        {
            number[i]='0';
            start++;
        }
        for(int i=0;i<number.size();i+=4)
        {
            string temp = "";
            temp+=number[i+0];
            temp+=number[i+1];
            temp+=number[i+2];
            temp+=number[i+3];
            int t = btod(temp);
            if(t==0)
                cout << "8";
            else
                cout << t;
        }
        cout << endl;
    }
}
