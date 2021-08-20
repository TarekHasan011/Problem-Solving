#include<bits/stdc++.h>
using namespace std;

int main()
{
    double ncow,ncar,ns;
    while(cin >> ncow >> ncar >> ns)
    {
        int total_door=ncow+ncar;
        double chance=(ncow/total_door)*(ncar/(total_door-1-ns))+(ncar/total_door)*((ncar-1)/(total_door-1-ns));
        cout << fixed << setprecision(5) << chance << "\n";
    }
}
