#include<bits/stdc++.h>

using namespace std;

#define tillEnd() int t,testCase=1;scanf("%d",&t);while(t--)
#define FEO(container) for(auto ith : container)
#define FEIO(container) for(int i=0; i<container.size();i++)
#define showCase(str) cout<<"Case "<<testCase<<": "<<str<<endl;testCase++
#define read_auto() freopen("in.txt","r",stdin)
#define write_auto() freopen("out.txt","w",stdout)
#define read_write_auto() read_auto();write_auto()
#define to_order() ofstream order("test_cases.txt")
#define space << " " <<
#define get_random(a,b) rand()%(b-a+1)+a
#define lint long long int
#define INF(x) INT_MAX-x
#define boost_io() ios_base::sync_with_stdio(false);cin.tie(false)

int seive[100010]={0};

int cache[100010]={0};

int f(int x){
    if(x<=2){
        return x;
    }
    else if(seive[x]==0){
        cache[x]=0;
        return 0;
    }
    else if(cache[x]!=0){
        return cache[x];
    }

    int min1=100001,min2=100001,m1,m2;

    int sq = ceil(sqrt(x));

    for(int i=1;i<=sq;i++){
        if(x%i==0){
            m1=i;
            m2=x/i;

            if(m1+m2<=min1+min2){
                min1=m1;
                min2=m2;
            }
            else{
                break;
            }
        }
    }

//    cout<<min1 space min2<<endl;

    cache[x]=f(min1)+f(min2);

    return cache[x];
}

int main(){

//    read_auto();

    int x;

    cin>>x;

    for(int i=2;i<=x;i++){

        if(seive[i]==0){

            for(int j=i+i;j<=x;j+=i){
                seive[j]=1;
            }

        }

    }

//    for(int i=0;i<=x;i++){
//        if(seive[i]==0){
//            cout<<i<<" ";
//        }
//    }

    cout<<f(x)<<endl;

    return 0;
}
