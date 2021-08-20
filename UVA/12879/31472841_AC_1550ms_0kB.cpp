//Problem :: https://www.spoj.com/problems/VFMUL/

#include <bits/stdtr1c++.h>
const double EPS = 1e-9;
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

typedef complex<double> complx;

/// Computes the discrete fourier transformation of the vector when inv = 1
/// Computes the inverse discrete fourier transformation when inv = -1

void FFT(vector <complx> &ar, int inv)
{
    int i, j, l, len, n = ar.size();
    const double p = 4.0 * inv * acos(0.0);

    for (i = 1, j = 0; i < n; i++)
    {
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }

    for (l = 1, len = 2; len <= n; l <<= 1, len <<= 1)
    {
        double theta = p / len;
        complx mul(cos(theta), sin(theta));

        for (i = 0; i < n; i += len)
        {
            complx w(1.0, 0.0);
            for (j = 0; j < l; j++)
            {
                complx u = ar[i + j], v = ar[i + j + l] * w;
                ar[i + j] = u + v, ar[i + j + l] = u - v;
                w *= mul;
            }
        }
    }

    if (inv == -1)
    {
        for (i = 0; i < n; i++) ar[i] /= n;
    }
}

/***
    Computes the circular convolution of A and B, denoted A * B, in C
    A and B must be of equal size, if not normalize before calling function
    Example to demonstrate convolution for n = 5:

    c0 = a0b0 + a1b4 + a2b3 + a3b2 + a4b1
    c1 = a0b1 + a1b0 + a2b4 + a3b3 + a4b2
    ...
    c4 = a0b4 + a1b3 + a2b2 + a3b1 + a4b0


    Note: If linear convolution is required, pad with zeros appropriately, as in multiplication

***/

void convolution(vector <complx> A, vector <complx> B, vector<complx>& C)
{
    int n, m, i;
    n = A.size();
    m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));
    A.resize(m, 0), B.resize(m, 0), C.resize(m, 0);

    FFT(A, 1), FFT(B, 1);
    for (i = 0; i < m; i++) C[i] = A[i] * B[i];
    FFT(C, -1);
}

/// Multiplies two polynomials A and B and return the coefficients of their product in C
void multiply(vector <complx> A, vector <complx> B, vector<complx>& C)
{
    int n, m, i;
    n = A.size() + B.size() - 1;
    m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));
    A.resize(m, 0), B.resize(m, 0), C.resize(m, 0);

    FFT(A, 1), FFT(B, 1);
    for (i = 0; i < m; i++) C[i] = A[i] * B[i];
    FFT(C, -1);
}

/*string multiplyString(string a, string b) {
    vector<complx> A, B, C;
    for(int i = 0; i < a.size(); i++) { A.push_back(a[i] - '0'); }
    for(int i = 0; i < b.size(); i++) { B.push_back(b[i] - '0'); }

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    //edited By TarekHasan
    if(A.size()<B.size())
    {
        while(A.size()!=B.size())
            A.push_back(0);
    }
    if(B.size()<A.size())
    {
        while(A.size()!=B.size())
            B.push_back(0);
    }
    //TarekHasan
    multiply(A, B, C);

    string out;
    int carry = 0;
    for(int i = 0; i < C.size(); i++) {
        int num = floor(C[i].real() + 0.5) + carry;
        carry = num / 10;
        out.push_back((num % 10) + '0');
    }
    while(out.size()>1 && out[out.size() - 1] == '0') { out.pop_back(); } //Trim leading zeros
    reverse(out.begin(), out.end());
    return out;
}*/


int main()
{
#ifdef TarekHasan
    freopen("input.txt","r",stdin);
#endif // TarekHasan

    int n,m;
    while(cin >> n)
    {
        vector< complx > A(200007,0);
        vector< complx > B(200007,0);
        vector< complx > C;

        for(int i=0; i<n; i++)
        {
            int temp;
            cin >> temp;
            A[temp] = 1;
            B[temp] = 1;
        }

        multiply(A,B,C);
        cin >> m;
        int counter = 0;
        for(int i=0; i<m; i++)
        {
            int temp;
            cin >> temp;
            if(C[temp].real()>EPS || A[temp].real()>EPS)
                counter++;
        }
        cout << counter << "\n";
    }

    return 0;
}

