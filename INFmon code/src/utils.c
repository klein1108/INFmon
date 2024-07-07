#include<stdio.h>
#include "raylib.h"

#define TRUE 1
#define FALSE 0

Color defineCorDoBotao (int indexBotao, int mouseHoverRec){
    if(mouseHoverRec == indexBotao){
        return SKYBLUE;
    }
    return WHITE;
}

Rectangle criaRetangulo(float posX, float posY, float width, float height, float gap, int nRetangulo){
    return (Rectangle){
            posX,   // define X do retangulo (posicao inicial)
            posY + (gap*nRetangulo), // define Y do retangulo (posicao inicial), com o multiplicador sendo GAP_ENTRE_BOTOES x N_BOTAO
            width , //define largura do retangulo
            height };

}

Rectangle criaBotao(float posX, float posY, float width, float height, float gap, float nBotao, float larguraBorda, Color corPadrao, Color corSecundaria, int isEmCima){
    Rectangle button = criaRetangulo(posX, posY, width, height, gap, nBotao);
    DrawRectangleRec(button, isEmCima ? corSecundaria : corPadrao);
    if(larguraBorda){
        DrawRectangleLinesEx(button, larguraBorda, BLACK);
    }
    return button;
}

Rectangle criaBotaoDeModal(float posInicialX, float posInicialY, float posFinalX, float posFinalY, Color corFundo, int larguraBorda){
    Rectangle bottao = criaRetangulo(posInicialX, posInicialY, posFinalX, posFinalY, 0, 0);

    DrawRectangle(bottao.x, bottao.y, bottao.width, bottao.height, corFundo);
    if(larguraBorda){
        DrawRectangleLinesEx(bottao, larguraBorda, BLACK);
    }
    return bottao;
}



Rectangle abreModal(float posX, float posY, float width, float height, float sceenWidth, float screenHeight, float larguraLinha){
    Color background = { 130, 130, 130, 100};
    Rectangle modal = criaRetangulo(posX, posY, width, height, 0.0f, 0);

    DrawRectangle(0, 0, sceenWidth, screenHeight, background); //background cinza com 100 de transparencia

    //Modal
    DrawRectangle(modal.x, modal.y, modal.width, modal.height, WHITE);
    DrawRectangleLinesEx(modal, larguraLinha, BLACK);
    return modal;
}

void abreModalDeConfirmacao(char texto[], int tamanhoFonte, float margin, int alturaModal, int larguraModal, int larguraTela, int alturaTela , int* isAbertaModal){
    int larguraModalCalculada = MeasureText(texto, tamanhoFonte) + 2*(margin);

    if(larguraModalCalculada > larguraModal){
        larguraModal = larguraModalCalculada;
    }

    Rectangle modal;
    Rectangle botoesModal[2] = {};

    char botaoTexto[2][10] = {"Confirmar", "Sair"};
    float modalLarguraLinha = 3.0;

    int larguraBotaoModal = MeasureText(botaoTexto[0], tamanhoFonte) + 2*margin;
    int alturaBotaoModal = tamanhoFonte + 2*margin;


    modal = abreModal((float)larguraTela/2 - larguraModal/2, (float) alturaTela/2 - alturaModal/2,
              (float)larguraModal, (float)alturaModal, larguraTela, alturaTela, modalLarguraLinha);


    float botaoSairPosInicialX = modal.x + modal.width - larguraBotaoModal;
    float botaoSairPosInicialY = modal.y + modal.height - alturaBotaoModal;

    float botaoConfirmaPosInicialX = botaoSairPosInicialX - larguraBotaoModal - margin;
    float botaoConfirmaPosInicialY = botaoSairPosInicialY;

    //cria os botoes da modal
    botoesModal[1] = criaBotaoDeModal(botaoSairPosInicialX - margin, botaoSairPosInicialY - margin,
                                      (float)larguraBotaoModal, (float)alturaBotaoModal, RED, modalLarguraLinha);

    botoesModal[0] = criaBotaoDeModal(botaoConfirmaPosInicialX - margin, botaoConfirmaPosInicialY - margin,
                                      (float)larguraBotaoModal, (float)alturaBotaoModal, GREEN, modalLarguraLinha);

    //Escreve o texto da modal e a labels dos botoes
    DrawText(texto, modal.x + margin, modal.y + tamanhoFonte, tamanhoFonte, BLACK);
    DrawText(botaoTexto[0], botoesModal[0].x + margin, botoesModal[0].y + margin, tamanhoFonte, BLACK);
    DrawText(botaoTexto[1], botoesModal[1].x + margin, botoesModal[1].y + margin, tamanhoFonte, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), botoesModal[1]) && isAbertaModal){
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            *isAbertaModal = FALSE;
        }
    }
}
