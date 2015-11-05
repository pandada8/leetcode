double myPow(double x, int n) {
    if(x == -1) return n % 2 ? -1 : 1;
    if(x == 0 || x == 1) return x;
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n < 0) return myPow(1/x, -n);
    // n > 1
    return n % 2 ? x * myPow(x * x, (n-1)/2) : myPow(x * x, n/2);
}