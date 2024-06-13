#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "funkcije.h"
#include "strukture.h"



  void ispis(VOZILO* temp, int i, int n) {

	printf("Vozilo:%d\nID:%d\nMarka vozila:%s\nModel vozila:%s\nKaroserija vozila:%s\nGodina proizvodnje:%d\nPrijedeni kilometri:%d km\nStanje:%s\nVrsta motora:%s\nObujam motora:%.2lf cm^3\nSnaga Motora:%d kW\nVrsta mjenjaca:%s\nBroj stupnjeva mjenjaca:%d\nBroj sasije:%s\nCijena iznosi:%.2lf eura\n\n\n",

		 n,
		(temp + i)->redniBrUSustavu,
		(temp + i)->markaVozila,
		(temp + i)->nazivModelaVozila,
		(temp + i)->karoserijaVozila,
		(temp + i)->godinaProizvdnje,
		(temp + i)->kilometraza,
		(temp + i)->stanje,
		(temp + i)->vrstaMotora,
		(temp + i)->obujamMotora,
		(temp + i)->snagaMotora,
		(temp + i)->vrstaMjenjaca,
		(temp + i)->stupnjeviPrijenosa,
		(temp + i)->brojSasije,
		(temp + i)->cijena);


}



static int brojVozila = 0;


void ispisSvihVozila() {

	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	printf("Broj vozila na stanju je: %d\n\n", brojVozila);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	int i;
	int brojac=0;

	for (i = 0; i < brojVozila; i++)
	{
		brojac++;
		ispis(temp, i, brojac);
	}


	free(temp);
	temp = NULL;

	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	return;


}


void pregledVozilaMarka() {


	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	char* marka = calloc(20, sizeof(char));
	int i;
	int brojac = 0;
	printf("Unesite marku vozila koju zelite pronaci (ili '--' za izlaz):");
	scanf(" %19[^ \n]", marka);

	if (*(marka+0) == '-' && *(marka+1) == '-') {
		free(marka);
		marka = NULL;
		free(temp);
		temp = NULL;

		if (fclose(fP) != 0) {
			perror("Greska pri zatvaranju datoteke");
			exit(EXIT_FAILURE);
		}
		return;
	}
	for (i = 0; marka[i] != '\0'; i++) {
		marka[i] = toupper(marka[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(marka, (temp + i)->markaVozila) == 0) {

			printf("\n");
			brojac++;
			ispis(temp, i, brojac);
			
		}



	}

	if (brojac == 0) {
		printf("\nVozila marke %s nemamo na stanju.\n", marka);
	}

	free(marka);
	marka = NULL;
	free(temp);
	temp = NULL;

	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	return;
}

void pregledVozilaKaroserija() {

	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	char* karoserija=calloc(20, sizeof(char));
	int i;
	int brojac = 0;
	printf("Unesite karoseriju vozila koju zelite pronaci (ili '--' za izlaz):");
	scanf(" %19[^ \n]", karoserija);

	if (*(karoserija+0) == '-' && *(karoserija+1) == '-') {
		free(karoserija);
		karoserija = NULL;
		free(temp);
		temp = NULL;

		if (fclose(fP) != 0) {
			perror("Greska pri zatvaranju datoteke");
			exit(EXIT_FAILURE);
		}
		return;
	}

	for (i = 0; karoserija[i] != '\0'; i++) {
		karoserija[i] = toupper(karoserija[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(karoserija, (temp + i)->karoserijaVozila) == 0) {

			printf("\n");
			brojac++;
			ispis(temp, i, brojac);
			
		}



	}
	if (brojac == 0) {
		printf("\nVozila oblika karoserije %s nemamo na stanju.\n", karoserija);
	}

	free(karoserija);
	karoserija = NULL;
	free(temp);
	temp = NULL;

	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	return;



}


void pregledVozilaGodine() {
	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	int godinaDG;
	int godinaGG;
	int i;
	int brojac = 0;
	while(1) {
		printf("Unesite donju granicu raspon godine koju trazite (ili negativan broj za izlaz):");
		if (scanf("%d", &godinaDG) != 1) {
			while (getchar() != '\n');
			printf("Krivi unos (Moguci unos je 1920-2024)\n");
			continue;
		}
		if (godinaDG < 0) {
			free(temp);
			temp = NULL;
			fclose(fP);
			return;
		}
		if (godinaDG >= 1920 && godinaDG<2025) {
			break;
		}
		else {
			printf("Krivi unos (Moguci unos je 1920-2024)\n");
		}
	} 
	while (1) {
		printf("Unesite gornju granicu raspon godine koju trazite(ili negativan broj za izlaz):");
		if (scanf("%d", &godinaGG) != 1) {
			while (getchar() != '\n');
			printf("Krivi unos (Moguci unos je %d-2025)\n", (godinaDG + 1));
			continue;
		}
		if (godinaGG < 0) {
			free(temp);
			temp = NULL;
			fclose(fP);
			return;
		}
		if (godinaGG > godinaDG && godinaGG <= 2025) {
			break;
		}
		else {
			printf("Krivi unos (Moguci unos je %d-2025)\n", (godinaDG+1));
		}
	} 

	for (i = 0; i < brojVozila; i++) {
		if ((godinaDG <= ((temp + i)->godinaProizvdnje)) && (godinaGG >= ((temp + i)->godinaProizvdnje))) {

			printf("\n");
			brojac++;
			ispis(temp, i, brojac);
			
		}


	}

	if (brojac == 0) {
		printf("\nVozila u rasponu godina %d-%d nemamo na stanju.\n", godinaDG, godinaGG);
	}

	free(temp);
	temp = NULL;

	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	return;


}



void pregledVozilaKilometri() {



	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	int kilometrazaDG;
	int kilometrazaGG;
	int i;
	int brojac = 0;
	while(1){
		printf("Unesite donju granicu raspon kilometraze koji trazite (ili negativan broj za izlaz):");
		if (scanf("%d", &kilometrazaDG) != 1) {
			while (getchar() != '\n');
			printf("Krivi unos (Moguci unos 0-999999)\n");
			continue;
		}
		if (kilometrazaDG < 0) {
			free(temp);
			temp = NULL;
			fclose(fP);
			return;
		}
		if (kilometrazaDG >= 0 && kilometrazaDG < 1000000) {
			break;
		}
		else {
			printf("Krivi unos (Moguci unos 0-999999)\n");
		}
	} 
	while(1){
		printf("Unesite gornju granicu raspon kilometraze koji trazite (ili negativan broj za izlaz):");
		if (scanf("%d", &kilometrazaGG) != 1) {
			while (getchar() != '\n');
			printf("Krivi unos (%d-1000000)\n", (kilometrazaDG+1));
			continue;
		}
		if (kilometrazaGG < 0) {
			free(temp);
			temp = NULL;
			fclose(fP);
			return;
		}
		if (kilometrazaGG > kilometrazaDG && kilometrazaGG <= 1000000) {
			break;
		}
		else {
			printf("Krivi unos (%d-1000000)\n", (kilometrazaDG + 1));

		}
	}  

	for (i = 0; i < brojVozila; i++) {
		if ((kilometrazaDG <= ((temp + i)->kilometraza)) && (kilometrazaGG >= ((temp + i)->kilometraza))) {

			printf("\n");
			brojac++;
			ispis(temp, i, brojac);
		}



	}

	if (brojac == 0) {
		printf("\nVozila u rasponu kilometraze %d km-%d km nemamo na stanju.\n", kilometrazaDG, kilometrazaGG);
	}

	
	free(temp);
	temp = NULL;

	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	return;

}

void pregledVozilaSnaga() {



	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	int snagaDG;
	int snagaGG;
	int i;
	int brojac = 0;
	while(1){
		printf("Unesite donju granicu snage motora u KW koji trazite (ili negativan broj za izlaz):");
		if (scanf("%d", &snagaDG) != 1) {
			while (getchar() != '\n');
			printf("Krivi unos (moguci unos 0-1999)\n");
			continue;
		}
		if (snagaDG < 0) {
			free(temp);
			temp = NULL;
			fclose(fP);
			return;
		}
		if (snagaDG >= 0 && snagaDG < 2000) {
			break;
		}
		else {
			printf("Krivi unos (moguci unos 0-1999)\n");

		}
	}  
	while(1){
		printf("Unesite gornju granicu snage motora u KW  koji trazite (ili negativan broj za izlaz):");
		if (scanf("%d", &snagaGG) != 1) {
			while (getchar() != '\n');
			printf("Krivi unos (moguci unos %d-2000)\n", (snagaDG+1));
			continue;
		}
		if (snagaGG < 0) {
			free(temp);
			temp = NULL;
			fclose(fP);
			return;
		}
		if (snagaGG > snagaDG && snagaGG <= 2000) {
			break;
		}
		else {
			printf("Krivi unos (moguci unos %d-2000)\n", (snagaDG + 1));
		}
	} 

	for (i = 0; i < brojVozila; i++) {
		if ((snagaDG <= ((temp + i)->snagaMotora)) && (snagaGG >= ((temp + i)->snagaMotora))) {

			printf("\n");
			brojac++;
			ispis(temp, i, brojac);
		}



	}

	if (brojac == 0) {
		printf("\nVozila u rasponu snage %d kW-%d kW nemamo na stanju.\n", snagaDG, snagaGG);
	}

	
	free(temp);
	temp = NULL;

	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	return;

}

void pregledVozilaMotor() {

	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	char* motor = calloc(20, sizeof(char));
	int i;
	int brojac = 0;
	printf("Unesite vrstu motora vozila koju zelite pronaci (ili '--' za izlaz):");
	scanf(" %19[^ \n]", motor);

	if (*(motor+0) == '-' && *(motor+1) == '-') {
		free(motor);
		motor = NULL;
		free(temp);
		temp = NULL;

		if (fclose(fP) != 0) {
			perror("Greska pri zatvaranju datoteke");
			exit(EXIT_FAILURE);
		}
		return;
	}
	for (i = 0; motor[i] != '\0'; i++) {
		motor[i] = toupper(motor[i]);
	}


	for (i = 0; i < brojVozila; i++) {
		if (strcmp(motor, (temp + i)->vrstaMotora) == 0) {

			printf("\n");
			brojac++;
			ispis(temp, i, brojac);
		}



	}

	if (brojac == 0) {
		printf("\nVozila s motorom %s nemamo.\n", motor);
	}

	free(motor);
	motor = NULL;
	free(temp);
	temp = NULL;

	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	return;

}

void pregledVozilaMjenjac() {

	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	char* mjenjac = calloc(20, sizeof(char));
	int i;
	int brojac = 0;
	printf("Unesite vrstu mjenjaca vozila koju zelite pronaci (ili '--' za izlaz) :");
	scanf(" %19[^ \n]", mjenjac);
	if (*(mjenjac+0) == '-' && *(mjenjac+1) == '-') {
		free(mjenjac);
		mjenjac = NULL;
		free(temp);
		temp = NULL;

		if (fclose(fP) != 0) {
			perror("Greska pri zatvaranju datoteke");
			exit(EXIT_FAILURE);
		}
		return;
	}

	for (i = 0; mjenjac[i] != '\0'; i++) {
		mjenjac[i] = toupper(mjenjac[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(mjenjac, (temp + i)->vrstaMjenjaca) == 0) {

			printf("\n");
			brojac++;
			ispis(temp, i, brojac);
		}

	}

	if (brojac == 0) {
		printf("\nVozila s mjenjacem %s nemamo.\n", mjenjac);
	}

	free(mjenjac);
	mjenjac = NULL;
	free(temp);
	temp = NULL;

	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}


	return;



}


void pregledVozilaCijena() {



	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	VOZILO* temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));

	if (temp == NULL) {
		perror("Zauzimanje memorije za vozila");
		exit(EXIT_FAILURE);
	}

	fread(temp, sizeof(VOZILO), brojVozila, fP);



	if (temp == NULL) {
		printf("Polje vozila je prazno!\n");
		return;
	}

	double cijenaDG;
	double cijenaGG;
	int i;
	int brojac = 0;
	while (1) {
		printf("Unesite donju granicu raspona cijene koji trazite (ili negativan broj za izlaz): ");
		if (scanf("%lf", &cijenaDG) != 1) {
			while (getchar() != '\n');
			printf("Krivi unos (moguci unos 0-999999)\n");
			continue;
		}
		if (cijenaDG < 0) {
			free(temp);
			temp = NULL;
			fclose(fP);
			return; 
		}
		if (cijenaDG >= 0 && cijenaDG < 1000000) {
			break;
		}
		else {
			printf("Krivi unos (moguci unos 0-999999)\n");
		}
	}

	while (1) {
		printf("Unesite gornju granicu raspona cijene koji trazite (ili negativan broj za izlaz): ");
		if (scanf("%lf", &cijenaGG) != 1) {
			while (getchar() != '\n'); 
			printf("Krivi unos (moguci unos %d-1000000\n", (cijenaDG+1));
			continue;
		}
		if (cijenaGG < 0) {
			free(temp);
			temp = NULL;
			fclose(fP);
			return; 
		}
		if (cijenaGG > cijenaDG && cijenaGG <= 1000000) {
			break;
		}
		else {
			printf("Krivi unos (moguci unos %d-1000000\n", (cijenaDG + 1));
		}
	}

	for (int i = 0; i < brojVozila; i++) {
		if (cijenaDG <= ((temp + i)->cijena) && cijenaGG >= ((temp + i)->cijena)) {
			printf("\n");
			brojac++;
			ispis(temp, i, brojac);
		}
	}


	if (brojac == 0) {
		printf("\nVozila u rasponu cijene %.0lf-%.0lf eura nemamo na stanju.\n", cijenaDG, cijenaGG);
	}

	free(temp);
	temp = NULL;
	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	return;

}

void sigurnosnaKopija() {

	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		fP = fopen("vozila.bin", "wb+");
	}
	if (fP == NULL) {
		perror("Greska kod sigurnosnog kopiranja.");
		return;
	}

	FILE* sfP = NULL;
	sfP = fopen("vozila_kopija.bin", "wb+");
	if (sfP == NULL) {
		perror("Greska kod sigurnosnog kopiranja");
		return;
	}

	char buffer[1024];
	size_t bytesRead;
	while ((bytesRead = fread(buffer, 1, sizeof(buffer), fP)) > 0) {
		fwrite(buffer, 1, bytesRead, sfP);
	}

	
	fclose(fP);
	fclose(sfP);

	
	if (remove("vozila.bin") != 0) {
		perror("Greska pri brisanju originalne datoteke");
		return;
	}

	
	if (rename("vozila_kopija.bin", "vozila.bin") != 0) {
		perror("Greska pri preimenovanju sigurnosne kopije");
	}
	else {
		printf("Sigurnosna kopija je uspjesno kreirana i originalna datoteka je zamijenjena.\n");
	}
}