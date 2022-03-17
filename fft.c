#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, n1, m1, r, count = 0;
    while(scanf("%d %d", &n, &m)!=EOF) {
    count++; 
    n1 = n+1, m1 = m+1, r = n+m+1; 
    int pol_n[n1], pol_m[m1], pol[r];

    // inicializando
    for(int in = 0; in < r; in++) {
        pol[in] = 0;
    }
    // pegando os coeficientes de n 
    for(int i = 0; i < n1; i++) {
        scanf("%d", &pol_n[i]); 
    }

    // pegando os coeficientes de m
    for(int k = 0; k < m1; k++) {
        scanf("%d", &pol_m[k]); 
    }

    // fazendo um for duplo pra multiplicar cada elemento (que representa o coeficiente) contido em pol_n com cada elemento contido em pol_m
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m1; j++) {
            pol[i+j]+=(pol_n[i]*pol_m[j]);
            // quando multiplico, adiciono ao indice indicado (que representa meu grau) 
            // o indice indicado é a soma dos dois indices que to utilizando 
            // preciso acumular pra não perder o resto dos valores. 
            //printf("i: %d j: %d pol_n: %d pol_m: %d resultado da multiplicacao: %d, indice que ta entrando no resultado: %d, soma acumulada: %d\n", i, j, pol_n[i], pol_m[j], x, i+j, pol[i+j]);
        }
    }

    // por fim, printo o array com o resultado 
    printf("Caso #%d:", count); 
    for(int w = 0; w < r; w++)
        printf(" %d", pol[w]);
        
    printf("\n");
    }

    return 0;

    // obs. to precisando inicializar nesse caso pq nao to simplesmente sobrepondo os valores, e sim os acumulando desde o começo 
}