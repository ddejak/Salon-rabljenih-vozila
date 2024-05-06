#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "strukture.h"
#include "funkcije.h"


int main(void) {

	int izvrsi;

	//Izbornik
	while (1) {

		system("cls");

		printf("===================================================================================================\n");
		printf("\t\t\t\t1.Pregled dostupnih vozila.\n\
                \t\t2.Unos novog vozila.\n\
                \t\t3.Briasnje vozila.\n\
                \t\t4.Ugasite program.\n");
		printf("===================================================================================================\n");
		
		printf("\n\nUnesite sto zelite uciniti:");
		scanf("%d", &izvrsi);

		

		switch (izvrsi) {
			

		case 1:pregledVozila();break;

		case 2:unosNovogVozila();break;

		case 3:printf("\nBrisanje vozila iz baze.\n"); break;

		case 4:printf("\nProgram se ugasio.\nWOMP WOMP"); exit(EXIT_SUCCESS);

		default:printf("\nKrivi unos.\n"); break;
		}

		system("pause");

	}


	return 0;
}