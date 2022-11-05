#include <iostream>
#include <time.h> //biblioteca para poder gerar números aleatórios pelo horário do sistema
#include <cstdlib> //para valor rand
#include <locale> //para poder usar acentuação no c++

using namespace std;

int main()
{
    setlocale (LC_ALL, "Portuguese");
    srand(time(NULL));

    ///DECLARAÇÃO DE VARIAVEL
    int matJ[4][4]= {0};
    int matP[4][4]; //DEFINE A MATRIZ 4X4.
    int i,j,opcao,TP_matriz,n; //i E j COLUNA E LINHA DA MATRIZ | n CONTADOR DO VETOR ns.
    int Latual, Lpassada, Catual, Cpassada; // Latual E Catual SÃO VALORES DADOS PELO JOGADOR | Lpassada e Cpassada SÃO USADOS PARA ARMAZENAR OS VALOES DIGITADOS PARA A SEGUNDA JOGADA.
    int ns[8]; // VETOR QUE GUARDA OS NÚMEROS ALEATÓRIOS
    int contador=0, contador_jogada; //
    bool JGDRjogando = true, JGDRconseguiu = true; // VARIAVEIS RESPONSÁVEIS POR DISTINGUIR SE O JOGADOR ESTA JOGANDO OU NÃO E SE ACERTOU OU NÃO.


    /// LOOP PARA RETORNAR O MENU:
    do { // O JOGO SE ENCONTRA DENTRO DE UM LOOP PARA REPETIR O MENU E GERAR NÚMEROS ALEATÓRIOS SEM PRECISAR REINICAR O PROGRAMA.

    /// GERADOR DE NÚMEROS ALEATÓRIOS PARA A MATRIZ:
    for(int n = 0; n < 8; n++ ){ // COMANDO GERA 8 NÚMEROS ALEATÓRIOS DE 1 A 9.
         ns[n] =1 + rand () % 9;

           /// ENQUANTO O VETOR ns FOR IGUAL A OUTRO VALOR, DENTRO DELE GERA OUTRO NÚMERO ALEATÓRIO.

           while(ns[n] == ns[n - 1] || ns[n] == ns[n - 2] || ns[n] == ns[n - 3] ||
           ns[n] == ns[n - 4] || ns[n] == ns[n - 5] || ns[n] == ns[n - 6] || ns[n] == ns[n - 7] ){ //Impede que os números gerados aleatoriamente se repitam

           ns[n] = 1 + rand () % 9; // COMANDO PARA GERAR OUTRO NÚMERO ALEATÓRIO QUANDO EVENTUALMENTE GERAR O MESMO NUMERO ALEÁRIO NA MATRIZ.
        }
    }


    /// MATRIZ PRINCIPAL DO JOGO: //Prenche com o vetor dos números aleatórios
    matP[0][0] = ns[0], matP[0][1] = ns[1], matP[0][2] = ns[2], matP[0][3] = ns[3];
    matP[1][0] = ns[4], matP[1][1] = ns[5], matP[1][2] = ns[1], matP[1][3] = ns[0];
    matP[2][0] = ns[3], matP[2][1] = ns[6], matP[2][2] = ns[2], matP[2][3] = ns[7];
    matP[3][0] = ns[4], matP[3][1] = ns[7] ,matP[3][2] = ns[5], matP[3][3] = ns[6];

    system("cls"); // LIMPA O TERMINAR QUANDO O JOGO COMEÇA.


    /// MENU PRINCIPAL DO JOGO:

    cout<<"\n\n\n\n\n                                                  JOGO DA MEMÓRIA\n\n\n";
    cout<<"                                               1-JOGO\n                                               2-INSTRUÇÕES\n";
    cout<<"                                               3-CRÉDITOS\n                                               4-SAÍDA\n";

    opcao = 0;
    cin>>opcao; // COMANDO PARA ANALISAR QUAL OPÇÃO O JOGADOR DIGITOU

    if(opcao<1 || opcao>4){ // COMANDO QUE FILTRA A ESCOLHA DO JOGADOR ENTRE 1,2,3 E 4.
    cout<<"comando inválido tente novamente"<<endl; // MENSAGEM QUANDO JOGADOR DIGITAR UM NÚMERO QUE NÃO ESTEJA NAS OPÇÕES.

    system("pause"); // PAUSA O TERMINAL DO JOGO.
    }

    /// ESCOLHA DA OPÇÃO 1:
    if(opcao == 1){ // SE A OPÇÃO OPÇÃO ESCOLHIDA PELO JOGADOR FOR 1.
        JGDRjogando = true; // TEM-SE COMO VERDADEIRO QUE O JOGADOR COMEÇOU A JOGAR.
        contador_jogada = 24; // COMANDO PARA O CONTADOR COMEÇAR NO 24.

        system("cls"); // LIMPEZA DO TERMINAL

    /// SORTEIO DE QUAL MATRIZ SERÁ USADA NO JOGO
    TP_matriz = 1 + rand () % 4; // COMANDO DECIDIRA RANDOMICAMENTE QUAL MATRIZ SERÁ USADA NO JOGO.

    if (TP_matriz == 1) {  // SE O NÚMERO 1 FOR SORTEADO.
    /// MATRIZ  BASE:
    for (i=0; i<3; i++) { // COMANDO QUE DETERMINA A LINHA DA MATRIZ.
        for (j=0; j<3; j++) { // COMANDO QUE DETERMINA A COLUNA DA MATRIZ.
        matP[i][j];
        }
      }
    }


    if (TP_matriz == 2) {  // SE O NÚMERO 2 FOR SORTEADO.
    /// MATRIZ INVERSA:
    for (j=0; j<4; j++) { // COMANDO QUE DETERMINA A COLUNA DA MATRIZ. VEM POR PRIMEIRO PARA A QUE A COLUNA SE TORNE LINHA.
        for (i=0; i<4; i++) { // COMANDO QUE DETERMINA A LINHA DA MATRIZ. VEM DEPOIS PARA QUE A COLUNA SE TORNE LINHA.
        matP[i][j];
        }
      }
    }


    if (TP_matriz == 3) {   // SE O NÚMERO 3 FOR SORTEADO.
    /// MATRIZ INVERTIDA POR LINHA:
    for (i=3; i>=0; i--) { // COMANDO QUE DETERMINA A LINHA DA MATRIZ COM OS NUMEROS INVERTIDOS.
        for (j=0; j<4; j++) { //  COMANDO QUE DETERMINA A COLUNA DA MATRIZ.
        matP[i][j];
        }
      }
    }

    if (TP_matriz == 4) {   // SE O NÚMERO 4 FOR SORTEADO.
    /// MATRIZ INVERTIDA POR COLUNA:
    for (i=0; i<4; i++) { // COMANDO QUE DETERMINA A LINHA DA MATRIZ.
        for (j=3; j>=0; j--) { // COMANDO QUE DETERMINA A COLUNA DA MATRIZ COM NÚMEROS INVERTIDOS.
        matP[j][i];
        }
      }
    }

    /// JOGO:
    while (JGDRjogando) // LOOP PARA IMPRIMIR A MATRIZ ENQUANTO O JOGADOR NÃO GANHAR OU PERDER.
    {
        TP_matriz = matJ[i][j];

        JGDRconseguiu = true; // A CADA REPETIÇÃO DO WHILE SERÁ DETERMINADO QUE O JOGADOR ACERTOU.
        contador++; // ADICIONA 1 PONTO AO CONTADOR DÁ JOGADA.
        cout<<"NÚMERO DE JOGADAS RESTANTES: ["<<contador_jogada<<"]"<<"\n\n"; // MOSTRA A QUANTIDADE DE JOGADAS RESTANTES.

        for (int i=0; i < 4; i++ ) { // IMPRESSÃO DA MATRIZ JOGO.
            for (int j=0; j < 4; j++) {
                cout<<matJ[i][j]<<"  "; // MOSTRA A MATRIZ JOGO REPLETA DE ZEROS.
            }
        cout<<"\n\n"; // QUEBRA DE LINHA ENTRE AS PEÇAS DA MATRIZ.
        }

     cout<<"QUAL POSIÇÃO DA LINHA DESEJA REVELAR:"<<endl; // IMPRESSÃO DE MENSAGEM PARA O JOGADOR.
     cin>>Latual; // COMANDO ONDE O JOGADOR DIGITA A LINHA ESCOLHIDA.
     Latual--; // COMANDO PARA EVITAR CONFUSÃO. JOGADOR DIGITA 1 PARA ESCOLHER A PRIMEIRA LINHA, NÃO 0.

     while (Latual<0 || Latual>3) { // COMANDO QUE LIMITA O JOGADOR A ESCOLHER A POSIÇÃO DA LINHA ENTRE 1 E 4.
        cout <<"NUMERO INVALIDO, TENTE NOVAMENTE."<<endl;
        cin>>Latual; // COMANDO ONDE O JOGADOR DIGITA A LINHA QUE ESCOLHIDA.
        Latual--; // COMANDO PARA EVITAR CONFUSÃO. JOGADOR DIGITA 1 PARA ESCOLHER A PRIMEIRA LINHA, NÃO 0.
     }

     cout<<"QUAL POSIÇÃO DA COLUNA DESEJA REVELAR:"<<endl; // COMANDO QUE LIMITA O JOGADOR A ESCOLHER A POSIÇÃO DA COLUNA ENTRE 1 E 4.
     cin>>Catual; // COMANDO ONDE O JOGADOR DIGITA A COLUNA ESCOLHIDA.
     Catual--; // COMANDO PARA EVITAR CONFUSÃO. JOGADOR DIGITA 1 PARA ESCOLHER A PRIMEIRA COLUNA , NÃO 0.


     while (Catual<0|| Catual>3){ // COMANDO QUE LIMITA O JOGADOR A ESCOLHER A POSIÇÃO DA COLUNA ENTRE 1 E 4.
        cout <<"NUMERO INVALIDO, TENTE NOVAMENTE"<<endl;
        cin>>Catual; // COMANDO ONDE O JOGADOR DIGITA A COLUNA ESCOLHIDA.
        Catual--; // COMANDO PARA EVITAR CONFUSÃO. JOGADOR DIGITA 1 PARA ESCOLHER A PRIMEIRA COLUNA , NÃO 0.
     }

     system("cls"); // LIMPEZA DO TERMINAL.


     /// PRIMEIRA JOGADA:
     if (contador%2 == 1) // DETERMINA QUE O USUARIO ESTA NA PRIMEIRA ESCOLHA.
     {
         Lpassada=Latual; // GUARDA A POSIÇÃO DA LINHA ATUAL ESCOLHIDA PELO JOGADOR NA LINHA ANTERIOR ESCOLHIDA PELO MESMO.
         Cpassada=Catual; // GUARDA A POSIÇÃO DA COLUNA ATUAL ESCOLHIDA PELO JOGADOR NA COLUNA ANTERIOR ESCOLHIDA PELO MESMO.
     }
     if (matJ[Latual][Catual]!= 0) // DETERMINA QUE JÁ HOUVE Á PRIMEIRA JOGADA.
        {
        contador_jogada--;
        cout<<"ESCOLHA MAIS UMA PEÇA!"<<endl;

    /// SEGUNDA JOGADA:
    if (contador %2 == 0) { // DETERMINA QUE O JOGADOR ESTA NA SEGUNDA JOGADA.
        matJ[Lpassada][Cpassada] = 0; // ZERA O VALOR ANTERIOR DA MATRIZ JOGO PARA A SEGUNDA JOGADA
    }
    contador = 0; // COMANDO PARA O JOGOR PODER DIGITAR OS DOIS PRÓXIMOS VALORES.
    }

    else if (Latual < 0 || Latual > 4 || Catual < 0 || Catual > 4) {
        matJ[Lpassada][Cpassada] = 0;
        contador = 0;
     } else {
     matJ[Latual][Catual] = matP[Latual][Catual]; // ADICIONA O VALOR DA MATRIZ PRINCIPAL PARA A MATRIZ JOGO.

     if (contador %2 == 0) { // CASO O JOGADOR ESTEJA NA SEGUNDA JOGADA.
        contador_jogada--; // CONTA UMA JOGADA
        if (matJ[Latual][Catual] == matJ[Lpassada][Cpassada]) { // SE OS VALORES DA MATRIZ ANTERIOR E ATUAL SÃO IGUAIS.
            cout<<"ACERTOU, AS PEÇAS SÃO IGUAIS !!!"<<endl;
            cout<<"\n\n";
        } else { // SE OS VALORES DA MATRIZ ANTERIOR E ATUAL SÃO DIFERENTES.
        cout<<"OH NÃO, AS PEÇAS SÃO DIFERENTES !!!"<<"\n";
        cout<<"NÚMERO DE JOGADAS RESTANTES ["<<contador_jogada<<"]"<<endl;
        cout<<"\n\n"; // QUEBRA DE LINHA ENTRE AS PEÇAS DA MATRIZ.

    for (int i=0; i<4; i++) {
           for (int j=0; j<4; j++) {
            cout<<matJ[i][j]<<"  "; // IMPRIME A MATRIZ JOGO.
           }
     cout<<"\n\n"; // QUEBRA DE LINHA ENTRE AS PEÇAS DA MATRIZ.
     }
     system("pause"); // PAUSA O TERMINAL
     system("cls"); // LIMPEZA DO TERMINAL.
     matJ[Latual][Catual] = 0; // DETERMINA COMO ZERO OS VALORES DA MATRIZ JOGO ATUAL.
     matJ[Lpassada][Cpassada] = 0; // DETERMINA COMO ZERO OS VALORES DA MATRIZ JOGO ANTIGA.
      }
     }
    }


    /// VERIFICAÇÃO:
    for (int i=0; i<4; i++) { // COMANDO PARA VERIFICAR SE O JOGADOR TEM AS PEÇAS VIRADAS.
        for (int j=0; j<4; j++) {
            if (matJ[i][j] == 0) { // ANALISA SE AS PEÇAS NÃO ESTAM VIRADAS
                JGDRconseguiu=false; // CASO SEJA VERDADEIRO, O JOGADOR NÃO VENCEU
            }
        }
    }


    /// JOGADOR VENCEU
    if (JGDRconseguiu) { // VERIFICA SE O JOGADOR VENCEU.
        cout<<"\n\n";
        cout<<"  VOCÊ VENCEU!!!  "<<endl; // EXIBE FRASE DE PARABENIZAÇÃO.
        cout<<"\n\n";
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cout<<matJ[i][j]<<"  ";
            }
        cout<<"\n\n";
        }
        system("pause"); // PAUSA O TERMINAL DO JOGO.
        JGDRjogando = false; // JOGADOR ACABA O JOGO E ELE SAI DO LAÇO WHILE.
    }

    /// JOGADOR PERDEU
    if (contador_jogada == 0 && !JGDRconseguiu) { // VERIFICA SE O JOGADOR PERDEU.
        cout<<"INFELIZMENTE VOCÊ PERDEU."<<endl; // EXIBE FRASE DE CONSOLAÇAO.
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cout<<matJ[i][j]<<"  ";
            }
        cout<<"\n\n";
        }
        system("pause"); // PAUSA O TERMINAL DO JOGO
        JGDRjogando = false; // JOGADOR ACABA O JOGO E ELE SAI DO LAÇO WHILE.
    }
    }
    }

    /// ESCOLHA DA OPÇÃO 2:
    else if(opcao == 2){  // SE FOR ESCOLHIDO A 2º OPÇÃO IMPRIME-SE AS REGRAS.
    system("cls"); // LIMPEZA DO TERMINAL DO JOGO.
    cout<<"\n\n\n\n      O JOGO SE INICIA COM 16 CARTAS VIRADAS PARA BAIXO O OBJETIVO DO JOGO É DE ACHAR OS 8 PARES IGUAIS PARA ISSO O";
    cout<<"\n      JOGADOR DEVE OFERECER PRIMEIRO O NÚMERO DA LINHA E DEPOIS O DA COLUNA, O JOGO ACABA SE FOR ENCONTRADO TODOS OS\n      PARES OU PASSAR DE 24 JOGADAS.\n\n\n\n";
     system("pause"); // PAUSA DO TERMINAL DO JOGO.
    }

    /// ESCOLHA DA OPÇÃO 3:
    else if(opcao == 3){   // SE FOR ESCOLHIDO A 3º OPÇÃO, IMPRIME-SE OS CRÉDITOS.

    system("cls");
    cout<<"\n\n\n\n         OS CRÉDITOS VÃO PARA : ARTHUR GRANDI, LORINA ZONDERVAN E RAFAEL ARAÚJO\n\n\n\n";
    system("pause");
     }
    }

    /// ESCOLHA DA OPÇÃO 4:
while (opcao !=4); // SE FOR ESCOLHIDA A 4º OPÇÃO, O JOGADOR SAI DO JOGO.
return 0;
}
