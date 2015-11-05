/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct hash_map {
    int index;
    int value;
    UT_hash_handle hh;
};

typedef struct hash_map Map;

Map *data = NULL;

void addNumber(int num, int index){
    Map *item = malloc(sizeof(Map));
    item -> value = num;
    item -> index = index;
    HASH_ADD_INT(data, value, item);
}

int findIndexOfNumber(int number){
    Map *found = NULL;
    HASH_FIND_INT(data, &number, found);
    return found == NULL ? -1 : found->index;
}

void cleanup(){
    Map *cur, *tmp;
    HASH_ITER(hh, data, cur, tmp){
        HASH_DEL(data, cur);
        free(cur);
    }
}

int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int *ret = malloc(2*sizeof(int));
    
    for (i = 0; i < numsSize ; i++){
        addNumber(nums[i], i + 1);
    }
    
    for (i = 0; i < numsSize ; i++){
        j = findIndexOfNumber(target - nums[i]);
        if (j != -1 && j != i + 1){
            ret[0] = (j < i + 1) ? j : (i + 1);
            ret[1] = (j > i + 1) ? j : (i + 1);
            cleanup();
            return ret;
        }
    }
    
}