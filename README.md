# Tesi
Contiene tutti i file relativi al mio progetto di tesi

#Algoritmo di esplorazione
Ho fatto lcune scelte implementative:
  1) Ho inserito un controllo sulla somma restituita come output della chiamata della funzione findNeighbourhood: se è uguale a 0 restituisce un
     errore.
  2) Ho inserito una fase di aggiornamento dei feromoni in fase di inizializzazione per le celle in cui si trovano i robot e i corrispettivi
     vicini.
  3) Se un robot vede più di un vicino con valore uguale del feromone, e questo valore è quello minimo, allora viene scelto il primo che viene
     visto nell'ordine in cui vengono controllati. Da valutare la possibilità di scegliere invece, uno casuale tra questi vicini migliori.
