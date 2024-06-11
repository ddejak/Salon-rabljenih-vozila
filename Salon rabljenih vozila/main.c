#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "strukture.h"
#include "funkcije.h"


extern int brojVozila=0;

int main(void) {

	int izvrsi;

	
	while (1) {


		system("cls");
		printf("=========================================GLAVNI IZBORNIK===========================================\n");
		printf("===================================================================================================\n");
		printf("\t\t\t\t1.Pregled dostupnih vozila.\n\
                \t\t2.Unos novog vozila.\n\
                \t\t3.Azuriranje vozila.\n\
                \t\t4.Brisanje vozila.\n\
                \t\t5.Ugasite program.\n");
		printf("===================================================================================================\n");
		printf("===================================================================================================\n");


			printf("\nUnesite sto zelite uciniti:");
			if (scanf("%d", &izvrsi) != 1) {
				printf("\nNeispravan unos. Molimo unesite broj.\n");
				while (getchar() != '\n');
				continue; 
			}
			
	
		switch (izvrsi) {
			

		case PREGLED_VOZILA:pregledVozila();break;

		case UNOS_NOVOG_VOZILA:unosNovogVozila();break;

		case AZURIRANJE_VOZILA:azuriranjeVozila(); break;

		case BRISANJE_VOZILA:brisanjeVozila(); break;

		case UGASI_PROGRAM:printf("\nProgram se ugasio.\nWOMP WOMP"); exit(EXIT_SUCCESS);

		default:printf("\nKrivi unos.\n"); break;
		}system("pause");

		

	}


	return 0;
}