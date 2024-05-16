#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
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
	printf("Unesite marku vozila koju zelite pronaci:");
	scanf("%s", marka);
	for ( i = 0; marka[i] != '\0'; i++) {
		marka[i] = toupper(marka[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(marka, (temp + i)->markaVozila) == 0) {


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
	printf("Unesite karoseriju vozila koju zelite pronaci:");
	scanf("%s", karoserija);
	for ( i = 0; karoserija[i] != '\0'; i++) {
		karoserija[i] = toupper(karoserija[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(karoserija, (temp + i)->karoserijaVozila) == 0) {

			
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
	printf("Unesite donju granicu raspon godine koju trazite:");
	scanf("%d", &godinaDG);
	printf("Unesite donju granicu raspon godine koju trazite:");
	scanf("%d", &godinaGG);

	for (i = 0; i < brojVozila; i++) {
		if ((godinaDG <= ((temp + i)->godinaProizvdnje)) && (godinaGG >= ((temp + i)->godinaProizvdnje))) {


			ispis(temp, i);
			brojac++;
		}


	}

	if (brojac == 0) {
		printf("\nVozila u rasponu godina %d-%d nemamo na stanju.\n",godinaDG,godinaGG);
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
	printf("Unesite donju granicu raspon kilometraze koji trazite:");
	scanf("%d", &kilometrazaDG);
	printf("Unesite donju granicu raspon kilometraze koji trazite:");
	scanf("%d", &kilometrazaGG);

	for (i = 0; i < brojVozila; i++) {
		if ((kilometrazaDG <= ((temp+i)->kilometraza)) && (kilometrazaGG >= ((temp+i)->kilometraza))) {


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
	printf("Unesite donju granicu snage motora u KW koji trazite:");
	scanf("%d", &snagaDG);
	printf("Unesite donju granicu snage motora u KW  koji trazite:");
	scanf("%d", &snagaGG);

	for (i = 0; i < brojVozila; i++) {
		if ((snagaDG <= ((temp + i)->snagaMotora)) && (snagaGG >= ((temp + i)->snagaMotora))) {


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
	printf("Unesite vrstu motora vozila koju zelite pronaci:");
	scanf("%s", motor);
	for (i = 0; motor[i] != '\0'; i++) {
		motor[i] = toupper(motor[i]);
	}
	

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(motor, (temp + i)->vrstaMotora) == 0) {


			ispis(temp, i);
			brojac++;
		}



	}

	if (brojac == 0) {
		printf("\nVozila s motorom %s nemamo.\n",motor);
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
	printf("Unesite vrstu mjenjaca vozila koju zelite pronaci:");
	scanf("%s", mjenjac);
	for (i = 0; mjenjac[i] != '\0'; i++) {
		mjenjac[i] = toupper(mjenjac[i]);
	}

	for (i = 0; i < brojVozila; i++) {
		if (strcmp(mjenjac, (temp + i)->vrstaMjenjaca) == 0) {

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
	printf("Unesite donju granicu raspon cijene koji trazite:");
	scanf("%lf", &cijenaDG);
	printf("Unesite donju granicu raspon cijene koji trazite:");
	scanf("%lf", &cijenaGG);

	for (i = 0; i < brojVozila; i++) {
		if ((cijenaDG <= ((temp + i)->cijena)) && (cijenaGG >= ((temp + i)->cijena))) {


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

void unosNovogVozila() {

	int pin;
	printf("Unesite administratorski pin:");
	scanf("%d", &pin);
	if (pin != 3009) {
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
	printf("Unesite marku vozila:");
	scanf(" %19[^\n]", temp.markaVozila);
	for (int i = 0; temp.markaVozila[i] != '\0'; i++) {
		temp.markaVozila[i]=toupper(temp.markaVozila[i]);
	}

	printf("Unesite model vozila:");
	scanf(" %19[^\n]", temp.nazivModelaVozila);
	for (int i = 0; temp.nazivModelaVozila[i] != '\0'; i++) {
		temp.nazivModelaVozila[i] = toupper(temp.nazivModelaVozila[i]);
	}

	printf("Unesite tip karoserije vozila:");
	scanf(" %19[^\n]", temp.karoserijaVozila);
	for (int i = 0; temp.karoserijaVozila[i] != '\0'; i++) {
		temp.karoserijaVozila[i] = toupper(temp.karoserijaVozila[i]);
	}

	do {
		printf("Unesite godinu proizvodnje:");
		scanf("%d", &temp.godinaProizvdnje);
	} while (temp.godinaProizvdnje < 1920 || temp.godinaProizvdnje>2025);

	printf("Unesite stanje vozila:");
	scanf(" %19[^\n]", temp.stanje);
	for (int i = 0; temp.stanje[i] != '\0'; i++) {
		temp.stanje[i] = toupper(temp.stanje[i]);
	}

	printf("Unesite broj sasije:");
	scanf(" %19[^\n]", temp.brojSasije);
	for (int i = 0; temp.brojSasije[i] != '\0'; i++) {
		temp.brojSasije[i] = toupper(temp.brojSasije[i]);
	}

	printf("Unesite vrstu motora:");
	scanf(" %19[^\n]", temp.vrstaMotora);
	for (int i = 0; temp.vrstaMotora[i] != '\0'; i++) {
		temp.vrstaMotora[i] = toupper(temp.vrstaMotora[i]);
	}

	printf("Unesite vrstu mjenjaca:");
	scanf(" %19[^\n]", temp.vrstaMjenjaca);
	for (int i = 0; temp.vrstaMjenjaca[i] != '\0'; i++) {
		temp.vrstaMjenjaca[i] = toupper(temp.vrstaMjenjaca[i]);
	}

	do {
		printf("Unesite koliko stupnjeva prijenosa ima mjenjac:");
		scanf("%d", &temp.stupnjeviPrijenosa);
	} while (temp.stupnjeviPrijenosa < 3 || temp.stupnjeviPrijenosa>11);

	do {
		printf("Unesite kilometrazu vozila:");
		scanf("%d", &temp.kilometraza);
	} while (temp.kilometraza < 0 || temp.kilometraza>1000000);

	do {
		printf("Unesite obujam motora u cm kubnim:");
		scanf("%lf", &temp.obujamMotora);

	} while (temp.obujamMotora < 0 || temp.obujamMotora>12000);

	do {
		printf("Unesite snagu motora u kW:");
		scanf("%d", &temp.snagaMotora);
	} while (temp.snagaMotora < 0 || temp.snagaMotora>5000);

	do {
		printf("Unesite cijenu vozila u eurima:");
		scanf("%lf", &temp.cijena);
	} while (temp.cijena < 0 || temp.cijena >10000000);
	
	
	fseek(fP, sizeof(int) + sizeof(VOZILO) * brojVozila, SEEK_SET);
	fwrite(&temp, sizeof(VOZILO), 1, fP);
	rewind(fP);
	brojVozila++;
	fwrite(&brojVozila, sizeof(int), 1, fP);
	fclose(fP);
	
}


void azuriranjeVozila(){
	int pin;
	int id;
	char provjera;
	printf("Unesite administratorski pin:");
	scanf("%d", &pin);
	if (pin != 3009) {
		printf("Kriva lozinka, nemate pristup unosu novih vozila.\n");
		return;
	}

	

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

	if (brojVozila == 0) {
		printf("Nema unesenih vozila, ne mozete koristiti funkciju azuriranje vozila.\n");
		return;
	}


	VOZILO* temp = NULL;
	VOZILO* old = NULL;
	temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));
	old = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));
	fread(temp, sizeof(VOZILO), brojVozila, fP);
	memcpy(old, temp, sizeof(VOZILO) * brojVozila);
	printf("Broj Vozila na stanju je: %d\n", brojVozila);

	printf("\nUnesite ID vozila koje zelite azurirati:");
	do {
		if (scanf("%d", &id) != 1) {
			printf("\nNeispravan unos. Molimo unesite broj.\n");
			while (getchar() != '\n');
			continue;
		}
		if (id<0 || id>(temp + (brojVozila - 1))->redniBrUSustavu) {
			printf("\nNepostojeci id, ponovite unos:");
		}

	} while (id<0 || id>(temp + (brojVozila - 1))->redniBrUSustavu);


	printf("Odabrali ste azurirati ovo vozilo:\n\n");
	ispis(temp, id);

	printf("Jeste li sigurni?\nAko jeste unesite Y, a ako niste unesite n:");
	do {
		scanf(" %c", &provjera);
		if (provjera != 'Y' && provjera != 'n') {
			printf("\nKrivi unos, unesite Y za da ili unesite n za ne:");
		}
	} while (provjera != 'Y' && provjera != 'n');


	

	if (provjera == 'Y') {

		printf("\nUkoliko ne zelite naciniti promjene u odredenom kriteriju vozila unesite vrijednost 0.\n\n");

		printf("\n\nUnesite marku vozila:");
		scanf(" %19[^\n]", (temp + id)->markaVozila);
		for (int i = 0; (temp + id)->markaVozila[i] != '\0'; i++) {
			(temp + id)->markaVozila[i] = toupper((temp + id)->markaVozila[i]);
		}
		if (strcmp((temp + id)->markaVozila, "0") == 0) {

			strcpy((temp + id)->markaVozila, (old + id)->markaVozila);
		}
		printf("Unesite model vozila:");
		scanf(" %19[^\n]", (temp + id)->nazivModelaVozila);
		for (int i = 0; (temp + id)->nazivModelaVozila[i] != '\0'; i++) {
			(temp + id)->nazivModelaVozila[i] = toupper((temp + id)->nazivModelaVozila[i]);
		}
		if (strcmp((temp + id)->nazivModelaVozila, "0") == 0) {

			strcpy((temp + id)->nazivModelaVozila, (old + id)->nazivModelaVozila);
		}
		printf("Unesite tip karoserije vozila:");
		scanf(" %19[^\n]", (temp + id)->karoserijaVozila);
		for (int i = 0; (temp + id)->karoserijaVozila[i] != '\0'; i++) {
			(temp + id)->karoserijaVozila[i] = toupper((temp + id)->karoserijaVozila[i]);
		}
		if (strcmp((temp + id)->karoserijaVozila, "0") == 0) {

			strcpy((temp + id)->karoserijaVozila, (old + id)->karoserijaVozila);
		}
		printf("Unesite godinu proizvodnje:");
		scanf("%d", &(temp + id)->godinaProizvdnje);
		if ((temp + id)->godinaProizvdnje == 0) {

			(temp + id)->godinaProizvdnje = (old + id)->godinaProizvdnje;
		}
		printf("Unesite stanje vozila:");
		scanf(" %19[^\n]", (temp + id)->stanje);
		for (int i = 0; (temp + id)->stanje[i] != '\0'; i++) {
			(temp + id)->stanje[i] = toupper((temp + id)->stanje[i]);
		}
		if (strcmp((temp + id)->stanje, "0") == 0) {

			strcpy((temp + id)->stanje, (old + id)->stanje);
		}
		printf("Unesite broj sasije:");
		scanf(" %19[^\n]", (temp + id)->brojSasije);
		for (int i = 0; (temp + id)->brojSasije[i] != '\0'; i++) {
			(temp + id)->brojSasije[i] = toupper((temp + id)->brojSasije[i]);
		}
		if (strcmp((temp + id)->brojSasije, "0") == 0) {

			strcpy((temp + id)->brojSasije, (old + id)->brojSasije);
		}
		printf("Unesite vrstu motora:");
		scanf(" %19[^\n]", (temp + id)->vrstaMotora);
		for (int i = 0; (temp + id)->vrstaMotora[i] != '\0'; i++) {
			(temp + id)->vrstaMotora[i] = toupper((temp + id)->vrstaMotora[i]);
		}
		if (strcmp((temp + id)->vrstaMotora, "0") == 0) {

			strcpy((temp + id)->vrstaMotora, (old + id)->vrstaMotora);
		}
		printf("Unesite vrstu mjenjaca:");
		scanf(" %19[^\n]", (temp + id)->vrstaMjenjaca);
		for (int i = 0; (temp + id)->vrstaMjenjaca[i] != '\0'; i++) {
			(temp + id)->vrstaMjenjaca[i] = toupper((temp + id)->vrstaMjenjaca[i]);
		}
		if (strcmp((temp + id)->vrstaMjenjaca, "0") == 0) {

			strcpy((temp + id)->vrstaMjenjaca, (old + id)->vrstaMjenjaca);
		}

		printf("Unesite koliko stupnjeva prijenosa ima mjenjac:");
		scanf("%d", &(temp + id)->stupnjeviPrijenosa);
		if ((temp + id)->stupnjeviPrijenosa == 0) {

			(temp + id)->stupnjeviPrijenosa = (old + id)->stupnjeviPrijenosa;
		}
		printf("Unesite kilometrazu vozila:");
		scanf("%d", &(temp + id)->kilometraza);
		if ((temp + id)->kilometraza == 0) {

			(temp + id)->kilometraza = (old + id)->kilometraza;
		}
		printf("Unesite obujam motora u cm kubnim:");
		scanf("%lf", &(temp + id)->obujamMotora);
		if ((temp + id)->obujamMotora == 0) {

			(temp + id)->obujamMotora = (old + id)->obujamMotora;
		}
		printf("Unesite snagu motora u kW:");
		scanf("%d", &(temp + id)->snagaMotora);
		if ((temp + id)->snagaMotora == 0) {

			(temp + id)->snagaMotora = (old + id)->snagaMotora;
		}
		printf("Unesite cijenu vozila u eurima:");
		scanf("%lf", &(temp + id)->cijena);
		if ((temp + id)->cijena == 0) {

			(temp + id)->cijena = (old + id)->cijena;
		}


		fseek(fP, sizeof(int) + sizeof(VOZILO) * id, SEEK_SET);
		fwrite(&temp[id], sizeof(VOZILO), 1, fP);
		
	}
	else if (provjera == 'n') {

		printf("Azuriranje otkazano.\n");
		
	}

	free(temp);
	free(old);
	fclose(fP);

	return;


}

void brisanjeVozila() {
	int pin;
	int id;
	char provjera;
	int i;
	printf("Unesite administratorski pin:");
	scanf("%d", &pin);
	if (pin != 3009) {
		printf("Kriva lozinka, nemate pristup unosu novih vozila.\n");
		return;
	}
	

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

	if (brojVozila == 0) {
		printf("Nema unesenih vozila, ne mozete koristiti funkciju brisanje vozila.\n");
		return;
	}


	VOZILO* temp = NULL;
	temp = (VOZILO*)calloc(brojVozila, sizeof(VOZILO));
	fread(temp, sizeof(VOZILO), brojVozila, fP);
	printf("Broj Vozila na stanju je: %d\n", brojVozila);

	printf("\nUnesite ID vozila koje zelite obrisati:");
	do {
		if (scanf("%d", &id) != 1) {
			printf("\nNeispravan unos. Molimo unesite broj.\n");
			while (getchar() != '\n');
			continue;
		}
		if (id<0 || id>(temp + (brojVozila - 1))->redniBrUSustavu) {
			printf("\nNepostojeci id, ponovite unos:");
		}
		
	} while (id<0 || id>(temp + (brojVozila - 1))->redniBrUSustavu);


	printf("Obrisati ce te ovo vozilo:\n\n");
	ispis(temp, id);


	printf("Jeste li sigurni?\nAko jeste unesite Y, a ako niste unesite n:");
	do {
		scanf(" %c", &provjera);
		if (provjera != 'Y' && provjera != 'n') {
			printf("\nKrivi unos, unesite Y za da ili unesite n za ne:");
		}
	} while (provjera != 'Y' && provjera != 'n');
	
	if (provjera == 'Y') {

		fseek(fP, brojVozila, SEEK_SET);
		
		for (i = id + 1; i < brojVozila; i++) {
			fread(&temp[i - 1], sizeof(VOZILO), 1, fP); 
			fseek(fP, id * sizeof(VOZILO), SEEK_SET); 
			fwrite(&temp[i - 1], sizeof(VOZILO), 1, fP); 
			fseek(fP, (i * sizeof(VOZILO)), SEEK_SET); 
		}

		brojVozila--;

		printf("Vozilo s ID-jem %d je obrisano.\n", id);

		
		fseek(fP, 0, SEEK_SET);
		fwrite(&brojVozila, sizeof(int), 1, fP);
	}
	else if (provjera == 'n') {
		printf("Brisanje otkazano.\n");
	}
	
	
	free(temp);
	fclose(fP);
	
	return;

}

void pregledVozila() {

	int uvjet;

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

	if (brojVozila == 0) {
		printf("Nema unesenih vozila, kako bi mogli koristiti ovu funkciju prvo morate unjeti vozilo.\n");
		return;
	}

	while (1) {

		system("cls");
		printf("=================================IZBORNIK ZA PRETRAGU VOZILA======================================\n");
		printf("==================================================================================================\n");
		printf("\t\t\t1.Pregled svih vozila.\n\
                \t2.Pregled vozila unosom marke vozila.\n\
                \t3.Pregled vozila unosom oblika karoserije.\n\
                \t4.Pregled vozila unosom raspona godini proizvodnje.\n\
                \t5.Pregled vozila unosom raspona snage u kW.\n\
                \t6.Pregled vozila unosom raspona kilometara u km.\n\
                \t7.Pregled vozila po tipu motora.\n\
                \t8.Pregled vozila po tipu mjenjaca.\n\
                \t9.Pregled Vozila po rasponu cijene.\n\
                \t10.Vracanje u glavni izbornik\n");
		printf("==================================================================================================\n");
		printf("==================================================================================================\n");


		printf("\nOdaberite radnju koju zelite:");
		if (scanf("%d", &uvjet) != 1) {
			printf("\nNeispravan unos. Molimo unesite broj.\n");
			while (getchar() != '\n');
			continue;
		}

		switch (uvjet) {

		case 1:ispisSvihVozila(); break;
		case 2:pregledVozilaMarka(); break;
		case 3:pregledVozilaKaroserija();  break;
		case 4:pregledVozilaGodine();  break;
		case 5:pregledVozilaSnaga(); break;
		case 6:pregledVozilaKilometri();  break;
		case 7:pregledVozilaMotor(); break;
		case 8:pregledVozilaMjenjac();  break;
		case 9:pregledVozilaCijena(); break;
		case 10:return;
		default: printf("Krivi unos.\n"); break;



		}system("pause");


	}



}