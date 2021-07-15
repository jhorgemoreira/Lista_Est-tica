#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// QUANTIDADE MÁXIMA DE REGISTROS NA LISTA
#define MAX 5

// VARIÁVEL RESPONSÁVEL PELO TAMANHO DA LISTA
int tamanho_lista = 0;

// ESTRUTURA COM AS INFORMAÇÕES DOS ALUNOS
typedef struct {

    char nome[10];
    int matricula;
    int idade;

}ALUNO;

// MENU COM AS OPÇÕES
void Menu() {

    printf("\t 1 - INSERIR NA LISTA \n");
    printf("\t 2 - LISTAR ALUNOS \n");
    printf("\t 3 - TAMANHO DA LISTA \n");
    printf("\t 4 - ORDENAR LISTA \n");
    printf("\t 5 - CONSULTAR LISTA \n");
    printf("\t 6 - GRAVAR LISTA \n");
    printf("\t 7 - CARREGAR LISTA \n");
    printf("\t 8 - REMOVER DA LISTA \n");
    printf("\t 9 - SAIR \n");

}

// LIMPRA A TELA DEPOIS DA ESCOLHA DE UMA OPÇÃO
void Limpar_Tela() {

    system("cls");

}

void Inserir_Lista(ALUNO aluno[]) {

    char nome[10];

    printf("\n\n");

    // VERIFICAR SE O TAMANHO DA LISTA É IGUAL AO TAMANHO MÁXIMO DEFINIDO, SE ISSO ACONTECER A LISTA ESTARÁ CHEIA
    if(tamanho_lista == MAX) {

        printf("\t LISTA CHEIA \n");

    }

    // INFORMAÇÕES QUE SERÃO INSERIDAS NA LISTA
    else {

        printf("Informe o nome do aluno: \n");
        scanf("%s", &nome);

        strcpy(aluno[tamanho_lista].nome, nome);

        printf("Informe a matrícula do aluno: \n");
        scanf("%d", &aluno[tamanho_lista].matricula);

        printf("Informe a idade do aluno: \n");
        scanf("%d", &aluno[tamanho_lista].idade);

        // ACRESCENTA O TAMANHO EM MAIS 1
        tamanho_lista++;

    }

    printf("\n\n");

}

void Listar_Lista(ALUNO aluno[]) {

    int i;

    printf("\n\n");

    // VERIFICA SE O TAMANHO DA LISTA É IGUAL A ZERO, SE ISSO ACONTECER A LISTA ESTÁ VAZIA
    if(tamanho_lista == 0) {

        printf("\t LISTA VAZIA \n");

    }

    // EXIBIÇÃO NA TELA DAS INFORMAÇÕES DOS ALUNOS CADASTRADOS
    else {

        printf("\t ================================== \n");
        printf("\t INFORMAÇÕES SOBRE OS ALUNOS \n");
        printf("\t ================================== \n");

        for(i = 0; i < tamanho_lista; i++) {

            printf("\t ================================== \n");
            printf("\t POSICAO: %d \n", i+1);
            printf("\t NOME: %s \n", aluno[i].nome);
            printf("\t MATRÍCULA: %d \n", aluno[i].matricula);
            printf("\t IDADE: %d \n", aluno[i].idade);
            printf("\t ================================== \n");

        }

    }

    printf("\n\n");

}

void Ordenar_Aluno(ALUNO aluno[]) {

    int i, j;
    ALUNO aux;

    printf("\n\n");

    // VERIFICA SE O TAMANHO DA LISTA É IGUAL A ZERO, SE ISSO ACONTECER A LISTA ESTÁ VAZIA
    if(tamanho_lista == 0) {

        printf("\t LISTA VAZIA \n");

    }

    else {

        for(i = 1; i < tamanho_lista; i++) {

            aux = aluno[i];

            // ORDENAÇÃO DOS ALUNOS PELA MATRÍCULA
            for(j = i; j > 0 && (aux.matricula < aluno[j - 1].matricula); j--) {

                aluno[j] = aluno[j - 1];

            }

            aluno[j] = aux;

        }

    }

    printf("\n\n");

}

void Consultar_Lista(ALUNO aluno[]) {

    int matricula = 0;
    int i;

    printf("\n\n");

    // VERIFICA SE O TAMANHO DA LISTA É IGUAL A ZERO, SE ISSO ACONTECER A LISTA ESTÁ VAZIA
    if(tamanho_lista == 0) {

        printf("\t LISTA VAZIA \n");

    }

    else {

        printf("Informe a matrícula do aluno que deseja buscar: \n");
        scanf("%d", &matricula);

        for(i = 0; i < tamanho_lista; i++) {

            // VERIFICA SE A MATRÍCULA INFORMADA PELO USUÁRIO É IGUAL A CADASTRADA, SE ISSO ACONTECER AS INFORMAÇÕES SÃO EXIBIDAS NA TELA
            if(matricula == aluno[i].matricula) {

                //printf("\t POSICAO: %d \n", i+1);
                printf("\t NOME %s \n", aluno[i].nome);
                printf("\t MATRÍCULA %d \n", aluno[i].matricula);
                printf("\t IDADE %d \n", aluno[i].idade);
                break;

            }

        }

    }

    printf("\n\n");

}

void Gravar(ALUNO aluno[]) {

    FILE *arquivo;

    int i;

    // ABERTURA DO ARQUIVO
    arquivo = fopen("lista_estatica.txt", "w");

    printf("\n\n");

    // VERIFICAR SE O ARQUIVO OU TAMANHO DA LISTA ESTÃO CORRETOS
    if(arquivo == NULL || tamanho_lista == 0) {

        printf("\t NÃO FOI POSSÍVEL ABRIR O ARQUIVO \n");
        printf("\t LISTA VAZIA \n");
        exit(0);

    }

    else {

        // GRAVAÇÃO DAS INFORMAÇÕES DOS ALUNOS NO ARQUIVO
        for(i = 0; i < tamanho_lista; i++) {

            //fprintf(arquivo, "%d \n ", i+1);
            fprintf(arquivo, "%s \n ", aluno[i].nome);
            fprintf(arquivo, "%d \n ", aluno[i].matricula);
            fprintf(arquivo, "%d \n ", aluno[i].idade);

        }

    }

    // FECHAMENTO DO ARQUIVO
    fclose(arquivo);

    printf("\n\n");

}

void Carregar(ALUNO aluno[]) {

    FILE *arquivo;

    int i = 0;
    int resultado = 0;

    // ABERTURA DO ARQUIVO
    arquivo = fopen("lista_estatica.txt", "r");

    printf("\n\n");

    // VERIFICAR SE O ARQUIVO ESTÁ VAZIO
    if(arquivo == NULL) {

        printf("\t NÃO FOI POSSIVEL ABRIR NO ARQUIVO \n");
        exit(0);

    }

    else {

        while((resultado = fscanf(arquivo, "%s %d %d ",
        aluno[i].nome, &aluno[i].matricula, &aluno[i].idade) != EOF)) {

            // CARREGAR AS INFORMAÇÕES SALVAS NO ARQUIVO
            printf("\t ===================================== \n");
            //printf("\t POSICAO: %d \n", i);
            printf("\t NOME: %s \n", aluno[i].nome);
            printf("\t MATRÍCULA: %d \n", aluno[i].matricula);
            printf("\t IDADE: %d \n", aluno[i].idade);
            printf("\t ===================================== \n");

            tamanho_lista++;
            i++;

        }

    }

    // FECHAMENTO DO ARQUIVO
    fclose(arquivo);

    printf("\n\n");

}

void Remover_Lista(ALUNO aluno[]) {

    int posicao = 0;
    int i;

    printf("\n\n");

    // VERIFICA SE O TAMANHO DA LISTA É IGUAL A ZERO, SE ISSO ACONTECER A LISTA ESTÁ VAZIA
    if(tamanho_lista == 0) {

        printf("\t LISTA VAZIA \n");

    }

    else {

        printf("Informe a posicao do aluno que deseja remover: \n");
        scanf("%d", &posicao);

        // VERIFICAR SE A POSIÇÃO PESQUISADA PARA REMOÇÃO ESTÁ DENTRO DO TAMANHO DA LISTA
        if(posicao >= 0 && posicao <= tamanho_lista) {

            for(i = posicao - 1; i < tamanho_lista; i++) {

                aluno[i] = aluno[i + 1];

            }

            tamanho_lista--;

        }

    }

    printf("\n\n");

}

// CHAMADA DAS FUNÇÕES NO MÉTODO PRINCIPAL
int main(void) {

    ALUNO aluno[MAX];

    int opcao = 0;

    do {

        Menu();

        printf("Informe uma opção: \n");
        scanf("%d", &opcao);

        Limpar_Tela();

        switch(opcao) {

            case 1:

                Inserir_Lista(aluno);
                break;

            case 2:

                Listar_Lista(aluno);
                break;

            case 3:

                printf("\t TAMANHO DA LISTA %d \n", tamanho_lista);
                break;

            case 4:

                Ordenar_Aluno(aluno);
                break;

            case 5:

                Consultar_Lista(aluno);
                break;

            case 6:

                Gravar(aluno);
                break;

            case 7:

                Carregar(aluno);
                break;

            case 8:

                Remover_Lista(aluno);
                break;

            case 9:

                exit(0);
                break;

            default:

                printf("\t OPÇÃO INVÁLIDA \n");
                break;

        }

    }while(opcao != 0);

}
