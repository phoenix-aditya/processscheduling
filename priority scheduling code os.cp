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
    int priority;
};

// the structure name is wrong
bool prioritycomp(processpriority a, processpriority b)
{
    if(a.arrival==b.arrival)
    {
        if(a.priority==b.priority)
            return a.pid<b.pid;
        return a.priority<b.priority;
    }
    return a.arrival<b.arrival;
}
bool prioritychecker(processpriority arr[], int n)
{
    for(int i=0;i<n;i++)
        if(arr[i].burst>0)
            return false;
    
    return true;
}

void prioritys(processpriority arr[], int n)
{
    int currtime=0;
    int waittimeprocess[n];
    int prevexe[n];
    memset(waittimeprocess, 0, sizeof(waittimeprocess));
    memset(prevexe, 0, sizeof(prevexe));
    
    vector<int> gaant;
    
    for(int i=0;i<n;i++)
        prevexe[i]=arr[i].arrival;
            
    while(!prioritychecker(arr, n))
    {
        sort(arr, arr+n, prioritycomp);
        
        for(int i=0;i<n;i++)
        {
            if(arr[i].burst==0 || arr[i].arrival>currtime)
                continue;
            else
            {
                waittimeprocess[arr[i].pid]=currtime-arr[i].arrival;
                currtime+=arr[i].burst;
                arr[i].burst=0;
                gaant.push_back(arr[i].pid);
                break;
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
    cout<<"enter number of processes: ";
    int n;
    cin>>n;
    processpriority arr[n];
    
    cout<<"enter process id(0 format), arrival time , burst time, priority: \n";
    for(int i=0;i<n;i++)
        cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst>>arr[i].priority;
    
    prioritys(arr, n);
    
    return 0;
}
