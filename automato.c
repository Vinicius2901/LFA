#include <stdio.h>

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void imprimeVetorInt( int v[], int n ) {
    printf("Estados do automato: ");
    for( int i = 0; i < n; i++ ) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int ne, na, inicial, nf;
    printf("Digite quantos estados tem o automato: ");
    scanf("%d", &ne);
    int estados[ne];
    printf("Digite quantas letras tem o alfabeto do automato: ");
    scanf("%d", &na);
    char alfabeto[na];
    printf("Digite as letras do automato: ");
    for( int i = 0; i < na; i++ ) {
        scanf("%c", &alfabeto[i] );
    }
    for(int i = 0; i < ne; i++ ) {
        estados[i] = i;
    }
    imprimeVetorInt( estados, ne );

    printf("Digite qual o estado inicial: ");
    scanf("%d", &inicial);
    
    printf("Digite quantos estados finais tem: ");
    scanf("%d", &nf);

    int finais[nf];
    imprimeVetorInt( estados, ne );
    printf("Digite quais são os estados finais: ");
    for( int i = 0; i < nf; i++ ) {
        scanf("%d", &finais[i]);
    }

    char programa[ne][ne];
    for( int i = 0; i < ne; i++ ) {
        for( int j = 0; j < ne; j++ ) {
            programa[i][j] = '\0';
        }
    }

    printf("Indique o estado de origem e destino (Digite -1 em um dos estados para sair):\n");
    int origem = 0, destino = 0;
    while( 1 ) {
        flush_in();
        scanf("%d%d", &origem, &destino);
        if( origem < 0 || destino < 0 ) {
            break;
        }
        printf("Digite por qual letra do alfabeto essa transicao e feita:\n");
        scanf("%c", &programa[origem][destino]);
    }

    printf("Alfabeto: ");
    for( int i = 0; i < na; i++ ) {
        printf("%c ", alfabeto[i] );
    }
    printf("\n");
    printf("Estados: ");
    imprimeVetorInt( estados, ne );
    printf("Estado inicial: %d", inicial);
    printf("Transições:\n");
    printf("\t");
    for( int i = 0; i < ne; i++ ) {
        printf("%d ", i);
    }
    for( int i = 0; i < ne; i++ ) {
        printf("%d: ", i);
        for( int j = 0; j < ne; j++ ) {
            printf("%c ", programa[i][j]);
        }
        printf("\n");
    }
    printf("Estados finais: ");
    for( int i = 0; i < nf; i++ ) {
        printf("%d ", finais[i]);
    }

    // printf("Digite uma palavra para verificar: ");
    // char fita[50];
    // scanf("%s", fita );
    // for( int i = 0; fita[i] != '\0'; i++ ) {
    //     for( int j = 0; j < ne; j++ ) {
    //         if
    //     }
    // }
    return 0;
}