void swap(int* a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int removeElement(int* nums, int numsSize, int val) {
    for (int i = 0; i < numsSize;){
        if (nums[i] == val){
            swap(&nums[i], &nums[--numsSize]);
        }else{
            i++;
        }
    }
    return numsSize;
}