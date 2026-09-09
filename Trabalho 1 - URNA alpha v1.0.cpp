// Ultra Registrador de Notas da Andrea
// Versão Alpha 0.7
// Desenvolvido por: Carlos e Christian
// RA Carlos: 251026531
// RA Christian: 251024067
// Data: 30/05/2025
// Descrição: Um sistema simples para registrar notas de alunos, com funcionalidades de cadastro, exibição e análise de notas.
// Compilador: TDM-GCC 9.2.0 64-bit Release
// Sistema Operacional: Windows 11

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

//teclas
#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59

//ra
#define digitos 9
#define maxalunos 30


//do menu
void cabecalho(){
	printf(
"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ░░░░  ░░       ░░░   ░░░  ░░░      ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"
"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓       ▓▓▓  ▓  ▓  ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n"
"██████████████████████████████████████████  ████  ██  ███  ███  ██    ██        ████████████████████████████████████████\n"
"███████████████████████████████████████████      ███  ████  ██  ███   ██  ████  ████████████████████████████████████████\n"
"████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n"
"██████████████████████████████████████████ Ultra_Registrador_de_Notas_da_Andrea ████████████████████████████████████████\n"
"████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n\n"
);
}
void rodape(){
	printf("Utilize as setas para navegar no Menu(Enter para selecionar)\n");
	printf(
		"████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n"
		"████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n"
		"████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n"
		"████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n"
		"████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n"
		"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n"
		"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"
		"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
		);
}
//=====================================================================================
//=====================================================================================
//=====================================================================================
// FUNCOES AUXILIARES

//string para float manualmente - se formato errado retorna -1 (ex: 10.0, 10.00, 10)
float atofmanual(char temp[20]) {
    float resultado = 0.0, fatorDecimal = 1.0;
    int ponto = 0, j = 0;
    
    while (temp[j] != '\0' && resultado != -1) {
        if (temp[j] >= '0' && temp[j] <= '9') {
            if (ponto) {
                fatorDecimal /= 10.0;
                resultado += (temp[j] - '0') * fatorDecimal;
            } else {
                resultado = resultado * 10 + (temp[j] - '0');
            }
        } else if (temp[j] == '.') {
            if (ponto || j == 0 || temp[j + 1] == '\0') {
                resultado = -1;
				printf("Formato errado. Coloque o ponto de forma adequada...\n");
				return resultado;
            } else {
                ponto = 1;
            }
        } else {
            resultado = -1;
			printf("Formato errado. Apenas um ponto e numeros sao permitidos...\n");
        }
        j++;
    }
    return resultado;
}

//checar se o RA é igual a algum
int checara(int *alunos, char ra[maxalunos][digitos + 1], char temp[]) {
    for (int i = 0; i < *alunos; i++) {
        int j = 0;
        while (ra[i][j] == temp[j]) {
            if (ra[i][j] == '\0') {
                return 1; 
            }
            j++;
        }
    }
    return 0; 
}


//criacao das notas padrao
void notaspadrao(float *p1, float *p2){
	for(int i = 0; i < maxalunos; i++){
		p1[i] = -1; // -1 indica que a nota ainda nao foi cadastrada
		p2[i] = -1; // -1 indica que a nota ainda nao foi cadastrada
	}
}

//criacao da matriz de RA
void matrizpadrao(char ra[maxalunos][digitos + 1]){
	for(int i = 0; i < maxalunos; i++){
		for(int j = 0; j < digitos + 1; j++){
			ra[i][j] = 'a';
		}
	}
}

//limpa a linha da matriz de RA
void limparlinhamatriz(char ra[maxalunos][digitos + 1], int *alunos){
	for(int j = 0; j < digitos; j++){
		ra[*alunos][j] = 'a';
	}
	ra[*alunos][digitos] = '\0'; // garante final da string
}

//limpa o buffer do teclado
void limpabuffer(){
	int c;
	while( (c = getchar() ) != '\n' && c != EOF);
}

//limpar tela
void limpar(){
	system("cls");
}

//verifica se cadastro de alunos foi feito
int verificacadastro(int *alunos){
	if(*alunos == 0){
		printf("\033[0;33m\nPor favor, cadastre os alunos antes de acessar essa opcao.\033[0m\n");
		getch();
		return 0;
	}
	return 1;
}

//=====================================================================================
//=====================================================================================
//=====================================================================================
// FUNCOES DO PROGRAMA

//exbir alunos aprovados - aprovados sao aqueles com media >= 5 e frequencia > 70
void exibiraprovados(int *alunos, char ra[maxalunos][digitos + 1], float freq[maxalunos], float p1[maxalunos], float p2[maxalunos], int *ap1, int *ap2, float media[maxalunos]) {
	char spacetitulo[] = "                                           ";
	limpar();
	cabecalho();
	printf("\033[0;36m%sEXIBICAO DOS ALUNOS APROVADOS%s\n\n", spacetitulo, "\033[0m");

	if (*alunos == 0) {
		printf("Nenhum aluno cadastrado.\n");
		printf("Pressione qualquer tecla para continuar...\n");
		getch();
		return;
	}

	if (*ap1 == 0 && *ap2 == 0) {
		printf("Nenhuma nota cadastrada.\n");
		printf("Pressione qualquer tecla para continuar...\n");
		getch();
		return;
	}
	int i,j,k;
	// Calcular a média
	for (i = 0; i < *alunos; i++) {
		if (p1[i] != -1 && p2[i] != -1) {
			media[i] = (p1[i] + p2[i]) / 2;
		} else if (p1[i] != -1 || p2[i] != -1) {
			media[i] = (p1[i] != -1) ? p1[i] / 2 : p2[i] / 2;
		} else {
			media[i] = -1; // Média não calculada
		}
	}
	int aux = 0;
	for (i = 0; i < *alunos; i++) {
			if(media[i] < 0) media[i] = 0;
			if(media[i] >= 5 && freq[i] >= 70) {
				aux+=1;
			}

	}

	// cabecalho
	if(aux != 0)printf("\033[0;36m%-10s %-7s %-12s\n\033[0m", "RA", "Media", "Frequencia");
		for (i = 0; i < *alunos; i++) {
			if(media[i] >= 5 && freq[i] > 70) {
				printf("%-10s %-7.2f %-12.2f\n", ra[i], media[i], freq[i]);

			}
	}
	if (aux == 0) {
		printf("Nenhum aluno aprovado.\n");
	} else {
	    printf("Obs: Para o calculo, Notas nao cadastradas foram consideradas como 0.00!\n");
		printf("\n\033[0;36mTotal de alunos aprovados:\033[0m %d\n", aux);
	}
	printf("\nPressione qualquer tecla para continuar...\n");
	getch();
	return;
}


//exibir notas abaixo de 5
void exibirabaixo5(int *alunos, char ra[maxalunos][digitos + 1], float freq[maxalunos], float p1[maxalunos], float p2[maxalunos], int *ap1, int *ap2, float media[maxalunos]) {
	char spacetitulo[] = "                                           ";
	limpar();
	cabecalho();
	printf("\033[0;36m%sEXIBICAO ALUNOS COM NOTAS ABAIXO DE 5.0%s\n\n", spacetitulo, "\033[0m");

	if (*alunos == 0) {
		printf("Nenhum aluno cadastrado.\n");
		printf("Pressione qualquer tecla para continuar...\n");
		getch();
		return;
	}

	if (*ap1 == 0 && *ap2 == 0) {
		printf("Nenhuma nota cadastrada.\n");
		printf("Pressione qualquer tecla para continuar...\n");
		getch();
		return;
	}

	int i,j,k;
	// Calcular a média
	for (i = 0; i < *alunos; i++) {
		if (p1[i] != -1 && p2[i] != -1) {
			media[i] = (p1[i] + p2[i]) / 2;
		} else if (p1[i] != -1 || p2[i] != -1) {
			media[i] = (p1[i] != -1) ? p1[i] / 2 : p2[i] / 2;
		} else {
			media[i] = -1; // Média não calculada
		}
	}
	int aux=0;
	for (i = 0; i < *alunos; i++) {
		if (p1[i] < 5 || p2[i] < 5 || media[i] < 5) {
			if(media[i] < 0) media[i] = 0;
			aux++;
		}
	}
	// cabecalho
	if(aux != 0)printf("\033[0;36m%-10s %-12s %-7s %-7s %-7s\033[0m\n", "RA", "Frequencia", "P1", "P2", "Media");
	
	// Imprimir os alunos com média abaixo de 5
	int existe = 0;
	for (i = 0; i < *alunos; i++) {
		if (p1[i] < 5 || p2[i] < 5 || media[i] < 5) {
			printf("%-10s %-12.2f ", ra[i], freq[i]);
			if (p1[i] == -1) {
				printf("%-7s ", "N/A");
			} else {
				printf("%s%-7.2f%s ",(p1[i] < 5) ? "\033[0;33m" : "\033[0m", p1[i], "\033[0m");
			}
			if (p2[i] == -1) {
				printf("%-7s ", "N/A");
			} else {
				printf("%s%-7.2f%s ",(p2[i] < 5) ? "\033[0;33m" : "\033[0m", p2[i], "\033[0m");
			}
			if(media[i] < 0) media[i] = 0;
			printf("\033[0m%-7.2f\n", media[i]);
			if(media[i] < 5) existe +=1;
		} 

	}
	if (!existe) {
		printf("Nenhum aluno com média abaixo de 5.\n");
	} else {
		printf("Obs: Para o calculo, Notas nao cadastradas foram consideradas como 0.00!\n");
		printf("\n\033[0;36mTotal de alunos com média abaixo de 5:\033[0m %d\n", existe);
		printf("\n\033[0;36mTotal de alunos com notas abaixo de 5:\033[0m %d\n", aux);
	}
	printf("\nPressione qualquer tecla para continuar...\n");
	getch();
	return;
}



// Exibir médias em ordem crescente
void exibirmediacrescente(int *alunos, char ra[maxalunos][digitos + 1], float freq[maxalunos], float p1[maxalunos], float p2[maxalunos], int *ap1, int *ap2, float media[maxalunos]) {
    char spacetitulo[] = "                                           ";
    limpar();
    cabecalho();
    printf("\033[0;36m%sEXIBICAO DE MEDIAS EM ORDEM CRESCENTE%s\n\n", spacetitulo, "\033[0m");

    if (*alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        printf("Pressione qualquer tecla para continuar...\n");
        getch();
        return;
    }

    if (*ap1 == 0 && *ap2 == 0) {
        printf("Nenhuma nota cadastrada.\n");
        printf("Pressione qualquer tecla para continuar...\n");
        getch();
        return;
    }
	//vetor local
    char raLocal[maxalunos][digitos + 1];
    float mediaLocal[maxalunos];

    float soma = 0;
	int i,j,k;
    for (i = 0; i < *alunos; i++) {

        if (p1[i] != -1 && p2[i] != -1) {
            media[i] = (p1[i] + p2[i]) / 2;
            soma += media[i];
        } else if (p1[i] != -1 || p2[i] != -1) {
            media[i] = (p1[i] != -1) ? p1[i] / 2 : p2[i] / 2;
            soma += media[i];
        } else {
            media[i] = -1; // Média não calculada
        }
    }

	for (i = 0; i < *alunos; i++) { //copia media para vetor local
		mediaLocal[i] = media[i];
	}

	for (i = 0; i < *alunos; i++) { //copia RA para vetor local
        for (j = 0; j < digitos + 1; j++) {
            raLocal[i][j] = ra[i][j];
        }
	}


    float mediaGeral = soma / *alunos;
    for (i = 0; i < *alunos - 1; i++) {
        for (j = i + 1; j < *alunos; j++) {
            if (mediaLocal[j] < mediaLocal[i]) {

                // Troca as médias
				float tempMedia;
                tempMedia = mediaLocal[i];
                mediaLocal[i] = mediaLocal[j];
                mediaLocal[j] = tempMedia;

                // Troca os RAs
                char tempRA[digitos + 1];
				
                for (k = 0; k < digitos + 1; k++) {
                    tempRA[k] = raLocal[i][k];
                }
                for (k = 0; k < digitos + 1; k++) {
                    raLocal[i][k] = raLocal[j][k];
                }
                for (k = 0; k < digitos + 1; k++) {
                    raLocal[j][k] = tempRA[k];
                }
            }
        }
    }

    // Exibir cabeçalho
    printf("%-10s %-7s\n", "RA", "Media");
    // Imprimir os dados ordenados
    for (int i = 0; i < *alunos; i++) {
        if (mediaLocal[i] != -1) {
            printf("%-10s %-7.2f\n", raLocal[i], mediaLocal[i]);
        } else {
            printf("%-10s %-7s\n", raLocal[i], "0.00");
        }
    }
    printf("Obs: Para o calculo, Notas nao cadastradas foram consideradas como 0.00!\n");
    printf("\n\033[0;36mMédia Geral da Turma:\033[0;37m %.2f\033[0m\n", mediaGeral);
    printf("\nPressione qualquer tecla para continuar...\n");
    getch();
}

// Exibir parametros da turma
void parametrosdaTurma(int *alunos, char ra[maxalunos][digitos + 1], float freq[maxalunos], float p1[maxalunos], float p2[maxalunos], int *ap1, int *ap2, float media[maxalunos]) {
	char spacetitulo[] = "                                           ";
	limpar();
	cabecalho();
	printf("\033[0;36m%sPARAMETROS DA TURMA%s\n\n",spacetitulo, "\033[0m");

	if (*alunos == 0) {
		printf("Nenhum aluno cadastrado.\n");
		printf("Pressione qualquer tecla para continuar...\n");
		getch();
		return;
	}
    if (*ap1 == 0 && *ap2 == 0) {
        printf("Nenhuma nota cadastrada.\n");
        printf("Pressione qualquer tecla para continuar...\n");
        getch();
        return;
    }
	// Calcular a média geral
	float soma = 0;
	//int alunossemMedia = 0; // Contador de alunos sem média
	for (int i = 0; i < *alunos; i++) {
		media[i] = -1; // inicia a média como -1
	}
	for (int i = 0; i < *alunos; i++) {
		if (p1[i] != -1 && p2[i] != -1) {
			media[i] = (p1[i] + p2[i]) / 2;
			soma += media[i];
		} else if (p1[i] != -1 || p2[i] != -1) { // Se apenas uma nota foi cadastrada
			media[i] = (p1[i] != -1) ? p1[i]/ 2 : p2[i] / 2;
			soma += media[i];
		} else {
			media[i] = -1; // Indica que a média não foi calculada
			//alunossemMedia++; // esse seria um contador de alunos sem média
		}
	}
	
	float mediaGeral = soma / *alunos; // alunossemMedia seria descrementado do total de alunos

	// Encontrar maior e menor média
	float maior = -1, menor = 11;
	for (int i = 0; i < *alunos; i++) {
		if (media[i] != -1) {
			if (media[i] > maior) maior = media[i];
			if (media[i] < menor) menor = media[i];
		}
	}
	// Se não houver notas válidas, ajustar maior e menor e mediaGeral
	if (maior == -1) maior = 0; 
	if (menor == 11) menor = 0; 
	if (mediaGeral != mediaGeral) mediaGeral = 0;


	// Contar alunos acima da média
	int alunosAcimaDaMedia = 0;
	for (int i = 0; i < *alunos; i++) {
		if (media[i] != -1 && media[i] > mediaGeral) alunosAcimaDaMedia++;
	}

	// Contar alunos acima da média de aprovação (5.0)
	int acimaaprovacao = 0;
	for (int i = 0; i < *alunos; i++) {
		if (media[i] != -1 && media[i] >= 5.0) acimaaprovacao++;
	}
	printf("\033[0;36mMédia Geral da Turma:\033[0;37m %.2f\033[0m\n", mediaGeral);
	printf("\033[0;36mMaior Média:\033[0;37m %.2f\033[0m\n", maior);
	printf("\033[0;36mMenor Média:\033[0;37m %.2f\033[0m\n", menor);
	printf("\033[0;36mAlunos Acima da Média Geral:\033[0;37m %d alunos\033[0m\n", alunosAcimaDaMedia);
	printf("\033[0;36mAlunos Acima da Média de Aprovacao:\033[0;37m %d alunos\033[0m\n", acimaaprovacao);
    printf("Obs: Para o calculo, Notas nao cadastradas foram consideradas como 0.00!\n");
	printf("\nPressione qualquer tecla para continuar...\n");
	getch();
	return;
}

// Exibir notas
void exibirnotas(int *alunos, char ra[maxalunos][digitos + 1], float freq[maxalunos], float p1[maxalunos], float p2[maxalunos], int *ap1, int *ap2) {
	char reset[] = "\033[0m";
	char vermelhoclaro[] = "\033[0;31m";
	char spacetitulo[] = "                                           ";
	int na = 0;
	limpar();
	cabecalho();
	printf("\033[0;36m%sEXIBICAO DE NOTAS%s\n\n",spacetitulo, "\033[0m");
	
	if (*alunos == 0) {
		printf("Nenhum aluno cadastrado.\n");
		printf("Pressione qualquer tecla para continuar...\n");
		getch();
		return;
	}
		if (*ap1 == 0 && *ap2 == 0) {
		printf("Nenhuma nota cadastrada.\n");
		printf("Pressione qualquer tecla para continuar...\n");
		getch();
		return;
	}

	printf("%s%-10s %-11s %-7s %-7s%s\n",vermelhoclaro, "RA", "Frequencia", "P1", "P2", reset);
	for (int i = 0; i < *alunos; i++) {
		printf("%-10s %-11.2f ", ra[i], freq[i]);
		if (p1[i] == -1) {
			printf("%-7s ", "N/A");
			na = 1;
		} else {
			printf("%-7.2f ", p1[i]);
		}
		if (p2[i] == -1) {
			printf("%-7s \n", "N/A");
			na = 1;
		} else {
			printf("%-7.2f \n", p2[i]);
		}
	}
	if(na) printf("\nLegenda: N/A indica que a nota ainda nao foi cadastrada.\n\n");
	printf("\nPressione qualquer tecla para continuar...\n");
	getch();
	return;
}

// cadastrandoRA notas
void cadastronotas(float *p1, float *p2, int *ap1, int *ap2, int *alunos) {
    int op = 0;
    int valido = 1, valido2 = 1;
    char space[] = "      ";
	char spacetitulo[] = "                                           ";
    char select[] = "\033[0;31m   >> ";
    char reset[] = "\033[0m";

    while (1) {
        limpar();
        cabecalho();
        printf("\033[0;36m%sCADASTRO DE NOTAS%s\n\n",spacetitulo, reset);
        printf("%sCadastrar P1 ou P2? (Prova 1 ou Prova 2)\n", reset);
        printf("%s Prova 1%s\n", (op == 0) ? select : space, reset);
        printf("%s Prova 2%s\n", (op == 1) ? select : space, reset);
        printf("%s Voltar%s\n\n\n\n\n", (op == 2) ? select : space, reset);
        rodape();

        char t = getch();
        if (t == baixo) {
            if (op != 2) op++;
            else op = 0;
        } else if (t == cima) {
            if (op != 0) op--;
            else op = 2;
        } else if (t == enter) {
            switch (op) {
                case 0: // P1

                    do {
                        if (*ap1 >= *alunos) {
							limpar();
                        	cabecalho();
                      		printf("\033[0;36m%sCADASTRO DE NOTAS%s\n\n",spacetitulo, reset);
                            printf("Limite de Alunos atingido. Nao e possivel cadastrar mais notas da Prova 1.\n");
                            if (*alunos < maxalunos) printf("Cadastre mais alunos na opcao\033[0;33m [Cadastrar RA e frequencia dos alunos]\033[0m\n");
                            printf("Pressione qualquer tecla para continuar...\n");
                            getch();
                            return;
                        }
                        limpar();
                        cabecalho();
                        printf("\033[0;36m%sCADASTRO DE NOTAS%s\n\n",spacetitulo, reset);
                        printf("[Aluno %d] Digite a Nota da Prova 1: ", *ap1 + 1);
                        
						char temp[20]; // precisa caber até 19 caracteres mais '\0'
                        int cont=0, valido = 0;
						int erro = 0;
                        while (!valido) {
							if(erro == 1) printf("[Aluno %d] Digite a Nota da Prova 1: ", *ap1 + 1);
                            valido = 1;
							erro = 0;
                            scanf("%19s", temp); // limitado a 5
                            limpabuffer();
							while(temp[cont] != '\0') cont++;
                            if(cont > 5) {
								valido = 0;
								erro = 1;
								printf("Nota invalida. Deve conter no maximo 5 digitos...\n");
								cont = 0;
							}
							else{
								float valortemp = atofmanual(temp);
								if(valortemp < 0 || valortemp > 10) {
									valido = 0;
									erro = 1;
									cont = 0;
									if(valortemp != -1) {
										printf("Nota invalida. A nota deve ser no intervalo [0,10]...\n");
									}
								} else {
									p1[*ap1] = valortemp;
								}
							}
                            if (valido) {
                                p1[*ap1] = atofmanual(temp);
                            }
                        }
                    } while (!valido);
				    (*ap1)++;
                    if (*ap1 >= maxalunos) {
                        printf("Limite de alunos atingido. Nao e possivel cadastrar mais notas.\n");
                        if (*alunos < maxalunos) printf("Cadastre mais alunos na opcao \033[0;33m[Cadastrar RA e frequencia dos alunos]\033[0m\n");
                         printf("Pressione qualquer tecla para continuar...\n");
                        getch();
                        return;
                    }

                    printf("\nCadastro realizado com sucesso!\n");
                    printf("Pressione qualquer tecla para continuar...\n");
                    getch();
					break;


                case 1: // P2

                    do {
                        if (*ap2 >= *alunos) {
							limpar();
                        	cabecalho();
                      		printf("\033[0;36m%sCADASTRO DE NOTAS%s\n\n",spacetitulo, reset);
                            printf("Limite de Alunos atingido. Nao e possivel cadastrar mais notas da Prova 2.\n");
                            if (*alunos < maxalunos) printf("Cadastre mais alunos na opcao \033[0;33m[Cadastrar RA e frequencia dos alunos]\033[0m\n");
                            printf("Pressione qualquer tecla para continuar...\n");
                            getch();
                            return;
                        }
                        limpar();
                        cabecalho();
                        printf("\033[0;36m%sCADASTRO DE NOTAS%s\n\n",spacetitulo, reset);
                        printf("[Aluno %d] Digite a Nota da Prova 2: ", *ap2 + 1);
                        
                        char temp[20]; // precisa caber 19 caracteres + '\0'
                        int cont2=0, valido2 = 0;
						int erro2 = 0;
                        while (!valido2) {
							if(erro2 == 1) printf("[Aluno %d] Digite a Nota da Prova 2: ", *ap2 + 1);
                            valido2 = 1;
							erro2 = 0;
                            scanf("%19s", temp); // (19 para evitar overflow)
                            limpabuffer();
							while(temp[cont2] != '\0') cont2++;
                            if(cont2 > 5) {
								valido2 = 0;
								erro2 = 1;
								cont2 = 0;
								printf("Nota invalida. Deve conter no maximo 5 digitos...\n");
							}
							else{
								float valortemp = atofmanual(temp);
								if(valortemp < 0.0 || valortemp > 10.0) {
									valido2 = 0;
									erro2 = 1;
									cont2 = 0;
									if(valortemp != -1)printf("Nota invalida. A nota deve ser no intervalo [0,10]...\n");
								}
								else {
									p2[*ap2] = valortemp;
								}
							}
                            if (valido2) {
                                p2[*ap2] = atofmanual(temp);
                            }
                        }
                    } while (!valido2);
				            (*ap2)++;
                            if (*ap2 >= maxalunos) {
                                printf("Limite de alunos atingido. Nao e possivel cadastrar mais notas.\n");
                                if (*alunos < maxalunos) printf("Cadastre mais alunos na opcao \033[0;33m[Cadastrar RA e frequencia dos alunos]\033[0m\n");
                                printf("Pressione qualquer tecla para continuar...\n");
                                getch();
                                return;
                            }

                    printf("\nCadastro realizado com sucesso!\n");
                    printf("Pressione qualquer tecla para continuar...\n");
                    getch();
					break;

                case 2:
                    return;
            }
        }
    }
}


// Cadastrando RA e frequencia
void cadastrandoRA(int *alunos, char ra[maxalunos][digitos + 1], float freq[maxalunos]){
	int apenasnumeros = 1;
	char spacetitulo[] = "                                           ";
	float valortemp=-1;
	char reset[] = "\033[0m";
	
	limpar();
	cabecalho();
	printf("\033[0;36m%sCADASTRO DE RA E FREQUENCIA%s\n\n",spacetitulo, reset);
		if(*alunos >= maxalunos){
			printf("Limite de alunos(30) atingido. Nao e possivel cadastrar mais alunos.\n");
			printf("Pressione qualquer tecla para continuar...\n");
			getch();
			return;
		}
		char temp[20];
		int cont, valido = 0;

		while(!valido) {
			valido = 1;
			limparlinhamatriz(ra, alunos);
			printf("Digite o RA do aluno %d: ", *alunos + 1);
			scanf("%19s", temp);
			limpabuffer();

			cont = 0;
			while (temp[cont] != '\0') {
				cont++;
			}
			if(checara(alunos,ra,temp)==1){
				valido=0;
				printf("RA já cadastrado\n");
			}
			if (cont != digitos && valido) {
				valido = 0;
				printf("RA invalido. Deve conter exatamente %d digitos...\n", digitos);
			}
			for (int i = 0; i < cont && valido; i++) {
				if (temp[i] < '0' || temp[i] > '9') {
					valido = 0;
					printf("RA invalido. Apenas numeros sao permitidos...\n");
				}
			}
			if (valido) {
				for (int i = 0; i < digitos; i++) {
					ra[*alunos][i] = temp[i];
				}
				ra[*alunos][digitos] = '\0'; // garante final da string
			}
		}

		char temp2[20]; // precisa caber 19 caracteres + '\0'
        int cont2=0, Freqvalida = 0;
		int erro2 = 0;
		printf("Digite a Frequencia do aluno %d: ", *alunos + 1);
        while (!Freqvalida) {
			if(erro2 == 1) printf("Digite a Frequencia do aluno %d: ", *alunos + 1);
            Freqvalida = 1;
			erro2 = 0;
            scanf("%19s", temp2); // (19 para evitar overflow)
            limpabuffer();
			cont2 = 0;
			while(temp2[cont2] != '\0') cont2++;
        	    if(cont2 > 6) {
					Freqvalida = 0;
					erro2 = 1;
					printf("Frequencia invalida. Deve conter no maximo 6 digitos...\n");
				}
				else{
					float valortemp2 = atofmanual(temp2);
					if(valortemp2 < 0.0 || valortemp2 > 100.0) {
						Freqvalida = 0;
						erro2 = 1;
						if(valortemp2 != -1)printf("Frequencia invalida. A frequencia deve ser no intervalo [0,100]...\n");
					}
					else {
						freq[*alunos]=valortemp2;
						Freqvalida = 1;
					}
				}
			if (Freqvalida) {
				freq[*alunos] = atofmanual(temp2);
			}
        }
	printf("%.2f",freq[*alunos]);
	printf("\nCadastro realizado com sucesso!\n");
	printf("Pressione qualquer tecla para continuar...\n");
	getch();
}

//menu de cadastro de RA e frequencia
void cadastroRA(int *alunos , char ra[maxalunos][digitos + 1] , float freq[maxalunos], float *p1, float *p2, int *ap1, int *ap2){
	int op = 0;
	char spacetitulo[] = "                                           ";
	char space[] = "      ";
	char select[] = "\033[0;31m   >> ";
	char reset[] = "\033[0m";
	
	while(1){
		limpar();
		cabecalho();
		printf("\033[0;36m%sCADASTRO DE RA E FREQUENCIA%s\n\n",spacetitulo, reset);
		printf("%s Cadastrar Aluno %d e sua Frequencia%s\n", (op == 0) ? select : space, *alunos + 1, reset);
		if(*alunos != 0) printf("%s Remover Aluno %d e sua Frequencia%s\n", (op == 1) ? select : space, *alunos, reset);
		printf("%s Voltar%s\n\n\n\n\n\n\n", (op == 2) ? select : space, reset);
		rodape();
		
		
		char t = getch();
        
        if(t == baixo){
			if(op == 0 && *alunos == 0) op = 2;
			else if(op != 2) op++;
        	else op = 0;
		}
		else if(t == cima){
			if(op == 2 && *alunos == 0) op = 0;
			else if(op !=0) op--;
			else op = 2;
		}
		else if(t == enter){
			switch (op) {
				case 0:
					cadastrandoRA(alunos, ra, freq);
					*alunos+=1;
					break;
				case 1:
					limparlinhamatriz(ra, alunos);
					freq[*alunos] = 0;
					p1[*alunos] = -1;
					p2[*alunos] = -1;
					*alunos-=1;
					*ap1 = (*ap1 < 0) ? 0 : ((*ap1 > *alunos) ? *alunos : *ap1);
					*ap2 = (*ap2 < 0) ? 0 : ((*ap2 > *alunos) ? *alunos : *ap2);
					op = 0;
					printf("\033[0;33mAluno %d removido com sucesso!\033[0m\n", *alunos + 1);
					break;
				case 2:
					return;
					break;
			}
		}
		
	}

}

//menu principal
void menuprincipal(int *alunos, char ra[maxalunos][digitos + 1], float freq[maxalunos], float p1[maxalunos], float p2[maxalunos],int *ap1, int *ap2, float media[maxalunos]){
	
	int op = 0;
	char t;
	
	char space[] = "      ";
	char select[] = "\033[0;36m   >> ";
	char reset[] = "\033[0m";
	
	while(1){
		limpar();
		cabecalho();
		printf("%s Cadastrar RA e frequencia dos alunos%s\n", (op == 0) ? select : space, reset);
		printf("%s Cadastrar as notas dos alunos%s\n", (op == 1) ? select : space, reset);
		printf("%s Exibir todas as notas%s\n", (op == 2) ? select : space, reset);
		printf("%s Exibir parametros da turma(media geral, maior/menor media, alunos acima da media)%s\n", (op == 3) ? select : space, reset);
		printf("%s Exibir as medias em ordem crescente%s\n", (op == 4) ? select : space, reset);
		printf("%s Mostrar o RA dos alunos que tem notas de prova menores que 5%s\n", (op == 5) ? select : space, reset);
		printf("%s Mostrar os alunos aprovados na turma%s\n", (op == 6) ? select : space, reset);
		printf("%s Sair%s\n\n", (op == 7) ? select : space, reset);
		rodape();

		t = getch();

        if(t == baixo){
        	if(op != 7) op++;
        	else op = 0;
		}
		else if(t == cima){
			if(op !=0) op--;
			else op = 7;
		}
		else if(t == enter){
			switch (op) {
				case 0: //cadastrar RA e Freq
					cadastroRA(alunos, ra, freq, p1, p2, ap1, ap2);
					break;
				case 1://Cadastrar Notas
					if(!verificacadastro(alunos)) break;
					cadastronotas(p1, p2, ap1, ap2, alunos);
					break;
				case 2://Exibir Notas
					if(!verificacadastro(alunos)) break;
					exibirnotas(alunos, ra, freq, p1, p2, ap1, ap2);
					break;
				case 3://media geral, maior/menor media, alunos acima da media
					if(!verificacadastro(alunos)) break;
					parametrosdaTurma(alunos, ra, freq, p1, p2, ap1, ap2, media);
					break;
				case 4://exibir medias em ordem crescente
					if(!verificacadastro(alunos)) break;
					exibirmediacrescente(alunos, ra, freq, p1, p2, ap1, ap2, media);
					break;
				case 5://mostrar ra dos alunos que tem nota de prova menores que 5 
					if(!verificacadastro(alunos)) break;
					exibirabaixo5(alunos, ra, freq, p1, p2, ap1, ap2, media);
					break;
				case 6://mostrar aprovados na turma media >= 5, frequencia > 70
					if(!verificacadastro(alunos)) break;
					exibiraprovados(alunos, ra, freq, p1, p2, ap1, ap2, media);
					break;
				case 7://sair
					printf("Saindo...\n");
					return;
					break;

			}
		}
		
	}
}

//função principal
int main(){
	#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
	int alunos = 0;
	char ra[maxalunos][digitos + 1];
	float freq[maxalunos];
	float p1[maxalunos], p2[maxalunos];
	float media[maxalunos];
	int ap1=0, ap2=0;
	matrizpadrao(ra);
	notaspadrao(p1, p2);
	menuprincipal(&alunos, ra, freq, p1, p2, &ap1, &ap2, media);
	return 0;
}