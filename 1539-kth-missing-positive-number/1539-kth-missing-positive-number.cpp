class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> miss ;
        int i =1;
        int j = 0;
        while( miss.size()<=k ){
            if(   j<arr.size() && arr[j]==i){
                j++;

            }
            else{

            miss.push_back(i);
               
            }
                i++;
        }

        return miss[k-1];
    }
};