#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "funkcije.h"
#include "strukture.h"

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
	//printf("Broj vozila na stanju je: %d\n\n", brojVozila);
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

	char marka[20];
	int i;
	printf("Unesite marku vozila koju zelite pronaci:");
	scanf("%s", marka);

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(marka, (temp + i)->markaVozila) == 0) {


			ispis(temp, i);
		}



	}

	free(temp);


	return;
}

void PregledVozilaKaroserija() {

	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	//printf("Broj vozila na stanju je: %d\n\n", brojVozila);
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

	char karoserija[20];
	int i;
	printf("Unesite karoseriju vozila koju zelite pronaci:");
	scanf("%s", karoserija);

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(karoserija, (temp + i)->karoserijaVozila) == 0) {


			ispis(temp, i);
		}



	}

	free(temp);


	return;



}


void PregledVozilaGodine() {
	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	//printf("Broj vozila na stanju je: %d\n\n", brojVozila);
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
	printf("Unesite donju granicu raspon godine koju trazite:");
	scanf("%d", &godinaDG);
	printf("Unesite donju granicu raspon godine koju trazite:");
	scanf("%d", &godinaGG);

	for (i = 0; i < brojVozila; i++) {
		if ((godinaDG <= ((temp + i)->godinaProizvdnje)) && (godinaGG >= ((temp + i)->godinaProizvdnje))) {


			ispis(temp, i);
		}


	}

	free(temp);


	return;


}



void PregledVozilaKilometri() {


	
	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	//printf("Broj vozila na stanju je: %d\n\n", brojVozila);
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
	printf("Unesite donju granicu raspon kilometraze koji trazite:");
	scanf("%d", &kilometrazaDG);
	printf("Unesite donju granicu raspon kilometraze koji trazite:");
	scanf("%d", &kilometrazaGG);

	for (i = 0; i < brojVozila; i++) {
		if ((kilometrazaDG <= ((temp+i)->kilometraza)) && (kilometrazaGG >= ((temp+i)->kilometraza))) {


			ispis(temp, i);
		}



	}

	free(temp);


	return;

}

void PregledVozilaSnaga() {



	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	//printf("Broj vozila na stanju je: %d\n\n", brojVozila);
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
	printf("Unesite donju granicu snage motora u KW koji trazite:");
	scanf("%d", &snagaDG);
	printf("Unesite donju granicu snage motora u KW  koji trazite:");
	scanf("%d", &snagaGG);

	for (i = 0; i < brojVozila; i++) {
		if ((snagaDG <= ((temp + i)->snagaMotora)) && (snagaGG >= ((temp + i)->snagaMotora))) {


			ispis(temp, i);
		}



	}

	free(temp);


	return;

}

void PregledVozilaMotor() {
	
	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	//printf("Broj vozila na stanju je: %d\n\n", brojVozila);
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

	char motor[20];
	int i;
	printf("Unesite vrstu motora vozila koju zelite pronaci:");
	scanf("%s", motor);

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(motor, (temp + i)->vrstaMotora) == 0) {


			ispis(temp, i);
		}



	}

	free(temp);


	return;

}

void PregledVozilaMjenjac() {

	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		perror("Greska kod funkcije ispisVozila.");
		exit(EXIT_FAILURE);
	}
	fread(&brojVozila, sizeof(int), 1, fP);
	//printf("Broj vozila na stanju je: %d\n\n", brojVozila);
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

	char mjenjac[20];
	int i;
	printf("Unesite vrstu mjenjaca vozila koju zelite pronaci:");
	scanf("%s", mjenjac);

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(mjenjac, (temp + i)->vrstaMjenjaca) == 0) {


			ispis(temp, i);
		}



	}

	free(temp);


	return;



}

void unosNovogVozila() {

	int pin;
	printf("Unesite administratorski pin.");
	scanf("%d", &pin);
	if (pin != 1234) {
		printf("Kriva lozinka, nemate pristup unosu novih vozila.\n");
		return;
	}

	printf("\nUnos novog vozila\n");

	FILE* fP = NULL;
	fP = fopen("vozila.bin", "rb+");
	if (fP == NULL) {
		fP = fopen("vozila.bin", "wb+");
	}
	if (fP == NULL) {
		perror("Greska kod funkcije unosNovogVozila.");
		exit(EXIT_FAILURE);
	}

	fread(&brojVozila, sizeof(int), 1, fP);
	printf("Broj Vozila na stanju je: %d\n", brojVozila);
	VOZILO temp = { 0 };
	temp.redniBrUSustavu = brojVozila;
	getchar();
	printf("Unesite marku vozila:");
	scanf("%19[^\n]", temp.markaVozila);
	printf("Unesite model vozila:");
	getchar();
	scanf("%19[^\n]", temp.nazivModelaVozila);
	printf("Unesite tip karoserije vozila:");
	getchar();
	scanf("%19[^\n]", temp.karoserijaVozila);
	printf("Unesite godinu proizvodnje:");
	scanf("%d", &temp.godinaProizvdnje);
	printf("Unesite stanje vozila:");
	getchar();
	scanf("%19[^\n]", temp.stanje);
	printf("Unesite broj sasije:");
	getchar();
	scanf("%19[^\n]", temp.brojSasije);
	getchar();
	printf("Unesite vrstu motora:");
	scanf("%19[^\n]", temp.vrstaMotora);
	printf("Unesite vrstu mjenjaca.");
	getchar();
	scanf("%19[^\n]", temp.vrstaMjenjaca);

	printf("Unesite koliko stupnjeva prijenosa ima mjenjac:");
	scanf("%d", &temp.stupnjeviPrijenosa);
	printf("Unesite kilometrazu vozila:");
	scanf("%d", &temp.kilometraza);
	printf("Unesite obujam motora u cm kubnim:");
	scanf("%lf", &temp.obujamMotora);
	printf("Unesite snagu motora u kW:");
	scanf("%d", &temp.snagaMotora);
	
	
	fseek(fP, sizeof(int) + sizeof(VOZILO) * brojVozila, SEEK_SET);
	fwrite(&temp, sizeof(VOZILO), 1, fP);
	rewind(fP);
	brojVozila++;
	fwrite(&brojVozila, sizeof(int), 1, fP);
	fclose(fP);

}

void pregledVozila() {

	int uvjet;

	while (1) {

		system("cls");
		printf("\t\t\tDobrodosli u izbornik za pregled vozila\n");
		printf("==================================================================================================\n");
		printf("\t\t\t1.Pregled svih vozila.\n\
                \t2.Pregled vozila unosom marke vozila.\n\
                \t3.Pregled vozila unosom oblika karoserije.\n\
                \t4.Pregled vozila unosom raspona godini proizvodnje.\n\
                \t5.Pregled vozila unosom raspona snage u kW.\n\
                \t6.Pregled vozila unosom raspona kilometara u km.\n\
                \t7.Pregled vozila po tipu motora\n\
                \t8.Pregled vozila po tipu mjenjaca\n\
                \t9.Vrati se u glavni izbornik\n");
		printf("==================================================================================================\n");

		printf("Odaberit radnju koju zelite:");
		if (scanf("%d", &uvjet) != 1) {
			printf("\nNeispravan unos. Molimo unesite broj.\n");
			while (getchar() != '\n');
			continue;
		}

		switch (uvjet) {

		case 1:ispisSvihVozila(); break;
		case 2:pregledVozilaMarka(); break;
		case 3:PregledVozilaKaroserija();  break;
		case 4:PregledVozilaGodine();  break;
		case 5:PregledVozilaSnaga(); break;
		case 6:PregledVozilaKilometri();  break;
		case 7:PregledVozilaMotor(); break;
		case 8:PregledVozilaMjenjac();  break;
		case 9:return;
		default: printf("Krivi unos.\n"); break;



		}system("pause");


	}



}