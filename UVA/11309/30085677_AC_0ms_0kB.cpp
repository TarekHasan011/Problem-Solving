#include<bits/stdc++.h>
using namespace std;
bool palindrome(int n)
{
    int given = n;
    int temp = 0;
    while(n)
    {
        temp = (temp*10) + (n%10);
        n/=10;
    }
    return given == temp;
}

vector< int > answers;

void __init__()
{
    for(int i=0;i<=23;i++)
    {
        for(int j=0;j<=59;j++)
        {
            int temp = (i*100)+j;
            if(palindrome(temp))
                answers.push_back((i*60)+j);
        }
    }
    return;
}
int STOI(string str)
{
    int answer = 0;
    for(char c : str)
    {
        answer = (answer*10) + (c-'0');
    }
    return answer;
}
int next_time(int current_time)
{
    int left = 0;
    int right = answers.size()-1;
    int nt = 0;
    while(left<=right)
    {
        int mid = left + ((right-left)/2);

        if(answers[mid]>current_time)
        {
            nt = answers[mid];
            right = mid-1;
        }
        else
            left = mid+1;
    }
    return nt;
}
string itos(int n)
{
    string temp = "";
    while(n)
    {
        temp += ((n%10)+'0');
        n/=10;
    }
    reverse(temp.begin(),temp.end());
    while(temp.size()<2)
    {
        temp = "0" + temp;
    }
    return temp;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    __init__();

    int tt; cin >> tt;
    while(tt--)
    {
        string str; cin >> str;
        int curret_time = (STOI(str.substr(0,2))*60)+(STOI(str.substr(3,2)));
        int time = next_time(curret_time);
        int hour = time/60;
        int minute = time%60;
        cout << itos(hour) << ":" << itos(minute) << endl;
    }



    return 0;
}
