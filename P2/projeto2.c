/*
 * File : projeto2.c
 * Author: Rodrigo de Melo Pinto Nº 95666
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ht.h"

#define MAX_CARACTERES 1024 /* tamanho maximo de uma string */


void a(link_j* ht_j, link_e* ht_e, int nl, linkedlist_j lista_j){
    char n_jogo[MAX_CARACTERES];
    char equipa1[MAX_CARACTERES];
    char equipa2[MAX_CARACTERES];
    int score1, score2;
    link_e equipa;
    jogo j;
    scanf(" %[^:\n]:%[^:\n]:%[^:\n]:%d:%d", n_jogo,
    equipa1,
    equipa2, 
    &score1, 
    &score2);
    if(search_jogo(ht_j,n_jogo) == NULL){
        if(search_equipa(ht_e,equipa1) != NULL && search_equipa(ht_e,equipa2) != NULL){
            /* e possivel adicionar um jogo */
            j = novo_jogo(n_jogo, equipa1, equipa2, score1, score2);
            insert_j(ht_j,j);
            append_j(lista_j, j);
            if(score1 > score2){
                /* adiciona uma vitoria a equipa1 */
                equipa = search_equipa(ht_e,equipa1);
                equipa->e->vitorias += 1;
            }
            if(score2 > score1){
                /* adiciona uma vitoria a equipa2 */
                equipa = search_equipa(ht_e,equipa2);
                equipa->e->vitorias += 1;
            }
        }
        else{
            printf("%d Equipa inexistente.\n", nl);
        }
    }
    else{
        printf("%d Jogo existente.\n", nl);
    }

}

void A(link_e* ht_e, int nl, linkedlist_e lista_e){
    char nome[MAX_CARACTERES];
    equipa e;
    scanf(" %[^:\n]", nome);
    if(search_equipa(ht_e,nome) == NULL){
        /* a equipa ainda nao existe */
        e = nova_equipa(nome);
        insert_e(ht_e,e);
        append_e(lista_e, e);
        return;
    }
    else{
        printf("%d Equipa existente.\n", nl);
    }
}


void p(link_j* ht_j, int nl){
    char nome[MAX_CARACTERES];
    link_j jogo;
    scanf(" %[^:\n]", nome);
    jogo = search_jogo(ht_j,nome);
    if(jogo != NULL){
        /* o jogo foi encontrado */
        printf("%d %s %s %s %d %d\n",nl, jogo->j->n_jogo,
        jogo->j->equipa1,
        jogo->j->equipa2,
        jogo->j->score_equipa1,
        jogo->j->score_equipa2);
    }
    else{
        printf("%d Jogo inexistente.\n", nl);
    }

}


void P(link_e* ht_e, int nl){
    char nome[MAX_CARACTERES];
    link_e equipa;
    scanf(" %[^:\n]", nome);
    equipa = search_equipa(ht_e,nome);
    if(equipa == NULL){
        printf("%d Equipa inexistente.\n", nl);
        
    }
    else{
        /* a equipa foi encontrada */
        printf("%d %s %d\n", nl, equipa->e->nome, equipa->e->vitorias);
    }
}


void r(link_j* ht_j, link_e* ht_e, int nl, linkedlist_j lista_j){
    char nome[MAX_CARACTERES];
    link_j jogo;
    link_e equipa;
    scanf(" %[^:\n]", nome);
    jogo = search_jogo(ht_j,nome);
    if(jogo != NULL){
        /* o jogo existe */
        if(jogo->j->score_equipa1 > jogo->j->score_equipa2){
            /* retirar vitoria a euipa1 */
            equipa = search_equipa(ht_e,jogo->j->equipa1);
            equipa->e->vitorias -= 1;
        }
        if(jogo->j->score_equipa2 > jogo->j->score_equipa1){
            /* retirar vitoria a equipa2 */
            equipa = search_equipa(ht_e,jogo->j->equipa2);
            equipa->e->vitorias -= 1;
        }
        /* remover o jogo da hashtable e da lista ligada */
        remove_element_j(lista_j, jogo->j->n_jogo);
        delete_j(ht_j, jogo->j);
    }
    else{
        printf("%d Jogo inexistente.\n", nl);
    }
}

void s(link_j* ht_j, link_e* ht_e, int nl){
    char nome[MAX_CARACTERES];
    int novo_score1, novo_score2, res1, res2;
    link_j jogo;
    link_e equipa;
    scanf(" %[^:\n]:%d:%d", nome, &novo_score1, &novo_score2);
    jogo = search_jogo(ht_j, nome);
    if(jogo != NULL){
        /* o jogo foi encontrado */
        res1 = jogo->j->score_equipa1 - jogo->j->score_equipa2;
        res2 = novo_score1 - novo_score2;
        jogo->j->score_equipa1 = novo_score1;
        jogo->j->score_equipa2 = novo_score2;

        if(res1 > 0){ /* a equipa1 estava a ganhar */
            if(res2 > 0){ /* e continua a ganhar */
                return;
            }
            if(res2 == 0){ /* ficou empate */
                equipa = search_equipa(ht_e, jogo->j->equipa1);
                equipa->e->vitorias -= 1;
            }
            if(res2 < 0){ /* equipa2 passa a ganhar */
                equipa = search_equipa(ht_e, jogo->j->equipa1);
                equipa->e->vitorias -= 1;
                equipa = search_equipa(ht_e, jogo->j->equipa2);
                equipa->e->vitorias += 1;
            }
        }
        if(res1 == 0){ /* estava empate inicialmente */
            if(res2 > 0){ /* a equipa1 ganha */
                equipa = search_equipa(ht_e, jogo->j->equipa1);
                equipa->e->vitorias += 1;
            }
            if(res2 == 0){ /* continua empatado */
                return;
            }
            if(res2 < 0){ /* a equipa2 ganha */
                equipa = search_equipa(ht_e, jogo->j->equipa2);
                equipa->e->vitorias += 1;
            }
        }
        if(res1 < 0){ /* a equipa2 ganhava */
            if(res2 > 0){ /* a equipa1 passa a ganhar */
                equipa = search_equipa(ht_e, jogo->j->equipa1);
                equipa->e->vitorias += 1;
                equipa = search_equipa(ht_e, jogo->j->equipa2);
                equipa->e->vitorias -= 1;
            }
            if(res2 == 0){ /* passa a ficar empatado */
                equipa = search_equipa(ht_e, jogo->j->equipa2);
                equipa->e->vitorias -= 1;
            }
            if(res2 < 0){ /* a equipa2 continua a ganhar */
                return;
            }
        }
    }
    else{
        printf("%d Jogo inexistente.\n", nl);
    }
}

void l(linkedlist_j lista_j, int nl){
    Link_j current;
    if(lista_j->load != 0){
        /* a lista ligada nao esta vazia */
        for(current = lista_j->head; current != NULL; current = current->next){
            printf("%d %s %s %s %d %d\n", nl, getjogo(current)->n_jogo,
            getjogo(current)->equipa1,
            getjogo(current)->equipa2,
            getjogo(current)->score_equipa1,
            getjogo(current)->score_equipa2);
        }
    }
    return;
    
}

void g(linkedlist_e lista_e, int nl){
    char *vetor[10000]; /* vetor para guardar os ponteiros de strings */
    Link_e node, new_node;
    int max = 0, i = 0, j = 0;
    node = lista_e->head;
    new_node = lista_e->head;
    if(node != NULL){

        while(node != NULL){ /* procura o maior numero de vitorias */
            if(node->e->vitorias > max){
                max = node->e->vitorias;
            }
            node = node->next;
        }

        while(new_node != NULL){
            /* guarda no vetor os nomes das equipas com vitorias iguais ao maximo */
            if(new_node->e->vitorias == max){
                vetor[j] = malloc(sizeof(char) * (strlen(new_node->e->nome) + 1));
                strcpy(vetor[j], new_node->e->nome);
                j++;
            }
            new_node = new_node->next;
        }
        /* faz sort das equipas com ordem lexicografia */
        qsort(vetor, j, sizeof(char*), sort);

        printf("%d Melhores %d\n", nl, max);
        for(i=0;i<j;i++){
            /* faz o print dos nomes das equipas */
            printf("%d * %s\n", nl, vetor[i]);
            free(vetor[i]);
        }
    }
    else{
        return;
    }
}


int main(){
    char c;
    int nl = 1;
    linkedlist_j lista_j = init_j(); /* inicializa a lista ligadas dos jogos */
    linkedlist_e lista_e = init_e(); /* inicializa a lista ligada das equipas */
    link_j* ht_j = HASHinit_j(); /* inicializacao da hashtable dos jogos */
    link_e* ht_e = HASHinit_e(); /* inicializacao da hashtable das equipas */
    
    c = getchar();
    while(c != 'x'){
        switch(c){
            case 'a':
                a(ht_j, ht_e, nl, lista_j);
                nl++;
                break;
            case 'A':
                A(ht_e, nl, lista_e);
                nl++;
                break;
            case 'l':
                l(lista_j, nl);
                nl++;
                break;
            case 'p':
                p(ht_j, nl);
                nl++;
                break;
            case 'P':
                P(ht_e, nl);
                nl++;
                break;
            case 'r':
                r(ht_j, ht_e, nl, lista_j);
                nl++;
                break;
            case 's':
                s(ht_j, ht_e, nl);
                nl++;
                break;
            case 'g':
                g(lista_e, nl);
                nl++;
                break;
        }
        c = getchar();
    }
    destroy_hash_j(ht_j); /* faz free da hashtable dos jogos */
    destroy_hash_e(ht_e); /* faz free das hashtable das equipas */
    destroy_list_j1(lista_j); /* faz free da lista ligada dos jogos */
    destroy_list_e1(lista_e); /* faz free da lista ligada das equipas */
    return 0;
}