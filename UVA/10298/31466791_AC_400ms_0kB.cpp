#include<bits/stdc++.h>
using namespace std;

const int base = 137;
const int mod = 1000000009;

vector< int > Hash_values;
int m_expo[1000007];


int mod_expo(int x,int y)
{
    int res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1) res = ((long long)res*x) % mod;
        y = y>>1;
        x = ((long long)x*x) % mod;
    }
    return res;
}

void prefix_Hash(string &str)
{
    for(char c : str)
    {
        if(Hash_values.size()==0)
            Hash_values.push_back(c);
        else
        {
            int prev = Hash_values.back();
            prev=((long long)(prev%mod)*(base%mod))%mod;
            prev = (prev+c)%mod;
            Hash_values.push_back(prev);
        }
    }
    return;
}

int Hash_substring(int i , int j)
{
    int value = Hash_values[j];
    if(i-1>=0)
        value = (value - (((long long)(Hash_values[i-1]%mod) * (m_expo[j-i+1]%mod))%mod)+mod)%mod;
    return value;
}

int Hash(string &str)
{
    int hash_value = str[0]%mod;
    for(int i=1;i<str.length();i++)
    {
        hash_value = ((long long)(hash_value%mod)*(base%mod))%mod;
        hash_value = (hash_value+str[i])%mod;
    }
    return hash_value;
}
int counter(string &str, string &pattern)
{
    int pattern_hash = Hash_values[pattern.size()-1];
    int Count = 0;

    for(int i=0;i<=str.length()-pattern.length();i++)
    {
        int current_hash = Hash_substring(i,i+pattern.length()-1);
        if(current_hash==pattern_hash)
        {
            Count++;
            i = i+pattern.length()-1;
        }
    }
    return Count;
}

#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    for(int i=0;i<=1000001;i++)
        m_expo[i] = mod_expo(base,i);

    string str;

    while(getline(cin,str,'\n') && str[0]!='.')
    {
        Hash_values.clear();

        prefix_Hash(str);
        string temp = "";
        int n = str.length();
        int answer_length = 0;

        for(int i=0;i<n;i++)
        {
            temp+=str[i];
            int len = i+1;
            /*if(n/len==counter(str,temp))
            {
                answer_length = len;
                break;
            }*/
            if(n%len==0)
            {
                if(n/len==counter(str,temp))
                {
                    answer_length = (n/len);
                    break;
                }
            }
        }

        cout << answer_length << "\n";
    }

    return 0;
}

