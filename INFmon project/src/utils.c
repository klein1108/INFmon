#include "raylib.h"

#define TRUE 1
#define FALSE 0

#define ALTURA 600
#define LARGURA 1200

#define BOTAO_PRIMEIRA_COL 35.0F
#define BOTAO_SEGUNDA_COL 20.0F

#define BOTAO_PRIMEIRA_LIN 35.0f
#define BOTAO_SEGUNDA_LIN 20.0F

#define TEXTO_PRIMEIRA_COL 20.0F
#define TEXTO_SEGUNDA_COL 5.0F

#define TEXTO_PRIMEIRA_LIN 0.0F
#define TEXTO_SEGUNDA_LIN 10.0f


Color defineCorDoBotao (int indexBotao, int mouseHoverRec){
    if(mouseHoverRec == indexBotao){
        return SKYBLUE;
    }
    return WHITE;
}

//AJUSTE!!!
Rectangle criaRetangulo(float posX, float posY, float width, float height, float gapX, float gapY, int nRetangulo){
    return (Rectangle){
            posX + (gapX*nRetangulo),   // define X do retangulo (posicao inicial)
            posY + (gapY*nRetangulo), // define Y do retangulo (posicao inicial), com o multiplicador sendo GAP_ENTRE_BOTOES x N_BOTAO
            width , //define largura do retangulo
            height };

}

//AJUSTE!!!
Rectangle criaBotao(float posX, float posY, float width, float height,float gapX, float gapY, float nBotao, float larguraBorda, Color corPadrao, Color corSecundaria, int isEmCima){
    Rectangle button = criaRetangulo(posX, posY, width, height, gapX, gapY, nBotao);
    DrawRectangleRec(button, isEmCima ? corSecundaria : corPadrao);
    if(larguraBorda){
        DrawRectangleLinesEx(button, larguraBorda, BLACK);
    }
    return button;
}

//AJUSTE!!!
Rectangle criaBotaoDeModal(float posInicialX, float posInicialY, float posFinalX, float posFinalY, Color corFundo, int larguraBorda){
    Rectangle bottao = criaRetangulo(posInicialX, posInicialY, posFinalX, posFinalY, 0, 0, 0);

    DrawRectangle(bottao.x, bottao.y, bottao.width, bottao.height, corFundo);
    if(larguraBorda){
        DrawRectangleLinesEx(bottao, larguraBorda, BLACK);
    }
    return bottao;
}

//AJUSTE!!!
Rectangle abreModal(float posX, float posY, float width, float height, float sceenWidth, float screenHeight, float larguraLinha){
    Color background = { 130, 130, 130, 100};
    Rectangle modal = criaRetangulo(posX, posY, width, height, 0.0f, 0, 0);

    DrawRectangle(0, 0, sceenWidth, screenHeight, background); //background cinza com 100 de transparencia

    //Modal
    DrawRectangle(modal.x, modal.y, modal.width, modal.height, WHITE);
    DrawRectangleLinesEx(modal, larguraLinha, BLACK);
    return modal;
}

int abreModalDeConfirmacaoMenuInicial(char texto[], int tamanhoFonte, float margin, int alturaModal, int larguraModal, int larguraTela, int alturaTela , int* isAbertaModal){
    int isAceita = FALSE;
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

    //Logica botoes
    if (CheckCollisionPointRec(GetMousePosition(), botoesModal[0]) && *isAbertaModal){
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            *isAbertaModal = FALSE;
            isAceita = TRUE;
        }
    } else if (CheckCollisionPointRec(GetMousePosition(), botoesModal[1]) && *isAbertaModal){
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            *isAbertaModal = FALSE;
        }
    }

    return isAceita;    //retorna o que o usuario escolheu das opceos de botoes
}

void criaInterface(Rectangle *botao, char texto[], int index){
    float widthBotoes = 200.0f;
    float heightBotoes = 100.0f;
    float modalLarguraLinha = 4.0f;


    switch(index){
        case 0 :
            *botao = criaBotao(LARGURA - 2*widthBotoes - 35, ALTURA - 2*heightBotoes - 35, widthBotoes, heightBotoes, 0, 0, 0, modalLarguraLinha, WHITE, WHITE, 0);
            DrawText(texto, LARGURA - 2*widthBotoes - 20, ALTURA - 2*heightBotoes, 40, BLACK);
        break;

        case 1:
            *botao = criaBotao(LARGURA - widthBotoes - 20, ALTURA - 2*heightBotoes - 35, widthBotoes, heightBotoes, 0, 0, 0, modalLarguraLinha, WHITE, WHITE, 0);
            DrawText(texto, LARGURA - widthBotoes - 5, ALTURA - 2*heightBotoes, 40, BLACK);
        break;

        case 2:
            *botao = criaBotao(LARGURA - 2*widthBotoes - 35, ALTURA - heightBotoes - 20, widthBotoes, heightBotoes, 0, 0, 0, modalLarguraLinha, WHITE, WHITE, 0);
            DrawText(texto, LARGURA - 2*widthBotoes - 20, ALTURA - heightBotoes + 10, 40, BLACK);
        break;

        case 3:
            *botao = criaBotao(LARGURA - widthBotoes - 20, ALTURA - heightBotoes - 20, widthBotoes, heightBotoes, 0, 0, 0, modalLarguraLinha, WHITE, WHITE, 0);
            DrawText("Sair", LARGURA - widthBotoes - 5, ALTURA - heightBotoes + 10, 40, BLACK);
        break;
    }






}
