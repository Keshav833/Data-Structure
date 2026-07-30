class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        
        // vector<vector<char>> edge;
        vector<unordered_set<int>> adj(26);
        vector<bool> present(26,false);
        vector<int> indegree(26,0);
        for(auto word: words){
            for( char ch :word){
                present[ch - 'a']= true;
            }
        }
        for( int i =0 ; i < words.size() -1 ;i++){
            bool found = false;
            int mini = min( words[i].size(),words[i+1].size());
            const string &w1 = words[i];
            const string &w2 = words[i+1];
            for( int j =0; j < mini ;j++){
                if(w1[j]!=w2[j]){
                    found = true;
                    // edge.push_back({w1[j],w2[j]});
                    // adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    // indegree[w2[j]-'a']++;
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';
                    
                    if (adj[u].insert(v).second) {
                        indegree[v]++;
                    }
                    break;
                }
            }
            if(!found && w1.size()>w2.size()){
                return "";
            }
            
        }
        
        
        int dist=0;
        
        queue<int> q;
        for(int i =0; i < 26;i++){
            if( present[i] && indegree[i]==0){
                q.push(i);
            }
            if(present[i])
                dist++;
        
        }
        int p=0;
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            p++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if( p != dist ){
            return "";
        }
        
        string str = "";
        for( int it:ans){
            str+=(char)(it + 'a');
        }
        
        
        return str;
        
        
    }
};