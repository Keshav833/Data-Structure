class Solution {
public:
    bool canAliceWin(int n) {
        int x =10;
        while(true ){
            if(n-x<0){
                if( x %2==0){
                    return false;
                }
                else{
                    return true;
                }
            }
            n = n - x;
            x--;
        }
        return false;
    }
};