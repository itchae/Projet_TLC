#include "headers/interpretor.hh"

#include <iostream>

using namespace std;

/**--------------------------------------------------------------------------**/
void Interpretor::visitDecl(Decl *d){
  SymbolTable& symbol = SymbolTable::Instance();
  symbol.addDecl(d);
}

/**--------------------------------------------------------------------------**/
void Interpretor::visitAffect(Affect *a){
  //TODO add to the global symbol table
}

/**--------------------------------------------------------------------------**/
void Interpretor::visitFonction(Fonction *f){

}

/**--------------------------------------------------------------------------**/
void Interpretor::visitCall(Call *c){
  cout << "heheh" << endl;
}
