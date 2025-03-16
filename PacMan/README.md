# PacMan

Benvenuti nella sezione **PacMan** di PacGraph!

Questa cartella contiene le implementazioni in C di diversi *agents* che guidano Pac-Man nel labirinto sfruttando algoritmi basati sui grafi. L’obiettivo è quello di studiare e sperimentare strategie di navigazione, ottimizzazione e di evasione, trasformando il classico gioco in un laboratorio di intelligenza artificiale e pathfinding.

---

## Panoramica

In questa sezione il labirinto di Pac-Man viene modellato come un grafo:
- **Vertici**: rappresentano incroci o posizioni chiave (celle accessibili) del labirinto.
- **Archi**: rappresentano i corridoi o le connessioni tra questi punti.

Utilizzando algoritmi come **A\***, **Breadth-First Search (BFS)** e il metodo **boustrophedon**, gli agenti calcolano dinamicamente il percorso ottimale per raccogliere pillole, coprire l'intero labirinto e – quando necessario – evitare i fantasmi (il Ghost-Team).

---

## Agenti Disponibili

All'interno della cartella troverai diversi file sorgente, ognuno dei quali implementa una specifica strategia di navigazione:

- **gioca_tuki_vuoto.c**  
  Un agente base in cui Pac-Man rimane statico. Utile come punto di partenza o riferimento.

- **gioca_tuki_random.c**  
  Un agente che guida Pac-Man in modo casuale nel labirinto. Il percorso ottenuto è fortemente influenzato dalla fortuna e dalla configurazione dei fantasmi.

- **gioca_tuki_boustrophedon.c**  
  Implementa l’algoritmo boustrophedon, garantendo una copertura deterministica del labirinto. È l’ideale per chi vuole vedere Pac-Man “seguire il filo di Arianna”.

- **gioca_tuki_generagrafo.c**  
  Mentre Pac-Man si muove, questo agente costruisce “mentalmente” il grafo del labirinto, registrando incroci e corridoi (vertici e archi). Un ottimo esempio di applicazione della teoria dei grafi.

- **gioca_tuki_percorso.c**  
  L’agente segue un percorso sub-ottimale predefinito (una “mappa” di nodi). Purtroppo, i fantasmi possono facilmente interrompere questo cammino.

- **gioca_tuki_pesato.c**  
  Qui Pac-Man “pesa” i vari percorsi usando un’euristica: evita i fantasmi senza fuggire direttamente, bilanciando il percorso ottimale con la sicurezza.

- **gioca_tuki_respiro.c**  
  Questo agente utilizza il BFS per ottimizzare il percorso in tempo reale, aggiornando continuamente il cammino sulla base delle nuove informazioni.

- **gioca_tuki_evita.c**  
  La soluzione più completa: combina la ricerca di un percorso ottimale (A*) con strategie di evasione per evitare i fantasmi. L’agente ricalcola dinamicamente il cammino in base alle posizioni dei nemici e agli ostacoli presenti nel labirinto.

---

## Come Utilizzare

### Requisiti
- Compilatore **GCC** compatibile con C99.
- La piattaforma Tuki-5 (inclusa nella cartella `mvc`) per la gestione del labirinto e della logica di gioco.

