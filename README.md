# Mangia e Fuggi  
(ovvero, i miracolosi schemi di Pac-Man per completare il labirinto senza essere catturato dal Ghost-Team)

**New**  
Scopri la rivoluzione del pathfinding applicata a un classico: la guida intelligente di Pac-Man tramite algoritmi basati sui grafi!

---

## Introduzione

Pac-Man, l'icona dei videogiochi nata nel 1980 grazie alla creatività di Toru Iwatani, ha ispirato generazioni di giocatori. Oggi, l'idea di guidare Pac-Man non si limita più a spostamenti casuali, ma sfrutta potenti algoritmi di ricerca e ottimizzazione per trasformare il labirinto in un sistema dinamico e intelligente.  

Con il nostro approccio, il labirinto diventa un **grafo** in cui:
- **I Vertici** rappresentano gli incroci o le posizioni chiave del labirinto.
- **Gli Archi** collegano questi vertici e rappresentano le possibili mosse.

Utilizzando algoritmi come **A\*** e **Breadth-First Search (BFS)**, il sistema calcola in tempo reale il percorso più vantaggioso per raggiungere gli obiettivi (ad esempio, la pillola più vicina) e per evitare i pericoli rappresentati dal Ghost-Team.

---

## Il Potere dei Grafi

I grafi sono strutture matematiche estremamente potenti. In questo contesto:

- **Modelliamo il labirinto**: ogni cella accessibile o incrocio diventa un vertice, mentre i corridoi che collegano le celle sono rappresentati come archi.
- **Ottimizzazione del percorso**: grazie ad A* e ad altri algoritmi, ogni mossa di Pac-Man viene calcolata in base a una combinazione di costo reale e una stima euristica, assicurando così una navigazione ottimale e dinamica.
- **Adattamento in tempo reale**: il sistema è in grado di ricalcolare il percorso in presenza di nuovi ostacoli (ad es. l'apparizione dei fantasmi), garantendo decisioni sempre aggiornate e ottimali.

---

## Storia di Pac-Man

Nato nel 1980, Pac-Man è diventato un simbolo culturale mondiale. In origine concepito per offrire un'esperienza di gioco inclusiva e accessibile, Pac-Man ha anche ispirato studi accademici e applicazioni pratiche, dai videogiochi all'intelligenza artificiale. Oggi, la nostra soluzione basata sui grafi è un omaggio alla genialità di quel primo arcade, trasformando la sfida del labirinto in un problema di ottimizzazione e ricerca che ha rilevanza anche in settori come la robotica e la logistica.

---

## La Piattaforma Open Source Tuki-5

La piattaforma **Tuki-5** è una implementazione in C del gioco classico di Pac-Man. Essa permette di sperimentare diverse strategie e *agents* che utilizzano algoritmi basati sui grafi per guidare Pac-Man attraverso il labirinto.

### Strategie Disponibili

- **Pac-Man vaga per il labirinto**  
  Un agente che percorre il labirinto in maniera casuale – una questione di fortuna!  
  Prova il [codice](PacMan/gioca_tuki_random.c)

- **Pac-Man segue il filo di Arianna**  
  Un agente che utilizza l’algoritmo boustrophedon per coprire in modo deterministico ogni angolo del labirinto.  
  Prova il [codice](PacMan/gioca_tuki_boustrophedon.c)

- **Pac-Man si crea un grafo del labirinto**  
  Mentre esplora, l’agente costruisce mentalmente un grafo: gli incroci diventano **vertici** e i corridoi **archi**.  
  Prova il [codice](PacMan/gioca_tuki_generagrafo.c)

- **Pac-Man punta al bersaglio**  
  Utilizzando l'algoritmo A*, l’agente calcola e segue il percorso più breve verso il nodo desiderato.  
  Prova il [codice](PacMan/gioca_tuki_esploraeritorna.c)

- **Pac-Man ha un percorso**  
  Un agente che segue un percorso sub-ottimale predefinito, anche se i fantasmi possono distrarlo.  
  Prova il [codice](PacMan/gioca_tuki_percorso.c)

- **Pac-Man pesa i percorsi e evita i fantasmi senza fuggire**  
  Un agente che sfrutta l’euristica per evitare le minacce senza dover scappare a ogni costo.  
  Prova il [codice](PacMan/gioca_tuki_pesato.c)

- **Pac-Man ottimizza il percorso**  
  Un agente che utilizza l’algoritmo BFS per ottimizzare il cammino in tempo reale.  
  Prova il [codice](PacMan/gioca_tuki_respiro.c)

- **Pac-Man ottimizza il percorso ed evita i fantasmi senza fuggire**  
  Il top della sofisticazione: un agente che combina l’ottimizzazione del percorso con la strategia di evasione.  
  Prova il [codice](PacMan/gioca_tuki_evita.c)

---

## Perché Scegliere un Approccio Basato sui Grafi?

Immagina un sistema in cui ogni mossa di Pac-Man è il risultato di un’analisi matematica avanzata. Con i grafi, puoi:
- **Calcolare decisioni ottimali**: l’algoritmo A* trova il percorso più breve o sicuro.
- **Adattarsi alle situazioni dinamiche**: il sistema ricalcola in tempo reale il percorso se i fantasmi cambiano posizione.
- **Applicare soluzioni innovative**: le tecniche di pathfinding basate sui grafi sono utilizzate in robotica, logistica e intelligenza artificiale, rendendo questa piattaforma una base ideale per sperimentazioni e innovazioni.



