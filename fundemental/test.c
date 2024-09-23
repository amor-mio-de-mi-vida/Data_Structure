#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// we have defined the necessary header files here FOR this problem.
// IF additional header files are needed IN your program, please IMPORT here.

typedef struct Server {
    int id;
    int num;
    struct Server* next;
} Server;

Server* head;
int max = 0;
int sum = 0;
int result[20000];
int value[20000];

void insert(int id, int num) {
    Server* node = (Server*)malloc(sizeof(Server));
    node->id = id;
    node->num = num;

    Server* p;
    Server* prev = head;
    for(p = head->next; p!= NULL; p=p->next){
        if (p->id > id) {
            node->next = prev->next;
            prev->next = node;
        }
        prev = p;
    }
    prev->next = node;
    node->next = NULL;
}

void insert_server(int id, int num) {
    Server* node = (Server*)malloc(sizeof(Server));
    node->id = id;
    node->num = num;
    Server* p;
    Server* prev = head;
    for (p = head->next; p != NULL; p = p->next) {
        if (p->id > id) {
            break;
        }
        prev = p;
    }
    if (p != NULL) {
        node->next = p;
        prev->next = node;
        p->num -= num;
    } else {
        p->next = node;
        node->next = NULL;
        head->next->num -= num;
    }
}

void delete_server(int id) {
    Server* p;
    Server* prev = head;
    for (p = head->next; p != NULL; p=p->next) {
        if (p->id == id) {
            break;
        }
        prev = p;
    }
    if (p->next != NULL) {
        prev->next = p->next;
        p->next->num += p->num;
        free(p);
        p = NULL;
    } else {
        prev->next = NULL;
        head->next->num += p->num;
        free(p);
        p = NULL;
    }
}

int get_max() {
    Server* p = head->next;
    for (p = head->next; p != NULL; p = p->next) {
        if (p->num > max) {
            max = p->num;
        }
    }
    return max;
}

void get_result() {
    Server* p = head->next;
    for (p = head->next; p != NULL; p = p->next) {
        if (p->num == max) {
            result[sum] = p->id;
            value[sum] = p->num;
            sum++;
        }
    }
}


int main()
{
    int id;
    int num;
    char type;
    head = (Server*)malloc(sizeof(Server));
    while(1) {
        scanf("%d,%d", &id, &num);
        char c = getchar();
        insert(id, num);
        if (c == '\n') {
            break;
        }
    }

    while(1) {
        scanf("%c", &type);
        if (type == 'd') {
            scanf("%d", &id);
            delete_server(id);
        } else if (type == 'i') {
            scanf("%d %d", &id, &num);
            insert_server(id, num);
        } else {
            break;
        }
        getchar();
    }

    get_max();
    get_result();

    int i = 0;
    for (i = 0; i < sum; i++) {
        printf("%d, %d", result[i], value[i]);
        if (i + 1 < sum) {
            printf(" ");
        }
    }

    return 0;
}



