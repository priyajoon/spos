#include <bits/stdc++.h>
using namespace std;
 

bool search(vector<int> &fr,int key){
    for(int i=0;i<fr.size();i++){
        if(fr[i]==key){
            return true;
        }
    }
    return false;
}
void fifoPage(int pg[], int pn, int fn) {
    vector<int> fr;
    queue<int> f_q;
    int p_fault = 0,p_hit=0;

    for (int i = 0; i < pn; i++) {
        int currentPage = pg[i];

        if(search(fr,currentPage)){
            p_hit++;
            cout << "Page " << currentPage << " is in the frame. Frame Contents: ";
        }
        else{
            p_fault++;
            if (fr.size() < fn) {
                fr.push_back(currentPage);
                f_q.push(currentPage);
            } 
            else {
                int replacedPage = f_q.front();
                f_q.pop();
                fr.erase(remove(fr.begin(), fr.end(), replacedPage), fr.end());
                fr.push_back(currentPage);
                f_q.push(currentPage);
            }
            cout << "Page " << currentPage << " is not in the frame. Frame Contents: ";
        }
        for (int i=0;i<fr.size();i++) {
            cout << fr[i] << " ";
        }
        cout << endl;
        
    }

    cout << "No. of page faults = " << p_fault << endl;
    cout << "No. of page hits = " << p_hit << endl;
}
//5 0 2 3 0 1 3 4 5 4 2 0 3 4 3 
//7 0 1 2 0 3 0 4 2 3 0 3 2

int main() {
    int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
    int pn = sizeof(pg) / sizeof(pg[0]);
    int fn = 4;
    fifoPage(pg, pn, fn);

    // int pg[] = { 5,0,2,3,0,1,3,4,5,4,2,0,3,4,3};
    // int pn = sizeof(pg) / sizeof(pg[0]);
    // int fn = 3;
    // fifoPage(pg, pn, fn);
    return 0;
}
