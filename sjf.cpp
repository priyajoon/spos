#include <bits/stdc++.h>
using namespace std;

void input(int n,int at[],int bt[],int pid[]){
	cout<<"Enter arrival time and burst time of processes"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Process "<<i+1<<" ";
		cin>>at[i]>>bt[i];
		pid[i]=i+1;

	}
}

void calculate(int n,int at[],int bt[],int ct[],int tat[],int wt[]){
	int rt[n];
	for(int i=0;i<n;i++){
		rt[i]=bt[i];
	}
	int complete=0,t=0,minm=INT_MAX;
	int shortest=0,finish_time;
	bool check=false;

	cout<<"Ghant chart = ";

	while(complete!=n){

		for(int j=0;j<n;j++){
			if((at[j]<=t) && (rt[j]<minm) && rt[j]>0){
				minm=rt[j];
				shortest=j;
				check=true;
			}
		}

		if(check==false){
			t++;
			continue;
		}


		rt[shortest]--;
		minm=rt[shortest];

		cout<<"P"<<shortest+1<<" ";

		if(minm==0){
			minm=INT_MAX;
		}

		if(rt[shortest]==0){
			complete++;
			check=false;
			finish_time=t+1;
			ct[shortest]=t+1;

			wt[shortest]=finish_time-bt[shortest]-at[shortest];

			if(wt[shortest]<0){
				wt[shortest]=0;
			}
		}
		t++;
	}

	for(int i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
	}


}

void sort_res(int n, int pid[], int at[], int bt[], int ct[], int tat[], int wt[]){
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                    if (pid[j] > pid[j + 1])
                    {
                        swap(pid[j],pid[j+1]);
                        swap(at[j],at[j+1]);
                        swap(bt[j],bt[j+1]);
                        swap(ct[j],ct[j+1]);
                        swap(tat[j],tat[j+1]);
                        swap(wt[j],wt[j+1]);
                    }
                    
                
                    
            }
        }
    
}

void display(int n, int pid[], int at[], int bt[], int ct[], int tat[], int wt[]){
	
	cout<<"Process"<<" "<<"Arrival Time"<<" "<<"Burst Time"<<" "<<"Completion time"<<" "<<"Turn around time"<<"  "<<"Waiting Time"<<endl;
	for(int i=0;i<n;i++){
		cout<<pid[i]<<"       "<<at[i]<<"            "<<bt[i]<<"           "<<ct[i]<<"               "<<tat[i]<<"                 "<<wt[i]<<endl;
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
	int at[n],bt[n],ct[n],tat[n],wt[n],pid[n];
	input(n,at,bt,pid);
	calculate(n,at,bt,ct,tat,wt);
	cout<<endl;
	sort_res(n,pid, at, bt,ct,tat, wt);
	display(n,pid,at,bt,ct,tat,wt);

	return 0;
}