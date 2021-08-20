#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define PrintArray(a,n) for(int i=0;i<n;i++) cout << a[i] << " "; cout << endl;
#define CopyArray(a,temp,n) for(int i=0;i<n;i++) temp[i]=a[i];
#define InputArray(a,n) for(int i=0;i<n;i++) cin >> a[i];
#define MAX(a,b,c) max(max(a,b),c)
#define SumInRange(a,b) ((b*(b+1))/2)-(((a-1)*(a))/2)
#define Different_Random srand(time(NULL))
#define Random(a,b) (rand()%((b+1)-a))+a
#define __delete(v,n) v.erase(remove(v.begin(),v.end(),n),v.end())

#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)
#define newline cout << "\n";

#define read(x)    freopen(#x, "r", stdin)
#define write(x)   freopen(#x, "w", stdout)

#define all(x)     x.begin(), x.end()
#define dbg(args...)    {string sss(#args);sss+=',';cerr<<"-->";debugger::call(all(sss), args);cerr<<"\n";}
#define dbgA(A, n)      {cerr<<"-->"<<#A<<"=(";forn(i, n)cerr<<A[i]<<" ";cerr<<")\n";}
#define dbgA2(A, n, m)  {cerr<<"-->"<<#A<<"=\n";forn(i, n){forn(j, m){cerr<<setw(4)<<A[i][j]<<" ";}cerr<<"\n";}cerr<<"\n";}

struct debugger
{
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest)
    {
        string b;
        for(; *it!=','; ++it) if(*it!=' ')b+=*it;
        cerr << b << " = " << a << " ";
        call(++it, ed, rest...);
    }
};

template<typename T>
T Max(T a)
{
    return a;
}

template<typename T, typename... Args>
T Max(T a, Args... args)
{
    return a > Max(args...)? a : Max(args...);
}

template<typename T>
T Min(T a)
{
    return a;
}

template<typename T, typename... Args>
T Min(T a, Args... args)
{
    return a < Min(args...)? a : Min(args...);
}


//int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
//int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//int knight_x[] = {2, 2, -2, -2, 1, 1, -1, -1};
//int knight_y[] = {1, -1, 1, -1, 2, -2, 2, -2};

/*
cout.precision(x);
cout << fixed;
*/

typedef long long int ll;
typedef unsigned long long int ull;
const double GOLD = (1.0 + sqrt(5.0))/2.0;
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

ll expo(ll a, ll n)
{
    ll result = 1;
    while(n)
    {
        if(n%2) result*=a;
        a*=a;
        n/=2;
    }
    return result;
}

ll mod_expo(ll x,ll y,ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
const int MOD = 1e9+7;

int STOI(string str)
{
    int answer = 0;
    for(char c : str)
    {
        answer = (answer*10) + (c-'0');
    }
    return answer;
}
int octalToDecimal(string oc)
{
    int octalNumber = STOI(oc);

    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}
int hexadecimalToDecimal(string num)
{
    int len = num.size();

    int base = 1;
    int temp = 0;
    for (int i=len-1; i>=0; i--)
    {
        if (num[i]>='0' && num[i]<='9')
        {
            temp += (num[i] - 48)*base;
            base = base * 16;
        }
        else if (num[i]>='A' && num[i]<='F')
        {
            temp += (num[i] - 55)*base;
            base = base*16;
        }
    }
    return temp;
}
int decimalToDecimal(string num)
{
    return STOI(num);
}
int number_ta_den(string str)
{
    int x = count(str.begin(),str.end(),'x');
    if(x>0)
        return hexadecimalToDecimal(str);
    if(str[0]=='0')
        return octalToDecimal(str);
    return STOI(str);
}

int main()
{
#ifdef TarekHasan
    read(input.txt);
#endif // TarekHasan
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int q;


    while(cin >> str >> q && str!="0" && q)
    {
        int current = number_ta_den(str);
        int counter = 0;

        while(q--)
        {
            string stri;
            int current_result;
            cin >> stri >> current_result;

            int result_should_be;

            if(stri=="++i")
                result_should_be = current+1;
            else if(stri=="i++")
                result_should_be = current;
            else if(stri=="--i")
                result_should_be = current-1;
            else if(stri=="i--")
                result_should_be = current;
            else if(stri=="i")
                result_should_be = current;

            if(result_should_be==current_result)
            {
                counter++;
                if(stri=="i++" || stri=="++i")
                    current = current+1;
                if(stri=="i--" || stri=="--i")
                    current = current-1;
            }
            else
            {
                if(stri=="i--")
                    current = current_result-1;
                else if(stri=="i++")
                    current = current_result+1;
                else
                    current = current_result;
            }

        }
        cout << counter << "\n";


    }


    cerr << "time = " << clock() << " ms" << '\n';
    return 0;
}


