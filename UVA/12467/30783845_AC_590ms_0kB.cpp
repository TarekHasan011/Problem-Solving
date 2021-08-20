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


const int base = 31;
const int mod = 1000000007;

int m_expo[1000007];

vector< int > v_prefix_Hash;
vector< int > v_another_prefix_Hash;

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

void prefix_Hash(string &str, vector<int> &Hash_values)
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

int Hash_substring(int i , int j,vector< int > &Hash_values)
{
    int value = Hash_values[j];
    if(i-1>=0)
        value = (value - (((long long)(Hash_values[i-1]%mod) * (m_expo[j-i+1]%mod))%mod)+mod)%mod;
    return value;
}

int longest_prefix_matching(string &str, string &temp, int it)
{
    int left = 0;
    int right = (temp.size()-it)-1;
    int answer = 0;

    while(left<=right)
    {
        int mid = left + ((right-left)/2);

        int first = Hash_substring(0,mid,v_prefix_Hash);
        int second = Hash_substring(it,it+mid,v_another_prefix_Hash);

        if(first==second)
        {
            answer = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    }
    return answer+1;
}

int main()
{
    #ifdef TarekHasan
        read(input.txt);
    #endif // TarekHasan
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);



    for(int i=0;i<=1000001;i++)
        m_expo[i] = mod_expo(base,i);


    __test
    {
        v_prefix_Hash.clear();
        v_another_prefix_Hash.clear();

        string str; cin >> str;
        string temp = str;
        reverse(temp.begin(),temp.end());

        prefix_Hash(str,v_prefix_Hash);
        prefix_Hash(temp,v_another_prefix_Hash);

        vector< int > index;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]==str[0])
                index.push_back(i);
        }


        int p_index = 0;
        int max_answer = 0;

        for(int i=0;i<index.size();i++)
        {
            int ans = longest_prefix_matching(str,temp,index[i]);
            if(ans > max_answer)
            {
                max_answer = ans;
                p_index = index[i];
            }
        }

        for(int i=p_index+max_answer-1;i>=p_index;i--)
            cout << temp[i];
        cout << "\n";


    }

    cerr << "time = " << clock() << " ms" << '\n';
    return 0;
}



