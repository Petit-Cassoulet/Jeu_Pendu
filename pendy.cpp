#include <iostream>
#include <string> 
#include <cctype>
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include <fstream>


using namespace std;

int main(){
	string chaine;
	srand (time(NULL));
	vector<string> mot; 
  
	ifstream monFlux("word.txt"); 

		if(monFlux)
		{
			string ligne; 
			while(getline(monFlux, ligne))
			{
				mot.push_back(ligne); 
			}
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		}
	
	while(1){
		int v1 = rand() % mot.size();  
		int choix = 0;
		for (auto i = mot.begin(); i != mot.end(); ++i){
			if(choix == v1){
				chaine = *i; 
			};
			choix++;
		};

		unsigned int tentative = 0;

		cout << "-----------------------------	\n" 
				"	   							                  \n"
				"	   Le jeu du pendu.			          \n"	
				"								                    \n"	
				"-----------------------------	    \n" << endl;
			
		
		for(int i = 0; i < chaine.length(); i++){
			chaine[i] = tolower(chaine[i]);
		}

		string chaine_pass = string(chaine.length(), '*');
		cout << "Donner une lettre : " << endl;
		
		while(1){
			char letter;
			unsigned int longueur_onde = chaine.length();
			
			if(chaine == chaine_pass){
				  cout << "Bien joué c'etait : " << chaine << endl;
				  cout << "Nombre de tentative : " << tentative << endl;
				  break;
			}
			
			cout << "> "  ;
			cin >> letter;
				
			letter = tolower(letter);
			
			unsigned int letter_ascii = static_cast<int>(letter);
				
			if(letter_ascii >= 97 && letter_ascii <= 122){
				for(unsigned int i = 0;  i < longueur_onde; i++){
					int a = static_cast<int>(letter);
					int b = chaine[i];
						
					if(a == b){
						chaine_pass[i] = static_cast<char>(a);
					};
				};
				cout << chaine_pass << endl;
				tentative++;
				};
		};
	int Choix_User;
	cout << "-----------------------------	\n" 
			"	   Nouvelle partie ?		\n"	
			"				1 = OUI			\n"	
			"				0 = NON			\n"	
			"-----------------------------	\n" << endl;
	cout << "> ";
	cin >> Choix_User;
	if(Choix_User == 1){
		cout << "Nouvelle Partie lancée" << endl;
	}
	else{
		cout << "Arrêt de la partie" << endl;
		return 0;
	}
	
	};
	
	

	return 0;
};