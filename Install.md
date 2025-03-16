Clona il progetto:
    git clone https://github.com/francescosisini/LIBROGRAFI.git

Scegli uno degli agent di Pac-Man tra:
    - **Gioca_tuki_random.c**  
      Pac-Man esplora il labirinto scegliendo casualmente dove svoltare.
    - **Gioca_tuki_boustrophedon.c**  
      Pac-Man esplora il labirinto in modo deterministico grazie all'algoritmo boustrophedon.
    - **Gioca_tuki_generagrafo.c**  
      Pac-Man genera un grafo vertice-arco mentre esplora il labirinto.
    - **Gioca_tuki_esploraeritorna.c**  
      Pac-Man utilizza il grafo che genera online per navigare nel labirinto.
    - **Gioca_tuki_percorso.c**  
      Pac-Man inizia il gioco con il grafo dell'intero labirinto e lo usa per completarlo in modo sub-ottimale.

Compila specificando se attivare il meccanismo di fuga e l'intervallo (in millisecondi) tra i passi:
    ./compila.sh PacMan/Gioca_tuki_percorso.c 1 50

Imposta il terminale ad almeno 60x60

Esegui:
    ./tuki5.game 1

dove **1** indica il numero di fantasmi (da 0 a 4).
