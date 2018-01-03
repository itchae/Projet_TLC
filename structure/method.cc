#include "method.hh"

Method::Method(vector<Fonction*> v)
{
	//copie le vecteur v dans le vecteur vars
	vars.reserve(v.size());
	copy(v.begin(),v.end(),back_inserter(vars));
}

Method::~Method() {
  while (vars.size()>0){
	  delete vars.back();
	  vars.pop_back();
  }
}

bool Method::contains(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->compare(var)==0) return true;
	}
	return false;
}

Decl* Method::getFonction(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->compare(var)==0) return vars[i];
	}
	return null;
}

void Method::visit(Visitor& visitor) const {
  return visitor.visitBlock(this);
}
