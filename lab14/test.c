#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static char *room_names[] = {"Boss room", "Safe zone", "Secret shop", "Hidden room", "Default room"};
static char *room_sizes[] = {"Large", "Big", "Medium", "Small"};

struct room {
    char name[50];
    int level;
    int number;
    int resolution;
    char size_name[20];
};

typedef struct Node {
    struct room data;
    struct Node* next;
    struct Node* prev;
    struct Node* vertical;
} node_nt;




node_nt* createNode(struct room data) {
    node_nt* newNode = (node_nt*)malloc(sizeof(node_nt));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->vertical = NULL;
    return newNode;
}


node_nt* TwoRowList(node_nt* head, int N) {
    if (N < 1) return head;
    
    node_nt* nodes[100];
    
    for (int i = 1; i <= N; i++) {
        struct room r;
        strcpy(r.name, room_names[rand() % 5]);
        strcpy(r.size_name, room_sizes[rand() % 4]);
        r.level = rand() % 10 + 1;
        r.number = i;
        r.resolution = rand() % 100 + 20;
        
        nodes[i] = createNode(r);
    }
    
    node_nt* prevTop = NULL;
    for (int i = (N % 2 == 0 ? N : N-1); i >= 2; i -= 2) {
        if (prevTop != NULL) {
            prevTop->next = nodes[i];
            nodes[i]->prev = prevTop;
        }
        prevTop = nodes[i];
    }
     
    node_nt* prevBottom = NULL;
    for (int i = (N % 2 == 1 ? N : N-1); i >= 1; i -= 2) {
        if (prevBottom != NULL) {
            prevBottom->next = nodes[i];
            nodes[i]->prev = prevBottom;
        }
        prevBottom = nodes[i];
    }
    
    for (int i = 2; i <= N; i += 2) {
        if (i-1 >= 1) {
            nodes[i]->vertical = nodes[i-1];
        }
    }
    for (int i = 1; i <= N-1; i += 2) {
        if (i+1 <= N) {
            nodes[i]->vertical = nodes[i+1];
        }
    }
    
    head  = nodes[N];
    return head;
}


void printList(node_nt* head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return;
    }
    
    printf("\n== Весь список ==\n");
    
    node_nt* current = head;
    printf("Верхний ряд: ");
    while (current != NULL && current->data.number % 2 == 0) {
        printf("a%d(%s) ", current->data.number, current->data.name);
        if (current->next != NULL && current->next->data.number % 2 == 0)
            printf("-> ");
        current = current->next;
    }
    printf("\n");
    
    node_nt* bottomStart = NULL;
    if (head->data.number % 2 == 1) {
        bottomStart = head;
    } else {
        bottomStart = head->vertical;
    }
    
    current = bottomStart;
    printf("Нижний ряд: ");
    while (current != NULL && current->data.number % 2 == 1) {
        printf("a%d(%s) ", current->data.number, current->data.name);
        if (current->next != NULL && current->next->data.number % 2 == 1)
            printf("-> ");
        current = current->next;
    }
    printf("\n");
}
void printCurrentNode(node_nt* node) {
    if (node == NULL) {
        printf("Текущий узел: NULL\n");
        return;
    }
    
    printf("\n=-=-=-= Комната a%d =-=-=-=\n", node->data.number);
    printf("Название: %s \n", node->data.name);
    printf("Уровень: %d \n", node->data.level);
    printf("Размер: %s (%d м^2) \n", node->data.size_name, node->data.resolution);
    
}

void navigateList(node_nt* head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return;
    }
    
    node_nt* current = head;
    char command;
    
    printf("\n= Управление = \n");
    printf("Команды: w(8) вверх, s(2) вниз, a(4) влево, d(6) вправо, r вернуться к head, q выход\n");
    
    do {
        printCurrentNode(current);
        printf("\nКоманда: ");
        scanf(" %c", &command);
        
        switch(command) {
            case 'd':
            case 'D':
            case '6':
                if (current->next != NULL) {
                    current = current->next;
                    printf("-> Перешли вправо к a%d\n", current->data.number);
                } else {
                    printf("-> Прохода нет \n");
                }
                break;
                
            case 'a':
            case 'A':
            case '4':
                if (current->prev != NULL) {
                    current = current->prev;
                    printf("-> Перешли влево к a%d\n", current->data.number);
                } else {
                    printf("-> Прохода нет \n");
                }
                break;
                
            case 'w':
            case 'W':
            case '8':
                if (current->vertical != NULL && current->data.number % 2 == 1) {
                    current = current->vertical;
                    printf("-> Перешли вверх к a%d\n", current->data.number);
                } else if (current->data.number % 2 == 0) {
                    printf("-> Прохода нет (верхний ряд)\n");
                } else {
                    printf("-> Прохода нет \n");
                }
                break;
                
            case 's':
            case 'S':
            case '2':
                if (current->vertical != NULL && current->data.number % 2 == 0) {
                    current = current->vertical;
                    printf("-> Перешли вниз к a%d\n", current->data.number);
                } else if (current->data.number % 2 == 1) {
                    printf("-> Прохода нет (нижний ряд)\n");
                } else {
                    printf("-> Прохода нет \n");
                }
                break;
                
            case 'r':
            case 'R':
                current = head;
                printf("-> Вернулись к head (a%d)\n", current->data.number);
                break;
                
            case 'q':
            case 'Q':
                printf("Выход\n");
                break;
                
            default:
                printf("Неизвестная команда\n");
        }
        
        } while (command != 'q' && command != 'Q');
}

int main() {
    srand(time(NULL));
    
    node_nt* head = {NULL};
    int N;
    
    printf("Введите количество комнат N: ");
    scanf("%d", &N);
    
    if (N % 2 != 0) {
        printf("Error: Количество комнат должно быть четным!\n");
        return -1;
    }
    
    head=TwoRowList(head, N);
    printList(head);
    
    navigateList(head);
    
    
    return 0;
}    