#include <bits/stdc++.h>
using namespace std;


struct block {
    int id;
    int size;
    bool allocated;
    int size_alloc;
};

void first(vector<block> &mem,int processsize,int processid){
	int n=mem.size();
	
    for(int i=0;i<n;i++){
        if(!mem[i].allocated && mem[i].size>=processsize){
            mem[i].allocated=true;
            mem[i].size_alloc=processsize;
            return;
        }
    }
	
    cout<<"Process "<<processid<<" cannot be allocated"<<endl;

}
void dell(vector<block>& memory, int processId) {
    for (int i = 0; i < memory.size(); i++) {
        if (memory[i].allocated && memory[i].id == processId) {
            memory[i].allocated = false;
            memory[i].size_alloc=0;
            cout << "Deallocated Process " << processId << " from Block " << memory[i].id << endl;
            break;
        }
    }
}

void display(vector<block>& mem){
    cout<<"ID"<<"    "<<"Status"<<"    "<<"Block_Size"<<"   "<<"Memory_allocated"<<endl;
    for(const block& Block:mem){
        
        if(Block.allocated){
            cout<<Block.id<<"    "<<"Allocated"<<"    "<<Block.size<<"                "<<Block.size_alloc<<endl;
        }
        else{
            cout<<Block.id<<"    "<<"Free"<<"         "<<Block.size<<"                "<<Block.size_alloc<<endl;
        }
    }
}

int main(){
    
    int n,ch,a,b,c;
    cout<<"Enter number of memory blocks = ";
    cin>>n;
    cout<<"Enter size of blocks = ";
    vector<block> mem(n);
    for(int i=0;i<n;i++){
    	mem[i].id=i+1;
    	int x;
    	cin>>x;
    	mem[i].size=x;

    	mem[i].allocated=false;
    	mem[i].size_alloc=0;
    }

    int processsize,processid;
    int last_alloc_block=0;

    while(true){


    	cout<<"1. Allocate memory "<<endl;
    	cout<<"2. Deallocate memory "<<endl;
    	cout<<"3. exit "<<endl;
    	cout<<"Enter your choice = ";
    	cin>>ch;

    	switch(ch){
    		case 1:
    			cout<<"Enter number of blocks you want to allocate = ";
    			cin>>a;
    			cout<<"Enter memory size = ";
    			for(int i=0;i<a;i++){
    				cin>>processsize;
    				first(mem,processsize,i+1);
    			}
    			cout << "Memory Block Status after allocation:" << endl;
    			display(mem);
    			break;

    		case 2:
    			cout<<"Enter number of blocks you want to deallocate = ";
    			cin>>a;
    			cout<<"Enter processid = ";
    			for(int i=0;i<a;i++){
    				cin>>processid;
    				dell(mem,processid);
    			}
    			cout << "Memory Block Status after deallocation:" << endl;
    			display(mem);

    			break;
    		case 3:
    			exit(0);


    			
    	}

    }

    


	return 0;
}
