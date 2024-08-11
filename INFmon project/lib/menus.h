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
//int criaInterfaceMenuBatalhaAtaques(Rectangle botoes[], Infmon aliado, Infmon inimigo, float posXInicioTexto, float posYInicioTexto);
#endif // menus_h
