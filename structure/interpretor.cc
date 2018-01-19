#include "headers/interpretor.hh"

#include <iostream>

using namespace std;

/**--------------------------------------------------------------------------**/
void Interpretor::visitDecl(Decl *d){
  SymbolTable& symbol = SymbolTable::Instance();
  Variable* v = new Variable(d->getVar(), d->getType());
  symbol.addVar(v);
}

/**--------------------------------------------------------------------------**/
void Interpretor::visitAffect(Affect *a){
  SymbolTable& symbol = SymbolTable::Instance();
  if (a->getVars().size()>0){
    //affectation simple, une variable := une valeur
    if (a->getVars().size()==1){
      vector<string> tmp;
      tmp.push_back(a->getVars()[0]);
      Variable* v = symbol.findVar(tmp);
      if (v==NULL) throw invalid_argument("variable inexistante");
      v->setVar(a->getExprs()[0]);
    }
  }
}

/**--------------------------------------------------------------------------**/
void Interpretor::visitFonction(Fonction *f){

}

/**--------------------------------------------------------------------------**/
void Interpretor::visitCall(Call *c){
  cout << "heheh" << endl;
}
