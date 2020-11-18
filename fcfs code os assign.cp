#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
//Hello World
using namespace std;
#include<string.h>

struct process{
    
    // but to burst
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

int main()
{
    cout<<"enter number of processes: ";
    int n;
    cin>>n;
    process arr[n];
    
    cout<<"enter process id, arrival time , burst time: \n";
    for(int i=0;i<n;i++)
        cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst;
    
    fcfs(arr, n);
    
    return 0;
}
