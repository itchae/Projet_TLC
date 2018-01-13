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
