int reverse(int x) {
    long long result = 0;
    int pos = 0;
    if(x == 0)
        return 0;
    while(x % 10 == 0) // Remove Trailing zero
        x /= 10;
    while(x){
        result = result * 10 + (x % 10);
        x /= 10;
        if(result > INT_MAX || result < INT_MIN){
            return 0;     // overflow
        }
    }
    return result;
}