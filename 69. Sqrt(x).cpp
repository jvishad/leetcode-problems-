// binary search approach time complexity = log(x*e)
// where e is no of decimal values.

class Solution {
public:
    double func(int x){
        double low = 1;
        double high = double(x);
        while(high - low > 1e-5){
            double mid = (high + low)/2.0;
            if(mid*mid == (double)x){
                return mid;
            }
            if(mid*mid < x){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        cout << low << endl;
        return high;
    }
    
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        int ans = func(x);
        return ans;
    }
};
