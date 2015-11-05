/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* ret = malloc(digitsSize * sizeof(int));
    int add = 10;
    for(int j = digitsSize - 1; j >= 0; j--){
        add = ret[j] = digits[j] + add / 10;
        ret[j] %= 10;
    }
    if (add / 10){
        // insert 1 to the top;
        int* ret_ = malloc(digitsSize * sizeof(int));
        ret_[0] = add / 10;
        memcpy(ret_+1, ret, digitsSize);
        free(ret);
        *returnSize = digitsSize + 1;
        return ret_;
    }else{
        *returnSize = digitsSize;
        return ret;
    }
}