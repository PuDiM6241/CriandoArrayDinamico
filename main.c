#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int value;
    struct Cell *next;
} Cell;

typedef struct LDE {
    Cell *first;
    int quantity;
} LDE;

void printList(LDE *targetLDE);
LDE *createLDE();
void AddLDECell(LDE *targetLDE, int value);

int main() {
    LDE *list;
    list = (LDE *)createLDE();
    while ( 1 ) {
        int value;
        printf("add numbers: \n");
        scanf(" %d", &value);
        AddLDECell(list, value);
        printf("added %d\n", value);
        printList(list);
    }
    
}

void printList(LDE *targetLDE){
    Cell *CurrentCell = targetLDE[0].first;
    char *string = (char *)malloc(100*sizeof(char));
    int i = 0;
    while( CurrentCell != NULL && i < 98 ) {
        string[i] = '[';
        i++;
        string[i] = (char)(CurrentCell->value + '0');
        i++;
        string[i] = ']';
        i++;
        CurrentCell = CurrentCell->next;
    }
    string[i] = '\0';
    printf("%s\n", string);
    free(string);
}

LDE *createLDE(){
    LDE *newLDE = (LDE *)malloc(sizeof(LDE));
    newLDE->first = NULL;
    newLDE->quantity = 0;
    return newLDE;
}

void AddLDECell(LDE *targetLDE, int value){

    Cell *BehindCell = NULL;
    Cell *CurrentCell = targetLDE->first;
    Cell *newCell = (Cell *)malloc(sizeof(Cell));
    newCell->value = value;
    newCell->next = NULL;

    targetLDE->quantity++;
    while( CurrentCell != NULL && CurrentCell->value < value ) {
        BehindCell = CurrentCell;
        CurrentCell = BehindCell->next;
    }
    newCell->next = CurrentCell;
    if( BehindCell == NULL ){
        targetLDE->first = newCell;
        return;
    }
    BehindCell->next = newCell;

}