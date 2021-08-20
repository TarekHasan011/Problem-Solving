///*** author: HM Imu SC ***\\\

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

vector<int> packets;
int cache[110][110];
int n,k;

int tryToTake(int kg,int packet){

    if(packet==0){
        if(kg==0){
            return 0;
        }
        else{
            return 200000;
        }
    }

    if(kg==0){
        return 0;
    }

    if(cache[kg][packet]!=-1){
        return cache[kg][packet];
    }

    int _n,nMin=200000;

    for(int i=0;i<packets.size();i++){
        if(packets[i]!=-1 && kg-i-1>=0){
            _n=packets[i]+tryToTake(kg-i-1,packet-1);
        }
        else{
            _n=200000;
        }
        nMin=min(nMin,_n);
    }

    cache[kg][packet]=nMin;

    return cache[kg][packet];
}

int main(){

//    read_auto();

    tillEnd(){

        memset(cache,-1,sizeof(cache));
        packets.clear();

        cin>>n>>k;

        int m=k;

        while(m--){
            int x;
            cin>>x;
            packets.push_back(x);
        }

        int cost = tryToTake(k,n);

        if(cost>=200000){
            cout<<"-1"<<endl;
        }
        else{
            cout<<cost<<endl;
        }
    }

    return 0;
}
