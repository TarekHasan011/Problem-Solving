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

#define _size 1000001

int ar[_size]={0};
vector<int> prime;
vector<int> digit_prime;

int prime_b_search(int l,int r,int target,int bound=0){

//    cout<<l space prime[l] space r space prime[r]<<endl;

    int m = (l+r)/2;

//    cout<<digit_prime[m]<<endl;

    if(digit_prime[m]==target){
        return m;
    }
    else if(l==r){

        if(bound){
            if(digit_prime[r]>target){
                return r;
            }
            else{
                return -1;
            }
        }
        else{
            if(digit_prime[r]>target){
                return r-1;
            }

            return r;
        }
    }
    else if(target>digit_prime[m]){
        return prime_b_search(m+1,r,target,bound);
    }
    else{
        return prime_b_search(l,m,target,bound);
    }
}

bool chk_digit_prime(int i){

    int digit_sum=0;

    while(i>0){
        digit_sum+=(i%10);
        i/=10;
    }

    return !ar[digit_sum];
}

int main(){

//    read_auto();

    for(int i=2;i<=_size-1;i++){
        if(ar[i]==0){
            prime.push_back(i);
        }
        else{
            continue;
        }
        for(int j=i+i;j<=_size-1;j+=i){
            ar[j]=1;
        }
    }

    for(int i : prime){
        if(chk_digit_prime(i)){
            digit_prime.push_back(i);
        }
    }

    int t1,t2;

//    cout<<"Size: "<<prime.size()<<endl;


//    for(int i=0;i<20;i++){
//        cout<<i<<" : "<<digit_prime[i]<<endl;
//    }

    tillEnd(){

//        cout<<"N: "<<n<<endl;

        scanf("%d%d",&t1,&t2);

        int lower_idx = prime_b_search(0,digit_prime.size()-1,t1,1);
        int upper_idx = prime_b_search(0,digit_prime.size()-1,t2);

//        cout<<upper_idx space lower_idx<<endl;

        printf("%d\n",upper_idx-lower_idx+1);
    }

    return 0;
}
