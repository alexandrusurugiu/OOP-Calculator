#include <stdio.h>
#include <malloc.h>
#include <string.h>



int* citireVector(int* n, FILE* file) {
	fscanf(file, "%d", n);
	int* v = (int*)malloc(sizeof(int) * (*n));

	for (int i = 0; i < *n; i++) {
		fscanf(file, "%d", &v[i]);	//in cazul in care vectorul era transmis prin pointer, trebuia sa scrie &(*v[i]) pentru a merge fix la adresa elementului respectiv din vector, 
		//asa mergand la primul element din vector (in cazul in care e transmis prin pointer)
	}

	return v;
}

void afisareVector(int* v, int n) {
	printf("Valorile citite din fisier:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
}

typedef struct Shaorma Shaorma;

struct Shaorma {
	char* tip;
	float pret;
	int nrIngrediente;
};

Shaorma citireShaorma(FILE* fileStream) {
	char buffer[10];	//ne luam un buffer de 10 bytes pentru a stoca cate o variabila de pe fiecare rand, pe masura ce le citim
	Shaorma shaorma;
	fgets(buffer, 10, fileStream);	//aici ii spunem compilatorului ca vrem sa luam maxim 10 bytes, pe rand, din fisierul citit

	char* tip = strtok(buffer, "\n");	//folosim strtok pentru a delimita variabilele citite prin \n
	shaorma.tip = (char*)malloc(sizeof(char) * (strlen(tip) + 1));	//alocam memorie pentru tipul shaormei
	strcpy(shaorma.tip, tip);	//copiem din variabila alocata de noi, "tip" in variabila "obiectului" shaorma

	fgets(buffer, 4, fileStream);
	shaorma.pret = atof(buffer);	//convertim caracterul ascii din fisier in float

	fgets(buffer, 4, fileStream);
	shaorma.nrIngrediente = atoi(buffer);	//convertam caracterul ascii din fisier in int

	return shaorma;
}

void main() {
	//1. Citirea unor valori simple din fisier txt
	int value1, value2;
	FILE* fisier = fopen("fisier.txt", "r");

	if (fisier != NULL) {
		fscanf(fisier, "%d", &value1);	//la functiile de citire ai nevoie de & ca sa citesti de la adresa X, pe cand la cele de scriere nu e nevoie
		fscanf(fisier, "%d", &value2);
	}

	fclose(fisier);
	printf("%d %d", value1, value2);

	//2. Citirea unui vector alocat dinamic din fisier
	FILE* fisier = fopen("fisier.txt", "r");
	int n;
	int* v = NULL;

	if (fisier != NULL) {
		v = citireVector(&n, fisier);
	}

	afisareVector(v, n);
	free(v);
	fclose(fisier);

	//3. Declararea unei structuri si citirea datelor structurii din fisier
	FILE* fisier = fopen("shaorma.txt", "r");
	Shaorma s;

	if (!fisier) {
		printf("Fisierul nu a putut fi gasit!");
		return 0;
	}
	else {
		s = citireShaorma(fisier);	//atribuim "obiectului" shaorma - s - datele citite din fisierul text
	}

	fclose(fisier);
	printf("Tipul ales este: %s", s.tip);
}

