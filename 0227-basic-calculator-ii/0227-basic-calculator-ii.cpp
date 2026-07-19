class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long result = 0;
        long long last = 0;
        int op = '+';

        for(int i =0;i< s.size();i++){
           char c = s[i];
           if( isdigit(c)){
            num= num*10 + (c-'0');
           }
           if((!isdigit(c) && c!=' ')  || i == s.size() -1){

            if( op=='+'){
                result += last ;
                last = num;
            }
            else if( op == '-'){
                result += last ;
                last = -num;
            }
            else if( op == '*'){
                last = last * num;
            }
            else if( op == '/'){
                last = last / num;
            }
            num =0;
            op = c;
           }
        }
        return result + last;

    }
};