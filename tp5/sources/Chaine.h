#ifndef Chaine_H
#define Chaine_H

#include <string>

using namespace std;
        
// Cette classe représente une Chaine
class Chaine {
public:
    // Constructeurs
    Chaine ();
    Chaine(string, string, string);
    
    // Setters
    
    void setChaineAdress(string);
    void setName(string);
    void setCodePostal(string);
    
    
    // Getters
    string getChaineName();
    string getChaineCodePostal();
    string getChaineAddress();
    
    //Affichage
    void afficher();
    
private:
    // Informations sur la chaine
    string chaineName;
    string chaineCodePostal;
    string chaineAddress;
};

#endif 
