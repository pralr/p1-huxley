#include <stdio.h>
#include <stdlib.h>

void init(int k, int students[]) {
    for(int i = 0; i < k; i++) {
        students[i] = 0;
    }
}

void anticlockwise(int count, int aux[]) {
    int i;
    for(i = 1; i < count; i++) {
        // se o atual for menor que o proximo, nao tinha nem que ta aqui
        if(aux[i] < aux[i+1])
            break;
    }

    if(i >= count-1)
        printf("SIM, ANTI-HORARIO");
    else 
        printf("NAO");
}

void clockwise(int count, int aux[]) {
    int i;
    for(i = 1; i < count; i++) {
        if(aux[i] > aux[i+1])
            break;
    }

    if(i >= count-1)
        printf("SIM, HORARIO");
    else
        printf("NAO");
}

void rotation(int k, int students[]){
    int i, aux[k];

    for(i = 0; i < k; i++) {
        if(students[i] == k)
            break;
    }

    // meu numero de est será minha marcação 
    aux[0] = students[i];

    for(int j = 1; j < k+1; j++) {
        i++; 
        // caso isso aconteça, retorne ao começo do array (pra "girar")
        if(students[i] == 0) 
            i = 0; 
        // reorganize o array para poder ver se é horario ou anti
        aux[j] = students[i];

    }

    // conferindo se é anti horario ou horario
        if(aux[1] <= aux[2]) {
            clockwise(k, aux);
        } else {
            anticlockwise(k, aux);
        }

}

int main() {
int cases, k, students[200] = {0};
scanf("%d", &cases);

while(cases!=0) {
    scanf("%d", &k); 
    for(int i = 0; i < k; i++) 
        scanf("%d", &students[i]); 
    rotation(k,students);
    printf("\n"); 
    init(k, students);
    cases--; 
}
    return 0;
}
