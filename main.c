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
                    printf("Digite o indice da tarefa a editar: ");
                    scanf("%d", &indice);
                    getchar();
                    if (indice >= 0 && indice < quantidade) {
                        editarTarefa(tarefas, indice);
                    } else {
                        printf("Indice invalido!\n");
                    }
                } else {
                    printf("Nenhuma tarefa cadastrada.\n");
                }
                break;
            
            case 4: 
                if (quantidade > 0) {
                    printf("Digite o indice da tarefa a excluir: ");
                    scanf("%d", &indice);
                    getchar();
                    if (indice >= 0 && indice < quantidade) {
                        excluirTarefa(tarefas, &quantidade, indice);
                    } else {
                        printf("Indice invalido!\n");
                    }
                } else {
                    printf("Nenhuma tarefa cadastrada.\n");
                }
                
            case 5: 
                salvarTarefasEmArquivo(tarefas, quantidade);
                break;
                
            case 6: 
                printf("Encerrando o programa.\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
