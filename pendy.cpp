#include <iostream>
#include <string> 
#include <cctype>
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include <fstream>

 
// Fonction definissant le choix du mot via un nombre random
std::string choix_mot(std::vector<std::string> mot) {
	std::string chaine;
	int v1 = rand() % mot.size();
	int choix = 0;
	for (auto i = mot.begin(); i != mot.end(); ++i) {  // Boucle faisant le scrolling de tous les mots 
		if (choix == v1) { // Choix en fonction du chiffre random 
			chaine = *i;
		};
		choix++;
	};

	return chaine; // Retourne le mot choisit

};

// Fonction main
int main() {
	std::string chaine;
	srand(time(NULL)); // Intégration du random via le temps 
	std::vector<std::string> mot;

	std::ifstream monFlux("Text.txt"); // Mise d'un texte a lire dans le ifstream 

	if (monFlux)
	{
		std::string ligne;
		while (std::getline(monFlux, ligne))  // Lire ligne par ligne
		{
			mot.push_back(ligne);  // Mettre toutes les lignes dans le vector
		}
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
	}

	while (1) {

		chaine = choix_mot(mot);  // Appel de la fonction pour choisir le mot

		int tentative = 0; // Implémentation du nombre de tentative

		std::cout << "-----------------------------	\n"
					"Le jeu du pendu.				\n"
					"-----------------------------	\n" << std::endl;


		for (int i = 0; i < chaine.length(); i++) {  // Mise en minuscule de la chaine de caractère
			chaine[i] = tolower(chaine[i]);
		}

		std::string chaine_pass = std::string(chaine.length(), '*'); // Création d'un nombre d'* en fonction de la taille de la chaine
		

		while (1) {
			char letter;
			int longueur_onde = chaine.length(); 

			if (chaine == chaine_pass) {  // Condition en cas de victoire
				std::cout << "Bien joue c'etait : " << chaine << std::endl;
				std::cout << "Nombre de tentative : " << tentative << std::endl;
				break;
			}
			std::cout << "Donner une lettre : " << std::endl;
			std::cout << "> ";
			std::cin >> letter;  // Demande de lettre à l'utilisateur

			letter = tolower(letter);  // Mise de la lettre en minuscule

			int letter_ascii = static_cast<int>(letter); // Mise du char en int pour faire la comparaison

			if (letter_ascii >= 97 && letter_ascii <= 122) {  // Etre sur que la lettre est en minuscule
				for (int i = 0; i < longueur_onde; i++) {
					int a = static_cast<int>(letter);
					int b = chaine[i];

					if (a == b) {
						chaine_pass[i] = static_cast<char>(a);
					};
				};
				std::cout << chaine_pass << std::endl;
				tentative++; // Itération sur le nombre de tentative
			};
		};
		int Choix_User;
		std::cout << "-----------------------------		\n"
				"Nouvelle partie ?			\n"
				"	1 = OUI				\n"
				"	0 = NON				\n"
				"-----------------------------		\n" << std::endl;
		std::cout << "> ";
		std::cin >> Choix_User;
		if (Choix_User == 1) {
			std::cout << "Nouvelle Partie lancee" << std::endl;
		}
		else {
			std::cout << "Arret de la partie" << std::endl;
			return 0;
		} 
	}; 
	return 0;
};
