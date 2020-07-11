#include<bits/stdc++.h>
using namespace std;
struct patient
{
    int id;
    string name;
    int room;
    int op_begin;
    int op_end;
    int bed;
    int re_begin;
    int re_end;

    int minutes_for_surgery;
    int minutes_for_recovery;
};

struct roomBed
{
    int id;
    int minutes;
    double used;
};

bool sort_by_re_begin(patient a,patient b)
{
    return a.re_begin==b.re_begin ? a.id<b.id : a.re_begin<b.re_begin;
}
bool sort_by_id(patient a,patient b)
{
    return a.id<b.id;
}

int string_to_int(string str)
{
    int result = 0;
    for(char c : str)
    {
        result= (result*10)+(c-'0');
    }
    return result;
}
int time_to_int(string time)
{
    string hour,minute;
    bool flag = true;
    for(int i=0; i!=time.size(); i++)
    {
        if(time[i]==':')
        {
            flag = false;
            continue;
        }

        if(flag)
            hour+=time[i];
        else
            minute+=time[i];
    }
    return (string_to_int(hour)*60)+string_to_int(minute);
}
string int_to_string(int n)
{
    string result = "";
    while(n)
    {
        int y = n%10;
        char c = y+'0';
        result+=c;
        n/=10;
    }
    reverse(result.begin(),result.end());
    if(result.size()==1)
        result="0"+result;
    if(result.size()==0)
        result="00";
    return result;
}

string int_to_time(int time)
{
    int hour = time/60;
    int minute = time%60;

    return int_to_string(hour)+":"+int_to_string(minute);
}
void print(vector< patient > &v)
{
    if(v.size()==100) cout << " ";
    puts(" Patient          Operating Room          Recovery Room");
    if(v.size()==100) cout << " ";
    puts(" #  Name     Room#  Begin   End      Bed#  Begin    End");
    if(v.size()==100) cout << " ";
    puts(" ------------------------------------------------------");

    for(patient p : v)
    {
        if(p.id>=0 && p.id<=9)
            {
                if(v.size()==100) cout << " ";
                cout << " " << p.id;
            }
        else if(p.id>=10 && p.id<=99)
        {
            if(v.size()==100) cout << " ";
            cout << p.id;
        }
        else
            cout << p.id;

        cout << "  " << p.name << "  ";

        if(p.room>=0 && p.room<=9)
            cout << " " << p.room;
        else
            cout << p.room << endl;

        cout <<  "   ";
        string x = int_to_time(p.op_begin);
        if(x[0]=='0')
            x[0]=' ';
        cout << x << "   ";
        x = int_to_time(p.op_end);
        if(x[0]=='0')
            x[0]=' ';
        cout << x << "     ";

        if(p.bed>=0 && p.bed<=9)
            cout << " " << p.bed;
        else
            cout << p.bed;
        cout <<  "   ";
        x = int_to_time(p.re_begin);
        if(x[0]=='0')
            x[0]=' ';
        cout << x << "   ";
        x = int_to_time(p.re_end);
        if(x[0]=='0')
            x[0]=' ';
        cout << x << endl;
    }
}

typedef pair< int, int > pip;

void operation_theater( vector< patient > &v, int operation_rooms, int start, int prepare_operating_room_for_next)
{
    priority_queue< pip, vector<pip>, greater<pip>> pq;

    for(int i=0; i<operation_rooms; i++)
    {
        v[i].op_begin = start;
        v[i].op_end = v[i].op_begin+v[i].minutes_for_surgery;
        v[i].room = i+1;
        pq.push(make_pair(v[i].op_end,v[i].room));
    }

    for(int i=operation_rooms; i<v.size(); i++)
    {
        auto top = pq.top();
        pq.pop();

        v[i].op_begin = top.first+prepare_operating_room_for_next;
        v[i].op_end = v[i].op_begin+v[i].minutes_for_surgery;
        v[i].room = top.second;
        pq.push(make_pair(v[i].op_end,v[i].room));
    }

    return;
}
int total_timeCall(const vector< patient > &v,int start)
{
    int ending_time = 0;
    for(patient p : v)
    {
        ending_time=max(ending_time,p.re_end);
    }
    return abs(ending_time-start);
}
void print_uti(const vector< roomBed > &r, int rooms)
{
    for(int i=0; i!=r.size(); i++)
    {
        if(i<rooms)
            cout << "Room";
        else
            cout << "Bed ";
        cout << " ";
        if(r[i].id>=0 && r[i].id<=9)
            cout << " ";
        cout << r[i].id << "     ";

        if(r[i].minutes>=0 && r[i].minutes<=9)
            cout << "  ";
        else if(r[i].minutes>=10 && r[i].minutes<=99)
            cout << " ";
        cout << r[i].minutes << "  ";

        int x = r[i].used;

        if(x>=0 && x<=9)
            cout << "  ";
        else if(x>=10 && x<=99)
            cout << " ";

        cout.precision(2);
        cout << fixed;
        cout << r[i].used << endl;
    }
}
int main()
{
#ifdef TarekHasan
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif // TarekHasan

    int number_of_operating_rooms;
    int recovery_rooms;
    string starting_hour;
    int start_hour;
    int transport_patient_to_recovery_room;
    int prepare_operating_room_for_next;
    int prepare_recovery_room_for_next;
    int number_of_surgery;

    while(cin >> number_of_operating_rooms >> recovery_rooms >> starting_hour >> transport_patient_to_recovery_room >> prepare_operating_room_for_next>> prepare_recovery_room_for_next >> number_of_surgery)
    {

        start_hour=time_to_int(starting_hour);

        vector< patient > v(number_of_surgery);

        for(int i=0; i<number_of_surgery; i++)
        {
            cin >> v[i].name >> v[i].minutes_for_surgery >> v[i].minutes_for_recovery;
            v[i].id=i+1;
            while(v[i].name.size()<8)
            {
                v[i].name+=" ";
            }
        }
        operation_theater(v,number_of_operating_rooms,start_hour,prepare_operating_room_for_next);

        for(patient &x : v)
        {
            x.re_begin=x.op_end+transport_patient_to_recovery_room;
            x.re_end=x.re_begin+x.minutes_for_recovery;
        }

        sort(v.begin(),v.end(),sort_by_re_begin);
        int arr[recovery_rooms]= {0};
        for(patient &p : v)
        {
            for(int i=0; i<recovery_rooms; i++)
            {
                if(arr[i]<p.re_begin)
                {
                    p.bed=i+1;
                    arr[i]=p.re_end+prepare_recovery_room_for_next;
                    break;
                }
            }
        }
        sort(v.begin(),v.end(),sort_by_id);

        print(v);
        cout << endl;
        puts("Facility Utilization");
        puts("Type  # Minutes  % Used");
        puts("-------------------------");

        int total_time = total_timeCall(v,start_hour);

        vector< roomBed > r;

        for(int i=1; i<=number_of_operating_rooms; i++)
        {
            roomBed rb;
            rb.id = i;
            rb.minutes=0;

            for(patient p : v)
            {
                if(p.room==i)
                {
                    rb.minutes+=p.minutes_for_surgery;
                }
            }

            rb.used = (rb.minutes/(double)total_time)*100;
            r.push_back(rb);
        }

        for(int i=1; i<=recovery_rooms; i++)
        {
            roomBed rb;
            rb.id = i;
            rb.minutes=0;

            for(patient p : v)
            {
                if(p.bed==i)
                {
                    rb.minutes+=p.minutes_for_recovery;
                }
            }
            rb.used = (rb.minutes/(double)total_time)*100;
            r.push_back(rb);
        }

        print_uti(r,number_of_operating_rooms);
        cout << endl;
    }
    return 0;
}
