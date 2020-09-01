#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

//fcfs dependencies and function

struct process{
int burst;
int pid;
int arrival;
};

bool compfcfs(process a, process b)
{
    if(a.arrival==b.arrival)
        return a.pid<b.pid;
    return a.arrival<b.arrival;
}



void fcfs(process arr[], int n)
{
    vector<int> gaant;
    
    sort(arr, arr+n, compfcfs);
    
    float totalwt=0;
    int waittimeprocess[n];
    int currtime=0;
    
    for(int i=0;i<n;i++)
    {
        if(currtime<=arr[i].arrival)
        {
            currtime+=(arr[i].arrival+arr[i].burst);
            waittimeprocess[i]=0;
            gaant.push_back(arr[i].pid);
        }
        else
        {
            waittimeprocess[i]=currtime-arr[i].arrival;
            currtime+=arr[i].burst;
            gaant.push_back(arr[i].pid);
        }
    }
    
    for(int i=0;i<n;i++)
        totalwt+=waittimeprocess[i];
    
    totalwt=float(1.0*totalwt/n);
    
    cout<<"avg waiting time: "<<totalwt<<endl;
    cout<<"wait time per process: \n";
    for(int i=0;i<n;i++)
        cout<<waittimeprocess[i]<<" ";
    cout<<endl;
    
    for(auto x: gaant)
        cout<<x<<" ";
    cout<<endl;
}

//sjf non premptive dependencies and function

bool sjfcomp(process a, process b)
{
        return a.burst<b.burst;
}
bool sjfchecker(process arr[], int n)
{
    for(int i=0;i<n;i++)
        if(arr[i].burst>0)
            return false;
    
    return true;
}

void sjfnon(process arr[], int n)
{
    int currtime=0;
    int waittimeprocess[n];
    memset(waittimeprocess, 0, sizeof(waittimeprocess));
    vector<int> gaant;
            
    while(!sjfchecker(arr, n))
    {
        sort(arr, arr+n, sjfcomp);
        
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
        cout<<x<<" ";
    cout<<endl;
}

//sjf premptive dependencies and function

bool sjfcomp2(process a, process b)
{
    if(a.burst==b.burst)
        return a.pid<b.pid;
    return a.burst<b.burst;
}
bool sjfchecker2(process arr[], int n)
{
    for(int i=0;i<n;i++)
        if(arr[i].burst>0)
            return false;
    
    return true;
}

void sjf(process arr[], int n)
{
    int currtime=0;
    int waittimeprocess[n];
    int prevexe[n];
    memset(waittimeprocess, 0, sizeof(waittimeprocess));
    memset(prevexe, 0, sizeof(prevexe));
    
    vector<int> gaant;
    
    for(int i=0;i<n;i++)
        prevexe[i]=arr[i].arrival;
            
    while(!sjfchecker2(arr, n))
    {
        sort(arr, arr+n, sjfcomp2);
        
        for(int i=0;i<n;i++)
        {
            if(arr[i].burst==0 || arr[i].arrival>currtime)
                continue;
            else
            {
                waittimeprocess[arr[i].pid]+=(currtime-prevexe[arr[i].pid]);
                prevexe[arr[i].pid]=currtime+1;
                ++currtime;
                --arr[i].burst;
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
        cout<<x<<" ";
    cout<<endl;
}

//priority scheduling function and dependencies

struct processpriority{
    int burst;
    int pid;
    int arrival;
    int priority;
};

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

//round robin function and dependencies

bool rrcomp(process a, process b)
{
    if(a.arrival==b.arrival)
    {
        if(a.arrival==b.arrival)
            return a.pid<b.pid;
        return a.arrival<b.arrival;
    }
    return a.arrival<b.arrival;
}
bool rrchecker(process arr[], int n)
{
    for(int i=0;i<n;i++)
        if(arr[i].burst>0)
            return false;
    
    return true;
}

void roundrobin(process arr[], int n, int quantum)
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
    int choice=0;
    
    do{
        cout<<"enter your choice of algo:  \n";
        cout<<"1. FCFS \n";
        cout<<"2. SJF non premptive\n";
        cout<<"3. SJF premptive\n";
        cout<<"4. priority scheduling \n";
        cout<<"5. round robin \n";
        cout<<"6. exit\n";
        cin>>choice;
        
        if(choice==1)
        {
        cout<<"enter number of processes: ";
        int n;
        cin>>n;
        process arr[n];
        
        cout<<"enter process id, arrival time , burst time: \n";
        for(int i=0;i<n;i++)
            cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst;
        
        fcfs(arr, n);
        }
        else if(choice == 2)
        {
            cout<<"enter number of processes: ";
            int n;
            cin>>n;
            process arr[n];
            
            cout<<"enter process id, arrival time , burst time: \n";
            for(int i=0;i<n;i++)
                cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst;
            
            sjfnon(arr, n);
        }
        
        else if(choice ==3)
        {
            cout<<"enter number of processes: ";
            int n;
            cin>>n;
            process arr[n];
            
            cout<<"enter process id, arrival time , burst time: \n";
            for(int i=0;i<n;i++)
                cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst;
            
            sjf(arr, n);
        }
        else if(choice == 4)
        {
            cout<<"enter number of processes: ";
            int n;
            cin>>n;
            processpriority arr[n];
            
            cout<<"enter process id(0 format), arrival time , burst time, priority: \n";
            for(int i=0;i<n;i++)
                cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst>>arr[i].priority;
            
            prioritys(arr, n);
        }
        
        else if(choice==5)
        {
            int quantum;
            cout<<"enter number of processes: ";
            int n;
            cin>>n;
            process arr[n];
            
            cout<<"enter process id(0 format), arrival time , burst time: \n";
            for(int i=0;i<n;i++)
                cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst;
            
            cout<<"enter time quantum\n";
            cin>>quantum;
            
            roundrobin(arr, n,quantum);
        }
        
    }while(choice!=6);
    
    return 0;
}
