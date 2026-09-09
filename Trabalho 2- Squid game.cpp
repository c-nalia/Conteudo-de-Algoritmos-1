
//Feito por Christhian Lucio Nalia e Igor Kenji Imada Akimura
#include <limits.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define QUAD_WIDTH 10
#define QUAD_HEIGHT 5
#define QUAD_X_LEFT 14
#define QUAD_X_RIGHT 40
#define QUAD_GAP_Y 9
#define MAX_TELAS 3
void cursorxy (int x, int y);
void clearConsole();
int SetColor (char color);
int amalgamars(int numeroDeStrings,char strings[][80],char stringReceptora[]);
void printColoridof(int cor[],int corInicio,char StringASerCortada[],char charsTokens[],int intervalo);
void printfCor(char string[],int cor);
void printfDramatico(char string[],int cor,int intervalo);
void presstoContinue();
void limpabuffer();
int smatrizlen(int numeroDeStrings,char strings[][80]);
void printfDinamico(int cor[],int corInicio,char StringASerCortada[],char charsTokens[],int intervalo,int X, int Y);
void textoMenu(int qualMenu,int cor[],char StringASerCortada[],char charsTokens[]);
int escolhaMenu(int cor[],int posEixoYInicio,int posEixoY,int linhasMenu,int posEixoX);
int MenuPrincipal(int cor[],int numerodeReprocessamentos,int opcoesEscolhidas[]);
void Mapa();
void NotaMusical(int freq,int duracao,int intervalo);
void Musica(int seed,int loop);
void BatatinhaFrita123(int cor2[]);
void habilitarANSI() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modoOriginal = 0;
    GetConsoleMode(hOut, &modoOriginal);
    SetConsoleMode(hOut, modoOriginal | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void gotoxy(int x, int y) {
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void limparTela() {
    system("cls");
}

void desenharQuadrado(int x, int y, int claro) {
    gotoxy(x - 1, y - 1);
    printf("+");
    for (int i = 0; i < QUAD_WIDTH; i++) printf("-");
    printf("+");

    for (int i = 0; i < QUAD_HEIGHT; i++) {
        gotoxy(x - 1, y + i);
        printf("|");
        if (claro)
            printf("\033[48;2;230;230;230m          \033[0m");
        else
            printf("\033[48;2;218;218;218m          \033[0m");
        printf("|");
    }

    gotoxy(x - 1, y + QUAD_HEIGHT);
    printf("+");
    for (int i = 0; i < QUAD_WIDTH; i++) printf("-");
    printf("+");
}

void desenharTelaCompleta(int lados[], int score) {
    gotoxy(0, 0);
    printf("Use ← ou → para pular      \n");
    printf("Score: %d                  \n\n", score); // espaço extra para não sobrescrever

    for (int i = 0; i < MAX_TELAS; i++) {
        int y = 5 + i * QUAD_GAP_Y;
        desenharQuadrado(QUAD_X_LEFT, y, lados[i] == 0);
        desenharQuadrado(QUAD_X_RIGHT, y, lados[i] == 1);
        gotoxy(QUAD_X_LEFT-1, y - 3);
        printf("|          |              |          |");
    }
}

void animarBolinha(int deX, int deY, int paraX, int paraY) {
    int x = deX, y = deY;
    while (y > paraY || x != paraX) {
        gotoxy(x, y);
        printf("O");
        Sleep(35);
        gotoxy(x, y);
        printf(" ");

        if (y > paraY) y--;
        if (x < paraX) x++;
        if (x > paraX) x--;
    }
}

void quebrarQuadrado(int x, int y) {
    Beep(900, 100);
    Beep(700, 100);
    Beep(500, 150);

    gotoxy(x - 1, y - 1);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒");

    for (int i = 0; i < QUAD_HEIGHT; i++) {
        gotoxy(x, y + i);
        printf("▒▒▒▒▒▒▒▒▒▒");
        Sleep(70);
    }

    gotoxy(x - 1, y + QUAD_HEIGHT);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒");
}


int main(){
{
#ifdef _WIN32
SetConsoleOutputCP(CP_UTF8);
#endif
}
	int cor[50],cor2[5],opcoesEscolhidas[5],reprossMain=1;
	cor[0]=0;cor[1]=1;cor2[0]=100;cor2[1]=108;
	for(int loop=1,i=2;i<50;i++,loop++){ //setando as cores
		if(loop==1)cor[i]=7;
		else if(loop==2){
			cor[i]=4;
			loop=0;
		}
	}
	while(reprossMain==1){
		opcoesEscolhidas[0]=0;
		MenuPrincipal(cor,1,opcoesEscolhidas);//MenuPrincipal(cor,numerodeReprocessamentos,opcoesEscolhidas);
		switch(opcoesEscolhidas[0]){
			case 1: clearConsole();
			BatatinhaFrita123(cor2);
			break;
			
			case 2:{
				clearConsole();
				habilitarANSI();
    srand(time(NULL));

    int lados[MAX_TELAS];
    for (int i = 0; i < MAX_TELAS; i++)
        lados[i] = rand() % 2;

    int perdeu = 0;
    int score = 0;

    while (!perdeu) {
        gotoxy(0, 0);
        desenharTelaCompleta(lados, score);

        // input
        int input;
        while (1) {
            input = getch();
            if (input == 0 || input == 224) {
                input = getch();
                if (input == 75) { // esquerda
                    input = 0;
                    break;
                } else if (input == 77) { // direita
                    input = 1;
                    break;
                }
            }
        }

        int alvoY = 5 + (MAX_TELAS - 1) * QUAD_GAP_Y + 1;
        animarBolinha(((input == 0) ? QUAD_X_LEFT : QUAD_X_RIGHT) + 6, alvoY + 7, 
              (input == 0) ? QUAD_X_LEFT + 1 : QUAD_X_RIGHT + 1, alvoY + 2);

        if (input == lados[MAX_TELAS - 1]) {
            // acerto
            Beep(1000, 80); // som de acerto
            score++;

            for (int i = MAX_TELAS - 1; i > 0; i--) {
                lados[i] = lados[i - 1];
            }
            lados[0] = rand() % 2;

        } else {
            // ERROU
            int quebrarX = (input == 0) ? QUAD_X_LEFT : QUAD_X_RIGHT;
            quebrarQuadrado(quebrarX, alvoY);
            gotoxy(20, alvoY + 8);
            printf("VOCÊ PERDEU! Score final: %d", score);
            perdeu = 1;
        }

        gotoxy(0, alvoY + 15);
    }
    getch();
				break;
			}
			
			case 3: {
				clearConsole();
				int aux=1;
				char SimouNao[4];
				while(aux!=0){
				printfDramatico("\n					>> Voce deseja mesmo sair desse jogo? <<\n	>> ",12,25);
				scanf("%s",&SimouNao);
				aux=SimouNao[0];
				if(aux==49||aux==83||aux==115){
				aux=0;
				reprossMain=0; //sim
				}
				else if(aux==48||aux==78||aux==110){
				aux=0; //nao
				}
				else printf("Entrada Invalida\n");
				}
			}
						
			break;
			
			default: printfCor("ERRO",4);
			break;
		}
	}
}

void BatatinhaFrita123(int cor2[]){
	printfDramatico("\n>>Carregando:",1,5);
	int vivo=1,posAtualXY[2]={60,25};
	for(int j=0;j<80;j++){
		printfDramatico(" ",112,5);
		if(j%10==0){
			cursorxy(13,1);
			printf("                            ");
			cursorxy(13,1);
		}
	}
		char aux[]={"\n>> BATATINHA FRITA 1 2 3 <<y\nInstrucoes: Seu objetivo eh simples, chegue ate o fim do corredor em menos de 60 segundos e ande apenas enquanto estiver\n tocando musica, caso contrario você sera removido forcadamente desse jogo.Clique a tecla 'w' muitas vezes para se mover para frentey\n"};
		//printColoridof(int cor[],int corInicio,char StringASerCortada[],char charsTokens[],int intervalo)
	{
	printColoridof(cor2,0,aux,"y",5);
	presstoContinue();
	clearConsole();
	double numeroaleatorio=100000*(time(NULL)*M_PI)/asin(pow(time(NULL),sqrt(time(NULL))));
	srand(int(numeroaleatorio));
	while(vivo==1){ //kbhit(void);
		Mapa();
		cursorxy(posAtualXY[0],posAtualXY[1]);	
		printfCor(" ",17);
		int loop=1,seed=rand()%5;
		while(loop<=12){
			if(posAtualXY[1]!=25){
				cursorxy(posAtualXY[0],posAtualXY[1]+1);
				printfCor(" ",102);
			}
			cursorxy(posAtualXY[0],posAtualXY[1]);	
			printfCor(" ",17);
			if(kbhit()){
				if(loop>=9){
					if(getch()=='w'){
						loop=12;
						vivo=0;
					}
				}
				else{
					if(getch()=='w'){
						posAtualXY[1]--;
					}
				}
				while(kbhit())getch();
			}
			if(posAtualXY[1]==5){
				loop=12;
				vivo=-1;
			}
			if(vivo!=0&&vivo!=-1)Musica(seed,loop);
			loop++;
		}
	}
	if(vivo==-1){
		int aux=0;
		clearConsole();
		SetColor(10);
		cursorxy(25,1+aux++);printf("                           ___");
		cursorxy(25,1+aux++);printf("       ,---.   ,--,      ,--.'|_                          ,--,");
		cursorxy(25,1+aux++);printf("      /__./| ,--.'|      |  | :,'     ,---.     __  ,-. ,--.'|");
		cursorxy(25,1+aux++);printf(" ,---.;  ; | |  |,       :  : ' :    '   ,'\\  ,' ,'/ /| |  |,");
		cursorxy(25,1+aux++);printf("/___/ \\  | | `--'_     .;__,'  /    /   /   | '  | |' | `--'_        ,--.--.");
		cursorxy(25,1+aux++);printf("\\   ;  \\ ' | ,' ,'|    |  |   |    .   ; ,. : |  |   ,' ,' ,'|      /       \\");
		cursorxy(25,1+aux++);printf(" \\   \\  \\: | '  | |    :__,'| :    '   | |: : '  :  /   '  | |     .--.  .-. |");
		cursorxy(25,1+aux++);printf("  ;   \\  ' . |  | :      '  : |__  '   | .; : |  | '    |  | :      \__\/: . .");
		cursorxy(25,1+aux++);printf("   \\   \\   ' '  : |__    |  | '.'| |   :    | ;  : |    '  : |__    , .--.; |");
		cursorxy(25,1+aux++);printf("    \\   `  ; |  | '.'|   ;  :    ;  \\   \\  /  |  , ;    |  | '.'|  /  /  ,.  |");
		cursorxy(25,1+aux++);printf("     :   \\ | ;  :    ;   |  ,   /    `----'    ---'     ;  :    ; ;  :   .'   \\");
		cursorxy(25,1+aux++);printf("      '---  |  ,   /     ---`-'                        |  ,   /  |  ,     .-./");
		cursorxy(25,1+aux++);printf("              ---`-'                                     ---`-'    `--`---'\n");
		presstoContinue();
	}
	else if(vivo==0){
		int aux2=0;
		clearConsole();
		SetColor(4);
		cursorxy(15,1+aux2++);printf("    ,---,.");
		cursorxy(15,1+aux2++);printf("  ,'  .'  \\                                                                          ,---,");
		cursorxy(15,1+aux2++);printf(",---.' .' |                                    ,--,                                ,---.'|    ,---.");
		cursorxy(15,1+aux2++);printf("|   |  |: |                 ,----._,.        ,'_ /|    ,----._,.                   |   | :   '   ,'\"");
		cursorxy(15,1+aux2++);printf(":   :  :  /    ,--.--.     /   /  ' /   .--. |  | :   /   /  ' /    ,--.--.        |   | |  /   /   |");
		cursorxy(15,1+aux2++);printf(":   |    ;    /       \   |   :     | ,'_ /| :  . |  |   :     |   /       \     ,--.__| | .   ; ,. :");
		cursorxy(15,1+aux2++);printf("|   :     \  .--.  .-. |  |   | .\  . |  ' | |  . .  |   | .\  .  .--.  .-. |   /   ,'   | '   | |: :");
		cursorxy(15,1+aux2++);printf("|   |   . |   \__\/: . .  .   ; ';  | |  | ' |  | |  .   ; ';  |   \__\/: . .  .   '  /  | '   | .; :");
		cursorxy(15,1+aux2++);printf("'   :  '; |   , .--.; |  '   .   . | :  | : ;  ; |  '   .   . |   , .--.; |  '   ; |:  | |   :    |");
		cursorxy(15,1+aux2++);printf("|   |  | ;   /  /  ,.  |   `---`-'| | '  :  `--'   \  `---`-'| |  /  /  ,.  |  |   | '/  '  \   \  /");
		cursorxy(15,1+aux2++);printf("|   :   /   ;  :   .'   \  .'__/\_: | :  ,      .-./  .'__/\_: | ;  :   .'   \ |   :    :|   `----'");
		cursorxy(15,1+aux2++);printf("|   | ,'    |  ,     .-./  |   :    :  `--`----'      |   :    : |  ,     .-./  \   \  /");
		cursorxy(15,1+aux2++);printf("`----'       `--`---'       \   \  /                   \   \  /   `--`---'       `----'");
		cursorxy(15,1+aux2++);printf("                             `--`-'                     `--`-'\n");
		NotaMusical(800,1000,0);
		NotaMusical(600,1000,0);
		NotaMusical(400,1000,0);
		presstoContinue();
	}
	}
}

void textoMenu(int posEixoX,int qualMenu,int cor[],char charsTokens[]){
	//printColoridof(int cor[],int corInicio,char StringASerCortada[],char charsTokens[]); smatrizlen(int numeroDeStrings,char strings[][30]);amalgamars(int numeroDeStrings,char strings[][30],char stringReceptora[]);
	if(qualMenu==1){ 
		cursorxy(0,1);
		char texto1[][80]={"					   _____                           _y y\n",
							"					    (      y  ___. y ,   . `   ___/\n",
							"					     `--.  y.'   ` y |   | |  /   |\n",
							"					        |  y|    | y |   | | ,'   |\n",
							"					   \\___.'  y `---|.y `._/| / `___,'\n",
							"					            y     |/y\n",
							"					 	    ___\n",
							"						   .'   \  y  ___ y , _ , _   y  ___y\n",
							"						   |       y /   `y |' `|' `. y.'   `y\n",
							"						   |    _  y|    |y |   |   | y|----'y\n",
							"						    `.___| y`.__/|y /   '   / y`.___,y\n"};
		int size;
		size=smatrizlen(11,texto1);
		char receptor1[size];
		amalgamars(11,texto1,receptor1);
		printColoridof(cor,2,receptor1,charsTokens,50);
		printf("\n					");printfDramatico("=================================================\n",4,1);
     	//printf("					");printfCor("||",4);printfCor("              escolha uma opcao              ",15);printfCor("||\n",4);
		printf("					");printfDramatico("||",4,1);printfDramatico("           qual jogo deseja jogar?           ",15,5);printfDramatico("||\n",4,1);
		printf("					");printfDramatico("||",4,1);printfDramatico("            batatinha frita 1 2 3:           ",14,5);printfDramatico("||\n",4,1);
		printf("					");printfDramatico("||",4,1);printfDramatico("                  Amarelinha     :           ",6,5);printfDramatico("||\n",4,1);
		printf("					");printfDramatico("||",4,1);printfDramatico("                     Sair        :           ",12,5);printfDramatico("||\n",4,1);
		printf("					");printfDramatico("=================================================\n",4,1);
	}
}

int escolhaMenu(int cor[],int posEixoYInicio,int posEixoY,int linhasMenu,int posEixoX){
//funcao que associa o input das teclas Uparrow,down e enter a um movimento do cursor
//enter=13,UpArrow=72,down=80,left=75,right=77
	int buffer=1,imput=1,posEixoYFinal=posEixoYInicio+linhasMenu-1;
	while(buffer>0&&imput!=0){ 
		imput=1;
		buffer=getch();
		if(buffer==13)imput=13;
		else if(buffer==224){
			imput=getch();
		}
		else if(buffer<=0)imput=getch();	
		buffer=1;
		switch(imput){
			case 72: 
			cursorxy (posEixoX,posEixoY);
			printfCor("  ",cor[0]);
			posEixoY--;
			if(posEixoY<posEixoYInicio){//7 11
				posEixoY=posEixoYFinal;
				cursorxy (posEixoX,posEixoY);
				printfCor("<<",cor[3]);
			}
			else{
				cursorxy (posEixoX,posEixoY);
				printfCor("<<",cor[3]);
			}
			break;
		case 80: 
			cursorxy (posEixoX,posEixoY);
			printfCor("  ",cor[0]);
			posEixoY++;
			if(posEixoY>posEixoYFinal){
				posEixoY=posEixoYInicio;
				cursorxy (posEixoX,posEixoY);
				printfCor("<<",cor[3]);
			}
			else{
				cursorxy (posEixoX,posEixoY);
				printfCor("<<",cor[3]);
			}
			break;
		case 13: if((posEixoYInicio<=posEixoY)&&(posEixoY<=posEixoYFinal)){
			buffer=0;
			imput=0;
			}
			break;
		default: 
			buffer=1;
			imput=1;
		}			
	}
	return posEixoY;
}

int MenuPrincipal(int cor[],int numerodeReprocessamentos,int opcoesEscolhidas[]){
	int repross[numerodeReprocessamentos];
	for(int r=0;r<numerodeReprocessamentos;r++){
		repross[r]=1;
	}
	while(repross[0]==1){
		char eixoX[]={"                                                                            "};
		int posEixoYInicio=15,posEixoY=posEixoYInicio,linhasMenu=3,posEixoX=strlen(eixoX);//<<<<<<<<<<<<<<<<<<<<<<<< parametros
		clearConsole();
		textoMenu(posEixoX,1,cor,"y");
		cursorxy(posEixoX,posEixoY);
		printfCor("<<",cor[3]);
		posEixoY=escolhaMenu(cor,posEixoYInicio,posEixoY,linhasMenu,posEixoX);//escolhaMenu(int cor[],int posEixoYInicio,int posEixoY,int linhasMenu,int posEixoX)
		int opcao;
		switch(posEixoY){
			case 15: opcao=1;
			break;
			case 16: opcao=2;
			break;
			case 17: opcao=3;
			break;
			default: opcao=-444;
			break;
		}
		opcoesEscolhidas[0]=opcao;
		return 1;
	}
}

void NotaMusical(int freq,int duracao,int intervalo) {
    Beep(freq,duracao);
    Sleep(intervalo);  // pausa entre as notas musicais
}

void Mapa(){
	//smatrizlen(int numeroDeStrings,char strings[][80])  amalgamars(int numeroDeStrings,char strings[][80],char stringReceptora[]) sprintf(string receptora,"texto", blablalb)
	// printfDinamico(int cor[],int corInicio,char StringASerCortada[],char charsTokens[],int intervalo,int X, int Y);
	char LinhadeChegada[2100];int size,cor3[25];
	for(int i=0;i<25;i++){
		if(i<4)cor3[i]=51;
		else if(i==4)cor3[i]=68;
		else cor3[i]=102;
	}
	size=sprintf(LinhadeChegada,"%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy%80cy",' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ');
	printfDinamico(cor3,0,LinhadeChegada,"y",0,20,1);
}

void Musica(int seed,int loop){
	int duracao,intervalo;
	switch(seed){
		case 1: duracao=850;intervalo=1;break;
		case 2: duracao=575;intervalo=75;break;
		case 3: duracao=500;intervalo=100;break;
		case 4: duracao=600;intervalo=60;break;
		case 5: duracao=500;intervalo=60;break;
		default: duracao=500;intervalo=100;break;
	}
	switch(loop){
		case 1:	NotaMusical(392,duracao,intervalo);  // G4
			break;    
		case 2: NotaMusical(440,duracao,intervalo);  // A4
			break;
		case 3: NotaMusical(392,duracao,intervalo);  // G4
			break;
		case 4:NotaMusical(330,duracao,intervalo);  // E4
			break;
		case 5:NotaMusical(392,duracao,intervalo);  // G4
			break;
		case 6:NotaMusical(440,duracao,intervalo);  // A4
			break;
		case 7:NotaMusical(494,duracao,intervalo);  // B4
			break;
		case 8:NotaMusical(392,duracao,intervalo);	 // G4
			break;
		case 9:NotaMusical(600,900+duracao,0); 
			break;
		case 10:NotaMusical(600,900+duracao,0); 
			break;
		case 11:NotaMusical(600,duracao,0); //fim
			break;	
		default: break;
	}
}

void presstoContinue(){
	printf("-pressione qualquer tecla para continuar-");
			int aux3;
			aux3=getch();
			if(aux3<0)getch();
}
void limpabuffer(){
	while(getchar()!='\n');
}
void cursorxy (int x, int y){
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void clearConsole(){
  if(_WIN32){
  	system("cls");
  }
  else system("clear");
}
int SetColor (char color) {
	HANDLE h;
	h = GetStdHandle (STD_OUTPUT_HANDLE);
	return SetConsoleTextAttribute (h,color);
}
int smatrizlen(int numeroDeStrings,char strings[][80]){
	int tamanhoDaString=0;
	for(int i=0;i<numeroDeStrings;i++){
		tamanhoDaString+=strlen(strings[i]);
	}
	return tamanhoDaString;
}
int amalgamars(int numeroDeStrings,char strings[][80],char stringReceptora[]){ //amalgamarStrings(numeroDeStrings,strings[][30],stringReceptora[]);
	//^^ essa fução pode juntar varias strings em apenas 1 e dar o tamanho da string final resultante (OBS: para essa função funcionar, necessita que exista de frases).
	int tamanhoDaString=0;
	for(int i=0;i<numeroDeStrings;i++){
		strcat(stringReceptora,strings[i]);
	}
	tamanhoDaString=strlen(stringReceptora);
	return tamanhoDaString;
}
void printColoridof(int cor[],int corInicio,char StringASerCortada[],char charsTokens[],int intervalo){ //printColoridof(cor[],StringASerCortada[],charsTokens[]);
	// ^^ essa fução pode ou printar uma string com cores em diversas de suas partes (OBS: para essa função funcionar, necessita que exista um vetor para as cores e para os characteres que serão tokens para os cortes da string).
	//0 = Preto; 1 = Azul; 2 = Verde; 3 = Verde-água; 4 = Vermelho; 5 = Roxo; 6 = Amarelo; 7 = Branco; 8 = Cinza; 9 = Azul claro ;10 = Verde claro; 11 = Verde-água claro ; 12 = Vermelho claro; 13 = Lilás; 14 = Amarelo claro; 15 = Branco brilhante
	int i=corInicio;
	char* TokensdeCorte=strtok(StringASerCortada,charsTokens);
	while(TokensdeCorte!=NULL){
		SetColor(cor[i]);
		Sleep(intervalo);
		printf("%s ",TokensdeCorte);
		SetColor(7);
		TokensdeCorte=strtok(NULL,charsTokens);
		i++;
	}
}

void printfCor(char string[],int cor){
	SetColor(cor);
	printf("%s",string);
	SetColor(7);
}

void printfDramatico(char string[],int cor,int intervalo){
	int n=strlen(string);
	SetColor(cor);
	for(int i=0;i<n;i++){
		Sleep(intervalo);
		printf("%c",string[i]);
	}
	SetColor(7);
}

void printfDinamico(int cor[],int corInicio,char StringASerCortada[],char charsTokens[],int intervalo,int X, int Y){ //printColoridof(cor[],StringASerCortada[],charsTokens[]);
	// ^^ essa fução pode ou printar uma string com cores em diversas de suas partes (OBS: para essa função funcionar, necessita que exista um vetor para as cores e para os characteres que serão tokens para os cortes da string).
	//0 = Preto; 1 = Azul; 2 = Verde; 3 = Verde-água; 4 = Vermelho; 5 = Roxo; 6 = Amarelo; 7 = Branco; 8 = Cinza; 9 = Azul claro ;10 = Verde claro; 11 = Verde-água claro ; 12 = Vermelho claro; 13 = Lilás; 14 = Amarelo claro; 15 = Branco brilhante
	int i=corInicio,posicaoDinamicaY=0;
	char* TokensdeCorte=strtok(StringASerCortada,charsTokens);
	while(TokensdeCorte!=NULL){
		SetColor(cor[i]);
		cursorxy(X,Y+posicaoDinamicaY);
		Sleep(intervalo);
		printf("%s ",TokensdeCorte);
		SetColor(7);
		TokensdeCorte=strtok(NULL,charsTokens);
		i++;
		posicaoDinamicaY++;
	}
}