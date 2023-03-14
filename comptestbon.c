#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int liste[6];
int resultat;

void init() {
	srand(time(NULL));
	for (int i=0 ; i<6 ;i++) {
		liste[i] = (rand()%9)+1;
	}
	resultat = rand()%1000;
}

struct Operation{
	int nbre1;
	int nbre2;
	int operation;
};

struct Path {
	struct Operation operations[6];
	int total;
};



void affichage2(struct Path path){
	for (int i=0 ; i<5 ; i++) {
		printf("etape %d : %d",i+1,path.operations[i].nbre1);
		switch (path.operations[i].operation) {
			case 0 :
				printf(" +");
				printf(" %d",path.operations[i].nbre2);
				printf(" = %d\n",path.operations[i].nbre1 + path.operations[i].nbre2);
				break;
			case 1 :
				printf(" *");
				printf(" %d",path.operations[i].nbre2);
				printf(" = %d\n",path.operations[i].nbre1 * path.operations[i].nbre2);
				break;
			case 2 :
				printf(" -");
				printf(" %d",path.operations[i].nbre2);
				printf(" = %d\n",path.operations[i].nbre1 - path.operations[i].nbre2);
				break;
			case 3 :
				printf(" /");
				printf(" %d",path.operations[i].nbre2);
				printf(" = %d\n",path.operations[i].nbre1 / path.operations[i].nbre2);
				break;
		}

	}
}


void affichage1(){
	printf("la liste initiale est : ");
	for (int i=0; i<6; i++){
		printf("%d ", liste[i]);
	}
	printf("\net le resultat a trouver est %d\n",resultat);
}

struct Path search(int nbres[], int taille){
	struct Path result;
	struct Path bestresult;
	bestresult.total =999999999;

	// Si reste 1 seul élement ou bien si on a trouv
	// le résultat
	//if((taille==1) || (nbres[0]==resultat)){ //version qui n'utilise pas forcement tout les chiffres
	if (taille == 1) { // version qui utilise tout les chiffres
		result.total = nbres[0];
		return result;
	}

	for(int i = 0; i<taille-1; i++) {
		for(int j = i+1; j<taille; j++) {
			int temp = -1;
			int nbre1 = 0;
			int nbre2 = 0;

			// Test des 4 opérations
			for(int operation=0; operation<4; operation++){
				switch(operation){
					case 0: // +
						temp = nbres[i] + nbres[j];
						nbre1 = nbres[i];
						nbre2 = nbres[j];
						break;
					case 1: // *
						temp = nbres[i] * nbres[j];
						nbre1 = nbres[i];
						nbre2 = nbres[j];
						break;
					case 2: // -
						if (nbres[i]>nbres[j]){
							temp = nbres[i] - nbres[j];
							nbre1 = nbres[i];
							nbre2 = nbres[j];
						} else {
							temp = nbres[j] - nbres[i];
							nbre1 = nbres[j];
							nbre2 = nbres[i];
						}
						break;
					case 3: // /
						if ((nbres[i]==0) || (nbres[j]==0)) temp=0;
						else if (nbres[i]>nbres[j]){
							if (nbres[i]%nbres[j]==0){
								temp = nbres[i] / nbres[j];
								nbre1 = nbres[i];
								nbre2 = nbres[j];
							}
						}
						else {
							if (nbres[j]%nbres[i]==0){
								temp = nbres[j] / nbres[i];
								nbre1 = nbres[j];
								nbre2 = nbres[i];
							}
						}
				} // switch

				// Appel recursif
				if (temp!=-1){
					int tab[taille],compteur;
					compteur = 0;
 					tab[0] = temp;
 					for (int n=1; n<taille ; n++) {
						if ((n != i) && (n != j)) {
						compteur++;
						tab[compteur] = nbres[n];
						}
					}

					result = search(tab,taille-1);
					if ((abs(resultat-result.total)) < (abs(resultat-bestresult.total))) {
						bestresult = result;
						bestresult.operations[6-taille].nbre1 = nbre1;
						bestresult.operations[6-taille].nbre2 = nbre2;
						bestresult.operations[6-taille].operation = operation;
					}
				}
			}
		}
	}

	// Renvoi le résultat ainsi que la liste des opérations
	// mise à jour
	return bestresult;
}

int main(){
	struct Path result;
	init();
	affichage1();
	result = search(liste,6);
	affichage2(result);
	return 0;
}
