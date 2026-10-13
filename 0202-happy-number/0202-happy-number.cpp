class Solution {
public:
    bool isHappy(int n) {
     unordered_set<int> seen;
     while( n!=1){
        // 1. Check whether n has already appeared
            if(seen.count(n)){
                return false;
            }

            // 2. Insert n into the set
            seen.insert(n);

            // 3. Calculate the sum of squared digits

        int sum = 0;
        while( n> 0){
            int digit = n%10;
            sum+= digit*digit;
            n = n/10;
        }
        n = sum ;
     }
     return true ;
    }
};