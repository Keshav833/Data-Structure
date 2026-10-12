class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if( n1!=n2) return false;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for( int i=0; i <n1; i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(int i =0 ; i < mp1.size() ; i++){
            if( mp2[i]!=mp1[i]) return false;
        }
        return true ;

    }
};