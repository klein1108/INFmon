#ifndef menus_h
#define menus_h

#include <string.h>
#include "contants.h"
#include "raylib.h"
#include "utils.h"
#include "infmons.h"

int menuInicial(int processoInternoAtual);
int menuEscolheInfmon(int processoAtual);
int menuBatalha(int *processoInternoAtual, int isBoss);
void criaInterfaceMenuBatalhaInicial(Rectangle botoes[], int *processoAtualBatalha, int isBoss);
void criaInterfaceMenuBatalhaAtaques(Rectangle botoes[], Infmon aliado, Infmon *inimigo, float posXInicioTexto, float posYInicioTexto, int *processoAtualBatalha, int *indexInimigo);
int menuPause(int processoAtual);
int menuFimDeJogo(int processoAtual, int situacao);

//TROCAR DE LUGAR
float verificaSePossuiVantagem(char tipoAtacante, char tipoAlvo);
int ataqueInimigo(Infmon *aliado, Infmon inimigo, int *indexInimigo);
int calculaDano(Ataque ataque, int nivelAtaque, Infmon *infmonAlvo, int *indexAlvo);
Color retornaCorDoTipo(char tipo);
void criaInterfaceDeVidaINFmon(int isAliado, float posXInfmon, float larguraInfmon, float posYInfmon, Infmon infmon);
void criaBarraDeVidaINFmon(float posX, float posY, Infmon infmon);
#endif // menus_h
