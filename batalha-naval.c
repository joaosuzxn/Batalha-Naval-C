#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define TAMANHO 10
#define NAVIOS 25
#define AGUA '~'
#define NAVIO 'N'
#define ERRO 'E'
#define ACERTO 'A'

int save_x_cpu1 = -1; // Coordenada x acertada vai ser salva aqui
int save_y_cpu1 = -1; // Coordenada y acertada vai ser salva aqui
int save_case_cpu1 = 0; // Caso do switchcase de acerto do bot inteligente

int save_x_cpu2 = -1; // Coordenada x acertada vai ser salva aqui
int save_y_cpu2 = -1; // Coordenada y acertada vai ser salva aqui
int save_case_cpu2 = 0; // Caso do switchcase de acerto do bot inteligente

void imprimirTabuleiro(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("\n   ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("%c  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void imprimirTabuleiroEmoji(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("   ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < TAMANHO; j++)
        {
            if (tabuleiro[i][j] == AGUA)
            {
                printf("🌊 ");
            }
            else if (tabuleiro[i][j] == ACERTO)
            {
                printf("💥 ");
            }
            else if (tabuleiro[i][j] == ERRO)
            {
                printf("⭕ ");
            }
            else
            {
                printf("🚢 ");
            }
        }
        printf("\n");
    }
}

void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
    }
}

int verifyPosHor(char tabuleiro[TAMANHO][TAMANHO], int y, int x, int tamanhoNavio){
    int verify;
    
    for(int i = 0; i < tamanhoNavio; i++){
        if(tabuleiro[y][x + i] == NAVIO){
            return 0;
        }else{
            verify = 1;
        }
    }
    if(verify == 1){
        return 1;
    }
}

int verifyPosHorInv(char tabuleiro[TAMANHO][TAMANHO], int y, int x, int tamanhoNavio){
    int verify;
    
    for(int i = 0; i < tamanhoNavio; i++){
        if(tabuleiro[y][x - i] == NAVIO){
            return 0;
        }else{
            verify = 1;
        }
    }
    if(verify == 1){
        return 1;
    }
}

int verifyPosVer(char tabuleiro[TAMANHO][TAMANHO], int y, int x, int tamanhoNavio){
    int verify;
    for(int i = 0; i < tamanhoNavio; i++){
        if(tabuleiro[y + i][x] == NAVIO){
            return 0;
        }else{
            verify = 1;
        }
    }
}

int verifyPosVerInv(char tabuleiro[TAMANHO][TAMANHO], int y, int x, int tamanhoNavio){
         int verify;
    for(int i = 0; i < tamanhoNavio; i++){
        if(tabuleiro[y - i][x] == NAVIO){
            return 0;
        }else{
            verify = 1;
        }
    }
}


void porNavio(int quantidadeNavio, int tamanhoNavio, int x, char y, char tabuleiro[TAMANHO][TAMANHO]){
    int verify = 1;
    int dir;
    for(int i = 0; i < quantidadeNavio; i++){
    do{
        x = rand() % TAMANHO;
        y = rand() % TAMANHO;
        dir = rand() % 2;
        
    }while(tabuleiro[y][x] == NAVIO || verify == 0);
    
    switch(dir){
        case 0: 

    if(x + tamanhoNavio < TAMANHO){
    
    
    if(verifyPosHor(tabuleiro, y, x, tamanhoNavio) == 1){
        for(int i = 0; i< tamanhoNavio; i++){
        if(verify = 1){
            tabuleiro[y][x + i] = NAVIO;
        }
    }
    }else{
        i--;
    }
    
} else{
    
    i--;
   
}
    break;

    case 1:
    if(y + tamanhoNavio < TAMANHO){
    
    
    if(verifyPosVer(tabuleiro, y, x, tamanhoNavio) == 1){
        for(int i = 0; i< tamanhoNavio; i++){
        if(verify = 1){
            
            tabuleiro[y + i][x] = NAVIO;

        }
    }

    }else{
       
        i--;
    }
    
} else{
    
    i--;
   
}

    break;

}

    }

}

void posicionarNaviosAleatorios(char tabuleiro[TAMANHO][TAMANHO])
{
    int x;
    char y;
    int numNavio = NAVIOS;
    int verify;

    int quantidadeNavio, tamanhoNavio;



porNavio(1, 5, x, y, tabuleiro);
porNavio(2, 4, x, y, tabuleiro);
porNavio(2, 3, x, y, tabuleiro);
porNavio(3, 2, x, y, tabuleiro);

}

int conferindo_posicao_inteligente(char t[][TAMANHO], int x, int y){

    if(t[y][x] == ACERTO || t[y][x] == ERRO || x < 0 || x > TAMANHO - 1 || y < 0 || y > TAMANHO - 1){
        return 0;
    }
    
    return 1;
}

int validando_possibilidades_inteligente(char t[][TAMANHO], int x, int y){
    int valid = 0;
    
    valid += conferindo_posicao_inteligente(t, x + 1, y);
    valid += conferindo_posicao_inteligente(t, x - 1, y);
    valid += conferindo_posicao_inteligente(t, x, y + 1);
    valid += conferindo_posicao_inteligente(t, x, y - 1);

    if(!valid){ // se não houver mais possibilidades válidas ao redor, retorna 0
        return 0;
    }
    
    return 1;
}

int validando_continuacao_inteligente(char t[][TAMANHO], int x, int y, int possib){
   
    switch(possib){
        case 1:
            x = x + 1;
            break;
        case 2:
            x = x - 1;
            break;
        case 3:
            y = y + 1;
            break;
        case 4:
            y = y - 1;
            break;
    }
    
    if(t[y][x] == ACERTO || t[y][x] == ERRO || x < 0 || x > TAMANHO - 1 || y < 0 || y > TAMANHO - 1){
        return 0;
    }
    
    return 1;
}

int ataque_gpt_inteligente(char t[][TAMANHO], int acertos, int cpu){
    int possib = 0;
    int test = 0;
    int x, y;
    
    if(cpu == 1){
        possib = save_case_cpu1;
        x = save_x_cpu1;
        y = save_y_cpu1;
    }else{
        possib = save_case_cpu2;
        x = save_x_cpu2;
        y = save_y_cpu2;
    }
    
    if(!possib){
        
        do{
            possib = (rand() % 4) + 1;
        }while(!validando_continuacao_inteligente(t, x, y, possib));
    }
  
    switch(possib){
        case 1:

            x = x + 1;
           
            break;
        case 2:
        
            x = x - 1;

            break;
        case 3:
        
            y = y + 1;

            break;
        case 4:
        
            y = y - 1;

            break;
    }
   
    if(t[x][y] == NAVIO){
        t[x][y] = ACERTO;
        printf("Computador %d acertou1 em %c %d!\n", cpu, 'A' + x, y + 1);
        acertos++;
        imprimirTabuleiro(t);
        
        if(validando_continuacao_inteligente(t, x, y, possib)){ 
            // se ainda for possível continuar jogando nessa direção o bot irá fazê-lo
            if(cpu == 1){
                save_x_cpu1 = x;
                save_y_cpu1 = y;
                save_case_cpu1 = possib;
            }else{
                save_x_cpu2 = x;
                save_y_cpu2 = y;
                save_case_cpu2 = possib;
            }
        }else{ 
            
            if(cpu == 1){
                save_x_cpu1 = -1;
                save_y_cpu1 = -1;
                save_case_cpu1 = 0;
            }else{
                save_x_cpu2 = -1;
                save_y_cpu2 = -1;
                save_case_cpu2 = 0;
            }
        }
        
    }else{
        t[x][y] = ERRO;
        printf("Computador %d errou1 em %c %d!\n", cpu, x + 'A', 1 + y);
        imprimirTabuleiro(t);
        
        if(cpu == 1){ //resetando os casos do switchcase
            save_case_cpu1 = 0;
            save_x_cpu1 = -1;
            save_y_cpu1 = -1;
        }else{
            save_case_cpu2 = 0;
            save_x_cpu2 = -1;
            save_y_cpu2 = -1;
        }
        
        if(cpu == 1){ // se não houver mais possibilidades, vai mudar o valor da posição salva
           if(!validando_possibilidades_inteligente(t, save_x_cpu1, save_y_cpu1)){ 
                save_x_cpu1 = -1;
                save_y_cpu1 = -1;
            }
        }else{
            if(!validando_possibilidades_inteligente(t, save_x_cpu2, save_y_cpu2)){ 
                save_x_cpu2 = -1;
                save_y_cpu2 = -1;
            }
        }
    }
    
    return acertos;
}


int ataqueComputador(char tabuleiro[TAMANHO][TAMANHO], int acertos, int cpu)
{
    int linha, coluna;
    int proxAtk;

    int inteligente = 0;
    
    if(cpu == 1){
        if(save_x_cpu1 >= 0 && save_y_cpu1 >= 0){ // se tiver posição salva, então atacará inteligente
            inteligente = 1;
        }
    }else if(save_x_cpu2 > 0 && save_y_cpu2 > 0){
       
           inteligente = 1;
       
    }
    
    if(inteligente){
        printf( "\x1b[33m \n\tataque inteligente\n \x1b[0m");
        acertos = ataque_gpt_inteligente(tabuleiro, acertos, cpu);
    }else{
        
        do
        {
            linha = 'A' + rand() % TAMANHO;
            coluna = rand() % TAMANHO;
        } while (tabuleiro[linha - 'A'][coluna] == ERRO || tabuleiro[linha - 'A'][coluna] == ACERTO);
    
        if (tabuleiro[linha - 'A'][coluna] == NAVIO)
        {
            printf("\nComputador %d acertou2 em %c %d!\n", cpu, linha, coluna + 1);
            tabuleiro[linha - 'A'][coluna] = ACERTO;
            acertos++;
            imprimirTabuleiro(tabuleiro);
            
            if(validando_possibilidades_inteligente(tabuleiro, linha - 'A', coluna)){
                
                if(cpu == 1){
                    save_x_cpu1 = linha - 'A';
                    save_y_cpu1 = coluna;
                }else{
                    save_x_cpu2 = linha - 'A';
                    save_y_cpu2 = coluna;
                }
            }
            
            proxAtk = rand() % 2;
        }
        else
        {
            printf("\nComputador %d errou2 em %c %d!\n", cpu, linha, coluna + 1);
            tabuleiro[linha - 'A'][coluna] = ERRO;
            imprimirTabuleiro(tabuleiro);
        }
    }
    
    return acertos;
}

void posicionarNaviosManual(char tabuleiroPlayer[TAMANHO][TAMANHO])
{

    int x, tamanhoNavio;
    int verify = 0, verifier = 0, uberprufen;
    char y;
    int portaaviao = 1, navioTanque = 2, contratorpedeiros = 2, submarino = 3;
    int verificarEspacos;

    int soma = portaaviao + navioTanque + contratorpedeiros + submarino;

    int choixDir, choiceShip;
    inicializarTabuleiro(tabuleiroPlayer);
    do
    {
        imprimirTabuleiro(tabuleiroPlayer);
        printf("Qual navio voce deseja colocar?");
        printf("\n1.Porta-avioes(%d restante(s))\n2.Navio-tanque(%d restante(s)) \n3.contratorpedeiros(%d restantes(s))\n4.submarino(%d restante(s))\n", portaaviao, navioTanque, contratorpedeiros, submarino);
        scanf("%d", &choiceShip);

        switch (choiceShip)
        {
        case 1:
            tamanhoNavio = 5;

            if (portaaviao <= 0)
            {
                printf("\nPorta avioes esgotados\n");
                continue;
            }
            portaaviao--;
            verifier++;
            uberprufen = 1;
            break;
        case 2:
            tamanhoNavio = 4;

            if (navioTanque <= 0)
            {
                printf("\nNavios Tanques esgotados\n");
                continue;
            }
            verifier++;
            navioTanque--;
            uberprufen = 2;
            break;
        case 3:
            tamanhoNavio = 3;
            if (contratorpedeiros <= 0)
            {
                printf("\nContratorpedeiros esgotados\n");
                continue;
            }
            contratorpedeiros--;
            verifier++;
            uberprufen = 3;
            break;
        case 4:
            tamanhoNavio = 2;
            if (submarino <= 0)
            {
                printf("\nsubmarinos esgotados\n");
                continue;
            }
            submarino--;
            verifier++;
            uberprufen = 4;
            break;
        default:
            printf("\nOpcao invalida\n");
            continue;
        }

        do
        {

            printf("\nVoce deseja posiciona-lo em qual direcao?\n1.Esquerda\n2.Direita\n3.Baixo\n4.Cima\n");
            scanf("%d", &choixDir);
            if (choixDir != 1 && choixDir != 2 && choixDir != 3 && choixDir != 4)
            {
                printf("\nInsira um valor valido\n");
                continue;
            }

            printf("\nInsira as coordenadas da posicao do navio: ");
            scanf("%d%c", &x, &y);

            getchar();
            x = x - 1;
            y = toupper(y);

            if (x < 0 || x + 1 > TAMANHO || y < 'A' || y > 'A' + TAMANHO - 1)
            {
                printf("\nInsira uma coordenada valida\n");
                continue;
            }
            y = y - 'A';
            if (tabuleiroPlayer[y][x] == NAVIO)
            {
                printf("Insira uma coordenada nao ocupada\n");
                verifier--;
                switch (uberprufen)
                {
                case 1:
                    portaaviao++;
                    break;

                case 2:
                    navioTanque++;
                    break;

                case 3:
                    contratorpedeiros++;
                    break;

                case 4:
                    submarino++;
                    break;
                }
                break;
            }

            switch (choixDir)
            {
            case 1:
                if (x - tamanhoNavio < 0)
                {
                    printf("\nTamanho n da\n");
                    break;
                }
                
                if (verifyPosHorInv(tabuleiroPlayer, y, x, tamanhoNavio) == 0)
                {
                    printf("\nPosicao ocupada\n");
                    break;
                }
                for (int i = 0; i < tamanhoNavio; i++)
                {

                    tabuleiroPlayer[y][x - i] = NAVIO;
                }
                verify = tamanhoNavio;
                break;

            case 2:
                if (x + tamanhoNavio > TAMANHO)
                {
                    printf("\nTamanho n da\n");
                    break;
                }
              
                if (verifyPosHor(tabuleiroPlayer, y,  x, tamanhoNavio) == 0)
                {
                    printf("\nPosicao ocupada\n");
                    break;
                }
                for (int i = 0; i < tamanhoNavio; i++)
                {

                    tabuleiroPlayer[y][x + i] = NAVIO;
                }
                verify = tamanhoNavio;
                break;

            case 3:
                if (y + tamanhoNavio > TAMANHO)
                {
                    printf("\nTamanho n da\n");
                    break;
                }
                
                if (verifyPosVer(tabuleiroPlayer, y, x, tamanhoNavio) == 0)
                {
                    printf("\nPosicao ocupada\n");
                    break;
                }
                for (int i = 0; i < tamanhoNavio; i++)
                {

                    tabuleiroPlayer[y + i][x] = NAVIO;
                }
                verify = tamanhoNavio;
                break;
            case 4:
                if (y - tamanhoNavio < 0)
                {
                    printf("\nTamanho n da\n");
                    break;
                }
                
                if (verifyPosVerInv(tabuleiroPlayer, y, x, tamanhoNavio) == 1)
                {
                    printf("\nPosicao ocupada\n");
                    break;
                }
                for (int i = 0; i < tamanhoNavio; i++)
                {
                    tabuleiroPlayer[y - i][x] = NAVIO;
                }
                verify = tamanhoNavio;
                break;
            default:
                printf("\nInsira um valor valido\n");
            }

        } while (verify != tamanhoNavio);

    } while (verifier != soma);
    printf("\nTabuleiro Posicionado!\n");
}

void botxbot()
{

    char tabuleiroComputador1[TAMANHO][TAMANHO];
    char tabuleiroComputador2[TAMANHO][TAMANHO];
    int acertosComputador1 = 0, acertosComputador2 = 0;

    srand(time(NULL));

    inicializarTabuleiro(tabuleiroComputador1);
    inicializarTabuleiro(tabuleiroComputador2);

    posicionarNaviosAleatorios(tabuleiroComputador1);
    posicionarNaviosAleatorios(tabuleiroComputador2);

    printf("Tabuleiro do Computador 1:\n");
        imprimirTabuleiro(tabuleiroComputador1);
        printf("\n");
        printf("Tabuleiro do Computador 2:\n");
        imprimirTabuleiro(tabuleiroComputador2);

    while (1)
    {
    
        acertosComputador1 = ataqueComputador(tabuleiroComputador2, acertosComputador1, 1);

        if (acertosComputador1 == NAVIOS)
        {
            printf("Computador 1 venceu! 🎆\n");
            imprimirTabuleiro(tabuleiroComputador2);
            break;
        }

        acertosComputador2 = ataqueComputador(tabuleiroComputador1, acertosComputador2, 2);

        if (acertosComputador2 == NAVIOS)
        {
            printf("Computador 2 venceu! 🎆\n");
            imprimirTabuleiro(tabuleiroComputador1);
            break;
        }

        getchar();
    }
}

int ataquePlayer(char tabuleiro[TAMANHO][TAMANHO], int acertos, char tabuleiroAmostra[TAMANHO][TAMANHO])
{
    char y;
    int x;
    int seila;

    do
    {
        printf("\n---------------------------------\n");
        printf("\n\tTabuleiro inimigo\n");

        imprimirTabuleiro(tabuleiroAmostra);
        printf("\nInsira a coordenada do ataque (ex: 1A, 2B, etc.): ");
        scanf(" %d%c", &x, &y);
        y = toupper(y);
        x = x - 1;

        if (x < 0 || x + 1 > TAMANHO || y < 'A' || y > 'A' + TAMANHO - 1)
        {
            printf("\nCoordenada inválida. Tente novamente.\n");
            continue;
        }

                if (tabuleiroAmostra[y - 'A'][x] == ACERTO || tabuleiroAmostra[y - 'A'][x] == ERRO)
        {
            printf("\nVocê já atacou esta coordenada anteriormente. Tente novamente.\n");
            continue;
        }

        if (tabuleiroAmostra[y - 'A'][x] == NAVIO)
        {
            tabuleiroAmostra[y - 'A'][x] = ACERTO;
            printf("O Player acertou em %d%c!\n", x + 1, x);
            acertos++;
        }
        else
        {
            tabuleiroAmostra[y - 'A'][x] = ERRO;
            printf("O Player errou em %d%c!\n", x + 1, y);
        }

        seila = 1;

    } while (seila != 1);

    return acertos;
}

void jogar()
{

    char tabuleiroPlayer[TAMANHO][TAMANHO];
    char tabuleiroCPU[TAMANHO][TAMANHO];
    int acertosCPU = 0, acertosPlayer = 0;
    char tabuleiroAmostra[TAMANHO][TAMANHO];

    inicializarTabuleiro(tabuleiroAmostra);

    srand(time(NULL));

    inicializarTabuleiro(tabuleiroCPU);
    posicionarNaviosAleatorios(tabuleiroCPU);

    posicionarNaviosManual(tabuleiroPlayer);
    while (1)
    {
        acertosCPU = ataqueComputador(tabuleiroPlayer, acertosCPU, 1);

        if (acertosCPU == NAVIOS)
        {
            printf("\nComputador Venceu!\n");
            imprimirTabuleiro(tabuleiroPlayer);
        }

        acertosPlayer = ataquePlayer(tabuleiroCPU, acertosPlayer, tabuleiroAmostra);

        if (acertosPlayer == NAVIOS)
        {
            printf("\nPlayer venceu!");
            imprimirTabuleiro(tabuleiroCPU);
        }
        getchar();
    }
}

int main()
{
    int escolha;
    int acertos = 0;
    char tabuleiro[TAMANHO][TAMANHO];
    char tabuleiro2[TAMANHO][TAMANHO];
    srand(time(NULL));
    printf("\t\t Bem vindo ao Batalha Naval de Suse e Tralhoto\nEscolha uma das opcoes abaixo:\n1.CPU x CPU\n2.Player X CPU\n3. Testes\n");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        botxbot();
        break;
    case 2:

        jogar();

        break;

    case 3:
        inicializarTabuleiro(tabuleiro2);
        posicionarNaviosAleatorios(tabuleiro2);
        while (1)
        {

            ataquePlayer(tabuleiro, acertos, tabuleiro2);
        }
        break;
    }

    return 0;
}