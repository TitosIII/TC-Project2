#include<stdio.h>
#include<stdlib.h>

#define MAX_LENGTH 100

void getString(char*);
int verifyString(char*);
void generateMoves(char*, int, int);

int main(){
    char moves[MAX_LENGTH];

    getString(moves);

    generateMoves(moves, 1, 16);

    return 1;
}

void getString(char* string){
    while(true){
        printf("Ingrese la cadena de movimientos (solo usar los caracteres 'r y 'b' e ingresar al menos 3 caracteres)\n");
        scanf("%s", string);
        
        int aux = verifyString(string);

        if(aux >= 3 && aux <= MAX_LENGTH){
            printf("Cadena válida.\n");
            return;
        }else{
            printf("Cadena inválida.\n");
        }
    }
}

int verifyString(char* string){
    int i;
    for(i = 0; i <= MAX_LENGTH; i++){
        if(string[i] == '\0'){
            return i;
        }else if(string[i] != 'r' && string[i] != 'b' && string[i] != 'R' && string[i] != 'B'){
            return -1;
        }
    }
    return i;
}

void printMoves(int* pos){
    int i;
    printf("{");
    for(i = 0; pos[i + 1] != -1; i++){
        printf("%d, ");
    }
    printf("%d}\n");
}

void writeMoves(FILE* ptr, int* pos){
    int i;
    printf("{");
    for(i = 0; pos[i + 1] != -1; i++){
        printf("%d, ");
    }
    printf("%d}\n");
}

void generateMoves(char* moves, int index, int p, int final, FILE* ptr, int* pos){
    if(moves[index] == '\0'){
        pos[index] = -1;
        printMoves(pos);

        if(pos[index - 1] == final)
            writeMoves(ptr, pos);
        
        return;
    }

    pos[index] = p;

    switch (p){
        case 1:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 2, final, ptr, pos);
                generateMoves(moves, index + 1, 5, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 6, final, ptr, pos);
            }
            break;

        case 2:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 5, final, ptr, pos);
                generateMoves(moves, index + 1, 7, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 1, final, ptr, pos);
                generateMoves(moves, index + 1, 3, final, ptr, pos);
                generateMoves(moves, index + 1, 6, final, ptr, pos);
            }
            break;

        case 3:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 2, final, ptr, pos);
                generateMoves(moves, index + 1, 4, final, ptr, pos);
                generateMoves(moves, index + 1, 7, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 6, final, ptr, pos);
                generateMoves(moves, index + 1, 8, final, ptr, pos);
            }
            break;

        case 4:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 7, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 3, final, ptr, pos);
                generateMoves(moves, index + 1, 8, final, ptr, pos);
            }
            break;
                
        case 5:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 2, final, ptr, pos);
                generateMoves(moves, index + 1, 10, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 1, final, ptr, pos);
                generateMoves(moves, index + 1, 6, final, ptr, pos);
                generateMoves(moves, index + 1, 9, final, ptr, pos);
            }
            break;

        case 6:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 2, final, ptr, pos);
                generateMoves(moves, index + 1, 5, final, ptr, pos);
                generateMoves(moves, index + 1, 7, final, ptr, pos);
                generateMoves(moves, index + 1, 10, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 1, final, ptr, pos);
                generateMoves(moves, index + 1, 3, final, ptr, pos);
                generateMoves(moves, index + 1, 9, final, ptr, pos);
                generateMoves(moves, index + 1, 11, final, ptr, pos);
            }
            break;

        case 7:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 2, final, ptr, pos);
                generateMoves(moves, index + 1, 4, final, ptr, pos);
                generateMoves(moves, index + 1, 10, final, ptr, pos);
                generateMoves(moves, index + 1, 12, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 3, final, ptr, pos);
                generateMoves(moves, index + 1, 6, final, ptr, pos);
                generateMoves(moves, index + 1, 8, final, ptr, pos);
                generateMoves(moves, index + 1, 11, final, ptr, pos);
            }
            break;
                
        case 8:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 4, final, ptr, pos);
                generateMoves(moves, index + 1, 7, final, ptr, pos);
                generateMoves(moves, index + 1, 12, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 3, final, ptr, pos);
                generateMoves(moves, index + 1, 11, final, ptr, pos);
            }
            break;

        case 9:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 5, final, ptr, pos);
                generateMoves(moves, index + 1, 10, final, ptr, pos);
                generateMoves(moves, index + 1, 11, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 6, final, ptr, pos);
                generateMoves(moves, index + 1, 14, final, ptr, pos);
            }
            break;

        case 10:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 5, final, ptr, pos);
                generateMoves(moves, index + 1, 7, final, ptr, pos);
                generateMoves(moves, index + 1, 13, final, ptr, pos);
                generateMoves(moves, index + 1, 15, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 6, final, ptr, pos);
                generateMoves(moves, index + 1, 9, final, ptr, pos);
                generateMoves(moves, index + 1, 11, final, ptr, pos);
                generateMoves(moves, index + 1, 14, final, ptr, pos);
            }
            break;
                
        case 11:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 7, final, ptr, pos);
                generateMoves(moves, index + 1, 10, final, ptr, pos);
                generateMoves(moves, index + 1, 12, final, ptr, pos);
                generateMoves(moves, index + 1, 15, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 6, final, ptr, pos);
                generateMoves(moves, index + 1, 8, final, ptr, pos);
                generateMoves(moves, index + 1, 14, final, ptr, pos);
                generateMoves(moves, index + 1, 16, final, ptr, pos);
            }
            break;

        case 12:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 7, final, ptr, pos);
                generateMoves(moves, index + 1, 15, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 8, final, ptr, pos);
                generateMoves(moves, index + 1, 11, final, ptr, pos);
                generateMoves(moves, index + 1, 16, final, ptr, pos);
            }
            break;

        case 13:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 10, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 9, final, ptr, pos);
                generateMoves(moves, index + 1, 14, final, ptr, pos);
            }
            break;
                
        case 14:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 10, final, ptr, pos);
                generateMoves(moves, index + 1, 13, final, ptr, pos);
                generateMoves(moves, index + 1, 15, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 9, final, ptr, pos);
                generateMoves(moves, index + 1, 11, final, ptr, pos);
            }
            break;

        case 15:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 10, final, ptr, pos);
                generateMoves(moves, index + 1, 12, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 11, final, ptr, pos);
                generateMoves(moves, index + 1, 14, final, ptr, pos);
                generateMoves(moves, index + 1, 16, final, ptr, pos);
            }
            break;

        case 16:
            if(moves[index] == 'r' || moves[index] == 'R'){
                generateMoves(moves, index + 1, 12, final, ptr, pos);
                generateMoves(moves, index + 1, 15, final, ptr, pos);
            }else{
                generateMoves(moves, index + 1, 11, final, ptr, pos);
            }
            break;
        
        default:
            printf("Error...");
            break;
    }
}

void generateMoves(char* moves, int p, int final){
    FILE* ptr = fopen("player 1.txt", "w");
    if(ptr == NULL){
        printf("Error al abrir el archivo.");
        return;
    }

    int pos[MAX_LENGTH + 1];
    generateMoves(moves, 0, p, final, ptr, pos);

    fclose(ptr);
}
