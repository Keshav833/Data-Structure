class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size()!=t.size()) return false;
        unordered_map<char,int> hash1;
        unordered_map<char,int> hash2;
        for( char c:s){
            hash1[c]++;
        }
        for( char c:t){
            hash2[c]++;
        }
        // for( int i =0; i <26;i++){
        //     if( hash1[i]!=hash2[i]) return false;
        // }
        return hash1==hash2;

    }
};