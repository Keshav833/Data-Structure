class Solution {
public:
    int calculate(string s) {
       
        stack<int>  st;
        long long num = 0;
        long long result = 0;
        int sign = 1;
        for(char c:s){
            if( c==' '){
                continue;
            }
            else if(c == '+'){
                result+=num*sign;
                num= 0;
                sign = 1;
            }
            else if(c=='-'){
                result +=num*sign;
                num = 0;
                sign = -1;
            }
            else if(c=='('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
                num = 0;
            }
            else if( c == ')'){
                result +=num*sign;
                num = 0;
                sign = st.top();
                st.pop();
                
                result=(result*sign) + st.top(); 
                st.pop();
            
            }
            else{
                num= num*10 + (c - '0');
            }

        }

        
        result+= num*sign;
        
        return (int)result ;
    }
};