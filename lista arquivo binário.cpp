#include <bits/stdc++.h>
using namespace std;
void ex1(){
    FILE *arq = fopen("dados.bin","r+b");
    if(arq == NULL){
        printf("erro na leitura de arquivo\n");
        return;
    }
	printf("digite 5 numeros inteiros\n");
	int aux;
	for(int i=0;i<5;i++){
		//scanf("%d",&aux);
		cin >> aux;	
		fwrite(&aux,sizeof(int),1,arq);
		getchar();
	}
	fclose(arq);
	printf("gravacao concluida\n");
}
void ex2(){
    FILE *arq = fopen("dados.bin","r+b");
    if(arq == NULL){
        printf("erro na leitura de arquivo\n");
        return;
    }
	int aux;
	printf("numeros contidos no arquivo:\n");
	for(int i=0;i<5;i++){
		fread(&aux,sizeof(int),1,arq);
		printf("%d\n",aux);
	}
	
	fclose(arq);
}
int main(){
	if((fopen("dados.bin","r+b"))==NULL){
		printf("Primeira vez acessando, iniciando arquivos essenciais...\n");
		FILE *arq;
		fopen("dados.bin","w+b"); fclose(arq);
	}
	int l;
	do{
		printf("Digite o numero do exercicio que deseja fazer\n");
		while (scanf("%d", &l) != 1) {
	    	printf("Incorreto. Apenas numeros\n");
	    	while(getchar() != '\n'); 
		}
		switch(l){
			case 1:
				ex1();
				break;		
			case 2:
				ex2();
				break;
			case 3:
				ex3();
				break;
		}
	}while(l!=0);
}