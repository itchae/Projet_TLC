#include "headers/symbolTable.hh"

/**--------------------------------------------------------------------------**/
SymbolTable SymbolTable::m_instance = SymbolTable();
vector<Class*> SymbolTable::classes;
vector<Variable*> SymbolTable::vars;

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
  while (vars.size()>0){
    delete vars.back();
    vars.pop_back();
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
void SymbolTable::addVar(Variable* v){
  for (int i=0; i<vars.size(); i++){
    //on ne peut pas avoir deux variables portant le meme nom
    if (v->getName().compare(vars[i]->getName())==0) throw invalid_argument("declaration deja existante");
  }
  vars.push_back(v);
}

/**--------------------------------------------------------------------------**/
Variable* SymbolTable::findVar(string name) const{
  for (int i=0; i<vars.size(); i++){
    if (name.compare(vars[i]->getName())==0) return vars[i];
  }
  return NULL;
}

/**--------------------------------------------------------------------------**/
Expression* SymbolTable::findResultOfMethodOfClass(string d, string m, vector<Expression*> e) const{
  return NULL;
}
