class Solution {
public:
    string minWindow(string s, string t) {
        int l =0;
        int r= 0;
        unordered_map<char , int> mp;
        unordered_map<char , int> window;
        for(char ch :t){
            mp[ch]++;
        }
        int count=0;
        int start =0;
        int len = INT_MAX;
        
        while( r<s.size()){

            
                if(mp.find(s[r])!=mp.end()){
                window[s[r]]++;

                if(window[s[r]]<=mp[s[r]]){
                    count++;
                }
                }
            while(count==t.size()){
                
                if(len>r-l+1){
                    start = l;
                    len = r-l+1;
                }

                if(mp.find(s[l])!=mp.end()){

                    window[s[l]]--;
                    
                    if(window[s[l]]<mp[s[l]]){
                    count--;
                    }
                }
                l++;
            }
                r++;
                


        }
            if(len == INT_MAX)
            return "";

        return s.substr(start, len);
    }
};