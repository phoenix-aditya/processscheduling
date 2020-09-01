#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

struct processpriority{
    int burst;
    int pid;
    int arrival;
};

bool rrcomp(processpriority a, processpriority b)
{
    if(a.arrival==b.arrival)
    {
        if(a.arrival==b.arrival)
            return a.pid<b.pid;
        return a.arrival<b.arrival;
    }
    return a.arrival<b.arrival;
}
bool rrchecker(processpriority arr[], int n)
{
    for(int i=0;i<n;i++)
        if(arr[i].burst>0)
            return false;
    
    return true;
}

void roundrobin(processpriority arr[], int n, int quantum)
{
    int currtime=0;
    int waittimeprocess[n];
    int prevexe[n];
    memset(waittimeprocess, 0, sizeof(waittimeprocess));
    memset(prevexe, 0, sizeof(prevexe));
    
    vector<int> gaant;
    
    for(int i=0;i<n;i++)
        prevexe[i]=arr[i].arrival;
    
    sort(arr,arr+n,rrcomp);
            
    while(!rrchecker(arr, n))
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i].burst==0 || arr[i].arrival>currtime)
                continue;
            else
            {
                if(arr[i].burst>=quantum)
                {
                    waittimeprocess[arr[i].pid]+=(currtime-prevexe[arr[i].pid]);
                    prevexe[arr[i].pid]=currtime+quantum;
                    currtime+=quantum;
                    arr[i].burst-=quantum;
                    gaant.push_back(arr[i].pid);
                    
                }
                else
                {
                    waittimeprocess[arr[i].pid]+=(currtime-prevexe[arr[i].pid]);
                    prevexe[arr[i].pid]=currtime+1;
                    ++currtime;
                    --arr[i].burst;
                    gaant.push_back(arr[i].pid);
                }
            }
        }
    }
    
    float totalwt=0;
    
    for(int i=0;i<n;i++)
        totalwt+=waittimeprocess[i];
    
    totalwt=float(1.0*totalwt/n);
    
    cout<<"avg waiting time: "<<totalwt<<endl;
    cout<<"wait time per process: \n";
    for(int i=0;i<n;i++)
        cout<<waittimeprocess[i]<<" ";
    cout<<endl;
    
    for(auto x: gaant)
        cout<<x+1<<" ";
    cout<<endl;
}

int main()
{
    int quantum;
    cout<<"enter number of processes: ";
    int n;
    cin>>n;
    processpriority arr[n];
    
    cout<<"enter process id(0 format), arrival time , burst time: \n";
    for(int i=0;i<n;i++)
        cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst;
    
    cout<<"enter time quantum\n";
    cin>>quantum;
    
    roundrobin(arr, n,quantum);
    
    return 0;
}
