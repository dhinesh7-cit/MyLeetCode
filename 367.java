class Solution {
    public boolean isPerfectSquare(int num) {
        if (num<=0) return false;
        int low=1, high=num;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            long square = (long) mid*mid;
            if (square==num) return true;
            else if (square<num) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
}
