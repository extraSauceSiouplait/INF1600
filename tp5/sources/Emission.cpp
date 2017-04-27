#include "Emission.h"

#include <fstream>
#include <iostream>

// Constructeur
Emission::Emission(){
    titre = "";
    animateur = "";
    chaine = new Chaine();
}
Emission::Emission (string titre,
                  string animateur,
                  string chaineName,
                  string chaineCodePostal,
                  string chaineAddress) {
    // Emission information
    this->titre = titre;
    this->animateur = animateur;
    this->chaine = new Chaine (chaineName, chaineCodePostal, chaineAddress);
}

// Setters
void Emission::setTitre(string titre) {
    this->titre = titre;
}
void Emission::setAnimateur(string animateur) {
    this->animateur = animateur;
}

// Associer une Chaine à l'Emission
void Emission::associerChaine (Chaine* chaine) {
    this -> chaine = chaine;
}

// Getters
string Emission::getTitre() {
    return this->titre;
}
string Emission::getAnimateur() {
    return this->animateur;
}
Chaine* Emission::getChaine() {
    return this->chaine;
}

// Enregistrer l'Emission dans un fichier
void Emission::saveEmission (string fileName) {

    ofstream outfile (fileName.c_str(), std::ofstream::binary | std::fstream::app);
    // write to outfile
    outfile<<this->titre <<","
                   <<this->animateur <<"\n";
    outfile.close();
}


// Retourne le prochain élément sur la ligne courant dans DB
string Emission::lireProchainElem(string line, int &indiceCourant) {
    string tmp = "";
    
    for (indiceCourant = indiceCourant + 1; indiceCourant < line.length() ; indiceCourant++) {
        if (line[indiceCourant] != ',') {
            tmp += line[indiceCourant];
        }   
        else {
            return tmp;
        }
    }
} 

// Retourne un ptr vers l'émission de la ligne courante dans DB
Emission* Emission::lireEmissionDB(string titreDB, string line, int indiceCourant) {
    // Récupérer le nom de l'animateur
    string animateurDB = lireProchainElem(line, indiceCourant);
    
    //  Récupérer le nom de l'éditeur
    string chaineNameDB = lireProchainElem(line, indiceCourant);
    
    // Récupérer le code postale de l'éditeur
    string chaineCodePostalDB = lireProchainElem(line, indiceCourant);
    
    // Récupérer l'addresse de l'éditeur
    string chaineAddressDB = lireProchainElem(line, indiceCourant);
    
    return new Emission(titreDB, animateurDB, chaineNameDB, chaineCodePostalDB, chaineAddressDB); 
}


// Trouver un Emission avec son nom dans la base de données DB
Emission* Emission::trouverEmission (string DB, string titre) {
     
    ifstream fichier(DB.c_str(), ios::in); // Ouvrir le fichier "DB.txt"
	
    if(fichier)
    {
        string line;
        // Lire les Emissions, un Emission par ligne dans la base de données (DB.txt)
        while (getline(fichier, line)) {
            string titreDB;
            // Récupérer le nom de l'Emission
            int iterateurDeLigne = -1;
            titreDB = lireProchainElem(line,iterateurDeLigne);
            
            // Si l'Emission qu'on lit actuellement est celui qu'on cherche
            if (titreDB == titre) {
                
                // Fermer la base de données
                fichier.close();
                // Retourner l'Emission sélectionné
                return  lireEmissionDB(titreDB, line, iterateurDeLigne);
            }
        }
        // Fermer la base de données
        fichier.close();
    }
    // Si l'Emission est innexistant, on retourne NULL
    return NULL;
}

// Afficher l'Emission
void Emission::afficher() {
    std::cout << "Titre : " << this->titre << std::endl;
    std::cout << "Animateur : " << this->animateur << std::endl;
    std::cout << "Chaine name : " << (this->chaine)->getChaineName() << std::endl;
    std::cout << "Chaine code postale : " << (this->chaine)->getChaineCodePostal() << std::endl;
    std::cout << "Chaine addresse : " << (this->chaine)->getChaineAddress() << std::endl;
}



