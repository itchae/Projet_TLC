#include "fonc.hh"

Fonction::Fonction(string name, vector<Decl*> v, Instruction* i)
	: name(name), instruct(i)
{
	//copie le vecteur v dans le vecteur vars
	param.reserve(v.size());
	copy(v.begin(),v.end(),back_inserter(vars));
}

Fonction::~Fonction() {
  while (param.size()>0){
	  delete param.back();
	  param.pop_back();
  }
  delete instruct;
}

bool Fonction::containsParam(string var) const{
	for (int i=0; i<param.size(); i++){
		if (param[i]->compare(var)==0) return true;
	}
	return false;
}

Decl* Fonction::getParam(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->compare(var)==0) return vars[i];
	}
	return null;
}

void Fonction::visit(Visitor& visitor) const {
  return visitor.visitBlock(this);
}
