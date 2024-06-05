#pragma once




typedef struct {

	
	char vrstaMotora[20];//
	char vrstaMjenjaca[20];//
	char karoserijaVozila[20];//
	char markaVozila[20];//
	char nazivModelaVozila[20];//
	char brojSasije[20];//
	char stanje[20];//
	double obujamMotora;
	double cijena;//
	int godinaProizvdnje;//
	int stupnjeviPrijenosa;//
	int snagaMotora;//
	int kilometraza;//
	int redniBrUSustavu;//


}VOZILO;


enum naredba_dva {
	ISPIS_SVE = 1,
	PREGLED_MARKA,
	PREGLED_KAROSERIJA,
	PREGLED_GODINE,
	PREGLED_SNAGA,
	PREGLED_KILOMETRI,
	PREGLED_MOTOR,
	PREGLED_MJENJAC,
	PREGLED_CIJENA,
	POVRATAK_GLAVNI_IZBORNIK
};


enum naredba {
	PREGLED_VOZILA = 1,
	UNOS_NOVOG_VOZILA,
	AZURIRANJE_VOZILA,
	BRISANJE_VOZILA,
	UGASI_PROGRAM
};

