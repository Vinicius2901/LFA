#include <stdio.h>

// void flush_in(){ 
//     int ch;
//     while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
// }

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
        scanf(" %c", &alfabeto[i] );
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
    printf("Digite quais sao os estados finais: ");
    for( int i = 0; i < nf; i++ ) {
        scanf("%d", &finais[i]);
    }

    char programa[ne][ne];
    for( int i = 0; i < ne; i++ ) {
        for( int j = 0; j < ne; j++ ) {
            programa[i][j] = '\0';
        }
    }

    int origem = 0, destino = 0;
    while( 1 ) {
        printf("Indique o estado de origem e destino (Digite -1 em um dos estados para sair):\n");
        scanf(" %d%d", &origem, &destino);
        if( origem < 0 || destino < 0 ) {
            break;
        }
        printf("Digite por qual letra do alfabeto essa transicao e feita:\n");
        scanf(" %c", &programa[origem][destino]);
    }

    printf("Alfabeto: ");
    for( int i = 0; i < na; i++ ) {
        printf("%c ", alfabeto[i] );
    }
    printf("\n");
    printf("Estados: ");
    imprimeVetorInt( estados, ne );
    printf("Estado inicial: %d\n", inicial);
    printf("Transicoes:\n");
    printf("\t");
    for( int i = 0; i < ne; i++ ) {
        printf("%d\t", i);
    }
    printf("\n");
    for( int i = 0; i < ne; i++ ) {
        printf("%d:\t", i);
        for( int j = 0; j < ne; j++ ) {
            printf("%c\t", programa[i][j]);
        }
        printf("\n");
    }
    printf("Estados finais: ");
    for( int i = 0; i < nf; i++ ) {
        printf("%d ", finais[i]);
    }
    printf("\n");
    char opt = 's';
    do {
        printf("Digite uma palavra para verificar: ");
        char fita[50];
        scanf(" %s", fita );
        int atual = inicial;
        int j, ver = 1;
        for( int i = 0; fita[i] != '\0'; i++ ) {
            for( j = 0; j < ne; j++ ) {
                if( programa[atual][j] == fita[i] ) {
                    atual = j;
                    break;
                }
            }
            if( j == ne ) {
                ver = 0;
                break;
            }
        }
        if( ver == 1 ) {
            for( int i = 0; i < nf; i++ ) {
                if( atual == finais[i] ) {
                    ver = 1;
                    break;
                }
                else {
                    ver = 0;
                }
            }
        }
        switch (ver)
        {
        case 0:
            printf("Essa palavra nao existe na linguagem.\n");
            break;
        
        default:
            printf("Essa palavra existe na linguagem.\n");
            break;
        }
        printf("Deseja continuar? (Digite s para continuar ou n para nao continuar)\n");
        scanf(" %c", &opt );
    } while( opt != 'n' && opt != 'N' );
    return 0;
}
