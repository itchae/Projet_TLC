#include "headers/symbolTable.hh"

/**--------------------------------------------------------------------------**/
SymbolTable SymbolTable::m_instance = SymbolTable();

/**--------------------------------------------------------------------------**/
SymbolTable::SymbolTable(){

}

/**--------------------------------------------------------------------------**/
SymbolTable::~SymbolTable(){
  while (classes.size()>0){
    delete classes.back();
    classes.pop_back();
  }
}

/**--------------------------------------------------------------------------**/
SymbolTable& SymbolTable::Instance(){
    return m_instance;
}

/**--------------------------------------------------------------------------**/
void SymbolTable::addClass(Class* c){
  for (int i=0; i<classes.size(); i++){
    if (c->getName().compare(classes[i]->getName())==0) throw invalid_argument("classe deja existante");
  }
  classes.push_back(c);
}

/**--------------------------------------------------------------------------**/
Class* SymbolTable::findClass(string name) const{
  for (int i=0; i<classes.size(); i++){
    if (name.compare(classes[i]->getName())==0) return classes[i];
  }
  return NULL;
}

/**--------------------------------------------------------------------------**/
void SymbolTable::addDecl(Decl* d){
  for (int i=0; i<decls.size(); i++){
    if (d->getVar().compare(decls[i]->getVar())==0) throw invalid_argument("declaration deja existante");
  }
  decls.push_back(d);
}

/**--------------------------------------------------------------------------**/
Decl* SymbolTable::findDecl(string name) const{
  for (int i=0; i<decls.size(); i++){
    if (name.compare(decls[i]->getVar())==0) return decls[i];
  }
  return NULL;
}

/**--------------------------------------------------------------------------**/
void SymbolTable::addAffect(Affect* a){
  for (int i=0; i<affects.size(); i++){
    if (a->getVar()->getVar().compare(affects[i]->getVar()->getVar())==0) throw invalid_argument("affectation deja existante");
  }
  affects.push_back(a);
}

/**--------------------------------------------------------------------------**/
Affect* SymbolTable::findAffect(string name) const{
  for (int i=0; i<affects.size(); i++){
    if (name.compare(affects[i]->getVar()->getVar())==0) return affects[i];
  }
  return NULL;
}
