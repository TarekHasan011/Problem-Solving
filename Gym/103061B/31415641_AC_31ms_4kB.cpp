#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &str)
{
    int left = 0;
    int right = str.length()-1;
    while(left<right)
    {
        if(str[left]!=str[right]) return false;
        left++;
        right--;
    }
    return true;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    string str; cin >> str;
    int answer = INT_MAX;

    for(int i=0;i<str.size();i++)
    {
        string temp = "";
        for(int j=i;j<str.size();j++)
        {
            temp+=str[j];
            if(!isPalindrome(temp))
                answer = min(answer,(int)temp.length());
        }
    }
    cout << (answer!=INT_MAX ? answer : -1) << "\n";
    return 0;
}
