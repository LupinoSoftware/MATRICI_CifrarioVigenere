// Lupi.Giuliano.CIFRARIO_VIGENERE
#include <iostream>
#include <string>
#include <string.h>
#define MAX 100

using namespace std;

void creaMatrice (char matrice[MAX][MAX], int grandezza) {
	char lettera=64;
	grandezza += 1;
	int i, j;
	int c = 0;
	for (i = 0; i < grandezza; i++) {//Righe
		for (j = 0; j < grandezza; j++) {//Colonne
			if (i==0) {
				matrice[i][j] = lettera + j;
			}
			else {
				if (j > 0) {
					if (lettera + j > 90) {
						matrice[i][j]=matrice[0][1+c];
						c++;
					}
					else {matrice[i][j] = lettera + j;}
				}
				else {matrice[i][j] = matrice[j][i];}
			}
		}
		if (i > 0 && j > 0) { 
			lettera++;
			c = 0;
		}
	}
}
//PRIMA RIGA=RIGA PER LE LETTERE DA CIFRARE
//PRIMA COLONNA=COLONNA PER LE LETTERE DELLA CHIAVE
//ANDARE A SOSTITUIRE IL CARATTERE DELLA LETTERA DA DECIFRARE CON IL CARATTERE IN POSIZIONE X(riga)=LETTERA DA DECIFRARE E Y(colonna)=LETTERA DELLA CHIAVE
void visualizzaMatrice(char matrice[MAX][MAX], int grandezza) {
	grandezza += 1;
	for (int i = 0; i < grandezza; i++) {
		for (int j = 0; j < grandezza; j++) {
			cout << matrice[i][j] << " ";
		}
		cout << endl;
	}
}

string creaChiave(int grandezza) {
	string chiave;
	string chiave2;
	string chiaveVerificata;
	int k = 0;
	cout << "Inserisci la chiave di codifica : ";
	getline(cin, chiave);
	if (chiave.length() < grandezza) {
		chiave2.resize(grandezza - chiave.length());
		//cout << chiave2.length();
		for (int i = 0; i < chiave2.length(); i++) {
			chiave2[i] = chiave[k];
			if (k == chiave.length()-1) {
				k = -1;
			}
			k++;
		}
		//cout << chiave2;
		chiaveVerificata = chiave + chiave2;
		//cout << chiaveVerificata;
		return chiaveVerificata;
	}
	else if (chiave.length() > grandezza) {
		for (int k = chiave.length()-1; k > chiave.length()-1 - grandezza; k--) {
			chiave.erase(k);
		}
		//cout << chiave;
		return chiave;
	}
	
}

int main()
{
	char matrice[MAX][MAX];
	creaMatrice(matrice, 26);
	visualizzaMatrice(matrice, 26);
	creaChiave(10);
}
