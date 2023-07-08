# Calcolatrice polacca

Questo è un progetto di calcolatrice polacca scritto in linguaggio C.

## Descrizione

La calcolatrice polacca è un tipo di notazione matematica in cui l'operatore viene posizionato prima degli operandi anziché tra di essi come nella notazione tradizionale. Questa calcolatrice consente di eseguire operazioni matematiche utilizzando la notazione polacca.

## Funzionalità

La calcolatrice polacca supporta le seguenti operazioni:

- Somma: `+`
- Differenza: `-`
- Prodotto: `x` o `*`
- Divisione: `/` o `:`
- Potenza: `e` o `E`
- Percentuale: `%`
- Radice quadrata: `q` o `Q`

## Utilizzo

La calcolatrice viene eseguita da riga di comando. Di seguito è riportata la sintassi generale:

```
calcolatrice-polacca <operatore> <numero> <numero>
```

Dove:
- `<operatore>`: l'operazione da eseguire.
- `<numero>`: i numeri su cui effettuare l'operazione.

Esempi di utilizzo:

- Somma: `calcolatrice-polacca + 5 5`
  - Risultato: 10

- Differenza: `calcolatrice-polacca - 10 2`
  - Risultato: 8

- Prodotto: `calcolatrice-polacca x 10 2`
  - Risultato: 20

- Divisione: `calcolatrice-polacca / 10 2`
  - Risultato: 5

- Potenza: `calcolatrice-polacca e 2 3`
  - Risultato: 8

- Percentuale: `calcolatrice-polacca % 100 20`
  - Risultato: 20

- Radice quadrata: `calcolatrice-polacca q 25`
  - Risultato: 5

## Requisiti di compilazione

- Linguaggio: C
- Editor: Visual Studio Code v1.62.3
- Compilatore: MinGW32-base v201307220, MinGW32-gcc-g++ v6.3.0-1, MinGW32-gcc-objc v6.3.1-1

## Esecuzione

Per compilare ed eseguire il programma, seguire i seguenti passaggi:

1. Assicurarsi che siano soddisfatti i requisiti di compilazione.
2. Compilare il programma utilizzando il compilatore GCC.
3. Eseguire il programma passando gli argomenti necessari.

## Comandi aggiuntivi

- `calcolatrice-polacca help`: mostra l'elenco delle operazioni supportate e fornisce informazioni sull'utilizzo.