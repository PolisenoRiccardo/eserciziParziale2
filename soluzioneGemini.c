void rimuoviPrimoDuplicato(Nodo* head) {
    if (head == NULL) return; // Lista vuota, nulla da fare

    Nodo *current = head;
    
    // Ciclo esterno: avanza nodo per nodo (1, poi 3, poi 5...)
    while (current != NULL) {
        
        Nodo *runner = current;
        
        // Ciclo interno: cerca in avanti se esiste un uguale a current
        while (runner->next != NULL) {
            
            if (runner->next->valore == current->valore) {
                // TROVATO! runner->next è il duplicato di current
                
                Nodo *daCancellare = runner->next;
                
                // 1. Scavalchiamo il nodo da cancellare
                runner->next = runner->next->next;
                
                // 2. Liberiamo la memoria
                free(daCancellare);
                
                // 3. STOP. La richiesta dice "cancellare la prima istanza", 
                // quindi ci fermiamo dopo la prima cancellazione.
                return; 
            } else {
                // Altrimenti avanziamo
                runner = runner->next;
            }
        }
        
        // Passiamo al prossimo nodo di riferimento
        current = current->next;
    }
}
