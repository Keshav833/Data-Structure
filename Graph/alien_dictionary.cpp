class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        
        vector<vector<char>> edge;
        vector<bool> present(26,false);
        for(auto word: words){
            for( char ch :word){
                present[ch - 'a']= true;
            }
        }
        for( int i =0 ; i < words.size() -1 ;i++){\
            bool found = false;
            int mini = min( words[i].size(),words[i+1].size());
            string w1 = words[i];
            string w2 = words[i+1];
            for( int j =0; j < mini ;j++){
                if(w1[j]!=w2[j]){
                    found = true;
                    edge.push_back({w1[j],w2[j]});
                    // adj(w1[j] - 'a').push_back(w2[j] - 'a');
                    break;
                }
            }
            if(!found && w1.size()>w2.size()){
                return "";
            }
            
        }
        
        vector<vector<int>> adj(26);
        vector<int> indegree(26,0);
        
        for(auto it:edge){
            adj[it[0]-'a'].push_back(it[1] - 'a');
            indegree[it[1]-'a']++;
            
            
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