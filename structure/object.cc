#include "headers/object.hh"

//--------------------------------------------------------------------------//
Object::Object(string n, Class* c)
{
  nom = n;
  classe = c;
  vector<Decl*> d = c->getData()->getVars();
  for (int i=0; i<d.size(); i++){
    vars.push_back(new Variable(d[i]->getVar(),d[i]->getType()));
  }
}

//--------------------------------------------------------------------------//
Object::~Object() {
  for (int i=0; i<vars.size(); i++){
    delete vars[i];
  }
}

//--------------------------------------------------------------------------//
void Object::setVar(string name, Expression* val){
  for (int i=0; i<vars.size(); i++){
    if (vars[i]!=NULL) {
      if (vars[i]->getName().compare(name)==0){
        vars[i]->setVar(val);
      }
    }
  }
}

//--------------------------------------------------------------------------//
string Object::getType() const {
  return classe->getName();
}

//--------------------------------------------------------------------------//
void Object::visit(Visitor& visitor) {
  //return visitor.visitClass(this);
}

//--------------------------------------------------------------------------//
void Object::print() const{
	cout<<"(";
  for (int i=0; i<vars.size(); i++){
    if (vars[i]!=NULL) {
      vars[i]->print();
      cout<<" , ";
    }
  }
  cout<<")"<<endl;
}

//--------------------------------------------------------------------------//
Variable* Object::getVar(string n) const{
  for (int i=0; i<vars.size(); i++){
    if (vars[i]!=NULL) {
      if (vars[i]->getName().compare(n)==0) return vars[i];
    }
  }
  return NULL;
}

//--------------------------------------------------------------------------//
Fonction* Object::getFonction(string n) const{
  return classe->getMethod()->getFonction(n);
}
