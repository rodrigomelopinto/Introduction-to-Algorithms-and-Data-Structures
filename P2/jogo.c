#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"


/* cria um novo jogo */
jogo novo_jogo(char *n_jogo, char *equipa1, char *equipa2, int score_equipa1, int score_equipa2){
    jogo x = (jogo) malloc(sizeof(struct stru_jogo));
    x->n_jogo = (char*) malloc(sizeof(char) * (strlen(n_jogo)+1));
    x->equipa1 = (char*) malloc(sizeof(char) * (strlen(equipa1)+1));
    x->equipa2 = (char*) malloc(sizeof(char) * (strlen(equipa2)+1));

    strcpy(x->n_jogo, n_jogo);
    strcpy(x->equipa1, equipa1);
    strcpy(x->equipa2, equipa2);

    x->score_equipa1 = score_equipa1;
    x->score_equipa2 = score_equipa2;

    return x;
}

/* apaga um jogo existente */
void delete_jogo(jogo j){
    if (j != NULL){
        free(j->n_jogo);
        free(j->equipa1);
        free(j->equipa2);
        free(j);
    }
}

/* cria uma nova equipa */
equipa nova_equipa(char *nome){
    equipa x = (equipa) malloc(sizeof(struct stru_equipa));
    x->nome = (char*) malloc(sizeof(char) * (strlen(nome)+1));

    strcpy(x->nome, nome);

    x->vitorias = 0;

    return x;
}

/* apaga uma equipa existente */
void delete_equipa(equipa e){
    if (e){
        free(e->nome);
        free(e);
    }
}