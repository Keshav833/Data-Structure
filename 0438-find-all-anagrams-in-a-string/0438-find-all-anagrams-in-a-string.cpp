class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq_s(26,0);
        vector<int> freq_p(26,0);
        int l = 0;
        int r = 0;
        int n = s.size();
        for( char c :p){
            freq_p[c-'a']++;
        }
        while( r< n){
            freq_s[s[r]-'a']++;
            while(r-l+1>p.size()){
                freq_s[s[l]-'a']--;
                l++;
            }
            if( freq_s==freq_p){
                ans.push_back(l);
            }
            r++;
        }
        return ans;
    }
};