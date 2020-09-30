#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

struct process{
int burst;
int pid;
int arrival;
};

// here might be a mistake
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

int main()
{
    cout<<"enter number of processes: ";
    int n;
    cin>>n;
    process arr[n];
    
    cout<<"enter process id, arrival time , burst time: \n";
    for(int i=0;i<n;i++)
        cin>>arr[i].pid>>arr[i].arrival>>arr[i].burst;
    
    sjfnon(arr, n);
    
    return 0;
}
