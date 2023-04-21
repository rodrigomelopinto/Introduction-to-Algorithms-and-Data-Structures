#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ht.h"

#define HASH_SIZE 1049 /* tamanho das hashtables */

/* funcoes para a hashtable dos jogos */

/* insere um novo node no inicio de uma lista ligada */
link_j push_j(link_j head, jogo j){
    link_j aux = NEWnode_j(j, head);
    return aux;
}

/* remove um node de uma lista ligada */
link_j remove_elem_j(link_j head, jogo j){ 
    link_j current, prev;
    for(current = head, prev = NULL; current != NULL; prev = current, current = current->next){
        if(strcmp((key(current->j)),key(j)) == 0){
            if(current == head){
                head = current->next;
            } 
            else{
                prev->next = current->next;
            } 
            DELETEnode_j(current);
            return head;
        }
    }
    return head;
}

/* procura uma node numa lista ligada */
link_j search_list_j(link_j head, char* nome){
    link_j current;
    for(current = head; current != NULL; current = current->next){
        if(strcmp((key(current->j)),nome) == 0){
            return current;
        }
    }
    return NULL;
}

/* apaga uma lista ligada */
void destroy_list_j(link_j head){
    link_j current, aux;
    if(head == NULL){
        return;
    }
    for(current = head, aux = head->next; current != NULL; aux = current->next,
    DELETEnode_j(current), current = aux){}
}

/* inicializa a hashtable dos jogos */
link_j* HASHinit_j(){
    int i;
    link_j* heads = (link_j*) malloc(HASH_SIZE*sizeof(link_j));
    for(i=0;i<HASH_SIZE;i++){
        heads[i] = NULL;
    }
    return heads;
}

/* funcao de hash */
int hash(char *v){
    int h, a = 31415, b = 27183;

    for(h = 0; *v != '\0'; v++, a = a*b % (HASH_SIZE-1)){
        h = (a*h + *v) % HASH_SIZE;
    }
    return h;
}

/* cria um novo node com um jogo */
link_j NEWnode_j(jogo j, link_j next){
    link_j x = (link_j) malloc(sizeof(struct node_j));

    x->j = j;
    x->next = next;

    return x;
}

/* apaga um node com um jogo */
void DELETEnode_j(link_j node){
    delete_jogo(node->j);
    free(node);
}

/* insere um jogo na hashtable */
void insert_j(link_j* heads, jogo j){
    int i = hash(key(j));
    heads[i] = push_j(heads[i], j);
}

/* apaga um jogo da hashtable */
void delete_j(link_j* heads, jogo j){
    int i = hash(j->n_jogo);
    heads[i] = remove_elem_j(heads[i], j);
}

/* procura um jogo na hashtable */
link_j search_jogo(link_j* heads, char* nome){
    int i = hash(nome);
    return search_list_j(heads[i], nome);
}

/* faz free da hashtable toda */
void destroy_hash_j(link_j* heads){
    int i;
    for(i=0;i<HASH_SIZE;i++){
        destroy_list_j(heads[i]);
    }
    free(heads);
}


/* funcoes para a hashtable das equipas */

/* insere um novo node no inicio de uma lista ligada */
link_e push_e(link_e head, equipa e){
    link_e aux = NEWnode_e(e, head);
    return aux;
}

/* remove um node de uma lista ligada */
link_e remove_elem_e(link_e head, equipa e){
    link_e current, prev;
    for(current = head, prev = NULL; current != NULL; prev = current, current = current->next){
        if(strcmp((key2(current->e)),key2(e)) == 0){
            if(current == head){
                head = current->next;
            } 
            else{
                prev->next = current->next;
            } 
            DELETEnode_e(current);
            return head;
        }
    }
    return head;
}

/* procura uma node numa lista ligada */
link_e search_list_e(link_e head, char* nome){
    link_e current;
    for(current = head; current != NULL; current = current->next){
        if(strcmp(current->e->nome,nome) == 0){
            return current;
        }
    }
    return NULL;
}

/* apaga uma lista ligada */
void destroy_list_e(link_e head){
    link_e current, aux;
    if(head == NULL){
        return;
    }
    for(current = head, aux = head->next; current != NULL; aux = current->next,
    DELETEnode_e(current), current = aux){}
}

/* innicializa a hashtable das equipas */
link_e* HASHinit_e(){
    int i;
    link_e* heads = (link_e*) malloc(HASH_SIZE*sizeof(link_e));
    for(i=0;i<HASH_SIZE;i++){
        heads[i] = NULL;
    }
    return heads;
}

/* cria um novo node com uma equipa */
link_e NEWnode_e(equipa e, link_e next){
    link_e x = (link_e) malloc(sizeof(struct node_e));

    x->e = e;
    x->next = next;

    return x;
}

/* faz free de um node com uma equipa */
void DELETEnode_e(link_e node){
    delete_equipa(node->e);
    free(node);
}

/* inseres uma equipa na hashtable das equipas */
void insert_e(link_e* heads, equipa e){
    int i = hash(key2(e));
    heads[i] = push_e(heads[i], e);
}

/* procura uma equipa nas hashtable das equipas */
link_e search_equipa(link_e* heads, char* nome){
    int i = hash(nome);
    return search_list_e(heads[i], nome);
}

/* faz free da hastable das equipas */
void destroy_hash_e(link_e* heads){
    int i;
    for(i=0;i<HASH_SIZE;i++){
        destroy_list_e(heads[i]);
    }
    free(heads);
}

/* ------------------------------------------------------------------------- */

/* listas ligadas */

/* funcoes para a lista ligada dos jogos */
linkedlist_j init_j(){
    linkedlist_j list = malloc(sizeof(struct masternode_j));
    list->load = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}


Link_j add_node_before_j(Link_j next, jogo j){
    Link_j new = malloc(sizeof(struct Node_j));
    new->j = j;
    new->next = next;
    return new;
}

Link_j add_node_after_j(Link_j prev, jogo j){
    Link_j new;
    if(prev == NULL) return add_node_before_j(prev, j);
    new = malloc(sizeof(struct Node_j));
    new->j = j;
    new->next = prev->next;
    prev->next = new;
    return new;
}

void delete_node_j(Link_j node){
    free(node);
}

jogo getjogo(Link_j node){
    if(node != NULL) return node->j;
    return NULL;
}

Link_j search_list_j1(linkedlist_j lista, char* nome){
    Link_j current;
    for(current = lista->head; current != NULL; current = current->next){
        if(strcmp(getjogo(current)->n_jogo, nome) == 0){
            return current;
        }
    }
    return NULL;
}

void append_j(linkedlist_j lista, jogo j){
    Link_j newnode;
    newnode = add_node_after_j(lista->tail, j);
    lista->tail = newnode;
    if(lista->head == NULL) lista->head = newnode;
    lista->load++;
}

void remove_element_j(linkedlist_j lista, char* nome){
    Link_j current, prev;
    for (current = lista->head, prev = NULL; current != NULL; prev = current, current = current->next) {
        if(strcmp(getjogo(current)->n_jogo, nome) == 0){
            if (current == lista->tail) lista->tail = prev;
            if (current == lista->head) lista->head = current->next;
            else prev->next = current->next;
            free(current);
            lista->load--;
            return;
        }
	}
}

void destroy_list_j1(linkedlist_j lista){
    Link_j current, aux;
	if (lista == NULL) return;
	if (lista->load != 0)
		for (current = lista->head, aux = lista->head->next; current != NULL; aux = current->next, delete_node_j(current), current = aux){}
	free(lista);
}

/* funcoes para a lista ligada das equipas */
linkedlist_e init_e(){
    linkedlist_e list = malloc(sizeof(struct masternode_e));
    list->load = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Link_e add_node_before_e(Link_e next, equipa e){
    Link_e new = malloc(sizeof(struct Node_e));
    new->e = e;
    new->next = next;
    return new;
}

Link_e add_node_after_e(Link_e prev, equipa e){
    Link_e new;
    if(prev == NULL) return add_node_before_e(prev, e);
    new = malloc(sizeof(struct Node_e));
    new->e = e;
    new->next = prev->next;
    prev->next = new;
    return new;
}

void delete_node_e(Link_e node){
    free(node);
}

equipa getequipa(Link_e node){
    if(node != NULL) return node->e;
    return NULL;
}

Link_e search_list_e1(linkedlist_e lista, char* nome){
    Link_e current;
    for(current = lista->head; current != NULL; current = current->next){
        if(strcmp(getequipa(current)->nome, nome) == 0){
            return current;
        }
    }
    return NULL;
}

void append_e(linkedlist_e lista, equipa e){
    Link_e newnode;
    newnode = add_node_after_e(lista->tail, e);
    lista->tail = newnode;
    if(lista->head == NULL) lista->head = newnode;
    lista->load++;
}


void destroy_list_e1(linkedlist_e lista){
    Link_e current, aux;
	if (lista == NULL) return;
	if (lista->load != 0)
		for (current = lista->head, aux = lista->head->next; current != NULL; aux = current->next, delete_node_e(current), current = aux){}
	free(lista);
}


/* funcao de comparacao de string */

int sort(const void* e1, const void* e2){
    const char** na = (const char **)e1;
    const char** nb = (const char **)e2;
    return strcmp(*na, *nb);
}
