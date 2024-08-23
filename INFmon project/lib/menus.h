#ifndef menus_h
#define menus_h

#include <string.h>
#include "constantes.h"
#include "raylib.h"
#include "utils.h"
#include "infmons.h"

int menuInicial(int processoInternoAtual);
int menuEscolheInfmon(int processoAtual, Personagem *jogador);
int menuBatalha(int *processoInternoAtual, int isBoss, int *fase, Personagem *jogador);
void criaInterfaceMenuBatalhaInicial(Rectangle botoes[], int *processoAtualBatalha, int isBoss, Personagem *aliado, Infmon *inimigo, int fase, int *indexInfmon);
void criaInterfaceMenuBatalhaAtaques(Rectangle botoes[], Infmon *aliado, Infmon *inimigo,
                                      float posXInicioTexto, float posYInicioTexto, int *processoAtualBatalha, int *indexInimigo);
int menuPause(int processoAtual);
int menuFimDeJogo(int processoAtual, int situacao);
void menuTrocaInfmon(int *processoAtualBatalha, Personagem *jogador, int *indexInfmon);
int verificaProxInfmonAtivo(Infmon infmonsAliado[], int *indexInfmonAtivo, int nInfmonsAliado);
void resetaValoresInfmons(Personagem *jogador, int nInfmons);
void sobeNivelInfmon(Personagem *jogador);

//TROCAR DE LUGAR
float verificaSePossuiVantagem(char tipoAtacante, char tipoAlvo);
int ataqueInimigo(Infmon infmonsAliado[], Infmon *inimigo, int *indexAliado, int nInfmonsAliado);
int calculaDano(Ataque ataque, Infmon *infmonAtacante, Infmon *infmonAlvo,int *indexAlvo, int isTurnoInimigo);
Color retornaCorDoTipo(char tipo);
void criaInterfaceDeVidaINFmon(int isAliado, float posXInfmon, float larguraInfmon, float posYInfmon, Infmon infmon);
void criaBarraDeVidaINFmon(float posX, float posY, Infmon infmon);
#endif // menus_h
