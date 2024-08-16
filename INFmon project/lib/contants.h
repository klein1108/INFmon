#ifndef contants_h
#define contants_h

//-----DEFAULT--------------------
#define LARGURA 1200
#define ALTURA 600

#define TRUE 1
#define FALSE 0

//NAO MUDAR ORDEM
#define PROCESSO_MENU_INICIAL 0
#define PROCESSO_NOVO_JOGO 1
#define PROCESSO_CARREGAR_JOGO 2
#define PROCESSO_ESCOLHER_INFMON 3
#define PROCESSO_INICIA_JOGO 4


#define PROCESSO_INTERNO_MAPA 0
#define PROCESSO_INTERNO_BATALHA 1

//-----INFMON-----------------------
#define N_ATAQUES 3
#define MAX_INFMONS 5

#define TIPO_NORMAL 'N'
#define TIPO_AGUA 'A'
#define TIPO_FOGO 'F'
#define TIPO_TERRA 'T'

#define ATAQUE_NORMAL 1.0F
#define ATAQUE_EFETIVO 2.0F
#define ATAQUE_INEFETIVO 0.5F

#define ATAQUE_DEFESA_DEFAULT 2

//-----MAPA-------------------------
#define MAX_LINHA 30
#define MAX_COLUNA 61

//-----BATALHA----------------------
#define BATALHA_FUGA -1
#define BATALHA_DERROTA 1
#define BATALHA_VITORIA 2

#define PROCESSO_BATALHA_INICIAL 0
#define PROCESSO_BATALHA_ATAQUES 1
#define PROCESSO_BATALHA_TENTAR_FUGA 3

#define BATALHA_INFMON 0
#define BATALHA_BOSS 1


//------MENU------------------------
#define GAP_ENTRE_BOTOES 110

//NAO MUDAR ORDEM
#define BOTAO_NOVO_JOGO 0
#define BOTAO_CARREGAR_JOGO 1
#define BOTAO_SAIR 2

#define PROCESSO_INTERNO_MAPA 0
#define PROCESSO_INTERNO_BATALHA_BOSS 1
#define PROCESSO_INTERNO_BATALHA_INFMON 2

#endif // contants_h
