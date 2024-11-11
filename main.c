#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
#include <sys/stat.h>

#define MAX 1024

// Funzione per calcolare il risultato basato sull'operatore
float Calculate(float x, float y, char op);

// Funzione per controllare se una stringa rappresenta un numero valido
int ControlNumber(const char *text);

// Funzione per visualizzare l'help
void Help(const char *programName);

// Funzione per verificare se un file esiste
int IsFile(const char *filename);

// Funzione per gestire gli argomenti e rimuovere i file dalla lista
void ProcessArguments(int *argc, char *argv[]);

int main(int argc, char *argv[]) {
    char op;
    float x = 0, y = 0, result = 0;

    // Processiamo gli argomenti, rimuovendo i file dalla lista
    ProcessArguments(&argc, argv);

    // Gestione dei diversi casi di argomenti
    switch (argc) {
        case 1:
            printf("Usage: %s ? per help\n", argv[0]);
            break;
        case 2:
            op = argv[1][0];
            if (strcmp(argv[1], "help") == 0 || op == '?') {
                Help(argv[0]);
            } else {
                printf("Input non valido. Digita '%s ?' per l'help.\n", argv[0]);
            }
            break;
        case 3:
            op = argv[1][0];
            if (op == 'q' || op == 'Q') {
                if (ControlNumber(argv[2]) == 0) {
                    x = atof(argv[2]);
                    result = Calculate(x, 0, op);
                    if (result != 0) {
                        printf("Risultato: %g\n", result);
                    }
                } else {
                    printf("Errore: numero non valido '%s'.\n", argv[2]);
                }
            } else {
                printf("Operazione non valida. Digita '%s ?' per l'help.\n", argv[0]);
            }
            break;
        case 4:
            op = argv[1][0];
            if (ControlNumber(argv[2]) == 0 && ControlNumber(argv[3]) == 0) {
                x = atof(argv[2]);
                y = atof(argv[3]);
                result = Calculate(x, y, op);
                if (result != 0) {
                    printf("Risultato: %g\n", result);
                }
            } else {
                // Errori specifici per il numero non valido
                if (ControlNumber(argv[2]) != 0) {
                    printf("Errore: numero non valido '%s'.\n", argv[2]);
                }
                if (ControlNumber(argv[3]) != 0) {
                    printf("Errore: numero non valido '%s'.\n", argv[3]);
                }
            }
            break;
        default:
            printf("Usage: %s ? per help\n", argv[0]);
            break;
    }

    return 0;
}

// Funzione per calcolare il risultato basato sull'operatore
float Calculate(float x, float y, char op) {
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case 'x':
        case 'X':
        case '*': return x * y;
        case '/':  // Verifica divisione per zero
        case ':':
            if (y == 0) {
                printf("Errore: Divisione per zero.\n");
                return 0; // Non stampiamo "Risultato: 0" per gli errori
            }
            return x / y;
        case '%': return (x * y) / 100;
        case 'e':
        case 'E': return pow(x, y);
        case 'q':
        case 'Q':
            if (x < 0) {
                printf("Errore: Radice quadrata di un numero negativo.\n");
                return 0; // Non stampiamo "Risultato: 0" per gli errori
            }
            return sqrt(x);
        default:
            printf("Operazione non valida.\n");
            return 0;
    }
}

// Funzione per controllare se la stringa rappresenta un numero valido
int ControlNumber(const char *text) {
    int i, dotCount = 0;

    // Scorre la stringa per contare i punti decimali
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == ',') {
            dotCount++;
            if (dotCount > 1) return 1;  // Più di un punto decimale
            if (text[i] == ',') {
                // Sostituisce la virgola con il punto
                return 0;
            }
        }
        if ((text[i] < '0' || text[i] > '9') && text[i] != '.') return 1;  // Carattere non valido
    }
    return 0; // È un numero valido
}

// Funzione di help per visualizzare le istruzioni d'uso
void Help(const char *programName) {
    printf("Calcolatore polacco da linea di comando\n\n");
    printf("Uso: %s <operatore> <numero1> <numero2>\n\n", programName);
    printf("Operatori disponibili:\n");
    printf("  [q | Q]      : Calcola la radice quadrata del primo numero\n");
    printf("  [+]          : Somma il primo e il secondo numero\n");
    printf("  [-]          : Sottrae il secondo numero dal primo\n");
    printf("  [x | X | *]  : Moltiplica il primo numero per il secondo\n");
    printf("  [/ | :]      : Divide il primo numero per il secondo\n");
    printf("  [%%]          : Calcola la percentuale del secondo numero sul primo\n");
    printf("  [e | E]      : Calcola la potenza del primo numero elevato al secondo\n");
    printf("\nEsempi:\n");
    printf("  q 25         : Restituisce 5      (radice quadrata di 25)\n");
    printf("  + 5 5        : Restituisce 10     (5 + 5)\n");
    printf("  x 10 2       : Restituisce 20     (10 * 2)\n");
    printf("  / 10 2       : Restituisce 5      (10 / 2)\n");
    printf("  %% 100 20     : Restituisce 20     (20%% di 100)\n");
    printf("  e 2 3        : Restituisce 8      (2 elevato alla potenza di 3)\n");
}

// Funzione per verificare se un percorso è un file
int IsFile(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0 && S_ISREG(buffer.st_mode));
}

// Funzione per processare gli argomenti e rimuovere i file dalla lista
void ProcessArguments(int *argc, char *argv[]) {
    int i, j;
    int mod = 0;

    // Scorre gli argomenti e rimuove i file
    for (i = 1; i < *argc; i++) {
        if (IsFile(argv[i])) {  // Se è un file
            // Shift degli argomenti verso sinistra
            memmove(&argv[i], &argv[i + 1], (*argc - i - 1) * sizeof(char *));
            mod = 1;
            (*argc)--;  // Riduce il numero di argomenti
            i--;  // Ricontrolla l'argomento che è stato spostato
        }
    }

    // Se sono stati rimossi file, metti '*' al posto dell'argomento
    if (mod) {
        for (i = *argc; i > 1; i--) {
            argv[i] = argv[i - 1];  // Sposta ogni elemento a destra
        }
        argv[1] = "*";  // Metti "*" in argv[1]
        (*argc)++;
    }
}
