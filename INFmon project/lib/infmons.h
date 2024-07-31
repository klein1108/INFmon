#define N_ATAQUES 3
#define MAX_INFMONS 5

#define TIPO_AGUA 'A'
#define TIPO_FOGO 'F'
#define TIPO_TERRA 'T'

#define ATAQUE_DEFESA_DEFAULT 2


typedef struct {
    char nome[50];
    int dano;
} Ataque;

typedef struct {
    char nome[100];
    int nivel;
    int vida;
    int ataque;
    int defesa;
    int xp;
    char tipo;
    Ataque ataques[N_ATAQUES];
} Infmon;

typedef struct {
    Infmon infmons[MAX_INFMONS];
} Personagem;

Infmon criaPokemonAliadoAgua();
Infmon criaPokemonInimigoFogo();
