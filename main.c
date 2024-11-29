#include <stdio.h>
#include <string.h> 

void cadastrarTarefa (char tarefas [][4][50], int *quantidade);
void listarTarefa (char tarefas [][4][50], int quantidade);
void editarTarefa (char tarefas [][4][50], int indice);
void excluirTarefa (char tarefas [][4][50], int *quantidade, int indice);
void salvarTarefasEmArquivo (char tarefas [][4][50], int quantidade);


int main()
{
    int t;
    
    printf ("Informe o limite de tarefas (linhas da matriz): ");
    scanf ("%d", &t);
    
    char tarefas[t][4][50];
    int quantidade = 0, indice, opcao = 0;
    
    while (opcao != 6){
        printf ("\n=== Sistema de Gerenciamento de Tarefas ===\n");
        printf ("1. Cadastrar Tarefa\n");
        printf ("2. Listar Tarefas\n");
        printf ("3. Editar Tarefas\n");
        printf ("4. Excluir Tarefa\n");
        printf ("5. Salvar Tarefas em Arquivo\n");
        printf ("6. Sair\n"); 
        printf ("Escolha uma opcao: ");
        scanf ("%d", &opcao);
        getchar ();
        
        switch (opcao) {
            case 1: 
                cadastrarTarefa (tarefas, &quantidade);
                break;
                
            case 2: 
                listarTarefa (tarefas, quantidade);
                break; 
            
            case 3: 
                if (quantidade > 0) {
                    printf ("Digite o indice da tarefa a editar: ");
                    scanf ("%d", &indice);
                    getchar ();
                    if (indice >= 0 && indice < quantidade) {
                        editarTarefa (tarefas, indice);
                    } else {
                        printf ("Indice invalido!\n");
                    }
                } else {
                    printf ("Nenhuma tarefa cadastrada.\n");
                }
                break;
            
            case 4: 
                if (quantidade > 0) {
                    printf ("Digite o indice da tarefa a excluir: ");
                    scanf ("%d", &indice);
                    getchar ();
                    if (indice >= 0 && indice < quantidade) {
                        excluirTarefa (tarefas, &quantidade, indice);
                    } else {
                        printf ("Indice invalido!\n");
                    }
                } else {
                    printf ("Nenhuma tarefa cadastrada.\n");
                }
                
            case 5: 
                salvarTarefasEmArquivo (tarefas, quantidade);
                break;
                
            case 6: 
                printf ("Encerrando o programa.\n");
                break;
                
            default:
                printf ("Opção inválida!\n");
        }
    }

    return 0;
}

void cadastrarTarefa (char tarefas[t][4][50], int *quantidade) {
    if (*quantidade < t) {
        printf ("Digite o título da tarefa: ");
        fgets (tarefas[*quantidade][0], 50, stdin);
        tarefas[*quantidade][0][strcspn(tarefas[*quantidade][0], "\n")] = 0;
        
        printf ("Digite a descrição da tarefa: ");
        fgets (tarefas[*quantidade][1], 50, stdin);
        tarefas[*quantidade][1][strcspn(tarefas[*quantidade][1], "\n")] = 0;

        printf ("Digite a prioridade da tarefa (Alta, Media, Baixa): ");
        fgets (tarefas[*quantidade][2], 50, stdin);
        tarefas[*quantidade][2][strcspn(tarefas[*quantidade][2], "\n")] = 0;

        printf ("Digite o status da tarefa (Pendente, Concluido): ");
        fgets (tarefas[*quantidade][3], 50, stdin);
        tarefas[*quantidade][3][strcspn(tarefas[*quantidade][3], "\n")] = 0;

        (*quantidade)++;
        printf ("Tarefa cadastrada com sucesso!\n");
    } else {
        printf ("Limite máximo de tarefas atingido!\n");
    }
}
void listarTarefas (char tarefas[][4][50], int quantidade) {
    if (quantidade > 0) {
        printf ("\n=== Lista de Tarefas ===\n");
        for (int x = 0; x < quantidade; x++) {
            printf ("Tarefa %d:\n", x);
            printf ("Título: %s\n", tarefas[x][0]);
            printf ("Descrição: %s\n", tarefas[x][1]);
            printf ("Prioridade: %s\n", tarefas[x][2]);
            printf ("Status: %s\n\n", tarefas[x][3]);
        }
    } else {
        printf ("Nenhuma tarefa cadastrada.\n");
    }
}

void editarTarefa (char tarefas[][4][50], int indice) {
    printf ("Editando a tarefa %d:\n", indice);

    printf("Digite o novo título da tarefa: ");
    fgets (tarefas[indice][0], 50, stdin);
    tarefas[indice][0][strcspn(tarefas[indice][0], "\n")] = 0;

    printf ("Digite a nova descrição da tarefa: ");
    fgets(tarefas[indice][1], 50, stdin);
    tarefas[indice][1][strcspn(tarefas[indice][1], "\n")] = 0;

    printf ("Digite a nova prioridade da tarefa: ");
    fgets (tarefas[indice][2], 50, stdin);
    tarefas[indice][2][strcspn(tarefas[indice][2], "\n")] = 0;

    printf ("Digite o novo status da tarefa: ");
    fgets (tarefas[indice][3], 50, stdin);
    tarefas[indice][3][strcspn(tarefas[indice][3], "\n")] = 0;

    printf ("Tarefa editada com sucesso!\n");
}

void excluirTarefa (char tarefas[t][4][50], int *quantidade, int indice) {
    for (int x = indice; x < *quantidade - 1; x++) {
        for (int y = 0; y < 4; y++) {
            strcpy(tarefas[x][y], tarefas[x + 1][y]);
        }
    }
    (*quantidade)--;
    printf("Tarefa excluída com sucesso!\n");
}
