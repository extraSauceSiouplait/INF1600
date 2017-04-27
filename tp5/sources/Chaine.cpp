#include "Chaine.h"

#include <fstream>
#include <iostream>

// Constructeurs
Chaine::Chaine(){
    this->chaineName = "";
    this->chaineCodePostal = "";
    this->chaineAddress = "";
    
}
Chaine::Chaine   (string chaineName,
                  string chaineCodePostal,
                  string chaineAddress) {

    // Chaine information
    this->chaineName = chaineName;
    this->chaineCodePostal = chaineCodePostal;
    this->chaineAddress = chaineAddress;
    
}

// Setters
void Chaine::setName(string chaineName) {
    this->chaineName = chaineName;
}
void Chaine::setCodePostal(string chaineCodePostal) {
    this->chaineCodePostal = chaineCodePostal;
}
void Chaine::setChaineAdress(string chaineAddress) {
    this->chaineAddress = chaineAddress;
}

// Getters

string Chaine::getChaineName() {
    return this->chaineName;
}

string Chaine::getChaineCodePostal() {
    return this->chaineCodePostal;
}

string Chaine::getChaineAddress() {
    return this->chaineAddress;
}

// Afficher la chaine
void Chaine::afficher() {
    std::cout << "Chaine name : " << this->chaineName << std::endl;
    std::cout << "Chaine code postale : " << this->chaineCodePostal << std::endl;
    std::cout << "Chaine address : " << this->chaineAddress << std::endl;
}


