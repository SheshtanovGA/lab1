#include <stdio.h>
#include <stdlib.h>

void Snake(char *field, char size) {
    field = malloc(sizeof(char)*size*size);
    char number = 1;
    char streak = 1;
    char i = 0;
    char j = 0;
    *(field + i*size + j) = number++;
    while (1) {
        i++;
        *(field + i*size + j) = number++;
        for (int k = 0; k < streak; k++) {
            i--;
            j++;
            *(field + i*size + j) = number++;
        }
        if ((size%2 == 0)&&(i == 0)&&(j == size-1)) break;
        streak++;
        j++;
        *(field + i*size + j) = number++;
        for (int k = 0; k < streak; k++) {
            i++;
            j--;
            *(field + i*size + j) = number++;
        }
        if ((size%2 == 1)&&(i == size-1)&&(j == 0)) break;
        streak++;
    }
    streak--;
    if (size%2 == 1) goto f;
    while(2) {
        i++;
        *(field + i*size + j) = number++;
        if ((i == size-1)&&(j == size-1)) break;
        for (int k = 0; k < streak; k++) {
            i++;
            j--;
            *(field + i*size + j) = number++;
        }
        streak--;
        f:
        j++;
        *(field + i*size + j) = number++;
        if ((i == size-1)&&(j == size-1)) break;
        for (int k = 0; k < streak; k++) {
            i--;
            j++;
            *(field + i*size + j) = number++;
        }
        streak--;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", *(field + i*size + j));
        }
        printf("\n");
    }
    free(field);
    printf("\n");   
}

int main() {
    char *field;
    Snake(field, 4);
    Snake(field, 5);
    Snake(field, 6);
}