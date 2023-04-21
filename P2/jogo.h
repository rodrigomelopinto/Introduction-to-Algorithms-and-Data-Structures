typedef struct stru_jogo{
    char *n_jogo; /* pointer para o nome do jogo */
    char *equipa1; /* pointer para o nome da equipa1 */
    char *equipa2; /* pointer para o nome da equipa2 */
    int score_equipa1; /* guarda o valor do score da quipa1 */
    int score_equipa2; /* guarda o valor do score da equipa2 */
} *jogo;

typedef char *Key; /* tipo da chave */
#define key(a) (a->n_jogo) /* retorna o nome do jogo */
#define key2(b) (b->nome) /* retorna o nome da equipa */

typedef struct stru_equipa{
    char *nome; /* pointer para o nome da equipa */
    int vitorias; /* guarda o valor das vitorias de uma equipa */
} *equipa;

/* prototipos jogo */
jogo novo_jogo(char *n_jogo, char *equipa1, char *equipa2, int score_equipa1, int score_equipa2);
void delete_jogo(jogo j);

/* prototipos equipa */
equipa nova_equipa(char *nome);
void delete_equipa(equipa e);



