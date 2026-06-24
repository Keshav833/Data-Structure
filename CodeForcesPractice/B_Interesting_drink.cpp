#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 int solve(int m , vector<int>& prices){
    int l = 0;
    int r = prices.size() -1;
    while( l <=r){
        int mid = l + (r-l)/2;
        if( prices[mid]<=m){
            l= mid+1;
        }
        else{
            r= mid-1;
        }
    }
    return l;
 }

int main() {

    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int q;
    cin >> q;

    vector<int> queries(q);

    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    int i =0;
    sort(prices.begin(), prices.end());

    
    while( i<q){
        cout << solve(queries[i],prices)<<endl;
        i++;
    }

    

    return 0;
}