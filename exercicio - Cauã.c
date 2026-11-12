#include <stdio.h>
#include <string.h>

#define MAX 5

int main() {
    char fila[MAX][10];
    char pilha[MAX][10];
    int tamFila = 0;
    int tamPilha = 0;
    int opcao = -1;
    int i;
    char codigo[10];

    while (opcao != 0) {
        printf("\n===== ROMANEIO E CAMINHAO =====\n");
        printf("1 - Incluir pacote no romaneio\n");
        printf("2 - Retirar da fila e carregar\n");
        printf("3 - Retirar pacote do caminhao\n");
        printf("4 - Mostrar romaneio e caminhao\n");
        printf("0 - Encerrar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (tamFila == MAX) {
                printf("Romaneio cheio! Nao da para incluir.\n");
            } else {
                printf("Codigo do pacote (ex: P01): ");
                scanf("%9s", codigo);
                strcpy(fila[tamFila], codigo);
                tamFila++;
                printf("Pacote %s incluido no romaneio.\n", codigo);
            }
        }
        else if (opcao == 2) {
            if (tamFila == 0) {
                printf("Romaneio vazio! Nao ha pacote para carregar.\n");
            } else if (tamPilha == MAX) {
                printf("Caminhao cheio! O pacote continua na fila.\n");
            } else {
                strcpy(pilha[tamPilha], fila[0]);
                tamPilha++;
                printf("Pacote %s carregado no caminhao.\n", fila[0]);

                for (i = 0; i < tamFila - 1; i++) {
                    strcpy(fila[i], fila[i + 1]);
                }
                tamFila--;
            }
        }
        else if (opcao == 3) {
            if (tamPilha == 0) {
                printf("Caminhao vazio! Nao ha pacote para retirar.\n");
            } else {
                printf("Pacote retirado do caminhao: %s\n", pilha[tamPilha - 1]);
                tamPilha--;
            }
        }
        else if (opcao == 4) {
            printf("\nROMANEIO (frente -> fim): ");
            if (tamFila == 0) {
                printf("vazio");
            }
            for (i = 0; i < tamFila; i++) {
                printf("%s ", fila[i]);
            }

            printf("\nCAMINHAO (base -> topo):  ");
            if (tamPilha == 0) {
                printf("vazio");
            }
            for (i = 0; i < tamPilha; i++) {
                printf("%s ", pilha[i]);
            }
            printf("\n");
        }
        else if (opcao == 0) {
            printf("Encerrando o programa...\n");
        }
        else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
