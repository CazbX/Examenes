#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf ("Se recomienda ejecutar en pantalla completa\n");
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	WORD colorOriginal = csbi.wAttributes;
	
	int c,j;
	
	printf ("Ingrese la cantidad de libros:\t");
	scanf ("%d", &c);
	getchar ();
	
	char isbn [c][11];
	char titulo [c][20], autor [c][20], genero [c][20];
	int  precio[c], stock[c];
	int i ;
	int digitos = 0;
	float ganancia [c], acum =0, prom=0;
	

	
	for (i = 0; i < c ; i++){
		
		
		printf ("|-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|\n");
		
		printf ("Ingrese el titulo:\t");
		scanf (" %[^\n]", &titulo[i]);
		
			for (j = 0 ; titulo[i][j];j++){
				
				titulo [i][j] = toupper(titulo [i][j]);
				
			}
			getchar ();
		
		printf ("Ingrese el autor:\t");
		scanf (" %[^\n]", &autor[i]);
			
			for (j = 0 ; autor[i][j];j++){
				
				autor [i][j] = toupper(autor [i][j]);
				
			}
		
			getchar ();
		
		printf ("Ingrese el genero:\t");
		scanf (" %[^\n]", &genero[i]);
		
		for (j = 0 ; genero[i][j];j++){
				
				genero [i][j] = toupper(genero [i][j]);
				
			}
			getchar ();
			
		do {
		printf ("Ingrese el ISBN (debe ser de 10 digitos, en caso de que le vuelva a salir el mensaje se debe a que a ingresado mas o menos digitos de lo esperado):\t");
		scanf (" %[^\n]s", &isbn[i]);
		getchar ();
		
		digitos = strlen(isbn[i]);
		
			} while (digitos != 10);
			
		do {
		
			
		printf ("Ingrese el precio (Debe ser positivo):\t");
		scanf ("%d", &precio[i]);
		
		if (precio [i] < 0){
			
			printf ("El precio unitario no debe ser negativo vuelva a ingresarlo:\t");
		}
		
		} while (precio [i]<0);
		
		printf ("Ingrese el stock:\t");
		scanf ("%d", &stock[i]);
		
		ganancia [i] = (stock[i]*precio[i]);
		
		
			getchar ();
	}
	
	printf ("\n");
	printf ("| %-18s |  |  %-17s |  | %-16s |    | %-9s  |  |%-6s|    | %-6s|  |%-6s |\n", "TITULO", "AUTOR", "GENERO", "ISBN", "PRECIO", "STOCK","GANANCIA");
	
	for (i=0; i<c; i++){
		
	
		printf ("| %-18s |\t", titulo[i]);
		printf ("| %-18s |\t", autor[i]);
		printf ("| %-16s |\t", genero[i]);
		printf ("| %-8s |\t", isbn[i]);
		printf ("|  %-1d  |\t", precio[i]);
		printf ("|%d|\t", stock[i]);
		
		
		
		if (ganancia [i] > 0){
			
		SetConsoleTextAttribute(hConsole, 2);
            printf ("  |%-2.1f|\n", ganancia [i]);
        SetConsoleTextAttribute(hConsole, colorOriginal);
        }
        else if (ganancia [i] < 0) {
        SetConsoleTextAttribute(hConsole, 4);
            printf ("  |%-2.1f|\n", ganancia [i]);
        SetConsoleTextAttribute(hConsole, colorOriginal);
        }
        
        
	}
	
char consulta[20];  

printf("Ingrese el libro a buscar:\n");
scanf(" %[^\n]", consulta);
getchar();

for (i = 0; i < c; i++) {
    if (
        strcasecmp(consulta, titulo[i]) == 0 ||
        strcasecmp(consulta, autor[i]) == 0 ||
        strcasecmp(consulta, genero[i]) == 0 ||
        strcmp(consulta, isbn[i]) == 0
    ) {
        printf("| %-18s |  |  %-17s |  | %-16s |    | %-9s  |  |%-6s|    | %-6s|  |%-6s |\n", "TITULO", "AUTOR", "GENERO", "ISBN", "PRECIO", "STOCK", "GANANCIA");

        printf("| %-18s |\t", titulo[i]);
        printf("| %-18s |\t", autor[i]);
        printf("| %-16s |\t", genero[i]);
        printf("| %-8s |\t", isbn[i]);
        printf("|  %-1d  |\t", precio[i]);
        printf("|%d|\t", stock[i]);

        if (ganancia[i] > 0) {
            SetConsoleTextAttribute(hConsole, 2);
            printf("  |%-2.1f|\n", ganancia[i]);
            SetConsoleTextAttribute(hConsole, colorOriginal);
        } 
		else if (ganancia[i] < 0) {
            SetConsoleTextAttribute(hConsole, 4);
            printf("  |%-2.1f|\n", ganancia[i]);
            SetConsoleTextAttribute(hConsole, colorOriginal);
        }
    }
}




	//Nota: profe si asi fue la practica no me quiero imaginar el parcial, tarde 5 horas y casi no lo termino porque al final toque algo y rompi el codigo :(
	//Si revisas el codigo e intentas no buscar un libro se me olvido como hacerlo disculpeme :(
	//Di lo mejor de mi se lo prometo :(

	return 0;
}
