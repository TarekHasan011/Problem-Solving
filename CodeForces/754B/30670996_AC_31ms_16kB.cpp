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

struct debugger{
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it) if(*it!=' ')b+=*it;
        cerr << b << " = " << a << " ";
        call(++it, ed, rest...);
    }
};

template<typename T>
T Max(T a) {return a;}

template<typename T, typename... Args>
T Max(T a, Args... args){ return a > Max(args...)? a : Max(args...);}

template<typename T>
T Min(T a) {return a;}

template<typename T, typename... Args>
T Min(T a, Args... args){ return a < Min(args...)? a : Min(args...);}


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
        a*=a; n/=2;
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


char arr[4][4];

bool valid(int i, int j)
{
    return i>=0 && i<4 && j>=0 && j<4;
}
bool win()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]=='x')
            {
                int first_i = i; int first_j = j-1;
                int first_ii = i; int first_jj = j+1;

                if(valid(first_i,first_j) && valid(first_ii,first_jj) && arr[first_i][first_j]=='x' && arr[first_ii][first_jj]=='x')
                    return true;

                first_i = i-1; first_j = j;
                first_ii = i+1; first_jj = j;

                if(valid(first_i,first_j) && valid(first_ii,first_jj) && arr[first_i][first_j]=='x' && arr[first_ii][first_jj]=='x')
                    return true;

                first_i = i-1; first_j = j-1;
                first_ii = i+1; first_jj = j+1;

                if(valid(first_i,first_j) && valid(first_ii,first_jj) && arr[first_i][first_j]=='x' && arr[first_ii][first_jj]=='x')
                    return true;


                first_i = i+1; first_j = j-1;
                first_ii = i-1; first_jj = j+1;

                if(valid(first_i,first_j) && valid(first_ii,first_jj) && arr[first_i][first_j]=='x' && arr[first_ii][first_jj]=='x')
                    return true;

            }
        }
    }
    return false;
}

bool solve()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]=='.')
            {
                arr[i][j] = 'x';
                if(win())
                    return true;
                arr[i][j] = '.';
            }
        }
    }
    return false;
}
int main()
{
    #ifdef TarekHasan
        read(input.txt);
    #endif // TarekHasan
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin >> arr[i][j];

    cout << (solve() ? "YES" : "NO") << "\n";


    cerr << "time = " << clock() << " ms" << '\n';
    return 0;
}


