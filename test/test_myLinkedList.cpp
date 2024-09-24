#include "../include/utils.h"
#include "../include/ds.h"


int main() {
    srand((unsigned int)time(NULL));
    MyLinkedList* list = new MyLinkedList();
    // 构建链表 


    int rand1 = get_rand(0, 10);
    int rand2 = get_rand(0, 10);
    printf("############## Testing addAtHead() ################\n");
    for (int i = 0; i < rand1; i++) {
        int val = get_rand(-10, 10);
        printf("the val is %d ", val);
        list->addAtHead(val);
        list->debug();
    }
    printf("############## Testing addAtTail() ################\n");
    for (int i = 0; i < rand2; i++) {
        int val= get_rand(30, 50);
        printf("the val is %d ", val);
        list->addAtTail(val);
        list->debug();
    }


    printf("############## Testing addAtIndex() ################\n");
    // addAtIndex
    int rand3 = get_rand(0, 10);
    for (int i = 0; i < rand3; i++) {
        int val = get_rand(0, 20);
        int index = get_rand(-10, list->get_size() + 10);
        list->addAtIndex(index, val);
        printf("index is %d, val is %d, and result is ", index, val);
        list->debug();
    }

    // get
    printf("############## Testing get() ################\n");
    int rand4 = get_rand(0, 10);
    for (int i = 0; i < rand4; i++) {
        int index = get_rand(-10, list->get_size() + 10);
        int result = list->get(index);
        printf("index is %d and result is %d\n", index, result);
    }

    printf("############## Testing deleteAtIndex() ################\n");
    int rand5 = get_rand(0, 10);
    for (int i = 0; i < rand5; i++) {
        int index = get_rand(-10, list->get_size() + 10);
        list->deleteAtIndex(index);
        printf("index is %d, and result is ", index);
        list->debug();
    }
    

    return 0;
}