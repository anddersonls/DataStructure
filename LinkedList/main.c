#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node{
    int data;
    struct node *link;
};

//DECLARING THE SCOPES OF THE FUNCTIONS
struct node* addNodeAtEnd(struct node *ptr, struct node *head);
struct node* addNodeAtTheBeginning(struct node *head, struct node *ptr);
void showList(struct node *ptr);
void numberOfNodes(struct node *ptr);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int choice = 0;

    //POINTER OF THE HEAD OF THE LIST
    struct node *head = malloc(sizeof(struct node));
    head->link = NULL;

    //POINTER OF THE END OF THE LIST
    struct node *ptr = head;

    while(choice != 5){
        printf("\n\n|-------------MENU----------|\n");
        printf("1 - Adicionar um item no final da lista\n");
        printf("2 - Adicionar um item no início da lista\n");
        printf("3 - Mostrar os itens da lista\n");
        printf("4 - Contar itens da lista\n");
        printf("5 - Sair do programa\n");
        printf("Digite a operação que deseja realizar: ");
        scanf("%d", &choice);

        switch(choice){
            case(1): ptr = addNodeAtEnd(ptr, head);
                     break;
            case(2): head = addNodeAtTheBeginning(head, ptr);
                     break;
            case(3): showList(head);
                     break;
            case(4): numberOfNodes(head);
                     break;
            case(5): printf("Obrigado por utilizar o programa!\n");
                     break;
            default: printf("\n\nDigite um valor de operação válido!");
                     break;
        }

    }

    return 0;
}


//FUNCTIONS
struct node* addNodeAtEnd(struct node *ptr, struct node *head){
    int newData = 0;

    printf("Digite o valor inteiro que deseja armazenar: ");
    scanf("%d", &newData);

    //IF THE DATA OF THE FIRST NODE IS NULL, THEN WE ADD THE NEW DATA AT THE BEEGINNING OF THE LIST
    if(head->data == NULL){
        head->data = newData;

        return ptr;
    }
    //ELSE, WE CREATE A NEW NODE, AND POINT THE CURRENT END OF THE LIST TO NEW NODE
    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));

        temp->data = newData;
        temp->link = NULL;

        ptr->link = temp;

        return ptr->link;
    }
}


struct node* addNodeAtTheBeginning(struct node *head, struct node *ptr){
    if(head->data == NULL){
        ptr = addNodeAtEnd(ptr, head);
        return ptr;
    }
    else{
        struct node* temp = malloc(sizeof(struct node*));
        temp->link == NULL;
        printf("Valor que deseja colocar no início da lista: ");
        scanf("%d", &temp->data);

        //WE CREATE A NEW NODE AND POINT THIS NEW NODE TO THE HEAD, THEN WE RETURN THE NEW HEAD
        //SO THE PREVIOUS HEAD AT THE MAIN RECIVIE THE NEW HEAD
        temp->link = head;

        return temp;
    }
}


void showList(struct node *ptr){
    int currentData = 0;
     if(ptr->data == NULL){
        printf("Empty Linked List!");
    }
    else{
        while(ptr != NULL){
        currentData = ptr->data;
        printf("Dados: %d\n", currentData);
        ptr = ptr->link;
        }
    }
}


void numberOfNodes(struct node *ptr){
    int count = 0;
    if(ptr->data == NULL){
        printf("Empty Linked List!");
    }
    else{
        while(ptr != NULL){
            count++;
            ptr = ptr->link;
        }
        printf("Number of Nodes: %d", count);
    }
}
