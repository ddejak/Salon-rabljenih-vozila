#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "funkcije.h"
#include "strukture.h"


static int brojVozila = 0;


inline int usporedbaMarkeZaQSort(const void* a, const void* b) {
	VOZILO* voziloA = (VOZILO*)a;
	VOZILO* voziloB = (VOZILO*)b;
	return strcmp(voziloA->markaVozila, voziloB->markaVozila);
}

void sortiranjeAbecedno() {
	VOZILO* vozila;
	size_t result;

	FILE* fP = fopen("vozila.bin", "rb");
	if (fP == NULL) {
		perror("Greska kod otvaranja datoteke");
		exit(EXIT_FAILURE);
	}

	result = fread(&brojVozila, sizeof(int), 1, fP);
	if (result != 1) {
		perror("Greska kod citanja broja vozila");
		fclose(fP);
		exit(EXIT_FAILURE);
	}

	vozila = (VOZILO*)malloc(brojVozila * sizeof(VOZILO));
	if (vozila == NULL) {
		perror("Nedovoljno memorije");
		fclose(fP);
		exit(EXIT_FAILURE);
	}

	result = fread(vozila, sizeof(VOZILO), brojVozila, fP);
	if (result != (size_t)brojVozila) {
		perror("Greska pri citanju podataka vozila\n");
		free(vozila);
		fclose(fP);
		exit(EXIT_FAILURE);
	}
	fclose(fP);

	qsort(vozila, brojVozila, sizeof(VOZILO), usporedbaMarkeZaQSort);

	fP = fopen("vozila.bin", "wb");
	if (fP == NULL) {
		perror("Ne mogu otvoriti datoteku za pisanje\n");
		free(vozila);
		exit(EXIT_FAILURE);
	}

	result = fwrite(&brojVozila, sizeof(int), 1, fP);
	if (result != 1) {
		perror("Greska pri pisanju broja vozila\n");
		free(vozila);
		fclose(fP);
		exit(EXIT_FAILURE);
	}

	result = fwrite(vozila, sizeof(VOZILO), brojVozila, fP);
	if (result != (size_t)brojVozila) {
		perror("Greska pri pisanju podataka vozila\n");
		free(vozila);
		fclose(fP);
		exit(EXIT_FAILURE);
	}

	fclose(fP);
	free(vozila);

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
		printf("Unesite godinu proizvodnje vozila:");
		if (scanf("%d", &temp.godinaProizvdnje) != 1) {
			while (getchar() != '\n');
			continue;
		}
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
		if (scanf("%d", &temp.stupnjeviPrijenosa) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (temp.stupnjeviPrijenosa < 3 || temp.stupnjeviPrijenosa>11);

	do {
		printf("Unesite kilometrazu vozila:");
		if (scanf("%d", &temp.kilometraza) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (temp.kilometraza < 0 || temp.kilometraza>1000000);

	do {
		printf("Unesite obujam motora u cm kubnim:");
		if (scanf("%lf", &temp.obujamMotora) != 1) {
			while (getchar() != '\n');
			continue;
		}

	} while (temp.obujamMotora < 0 || temp.obujamMotora>12000);

	do {
		printf("Unesite snagu motora u kW:");
		if (scanf("%d", &temp.snagaMotora) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (temp.snagaMotora < 0 || temp.snagaMotora>1500);

	do {
		printf("Unesite cijenu vozila u eurima:");
		if (scanf("%lf", &temp.cijena) != 1) {
			while (getchar() != '\n');
			continue;
		}
	} while (temp.cijena < 0 || temp.cijena > 10000000);

	
	
	fseek(fP, sizeof(int) + sizeof(VOZILO) * brojVozila, SEEK_SET);
	fwrite(&temp, sizeof(VOZILO), 1, fP);
	rewind(fP);
	brojVozila++;
	fwrite(&brojVozila, sizeof(int), 1, fP);
	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}


	sortiranjeAbecedno();
	

	return;
}


void azuriranjeVozila(){
	int pin;
	int id;
	char provjera;
	int flag = 0;
	int index = -1;
	int i = 0;
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

	printf("\nNa stanju su vozila s ovim ID-evima:");
	for (i = 0; i < brojVozila; i++) {
		printf("%d", (temp + i)->redniBrUSustavu);
		if (i != (brojVozila-1)) {
			printf(",");
		}
	}


	printf("\nUnesite ID vozila koje zelite azurirati:");
	do {
		if (scanf("%d", &id) != 1) {
			printf("\nNeispravan unos. Molimo unesite broj.\n");
			while (getchar() != '\n');
			continue;
		}
		index = -1;
		for (i = 0; i < brojVozila; i++) {
			index++;
			if (id == (temp + i)->redniBrUSustavu) {
				flag = 1;
				break;
			}
		}
		if (id < 0 || flag == 0) {
			printf("\nNepostojeci id, ponovite unos:");

		}

	} while (id < 0 || flag == 0);


	printf("Odabrali ste azurirati ovo vozilo:\n\n");
	ispis(temp, index);

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
		scanf(" %19[^\n]", (temp + index)->markaVozila);
		for ( i = 0; (temp + index)->markaVozila[i] != '\0'; i++) {
			(temp + index)->markaVozila[i] = toupper((temp + index)->markaVozila[i]);
		}
		if (strcmp((temp + index)->markaVozila, "0") == 0) {

			strcpy((temp + index)->markaVozila, (old + index)->markaVozila);
		}
		printf("Unesite model vozila:");
		scanf(" %19[^\n]", (temp + index)->nazivModelaVozila);
		for ( i = 0; (temp + index)->nazivModelaVozila[i] != '\0'; i++) {
			(temp + index)->nazivModelaVozila[i] = toupper((temp + index)->nazivModelaVozila[i]);
		}
		if (strcmp((temp + index)->nazivModelaVozila, "0") == 0) {

			strcpy((temp + index)->nazivModelaVozila, (old + index)->nazivModelaVozila);
		}
		printf("Unesite tip karoserije vozila:");
		scanf(" %19[^\n]", (temp + index)->karoserijaVozila);
		for ( i = 0; (temp + index)->karoserijaVozila[i] != '\0'; i++) {
			(temp + index)->karoserijaVozila[i] = toupper((temp + index)->karoserijaVozila[i]);
		}
		if (strcmp((temp + index)->karoserijaVozila, "0") == 0) {

			strcpy((temp + index)->karoserijaVozila, (old + index)->karoserijaVozila);
		}

		do {
			printf("Unesite godinu proizvodnje vozila:");
			if (scanf("%d", &(temp+index)->godinaProizvdnje) != 1) {
				while (getchar() != '\n');
				continue;
			}
			if ((temp + index)->godinaProizvdnje == 0) {

				(temp + index)->godinaProizvdnje = (old + index)->godinaProizvdnje;
			}
		} while ((temp + index)->godinaProizvdnje == 0 || (temp + index)->godinaProizvdnje < 1920 || (temp + index)->godinaProizvdnje>2025);
		

		printf("Unesite stanje vozila:");
		scanf(" %19[^\n]", (temp + index)->stanje);
		for ( i = 0; (temp + index)->stanje[i] != '\0'; i++) {
			(temp + index)->stanje[i] = toupper((temp + index)->stanje[i]);
		}
		if (strcmp((temp + index)->stanje, "0") == 0) {

			strcpy((temp + index)->stanje, (old + index)->stanje);
		}
		printf("Unesite broj sasije:");
		scanf(" %19[^\n]", (temp + index)->brojSasije);
		for ( i = 0; (temp + index)->brojSasije[i] != '\0'; i++) {
			(temp + index)->brojSasije[i] = toupper((temp + index)->brojSasije[i]);
		}
		if (strcmp((temp + index)->brojSasije, "0") == 0) {

			strcpy((temp + index)->brojSasije, (old + index)->brojSasije);
		}
		printf("Unesite vrstu motora:");
		scanf(" %19[^\n]", (temp + index)->vrstaMotora);
		for ( i = 0; (temp + index)->vrstaMotora[i] != '\0'; i++) {
			(temp + index)->vrstaMotora[i] = toupper((temp + index)->vrstaMotora[i]);
		}
		if (strcmp((temp + index)->vrstaMotora, "0") == 0) {

			strcpy((temp + index)->vrstaMotora, (old + index)->vrstaMotora);
		}
		printf("Unesite vrstu mjenjaca:");
		scanf(" %19[^\n]", (temp + index)->vrstaMjenjaca);
		for ( i = 0; (temp + index)->vrstaMjenjaca[i] != '\0'; i++) {
			(temp + index)->vrstaMjenjaca[i] = toupper((temp + index)->vrstaMjenjaca[i]);
		}
		if (strcmp((temp + index)->vrstaMjenjaca, "0") == 0) {

			strcpy((temp + index)->vrstaMjenjaca, (old + index)->vrstaMjenjaca);
		}


		do {
			printf("Unesite koliko stupnjeva prijenosa ima mjenjac:");
			if (scanf("%d", &(temp + index)->stupnjeviPrijenosa) != 1) {
				while (getchar() != '\n');
				continue;
			}
			if ((temp + index)->stupnjeviPrijenosa == 0) {

				(temp + index)->stupnjeviPrijenosa = (old + index)->stupnjeviPrijenosa;
			}
		} while ((temp + index)->stupnjeviPrijenosa < 3 || (temp + index)->stupnjeviPrijenosa>11 || (temp + index)->stupnjeviPrijenosa == 0);
		if ((temp + index)->stupnjeviPrijenosa == 0) {

			(temp + index)->stupnjeviPrijenosa = (old + index)->stupnjeviPrijenosa;
		}



		
		do {
			printf("Unesite kilometrazu vozila:");
			if (scanf("%d", &(temp + index)->kilometraza) != 1) {
				while (getchar() != '\n');
				continue;
			}
		} while ((temp + index)->kilometraza < -1 || (temp + index)->kilometraza>1000000);
		if ((temp + index)->kilometraza == 0) {

			(temp + index)->kilometraza = (old + index)->kilometraza;
		}


		
		do {
			printf("Unesite obujam motora u cm kubnim:");
			if (scanf("%lf", &(temp + index)->obujamMotora) != 1) {
				while (getchar() != '\n');
				continue;
			}

		} while ((temp + index)->obujamMotora < -1 || (temp + index)->obujamMotora>12000);
		if ((temp + index)->obujamMotora == 0) {

			(temp + index)->obujamMotora = (old + index)->obujamMotora;
		}


		
		do {
			printf("Unesite snagu motora u kW:");
			if (scanf("%d", &(temp + index)->snagaMotora) != 1) {
				while (getchar() != '\n');
				continue;
			}
		} while ((temp + index)->snagaMotora < -1 || (temp + index)->snagaMotora>1500);
		if ((temp + index)->snagaMotora == 0) {

			(temp + index)->snagaMotora = (old + index)->snagaMotora;
		}


		
		do {
			printf("Unesite cijenu vozila u eurima:");
			if (scanf("%lf", &(temp + index)->cijena) != 1) {
				while (getchar() != '\n');
				continue;
			}
		} while ((temp + index)->cijena < -1 || (temp + index)->cijena >10000000);
		if ((temp + index)->cijena == 0) {

			(temp + index)->cijena = (old + index)->cijena;
		}
		

		fseek(fP, sizeof(int) + sizeof(VOZILO) * index, SEEK_SET);
		fwrite(&temp[index], sizeof(VOZILO), 1, fP);
		
	}
	else if (provjera == 'n') {

		printf("Azuriranje otkazano.\n");
		
	}

	free(temp);
	temp = NULL;
	free(old);
	old = NULL;
	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}

	sortiranjeAbecedno();

	return;


}


void brisanjeVozila() {
	int pin;
	int id;
	char provjera;
	int i;
	int flag = 0;
	int index = -1;
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

	printf("\nNa stanju su vozila s ovim ID-evima:");
	for (i = 0; i < brojVozila; i++) {
		printf("%d", (temp + i)->redniBrUSustavu);
		if (i != (brojVozila - 1)) {
			printf(",");
		}
	}


	printf("\nUnesite ID vozila koje zelite obrisati:");
	do {
		if (scanf("%d", &id) != 1) {
			printf("\nNeispravan unos. Molimo unesite broj.\n");
			while (getchar() != '\n');
			continue;
		}
		index = -1;
		for (i = 0; i < brojVozila; i++) {
			index++;
			if (id == (temp + i)->redniBrUSustavu) {
				flag = 1;
				break;
			}
		}
		if (id<0 || flag == 0) {
			printf("\nNepostojeci id, ponovite unos:");

		}

	} while (id<0 || flag==0);


	printf("Obrisati ce te ovo vozilo:\n\n");
	ispis(temp, index);


	printf("Jeste li sigurni?\nAko jeste unesite Y, a ako niste unesite n:");
	do {
		scanf(" %c", &provjera);
		if (provjera != 'Y' && provjera != 'n') {
			printf("\nKrivi unos, unesite Y za da ili unesite n za ne:");
		}
	} while (provjera != 'Y' && provjera != 'n');

	if (provjera == 'Y') {

		VOZILO tempVozilo;
		for (i = index + 1; i < brojVozila; i++) {
			fseek(fP, i * sizeof(VOZILO) + sizeof(int), SEEK_SET);
			fread(&tempVozilo, sizeof(VOZILO), 1, fP);
			fseek(fP, (i-1) * sizeof(VOZILO) + sizeof(int), SEEK_SET);
			fwrite(&tempVozilo, sizeof(VOZILO), 1, fP);
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
	temp = NULL;
	if (fclose(fP) != 0) {
		perror("Greska pri zatvaranju datoteke");
		exit(EXIT_FAILURE);
	}
	

	sortiranjeAbecedno();

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

		case ISPIS_SVE:ispisSvihVozila(); break;
		case PREGLED_MARKA:pregledVozilaMarka(); break;
		case PREGLED_KAROSERIJA:pregledVozilaKaroserija();  break;
		case PREGLED_GODINE:pregledVozilaGodine();  break;
		case PREGLED_SNAGA:pregledVozilaSnaga(); break;
		case PREGLED_KILOMETRI:pregledVozilaKilometri();  break;
		case PREGLED_MOTOR:pregledVozilaMotor(); break;
		case PREGLED_MJENJAC:pregledVozilaMjenjac();  break;
		case PREGLED_CIJENA:pregledVozilaCijena(); break;
		case POVRATAK_GLAVNI_IZBORNIK:return;
		default: printf("Krivi unos.\n"); break;



		}system("pause");


	}



}