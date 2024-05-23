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



