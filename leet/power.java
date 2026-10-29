class PowerofTwo {
    public boolean isPowerOfTwo(int n) {
         return n > 0 && (n & n - 1) == 0;
    }
}

class PowerofThree {
    public boolean isPowerOfThree(int n) {
        if(n<=0) {
            return false;
        }
        while(n%3 == 0) {
            n = n/3;
        }
        return n == 1;
    }
}
