#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    int x;
    while(cin >> x){
        arr.push_back(x);
    }
    
    unordered_map<int,int> st;

    for(auto c:arr){
        st[c]++;
    }
    cout<< arr.size()- st.size();



  

    return 0;
}