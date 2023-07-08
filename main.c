/*=============================================================================
 |   Assignment:  CALCULATOR FOR POLISH NOTATION.
 |
 |       Author:  ALESSANDRO MASONE
 |     Language:  WRITTEN IN C
 |       Editor:  VISUAL STUDIO CODE V1.62.3
 |
 |   To Compile:  MINGW32-BASE V201307220
 |                MINGW32-GCC-G++ V6.3.0-1
 |                MINGW32-GCC-OBJC V6.3.1-1
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  BUILD A COMMAND LINE CALCULATOR THAT HANDLES 
 |                POLISH NOTATION.
 |
 |        Input:  PARAMETERS.
 |
 |       Output:  RESULT.
 |
 |    Algorithm:  TOP-DOWN.
 |
 |   Easter Egg:  IF THE OPERATOR IS "MAIN.EXE" IT WILL MULTIPLY THE
 |                PRICE TO PAY FOR THE '*' CHARACTER.
 |
 *===========================================================================*/

# include   <stdio.h>
# include   <stdlib.h>
# include   <math.h>
# include   <string.h>
# include   <conio.h>

#define MAX 1024

float Calculate(float, float, int);
void Error(int);
int ControlNumber(char *);
void Help(char *);

int posizione_errore = 0;

int main(int argc, char *argv[])
{
    char NAME_FILE[MAX] = {};

    //var for the central parts of the main
    float x = 0;
    float y = 0;
    float result = 0;
    char op;    

    //var for parts of control '*'
    int i, j;
    int multiplex = -1;
    int first_parameter = -1;

    //If the '*' character has been entered this will return all files present within the command directory, as it will return the command name with ".exe" added. Analyzing this state, we check and then modify argc & argv
    strcpy(NAME_FILE, argv[0]);
    strcat(NAME_FILE, ".exe");
    for (i = 0; i < argc;  i++)
        if (strcmp(argv[i], NAME_FILE) == 0)
            multiplex = i;
    if (multiplex != -1)
    {
        for (i = multiplex; i < argc;  i++)
        {
            if (ControlNumber(argv[i]) == 0)
            {
                first_parameter = i;
                break;
            }
        }
        j = 2;
        strcpy(argv[1], "x");
        for (i = first_parameter; i < first_parameter + 2; i++)
            strcpy(argv[j++], argv[i]);
        argc = 4;
    }
    //end section analyze '*'

    switch (argc) //number of arguments
    {
        case 1:
            printf("Usage: %s ? for help", argv[0]);
            break;
        case 2:
            op = argv[1][0];
            if (strcmp(argv[1], "help") == 0)
                Help(argv[0]);
            else if (strlen(argv[1]) > 1)
            {
                printf("Evaluating:\n");                    
                printf("        %s\n", argv[1]);
                Error(0);
            }
            else if (op == '?')
                Help(argv[0]);
            else
                printf("Usage: %s ? for help", argv[0]);
            break;
        case 3:
            op = argv[1][0];
            if (strlen(argv[1]) > 1)
            {
                printf("Evaluating:\n");                    
                printf("        %s %s\n", argv[1], argv[2]);
                Error(0);
            }
            else if (op == 'q' || op == 'Q')
            {
                if (ControlNumber(argv[2]) == 0)
                {
                    x = atof(argv[2]);
                    y = 0;
                    result = Calculate(x, y, op);
                    printf("Evaluating:\n");                    
                    printf("        %s %s\n", argv[1], argv[2]);
                    printf("Result:\n");
                    printf("        %g", result);
                }
                else
                {
                    printf("Evaluating:\n");                    
                    printf("        %s %s\n", argv[1], argv[2]);
                    Error(2);
                    
                }
            }
            else
                printf("Usage: %s ? for help", argv[0]);
            break;
        case 4:
            op = argv[1][0];
            if (strlen(argv[1]) > 1)
            {
                printf("Evaluating:\n");                    
                printf("        %s %s %s\n", argv[1], argv[2], argv[3]);
                Error(0);
            }
            else if (op == '+' || op == '-' || op == 'x' || op == 'X' || op == '/' || op == ':' || op == 'e' || op == 'E' || op == '%')
            {
                if (ControlNumber(argv[2]) == 0)
                {
                    if (ControlNumber(argv[3]) == 0)
                    {
                        x = atof(argv[2]);
                        y = atof(argv[3]);
                        result = Calculate(x, y, op);
                        printf("Evaluating:\n");     
                        if (multiplex != -1)
                            printf("        * %s %s\n", argv[2], argv[3]);
                        else
                            printf("        %s %s %s\n", argv[1], argv[2], argv[3]);
                        printf("Result:\n");
                        printf("        %g", result);
                    }
                    else
                    {
                        printf("Evaluating:\n");                    
                        printf("        %s %s %s\n", argv[1], argv[2], argv[3]);
                        Error(strlen(argv[1])+1+strlen(argv[2])+1);
                    }            
                }
                else
                {
                    printf("Evaluating:\n");                    
                    printf("        %s %s %s\n", argv[1], argv[2], argv[3]);
                    Error(strlen(argv[1])+1);
                }
            }
            else
            {
                printf("Evaluating:\n");                    
                printf("        %s %s %s\n", argv[1], argv[2], argv[3]);
                Error(0);
            }
            break;
        default:
            printf("Usage: %s ? for help", argv[0]);
            break;
    }
    return 0;
}

float Calculate(float x, float y, int op)
{
    float temp = 0;
    switch (op)
    {
    case 43:
        return(x+y);
    case 45:
        return(x-y);
    case 120:
        return(x*y);
    case 88:
        return(x*y);
    case 47:
        return(x/y);
    case 58:
        return(x/y);
    case 101:
        return(pow(x,y));
    case 69:
        return(pow(x,y));
    case 37:
        return((x*y)/100);
    case 113:
        return(sqrt(x));
    case 81:
        return(sqrt(x));
    default:
        break;
    }
}

void Error(int x)
{
   for (int i = 0; i < posizione_errore + 8 + x; i++)
       printf(" ");
   printf("^~~~~\nError near here");

}

int ControlNumber(char *text)
{
    char temp[MAX];
    int i, j;
    int segno = -1,
    ok = 1,
    virgola = 0;
    int position;
    strcpy(temp, text);
    if (temp[0] == '-' || temp[0] == '+')
        segno = 1;
    else
        segno = 0;
    for (i = segno; i < strlen(temp); i++)
        if (temp[i] == '.' || temp[i] == ',')
        {
            virgola++;
            if (virgola == 1)
                position = i;
        }
    if (virgola == 1)
    {
        virgola = 1;
        text[position] = '.';
    }
    else if (virgola == 0)
        virgola = 0;
    else
    {
        posizione_errore = position;
        return(1);
    }
    for (i = segno; i < strlen(temp); i++)
    {
        ok = 1;
        for (j = 0; j < 10; j++)
        {
            if(temp[i] == 48 + j)
                ok = 0;
            if (temp[i] == '.')
                ok = 0;
            if (temp[i] == ',')
                ok = 0;
        }
        if (ok == 1)
        {
            posizione_errore = i;
            return(1);
        }
    }
    return 0;
}

void Help(char *cm)
{
    printf("Calcolatrice a linea di comando.\n\n");
    printf("%s <operatore> <numero> <numero>\n\n", cm);
    printf(" Operatori:\n");
    printf(" [q | Q]");
    printf("\tEffettua la radice quadrata di un solo numero.\n");
    printf("\t\tESEMPIO: q 25\n");
    printf("\t\tRestituir\x85: 5\n");
    printf(" [+]");
    printf("\t\tEffettua la somma di due numeri.\n");
    printf("\t\tESEMPIO: + 5 5\n");
    printf("\t\tRestituir\x85: 10\n");
    printf(" [-]");
    printf("\t\tEffettua la differenza tra due numeri.\n");
    printf("\t\tESEMPIO: - 10 2\n");
    printf("\t\tRestituir\x85: 8\n");
    printf(" [/ | :]");
    printf("\tEffettua la divisione tra due numeri.\n");
    printf("\t\tESEMPIO: / 10 2\n");
    printf("\t\tRestituir\x85: 5\n");
    printf(" [X | x | *]");
    printf("\tEffettua il prodotto tra due numeri.\n");
    printf("\t\tESEMPIO: x 10 2\n");
    printf("\t\tRestituir\x85: 20\n");
    printf(" [%%]");
    printf("\t\tCalcola la percentuale del secondo numero sul primo.\n");
    printf("\t\tESEMPIO: % 100 20\n");
    printf("\t\tRestituir\x85: 20\n");
    printf(" [e | E]");
    printf("\tCalcola la potenza con base primo numero\n\t\te esponente il secondo numero.\n");
    printf("\t\tESEMPIO: e 2 3\n");
    printf("\t\tRestituir\x85: 8\n");
    
}