#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} node;

typedef struct List {
    node* begining;
    node* end;
} list;

node* createNode(int value){
    node* newNode;

    newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

list* createList(){
    list* newList;

    newList = malloc(sizeof(list));
    newList->begining = NULL;
    newList->end = NULL;

    return newList;
}

void addNodeToBegining(list* myList, int value){
    node *newNode = createNode(value);

    if(myList->begining == NULL){
        myList->begining = newNode;
        myList->end = myList->begining;
    }else{
        newNode->next = myList->begining;
        myList->begining = newNode;
    }
}

void removeNodeFromBegining(list* myList){
    if(myList->begining == NULL){
        return;
    }else{
        node *erasedNode = myList->begining;
        myList->begining = myList->begining->next;
        erasedNode->next = NULL;
        free(erasedNode);
    }
}

void addNodeToEnd(list* myList, int value){
    node *newNode = createNode(value);

    if(myList->begining == NULL){
        myList->begining = newNode;
        myList->end = myList->begining;
    }else{
        myList->end->next = newNode;
        myList->end = myList->end->next;
    }
}

void removeNodeFromEnd(list* myList){
    if(myList->begining == NULL){
        return;
    }else{
        node* auxNode = myList->begining;
        node* erasedNode = myList->end;

        while(auxNode->next->next != NULL){
            auxNode = auxNode->next;
        }

        myList->end = auxNode;
        auxNode->next = NULL;
        free(erasedNode);
    }
}

void addAfterValue(list* myList, int targetValue, int addedValue){
    if(myList->begining == NULL){
        return;
    }else{
        node* auxNode = myList->begining;

        while(auxNode != NULL){
            if(auxNode->value == targetValue) {
                node* newNode = createNode(addedValue);
                newNode->next = auxNode->next;
                auxNode->next = newNode;
            }
            auxNode = auxNode->next;
        }
    }
}

void removeValue(list* myList, int targetValue){
    if(myList->begining == NULL){
        return;
    }else if(myList->begining->value == targetValue){
        removeNodeFromBegining(myList);
    }else if(myList->end->value == targetValue){
        removeNodeFromEnd(myList);
    }else{
        node* auxNode = myList->begining;

        while(auxNode != NULL){
            if(auxNode->next != NULL && auxNode->next->value == targetValue) {
                node* erasedNode = auxNode->next;
                auxNode->next = auxNode->next->next;

                free(erasedNode);
            }
            auxNode = auxNode->next;
        }
    }
}

void printList(list* myList){
    node* auxNode = myList->begining;

    while(auxNode != NULL){
        printf("%d ", auxNode->value);
        auxNode = auxNode->next;
    }

    printf("\n");
}

int main(){
    list* myList = createList();

    addNodeToBegining(myList, 6);
    addNodeToBegining(myList, 16);
    addNodeToBegining(myList, 26);
    addNodeToBegining(myList, 36);
    addNodeToEnd(myList, 46);
    addNodeToEnd(myList, 56);
    addNodeToEnd(myList, 66);
    addAfterValue(myList, 46, 8);

    removeNodeFromEnd(myList);
    removeNodeFromBegining(myList);
    removeValue(myList, 6);
    removeValue(myList, 26);

    printList(myList);

    return 0;
}
