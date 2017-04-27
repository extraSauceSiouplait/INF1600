#ifndef Emission_H
#define Emission_H

#include <string>
#include "Chaine.h"

using namespace std;
        
// Cette classe représente un Emission
class Emission {
public:
    // Constructeurs
    Emission ();
    Emission(string, string, string, string, string);
    
    // Setters
    void setTitre(string);
    void setAnimateur(string);
    void associerChaine(Chaine*);
    
    // Getters
    string getTitre();
    string getAnimateur();
    Chaine* getChaine();
    
    // Enregistrer l'Emission
    void saveEmission(string);
    // Afficher l'Emission
    void afficher();
    // Chercher un Emission dans une base de données par titre
    Emission* trouverEmission(string, string);
    // Retourne le prochain élément sur la ligne courant dans DB
    string lireProchainElem(string, int&);
    // Retourne un ptr vers l'émission de la ligne courante dans DB
    Emission* lireEmissionDB(string, string, int);

    
private:
    // Information sur l'emission
    string titre;
    string animateur;
    Chaine* chaine;
};

#endif 
