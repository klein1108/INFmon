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
void criaInterfaceMenuBatalhaAtaques(Rectangle botoes[], Infmon aliado, Infmon inimigo, float posXInicioTexto, float posYInicioTexto, int *processoAtualBatalha);
void criaInterfaceDeVidaINFmon(int isAliado, float posXInfmon, float larguraInfmon, float posYInfmon);

#endif // menus_h
