#include <bits/stdc++.h>
using namespace std;

void input(int n,int at[],int bt[],int pid[],int prt[]){
    cout<<"Enter arrival time and burst time and priority of processes"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Process "<<i+1<<" ";
        cin>>at[i]>>bt[i]>>prt[i];
        pid[i]=i+1;

    }
}

void calculate(int n,int at[],int bt[],int prt[],int ct[],int tat[],int wt[]){
    int rt[n];
    int min_at=INT_MAX;
    for(int i=0;i<n;i++){
        rt[i]=bt[i];
        min_at=min(min_at,at[i]);

    }
    int complete=0,t=0,maxm=-1;
    int shortest,finish_time;

    prt[n]=-1;
    for(t=0;complete!=n;t++){
        shortest=n;
        for(int i=0;i<n;i++){
            if(at[i]<=t && prt[i]>prt[shortest] && rt[i]>0){
                maxm=prt[i];
                shortest=i;
            }
        }

        t+=rt[shortest]-1;
        rt[shortest]=-1;
        complete++;
        finish_time=t+1;
        ct[shortest]=finish_time;
        wt[shortest]=finish_time-at[shortest]-bt[shortest];
    }
    

    
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
    }


}


void display(int n, int pid[], int at[], int bt[],int prt[], int ct[], int tat[], int wt[]){
    
    cout<<"Process"<<" "<<"Arrival Time"<<" "<<"Burst Time"<<" "<<"Priority"<<" "<<"Completion time"<<" "<<"Turn around time"<<"  "<<"Waiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<pid[i]<<"       "<<at[i]<<"            "<<bt[i]<<"           "<<prt[i]<<"           "<<ct[i]<<"               "<<tat[i]<<"                 "<<wt[i]<<endl;
    }
    float avg_wt=0,avg_tat=0;
    for(int i=0;i<n;i++){
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    avg_wt/=n;
    avg_tat/=n;
    cout<<"Average Waiting time = "<< avg_wt<<endl;
    cout<<"Average Turn around time = "<< avg_tat<<endl;
}
int main(){

    cout<<"Enter no. of processes = ";
    int n;
    cin>>n;
    int at[n],bt[n],ct[n],tat[n],wt[n],pid[n],prt[n];
    input(n,at,bt,pid,prt);
    calculate(n,at,bt,prt,ct,tat,wt);
    cout<<endl;
    //sort_res(n,pid, at, bt,ct,tat, wt);
    display(n,pid,at,bt,prt,ct,tat,wt);

    return 0;
}