# Calcolatrice Polacca

Un'applicazione CLI (Command Line Interface) che implementa una calcolatrice in notazione polacca inversa per eseguire operazioni matematiche di base direttamente da terminale.

## Funzionalità
La calcolatrice supporta le seguenti operazioni:

- **Radice quadrata** (`q` o `Q`)  
- **Somma** (`+`)  
- **Sottrazione** (`-`)  
- **Moltiplicazione** (`x`, `X` o `*`)  
- **Divisione** (`/` o `:`)  
- **Percentuale** (`%`)  
- **Potenza** (`e` o `E`)  

Il programma gestisce inoltre:
- Operazioni su numeri a virgola mobile.
- Messaggi di errore per input non validi.
- Calcolo senza visualizzare il risultato per divisioni o radici quadrate non valide (divisione per zero e radici quadrate di numeri negativi).
- Messaggi di help per assistenza all'utente (`help` o `?`).

## Compilazione

Per utilizzare questo programma su vari sistemi operativi, segui le istruzioni qui sotto:

### Prerequisiti
Per tutti i sistemi, è necessario avere:
- Un compilatore C (es. `gcc`).

### Istruzioni di Compilazione e Esecuzione

#### Linux/macOS

1. **Clona il repository:**
   ```bash
   git clone https://github.com/alessandromasone/calcolatrice-polacca.git
   cd calcolatrice-polacca
   ```

2. **Compila il codice:**
   ```bash
   gcc -o calcolatrice_polacca main.c -lm
   ```
   Il flag `-lm` è richiesto per linkare la libreria matematica (`math.h`).

3. **Esegui l'applicazione:**
   ```bash
   ./calcolatrice_polacca
   ```

#### Windows

1. **Clona il repository:** (puoi usare Git Bash o un client GUI per Git)
   ```bash
   git clone https://github.com/alessandromasone/calcolatrice-polacca.git
   cd calcolatrice-polacca
   ```

2. **Compila il codice** utilizzando `gcc` tramite MinGW o altro compilatore disponibile:
   ```bash
   gcc -o calcolatrice_polacca main.c -lm
   ```

3. **Esegui l'applicazione:**
   ```cmd
   calcolatrice_polacca.exe
   ```

## Esempi di Utilizzo

- **Help e assistenza:**  
  ```bash
  ./calcolatrice_polacca ?
  ```

- **Radice quadrata:**  
  ```bash
  ./calcolatrice_polacca q 25
  ```

- **Somma:**  
  ```bash
  ./calcolatrice_polacca + 5 5
  ```

- **Divisione:**  
  ```bash
  ./calcolatrice_polacca / 10 2
  ```

- **Potenza:**  
  ```bash
  ./calcolatrice_polacca e 2 3
  ```

## Struttura del Progetto

- **`main.c`**: Contiene il codice sorgente principale, inclusa la logica per il parsing degli argomenti e la gestione delle operazioni.
- **Funzioni chiave**:
  - `Calculate`: Gestisce le operazioni matematiche.
  - `ControlNumber`: Verifica la validità dei numeri.
  - `Help`: Fornisce assistenza per l'utilizzo del programma.
  - `IsFile`: Controlla se un percorso rappresenta un file.
  - `ProcessArguments`: Rimuove eventuali file dalla lista degli argomenti.

## Licenza

Distribuito sotto la **MIT License**. Vedi il file [LICENSE](LICENSE) per maggiori dettagli.