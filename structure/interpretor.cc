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
  VoidFonction* f2 = static_cast<VoidFonction*>(f);
  if (f2==NULL) throw invalid_argument("la methode n'est pas une procedure void");
  f2->getInst()->visit(*this);
}

/**--------------------------------------------------------------------------**/
void Interpretor::visitCall(Call *c){
  SymbolTable& symbol = SymbolTable::Instance();
  //on cherche la variable dans la table des symboles
  Variable* v = symbol.findVar(c->getObjs());
  if (v==NULL) throw invalid_argument("la variable n'existe pas");
  //si c'est la methode print
  if (c->getName().compare("print")==0){
    v->print();
  }else{
    //sinon il faut chercher la methode dans la classe
    Object* obj = static_cast<Object*>(v);
    if (obj==NULL) throw invalid_argument("la variable n'est pas un objet");
    Fonction* f = obj->getFonction(c->getName());
    if (f==NULL) throw invalid_argument("la methode n'est pas un reconnue");
    f->visit(*this);
  }
}
