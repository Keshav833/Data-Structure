class Solution {
public:
    bool canConstruct(string r, string m) {
          int n1 = r.size();
        int n2 = m.size();
        if( n1>n2) return false;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

       for (char c : r) mp1[c]++;
        for (char c : m) mp2[c]++;
        
        for(int i =0 ; i < mp1.size() ; i++){
            if( mp2[i] < mp1[i]) return false;
        }
        return true ;
    }
};