/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * step(struct ListNode** l1, struct ListNode** l2){
    struct ListNode* ret;
    if(!*l1 && !*l2) return NULL;
    if(!*l1){
        ret = *l2;
        *l2 = (*l2) -> next;
        return ret;
    };
    if(!*l2){
        ret = *l1;
        *l1 = (*l1) -> next;
        return ret;
    }
    if((*l1) -> val > (*l2) -> val){
        ret = *l2;
        *l2 = (*l2) -> next;
        return ret;
    }else{
        ret = *l1;
        *l1 = (*l1) -> next;
        return ret;
    }
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * head, *p;
    head = p = step(&l1, &l2);
    while(l1 || l2){
       p -> next = step(&l1, &l2);
       p = p -> next;
    }
    return head;
}