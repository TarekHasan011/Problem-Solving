#include<bits/stdc++.h>
using namespace std;
int OR(int a, int b)
{
    return max(a,b) == 1;
}

int XOR(int a, int b)
{
    return !(a==b);
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int tt; cin >> tt;
    while(tt--)
    {
        long long int a,b; cin >> a >> b;

        bitset< 62 > bits(a);
        string first = bits.to_string();

        bitset< 62 > _bits(b);
        string second = _bits.to_string();

        string temp = "";
        bool possible = true;

        for(int i=0;i<first.length();i++)
        {
            if(OR(0,first[i]-'0') == XOR(0,second[i]-'0'))
                temp+="0";
            else if(OR(1,first[i]-'0') == XOR(1,second[i]-'0'))
                temp+="1";
            else
            {
                possible = false;
                break;
            }
        }
        if(!possible)
            cout << "-1\n";
        else
        {
            long long int prod = 1;
            long long int answer = 0;
            for(int i=temp.length()-1;i>=0;i--)
            {
                if(temp[i]=='1')
                    answer+=prod;
                prod<<=1;
            }
            cout << answer << "\n";
        }

    }
    return 0;

}
