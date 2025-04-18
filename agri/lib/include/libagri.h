/*_______________________________________________
* FILE: libagri.h
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NNODI 44
#define PORTE 4
#define INFINITO 9999


typedef enum  {SX,DEORSUM,DX,SURSUM,FIXO} versus;
enum genus {MURO,ALTRO};
typedef enum genus rei_genus;

/*** TIPI COMUNUI ***/

typedef struct {
  int linea;
  int columna;
  int index;
  int ianua[PORTE];
} agri_Vertex;

/*** GRAFO COME LISTA DI ARCHI ***/

/* 
   ITA: Arco orientato e pesato
   ENG: diricted and weighted edge ("colligatio" means edge) 
*/
typedef struct colligatio {
  /* 
     ITA: vertici collegati dall'arco
     ENG: vertices connected by the edge
  */
  agri_Vertex ab, ad;
   /* 
    ITA: attributi
    ENG: attributes
   */
  versus discessus, meta;
  int longitudo;
} agri_Colligatio;

/* 
   ITA: Elemento della lista di archi
   ENG: Edges list item
*/
typedef struct membrum {
  agri_Colligatio colligatio;
  struct  membrum *  next;
} agri_Membrum;

typedef agri_Membrum * agri_Colligationes_Colligatae;

/*
  ITA: Inserisce l'arco in testa alla lista
  ENG: inserts an edge on top of the list
*/
void agri_Colligationem_insero
(agri_Colligationes_Colligatae * pg, agri_Colligatio colligatio);

/* ITA: Cerca tra gli elementi del grafo se uno degli archi è connesso
   ad un vertice in linea e columna. Se lo trova torna l'indice del
   vertice, altrimenti -1
   ENG: Looks into the graph for a vertex whose row and column attributes
   are equal to linea and columna
*/
int agri_Verticem_quaero(agri_Colligationes_Colligatae g, int linea, int columna);

void agri_libero(agri_Colligationes_Colligatae g);

/*** GRAFO COME ARRAY DI VERTICI ***/

typedef agri_Vertex * agri_Verticum_Dispositio;

agri_Vertex agri_Verticem_creo(int index, int linea, int columna);

typedef struct nodus_coda
{
  //Riferimento al nodus del grafo
  int index;

  //Priorità
  double prio;
  
  //Navigazione coda 
  struct nodus_coda * post;
  
} Nodus;

//Tipo per la coda di priorità
typedef Nodus * Ordo;
//Tipo per il cammino finale
typedef int * agri_Via;

/*____________________________________________
 * 
 * Inserimento ordinato in base alla priorità
 */
void Ordo_amoveo_nodus(Ordo * l, int index);

void Ordo_insero_nodus(Ordo * l,int index, double prio);

int Ordo_pop(Ordo * pOrdo);

agri_Via agri_astar(int start, int goal,
		    agri_Vertex * agri_Vertices_Colligati,
		    double (*spatium)(int ab, int ad),
		    double (*euristica)(int ab, int ad),
		    int nmembri
		    );

int agri_breadthfirstsearch(int start, 
		    agri_Vertex * agri_Vertices_Colligati,
		    int (*visitatus)(int ),
		    int nmembri
				 );

/*__________________________________________________________
 *|
 *| Torna l'index del nodus presente in (riga, colonna)
 *| Se non è presente alcun nodus (il fantasma è su un ramo)
 *| torna -1
 */
int index_nodus_cella(int riga, int col, agri_Vertex * av,int nmembri);


/*** GRAFO COME LISTA DI CELLE  ***/

/*
  ITA: Attributi della cella
  ENG: Cell attributes
 */
typedef struct dato
{
  int visitata;
  rei_genus rei;
} Attributi;

/*
  ITA: vicini di ogni cella
  ENG: cell's neighbords
 */
typedef struct cella {
  Attributi d;
  struct cella* dextra;
  struct cella* deorsum; //GIU
  struct cella* sinistra;
  struct cella* sursum; //SU
} agri_Cella;

/*
  ITA: Tabellam composto da celle
  ENG: Graph composed by cells
 */
typedef agri_Cella* agri_Tabella;

/*
  ITA: elementi della lista dei passi
  ENG: elements of the step list
 */
typedef struct nodo
{
  agri_Cella * locus;
  struct nodo * next;
  struct nodo * prev;
}agri_Passo;

/*
  ITA: lista dei passi
  ENG: step list
 */
typedef agri_Passo* agri_Iter;  


/*
  ITA: inizializza un grafo vuoto
  ENG: initialize an empty graph
 */
void agri_creo_Tabellam(agri_Tabella* g);
/*
  ITA: Aggiunge al grafo una nuova cella con attributi d, collegandola alla direzione
  dir cella corrente
  ENG: Adds a new cell, with the attributes d, to the graph, linking it to the
  direction dir of the current cell
 */
agri_Tabella agri_addo_Tabellam(agri_Tabella tabella,Attributi d,versus dir);

/*
  ITA: collega le cella da e a lungo la direzione da ---> a
 */
void agri_colligo_Cellas(agri_Cella * da, agri_Cella * a, versus da_a);



/*
  ITA: inizializza una lista di passo puntata da p_camm cammimo vuoto
  ENG: initialize an empty list of steps
 */
void agri_creo_Iter(agri_Iter* p_camm);
/*
  ITA: aggiunge una Cella nella lista puntata da p_camm dei passi compiuti
  ENG: adds a cell in the list pointed to by p_camm of the steps performed
 */
void agri_addo_Iter(agri_Iter * p_camm, agri_Cella * p_cella);
/*
  ITA:
 */
agri_Cella* agri_rivela_Cella(agri_Iter ap,versus ricerca);



/*** TRAFFORMAZIONI ***/

/*
  ITA: da un grafo di archi ad un grafo di vertici
 */
int  agri_muto(agri_Colligationes_Colligatae ge, agri_Verticum_Dispositio *a);

int agri_dispono(agri_Colligationes_Colligatae list ,agri_Colligationes_Colligatae * array);

int Verticem_quaero(agri_Verticum_Dispositio v, int index, int amplitudo);

versus agri_Versum_inverto(versus v);

int compar(const void * a, const void * b);


