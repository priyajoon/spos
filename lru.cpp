#include <bits/stdc++.h>
using namespace std;

void lru(int page[],int n,int capacity){
	unordered_set<int> s;
	unordered_map<int,int> indexes;

	int p_fault=0,p_hit=0;
	for(int i=0;i<n;i++){
		if(s.size()<capacity){
			if(s.find(page[i])==s.end()){
				s.insert(page[i]);
				p_fault++;
			}
			else{
				p_hit++;
			}

			indexes[page[i]]=i;
		}
		else{
			if(s.find(page[i])==s.end()){
				int lru=INT_MAX,val;

				for(auto it=s.begin();it!=s.end();it++){
					if(indexes[*it]<lru){
						lru=indexes[*it];
						val=*it;
					}
				}

				s.erase(val);
				s.insert(page[i]);
				p_fault++;
			}
			else{
				p_hit++;
			}

			indexes[page[i]]=i;
		}
		cout<<page[i]<<" ";
		for (auto it=s.begin(); it!=s.end(); it++){
				cout<<" "<<*it;
		}
		cout<<endl;
	}
	cout << "No. of page faults: " <<p_fault<<endl;
	cout << "No. of page hits: " <<p_hit<<endl;
}

int main(){
	//int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
	int pages[] = {1,2,3,1,4,6,8,5};
	int n = sizeof(pages)/sizeof(pages[0]);
	int capacity = 3;
	lru(pages, n, capacity);
	return 0;
}