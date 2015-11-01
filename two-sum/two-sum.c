#include <uthash.h>
#include <stdio.h>


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
void debug_print(){
    Map* s;
    for(s=data; s != NULL; s=(Map*)(s->hh.next))
        printf("key %d:  value %d\n", s->value, s->index);
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

int main() {
    int i,j;
    int numsSize = 10, target=20;
    int *ret = malloc( 2 * sizeof(int));

    for (i = 10; i < numsSize + 10 ; i++){
        addNumber(i, i + 1);
    }
    debug_print();
    for (i = 0; i < numsSize ; i++){
        j = findIndexOfNumber( i + 10);
        printf("%d\n", j);
    }
    cleanup();
    return 0;

}


