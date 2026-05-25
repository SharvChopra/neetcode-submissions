class Solution {
public:
    int reverse(int x) {
        int res = 0;

        const int MIN = -2147483648; 
        const int MAX = 2147483648;

        while(x!=0){
            int digit = x%10;
            x /=10;
            
            if(res>max/10 || (res == max/10 && digit>max%10))
                return 0;
            
            if(res<min/10 || (res == min/10 && digit<min%10))
                return 0;
            
            res = res*10+digit;
        }
        return res;
    }
};
