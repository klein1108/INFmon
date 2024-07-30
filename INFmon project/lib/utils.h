#include "raylib.h"

Color defineCorDoBotao (int indexBotao, int mouseHoverRec);
int abreModalDeConfirmacaoMenuInicial(char texto[], int tamanhoFonte, float margin, int alturaModal, int larguraModal, int larguraTela, int alturaTela, int* isAbertaModal);
//AJUSTE!!!
Rectangle criaRetangulo(float posX, float posY, float width, float height, float gapX, float gapY, int nRetangulo);
Rectangle criaBotaoDeModal(float posInicialX, float posInicialY, float posFinalX, float posFinalY, Color corFundo, int larguraBorda);
Rectangle abreModal(float posX, float posY, float width, float height, float sceenWidth, float screenHeight, float larguraLinha);
//AJUSTE!!!
Rectangle criaBotao(float posX, float posY, float width, float height, float gapX, float gapY, float nBotao, float larguraBorda, Color corPadrao, Color corSecundaria, int isEmCima);
