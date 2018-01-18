#include "headers/symbolTable.hh"

/**--------------------------------------------------------------------------**/
SymbolTable SymbolTable::m_instance = SymbolTable();
vector<Class*> SymbolTable::classes;
vector<Decl*> SymbolTable::decls;
vector<Affect*> SymbolTable::affects;

/**--------------------------------------------------------------------------**/
SymbolTable::SymbolTable(){

}

/**--------------------------------------------------------------------------**/
SymbolTable::~SymbolTable(){
  cleanAll();
}

/**--------------------------------------------------------------------------**/
SymbolTable& SymbolTable::Instance(){
    return m_instance;
}

/**--------------------------------------------------------------------------**/
void SymbolTable::cleanAll(){
  //on vide les vecteurs et supprime les objets de la mémoire
  while (classes.size()>0){
    delete classes.back();
    classes.pop_back();
  }
  while (decls.size()>0){
    delete decls.back();
    decls.pop_back();
  }
  while (affects.size()>0){
    delete affects.back();
    affects.pop_back();
  }
}

/**--------------------------------------------------------------------------**/
void SymbolTable::addClass(Class* c){
  for (int i=0; i<classes.size(); i++){
    //on ne peut pas avoir deux classes portant le meme nom
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
    //on ne peut pas avoir deux variables portant le meme nom
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
  /*for (int i=0; i<affects.size(); i++){
    if (*affects[i]==a){
      //on garde seulement la derniere affectation (qui correspond donc a la valeur actuelle de la variable)
      affects[i] = a;
      return;
    }
  }
  affects.push_back(a);*/
}

/**--------------------------------------------------------------------------**/
Affect* SymbolTable::findAffect(string name) const{
  return NULL;
}

/**--------------------------------------------------------------------------**/
Expression* SymbolTable::findResultOfMethodOfClass(string d, string m, vector<Expression*> e) const{
  return NULL;
}
