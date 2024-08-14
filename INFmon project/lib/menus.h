#ifndef menus_h
#define menus_h

#include <string.h>
#include "contants.h"
#include "raylib.h"
#include "utils.h"
#include "infmons.h"

int menuInicial(int processoInternoAtual);
int menuEscolheInfmon(int processoAtual, int *escolhido);
int menuBatalha(int *processoInternoAtual);
void criaInterfaceMenuBatalhaInicial(Rectangle botoes[], int *processoAtualBatalha);
void criaInterfaceMenuBatalhaAtaques(Rectangle botoes[], Infmon aliado, Infmon *inimigo, float posXInicioTexto, float posYInicioTexto, int *processoAtualBatalha, int *indexInimigo);

void calculaDano(int dano, Infmon *infmon);
Color retornaCorDoTipo(char tipo);
void criaInterfaceDeVidaINFmon(int isAliado, float posXInfmon, float larguraInfmon, float posYInfmon, Infmon infmon);
void criaBarraDeVidaINFmon(float posX, float posY, Infmon infmon);
#endif // menus_h
