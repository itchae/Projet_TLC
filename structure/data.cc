#include "data.hh"

Data::Data(vector<Decl*> v)
{
	//copie le vecteur v dans le vecteur vars
	vars.reserve(v.size());
	copy(v.begin(),v.end(),back_inserter(vars));
}

Data::~Data() {
  while (vars.size()>0){
	  delete vars.back();
	  vars.pop_back();
  }
}

bool Data::contains(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->compare(var)==0) return true;
	}
	return false;
}

Data* Decl::getDecl(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->compare(var)==0) return vars[i];
	}
	return null;
}

void Data::visit(Visitor& visitor) const {
  return visitor.visitBlock(this);
}
