#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct list {
    Node *first;
} List;

List new_list(){
    List list;
    list.first=NULL;
    return list;
}

void insert(List *l, int val){
    if(l->first == NULL){
        l->first = malloc(sizeof(Node));
        l->first->val = val;
        l->first->next = NULL;
    }
    else{
        Node *curr = l->first;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = malloc(sizeof(Node));
        curr->next->val = val;
        curr->next->next = NULL;
    }
    return;
}

int len(List *l){
    Node *curr = l->first;
    int count = 0;
    while(curr != NULL){
        curr = curr->next;
        count += 1;
    }
    return count;
}

void print_list(List *l){
    Node *curr = l->first;
    printf("{");
    while(curr != NULL){
        if(curr->next != NULL) {
            printf("%d, ", curr->val);
        }
        else{
            printf("%d", curr->val);
        }
        curr = curr->next;
    }
    printf("}\n");
    return;
}

int pop(List *l){
    int val = 0;
    Node *curr = l->first;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    val = curr->next->val;
    free(curr->next);
    curr->next = NULL;
    return val;
}

void insert_at(List *l, int val, int index){
    if(index == len(l)){
        insert(l, val);
        return;
    }
    Node *new_node = malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;
    if(index == 0){
        new_node->next = l->first;
        l->first = new_node;
    }
    else{
        Node *curr = l->first;
        while(index != 1){
            if(curr->next != NULL) {
                curr = curr->next;
            }
            else{
                perror("Index Error");
                return;
            }
            index--;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void remove_at(List *l, int index){
    if(len(l) <= index){
        perror("Index Error");
        return;
    }
    if(index == 0){
        free(l->first);
        l->first = malloc(sizeof(Node));
        l->first = l->first->next;
    }
    else{
        Node *curr = l->first;
        while(index != 1){
            if(curr->next != NULL){
                curr = curr->next;

            }
            else{
                perror("Index Error");
                return;
            }
            index--;
        }
        free(curr->next);
        curr->next = malloc(sizeof(Node));
        curr->next = curr->next->next;
    }
}

int main() {
    List list = new_list();
    printf("%d\n", len(&list));
    print_list(&list);
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 4);
    print_list(&list);
    insert_at(&list, 10, 4);
    print_list(&list);
    return 0;
}

