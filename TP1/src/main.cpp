/* 
 * File:   main.cpp
 * Author: William Harvey et Mathieu Bélanger
 *
 * Created on February 7 11:20 
 */

#include <iostream>
#include <fstream>
#include "HashMap.h"

using namespace std;

/* 
 * L'objectif est de trouver le mot ayant le plus d'occurence dans un document texte pris en entrée.
 * 
 */
int main(int argc, char** argv) {
    
  HashMap map;
  fstream in(argv[1], ios::in);
  
  string out;
  
  if (in.fail())
      cout << argv[1] << " est introuvable.";
      
  while(!ws(in).eof()) {
      in >> out; 
      cout  << out << " ";
      map.compteur(out);
  } 
   

  
    vector<string> mykeys = map.getKeys();
    
    int valeurMax = 4;
    int valeurCourante = 0;
    string motMax = "";
    
    for (int i = 0; i < mykeys.size() ; i++) {
        map.get(mykeys[i], valeurCourante);
        
        if(valeurCourante >= valeurMax) {
            valeurMax = valeurCourante;
            motMax = mykeys[i];
        }
    }
    
    cout << endl << motMax << " apparait " << valeurMax << " fois." << endl;
    in.close();
  
  
  return 0;
}
