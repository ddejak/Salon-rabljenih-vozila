#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "funkcije.h"
#include "strukture.h"



void ispis(VOZILO* temp, int i) {

	printf("Vozilo:%d\nID:%d\nMarka vozila:%s\nModel vozila:%s\nKaroserija vozila:%s\nGodina proizvodnje:%d\nPrijedeni kilometri:%d km\nStanje:%s\nVrsta motora:%s\nObujam motora:%.2lf cm^3\nSnaga Motora:%d kW\nVrsta mjenjaca:%s\nBroj stupnjeva mjenjaca:%d\nBroj sasije:%s\nCijena iznosi:%.2lf eura\n\n\n",

		i + 1,
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

	for (i = 0; i < brojVozila; i++)
	{
		ispis(temp, i);
	}


	free(temp);
	fclose(fP);

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

	char marka[20] = { 0 };
	int i;
	int brojac = 0;
	printf("Unesite marku vozila koju zelite pronaci(ako se zelite vratiti u izbornik unesite '--'):");
	scanf("%s", marka);

	if (marka[0] == '-' && marka[1] == '-') {
		return;
	}
	for (i = 0; marka[i] != '\0'; i++) {
		marka[i] = toupper(marka[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(marka, (temp + i)->markaVozila) == 0) {

			printf("\n");
			ispis(temp, i);
			brojac++;
		}



	}

	if (brojac == 0) {
		printf("\nVozila marke %s nemamo na stanju.\n", marka);
	}

	free(temp);
	fclose(fP);

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

	char karoserija[20] = { 0 };
	int i;
	int brojac = 0;
	printf("Unesite karoseriju vozila koju zelite pronaci (ako se zelite vratiti u izbornik unesite'--'):");
	scanf("%s", karoserija);

	if (karoserija[0] == '-' && karoserija[1] == '-') {
		return;
	}

	for (i = 0; karoserija[i] != '\0'; i++) {
		karoserija[i] = toupper(karoserija[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(karoserija, (temp + i)->karoserijaVozila) == 0) {

			printf("\n");
			ispis(temp, i);
			brojac++;
		}



	}
	if (brojac == 0) {
		printf("\nVozila oblika karoserije %s nemamo na stanju.\n", karoserija);
	}

	free(temp);
	fclose(fP);

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
	do {
		printf("Unesite donju granicu raspon godine koju trazite:");
		if (scanf("%d", &godinaDG) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (godinaDG < 1920 || godinaDG>2025);
	do {
		printf("Unesite gornju granicu raspon godine koju trazite:");
		if (scanf("%d", &godinaGG) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (godinaGG <= godinaDG || godinaGG > 2025);

	for (i = 0; i < brojVozila; i++) {
		if ((godinaDG <= ((temp + i)->godinaProizvdnje)) && (godinaGG >= ((temp + i)->godinaProizvdnje))) {

			printf("\n");
			ispis(temp, i);
			brojac++;
		}


	}

	if (brojac == 0) {
		printf("\nVozila u rasponu godina %d-%d nemamo na stanju.\n", godinaDG, godinaGG);
	}

	free(temp);
	fclose(fP);

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
	do {
		printf("Unesite donju granicu raspon kilometraze koji trazite:");
		if (scanf("%d", &kilometrazaDG) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (kilometrazaDG < 0 || kilometrazaDG>1000000);
	do {
		printf("Unesite gornju granicu raspon kilometraze koji trazite:");
		if (scanf("%d", &kilometrazaGG) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (kilometrazaGG <= kilometrazaDG || kilometrazaGG > 1000000);

	for (i = 0; i < brojVozila; i++) {
		if ((kilometrazaDG <= ((temp + i)->kilometraza)) && (kilometrazaGG >= ((temp + i)->kilometraza))) {

			printf("\n");
			ispis(temp, i);
			brojac++;
		}



	}

	if (brojac == 0) {
		printf("\nVozila u rasponu kilometraze %d km-%d km nemamo na stanju.\n", kilometrazaDG, kilometrazaGG);
	}

	free(temp);
	fclose(fP);

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
	do {
		printf("Unesite donju granicu snage motora u KW koji trazite:");
		if (scanf("%d", &snagaDG) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (snagaDG < 0 || snagaDG > 2000);
	do {
		printf("Unesite gornju granicu snage motora u KW  koji trazite:");
		if (scanf("%d", &snagaGG) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (snagaGG <= snagaDG || snagaGG > 2000);

	for (i = 0; i < brojVozila; i++) {
		if ((snagaDG <= ((temp + i)->snagaMotora)) && (snagaGG >= ((temp + i)->snagaMotora))) {

			printf("\n");
			ispis(temp, i);
			brojac++;
		}



	}

	if (brojac == 0) {
		printf("\nVozila u rasponu snage %d kW-%d kW nemamo na stanju.\n", snagaDG, snagaGG);
	}

	free(temp);
	fclose(fP);

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

	char motor[20] = { 0 };
	int i;
	int brojac = 0;
	printf("Unesite vrstu motora vozila koju zelite pronaci (ako se zelite vratiti u izbornik unesite '--'):");
	scanf("%s", motor);

	if (motor[0] == '-' && motor[1] == '-') {
		return;
	}
	for (i = 0; motor[i] != '\0'; i++) {
		motor[i] = toupper(motor[i]);
	}


	for (i = 0; i < brojVozila; i++) {
		if (strcmp(motor, (temp + i)->vrstaMotora) == 0) {

			printf("\n");
			ispis(temp, i);
			brojac++;
		}



	}

	if (brojac == 0) {
		printf("\nVozila s motorom %s nemamo.\n", motor);
	}

	free(temp);
	fclose(fP);

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

	char mjenjac[20] = { 0 };
	int i;
	int brojac = 0;
	printf("Unesite vrstu mjenjaca vozila koju zelite pronaci(ako zelite izaci unesite '--'):");
	scanf("%s", mjenjac);
	if (mjenjac[0] == '-' && mjenjac[1] == '-') {
		return;
	}

	for (i = 0; mjenjac[i] != '\0'; i++) {
		mjenjac[i] = toupper(mjenjac[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(mjenjac, (temp + i)->vrstaMjenjaca) == 0) {

			printf("\n");
			ispis(temp, i);
			brojac++;
		}

	}

	if (brojac == 0) {
		printf("\nVozila s mjenjacem %s nemamo.\n", mjenjac);
	}

	free(temp);
	fclose(fP);


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
	do {
		printf("Unesite donju granicu raspon cijene koji trazite:");
		if (scanf("%lf", &cijenaDG) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (cijenaDG < 0 || cijenaDG >1000000);
	do {
		printf("Unesite gornju granicu raspon cijene koji trazite:");
		if (scanf("%lf", &cijenaGG) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (cijenaGG <= cijenaDG || cijenaGG > 1000000);

	for (i = 0; i < brojVozila; i++) {
		if ((cijenaDG <= ((temp + i)->cijena)) && (cijenaGG >= ((temp + i)->cijena))) {

			printf("\n");
			ispis(temp, i);
			brojac++;
		}



	}

	if (brojac == 0) {
		printf("\nVozila u rasponu cijene %.0lf-%.0lf eura nemamo na stanju.\n", cijenaDG, cijenaGG);
	}

	free(temp);
	fclose(fP);

	return;

}

