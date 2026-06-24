class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l  =0;
        int r = 0;
        int n = fruits.size();
        int sum=0;
        unordered_map<int, int> freq;
        while( r<n){
            freq[fruits[r]]++;
            
            while(freq.size()>2){
                freq[fruits[l]]--;
                
                if( freq[fruits[l]]==0){
                    freq.erase(fruits[l]);
                }
                l++;
            }
            sum = max( sum , r-l+1);
            r++;

        }

        
        return sum;
    }
};