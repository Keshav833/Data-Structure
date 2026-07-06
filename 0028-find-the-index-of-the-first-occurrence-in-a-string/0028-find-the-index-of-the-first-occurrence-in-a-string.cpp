class Solution {
public:
    int strStr(string haystack, string needle) {
        // int first = -1;
        for(int i=0;i < haystack.size();i++){
            int idx = i;
            for(int j =0;j< needle.size();j++){
                if( haystack[idx]!=needle[j]){
                    break;
                }
                else{
                    idx++;
                    if( j == needle.size()-1){
                        // first = i ;
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};