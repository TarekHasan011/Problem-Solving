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


unordered_set< int > primeFactors(int n)
{


    unordered_set< int > st;

    if(n==1)
    {
        st.insert(1);
        return st;
    }

	while (n % 2 == 0)
	{
		st.insert(2);
		n = n/2;
	}
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			st.insert(i);
			n = n/i;
		}
	}
	if (n > 2)
		st.insert(n);
    return st;
}
int parent[1000007];

void SET()
{
    for(int i=0;i<=1000000;i++)
        parent[i] =i;

}
int FIND(int x)
{
    if(parent[x]==x) return x;
    else return parent[x] = FIND(parent[x]);
}
void UNION(int u , int v)
{
    int a = FIND(u);
    int b = FIND(v);
    if(a!=b)
        parent[b] = a;
}

unordered_map< int , bool > exist;


int main()
{
    #ifdef TarekHasan
        read(input.txt);
        write(output.txt);
    #endif // TarekHasan
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);


    __test
    {
        int n; cin >> n;
        vector< int > v(n);
        for(int i=0;i<n;i++) cin >> v[i];

        SET();
        exist.clear();


        for(int x : v)
        {
            unordered_set< int > temp1 = primeFactors(x);
            vector< int > temp;
            for(int x : temp1)
                temp.push_back(x);

            if(temp.size()) exist[temp[0]] = true;

            for(int i=1;i<temp.size();i++)
            {
                UNION(temp[i],temp[i-1]);
                exist[temp[i]] = true;
            }
        }

        unordered_set< int > st;
        for(auto x : exist)
            st.insert(FIND(x.first));

        Cases
        if(count(v.begin(),v.end(),1)>0)
            cout << (st.size()-1)+count(v.begin(),v.end(),1) << "\n";
        else
            cout << st.size() << "\n";


    }

    cerr << "time = " << clock() << " ms" << '\n';
    return 0;
}



