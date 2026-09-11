class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        int n = digits.size();
        unordered_set<int> myset;
        for( int i =0; i< n ;i++){
            for( int j =0; j< n;j++){
                for( int k = 0 ; k < n;k++){
                    
                    if( i!=j && j !=k && k!=i && digits[i]!=0){
                         int temp = digits[i] * 100
                                 + digits[j] * 10
                                 + digits[k];

                    auto [iterator, success] = myset.insert(temp);

                    if(success){
                        if(temp%2 ==0){
                            count++;
                        }
                        }
                    }
                }
            }
        }
        return count;
    }
};