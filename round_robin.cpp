#include <bits/stdc++.h>
using namespace std;

void input(int n,int at[],int bt[],int qnt,int pid[]){
	
	cout<<"Enter arrival time and burst time of processes"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Process "<<i+1<<" ";
		cin>>at[i]>>bt[i];
		pid[i]=i+1;

	}
}

void round_robin(int n,int at[],int bt[],int ct[],int tat[],int wt[],int qnt){
	vector<vector<int>> v;
	vector<int> d_bt(n);
	int min_at=INT_MAX;
	int max_at=INT_MIN;

	for(int i=0;i<n;i++){
		v.push_back({at[i],bt[i]});
		d_bt[i]=bt[i];
		min_at=min(min_at,at[i]);
		max_at=max(max_at,at[i]);
	}

	int current_time=min_at;
	vector<int> ready_queue;

	for(int i=0;i<n;i++){
		if(v[i][0]==min_at){
			ready_queue.push_back(i);
		}
	}

	vector<int> ghant_chart;

	while(true){

		if(ready_queue.empty() && current_time>max_at){
			break;
		}

		if(ready_queue.empty()){
			current_time+=1;

			for(int i=0;i<n;i++){
				if(v[i][0]>current_time-qnt && v[i][0]<=current_time){
					ready_queue.push_back(i);
				}
			}
		}
		else{
			int current_process=ready_queue[0];

			if(v[current_process][1]-qnt>0){

				v[current_process][1]-=qnt;
				current_time+=qnt;

				for(int i=0;i<n;i++){
					if(v[i][0]>current_time-qnt && v[i][0]<=current_time){
						ready_queue.push_back(i);
					}
				}

				ready_queue.push_back(current_process);
				ghant_chart.push_back(current_process);
				ready_queue.erase(ready_queue.begin());


			}
			else{
				current_time+=v[current_process][1];
				v[current_process][1]=0;

				for(int i=0;i<n;i++){
					if(v[i][0]>current_time-v[current_process][1] && v[i][0]<=current_time){
						ready_queue.push_back(i);
					}
				}
				ct[current_process]=current_time;
				ghant_chart.push_back(current_process);
				ready_queue.erase(ready_queue.begin());
			}
		}
	}
	cout<<"Ghant chart = ";
	for(auto i:ghant_chart){
		cout<<"P"<<i+1<<" ";
	}
	cout<<endl;

	for(int i=0;i<n;++i){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
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
	int n,quantum;
	cin>>n;
	cout<<"Enter time quantum = ";
	cin>>quantum;
	int at[n],bt[n],ct[n],tat[n],wt[n],pid[n];
	input(n,at,bt,quantum,pid);
	round_robin( n, at, bt, ct, tat, wt, quantum);
	display(n,pid,at,bt,ct,tat,wt);
	return 0;
}