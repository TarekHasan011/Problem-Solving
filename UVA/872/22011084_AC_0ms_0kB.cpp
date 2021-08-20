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

map<int,vector<int> > adjList;
vector<int> alphabets;
vector<int> indegreeOf;
vector<bool> visited;
list<int> order;
bool no;

void resetAll(int n){
//    cout<<"Size: "<<n<<endl;
    map<int,vector<int> > a;
    adjList = a;
    alphabets.clear();
    indegreeOf.assign(26,0);
    visited.assign(26,false);
    list<int> l;
    order=l;
    no=true;
}

void printOrder(){
    no=false;

    bool newSpace=false;

    FEO(order){

        if(newSpace){
            cout<<" ";
        }
        newSpace=true;

        cout<<(char)(ith+'A');
    }
    cout<<endl;
}

void showAllTopOrder(){

//    cout<<"p1 "<<order.size()<<endl;

    FEO(alphabets){
//        cout<<"Visit: "<<visited[ith] space "Indegree: "<<indegreeOf[ith] space ith<<endl;
        if(indegreeOf[ith]==0 && !visited[ith]){

//            cout<<"Called"<<endl;

            visited[ith]=true;
            order.push_back(ith);

            for(int i : adjList[ith]){
                indegreeOf[i]--;
            }

            showAllTopOrder();

            visited[ith]=false;
            order.pop_back();

            for(int i : adjList[ith]){
                indegreeOf[i]++;
            }
        }
    }

    if(order.size()==alphabets.size()){
        printOrder();
    }

}

int main(){

//    read_auto();
//
//    read_write_auto();

    string rawAlphabets;
    bool newLine=false;
    int t;
    cin>>t;

    getline(cin,rawAlphabets);

    while(t--){
        getline(cin,rawAlphabets);
        getline(cin,rawAlphabets);

        resetAll((rawAlphabets.size()+1)/2);

        for(int i=0;i<rawAlphabets.size();i++){
            if(rawAlphabets[i]!=32){
//                cout<<rawAlphabets[i] space rawAlphabets[i]-'A'<<" ";
                alphabets.push_back(rawAlphabets[i]-'A');
            }
        }

//        cout<<endl;

        getline(cin,rawAlphabets);

        string edge;

        stringstream ss(rawAlphabets);

        while(ss>>edge){
            adjList[edge[0]-'A'].push_back(edge[2]-'A');
            indegreeOf[edge[2]-'A']++;
        }

        if(newLine){
            cout<<endl;
        }
        newLine=true;

        showAllTopOrder();

        if(no){
            cout<<"NO"<<endl;
        }
    }


    return 0;
}
