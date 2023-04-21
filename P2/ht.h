#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

typedef struct node_j* link_j;
typedef struct node_e* link_e;

typedef struct node_j{ /*node de uma lista ligada que contem um jogo */
    jogo j;
    link_j next;
}node_j;

typedef struct node_e{ /* node de uma lista ligada que contem uma equipa */
    equipa e;
    link_e next;
}node_e;

typedef struct Node_j* Link_j;
typedef struct Node_e* Link_e;

struct Node_j {
    jogo j;
    Link_j next;
}Node_j;

struct Node_e {
    equipa e;
    Link_e next;
}Node_e;


typedef struct masternode_e{
    int load; /* guarda o tamanho da lista ligada */
    Link_e head;
    Link_e tail;
} * linkedlist_e;

typedef struct masternode_j{
    int load; /* guarda p tamanhp da lista ligada */
    Link_j head;
    Link_j tail;
} * linkedlist_j;


/* prototipos hashtable dos jogos */
link_j push_j(link_j head, jogo j);
link_j remove_elem_j(link_j head, jogo j);
link_j search_list_j(link_j head, char* nome);
void destroy_list_j(link_j head);
link_j *HASHinit_j();
int hash(char *v);
link_j NEWnode_j(jogo j, link_j next);
void DELETEnode_j(link_j node);
void insert_j(link_j* heads, jogo j);
void delete_j(link_j* heads, jogo j);
link_j search_jogo(link_j* heads, char* nome);
void destroy_hash_j(link_j* heads);


/* prototipos hashtable das equipas */
link_e push_e(link_e head, equipa e);
link_e remove_elem_e(link_e head, equipa e);
link_e search_list_e(link_e head, char* nome);
void destroy_list_e(link_e head);
link_e *HASHinit_e();
int hash(char *v);
link_e NEWnode_e(equipa e, link_e next);
void DELETEnode_e(link_e node);
void insert_e(link_e* heads, equipa j);
link_e search_equipa(link_e* heads, char* nome);
void destroy_hash_e(link_e* heads);


/* prototipos lista ligada jogos */
linkedlist_j init_j();
Link_j add_node_before_j(Link_j next, jogo j);
Link_j add_node_after_j(Link_j prev, jogo j);
void delete_node_j(Link_j node);
jogo getjogo(Link_j node);
Link_j search_list_j1(linkedlist_j lista, char* nome);
void append_j(linkedlist_j lista, jogo j);
void remove_element_j(linkedlist_j lista, char* nome);
void destroy_list_j1(linkedlist_j lista);


/* prototipos lista ligada equipas */
linkedlist_e init_e();
Link_e add_node_before_e(Link_e next, equipa e);
Link_e add_node_after_e(Link_e prev, equipa j);
void delete_node_e(Link_e node);
equipa getequipa(Link_e node);
Link_e search_list_e1(linkedlist_e lista, char* nome);
void append_e(linkedlist_e lista, equipa e);
void destroy_list_e1(linkedlist_e lista);


/* funcao de comparacao de strings */
int sort(const void* e1, const void* e2);



