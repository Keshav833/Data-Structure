#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Process this test case here
        vector<int> b= a;
        sort(b.begin(),b.end());
        if( k>1){
            cout<<"YES"<<endl;
        }else{
            if(a==b){
                cout<< "YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

    }

    return 0;
}