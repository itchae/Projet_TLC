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
Class* SymbolTable::findClass(string name){
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
Variable* SymbolTable::findVar(vector<string> s){
  Variable* tmp = NULL;
  if (s.size()==0) return tmp;
  for (int i=0; i<vars.size(); i++){
    if (vars[i]->getName().compare(s[0])==0) tmp = vars[i];
  }
  if (tmp==NULL) throw invalid_argument("variable inexistante");
  //on cherche dans la variable tmp une autre variable du nom de s[i]
  int i=1;
  while (i<s.size()){
    Object* obj = dynamic_cast<Object*>(tmp);
    if (obj==NULL) throw invalid_argument("objet inexistant");
    tmp = obj->getVar(s[i]);
    if (tmp==NULL) throw invalid_argument("variable inexistante");
  }
  return tmp;
}

/**--------------------------------------------------------------------------**/
Expression* SymbolTable::resultOfReturnFonction(vector<string> s, vector<Expression*> e){
  //le vector s contient les noms des variables, exemple si c'est var.v, il contient var puis v
  //on cherche donc si la premiere variable est présente dans la table des symboles
  Variable* tmp = NULL;
  for (int i=0; i<vars.size(); i++){
    if (vars[i]->getName().compare(s[i])==0) tmp = vars[i];
  }
  if (tmp==NULL) throw invalid_argument("variable inexistante");
  //on cherche dans la variable tmp une autre variable du nom de s[i]
  int i=1;
  while (i<s.size()-1){
    Object* obj = dynamic_cast<Object*>(tmp);
    if (obj==NULL) throw invalid_argument("objet inexistant");
    tmp = obj->getVar(s[i]);
    if (tmp==NULL) throw invalid_argument("variable inexistante");
  }
  // on est rendu a la fin de l'appel, donc il reste le nom de la methode
  // on la cherche donc dans la derniere variable
  Class* c = findClass(tmp->getType());
  if (c==NULL) throw invalid_argument("classe inexistante");
  Fonction* f = c->getMethod()->getFonction(s[s.size()-1]);
  if (f==NULL) throw invalid_argument("fonction inexistante");
  // seulement une fonction de type returnfonction renvoie une Expression
  ReturnFonction* f2 = dynamic_cast<ReturnFonction*>(f);
  if (f2==NULL) throw invalid_argument("fonction de type void");
  return f2->calcul();
}
