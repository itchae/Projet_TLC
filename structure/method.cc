#include "headers/method.hh"

/**--------------------------------------------------------------------------**/
Method::Method(vector<Fonction*> v) : vars(v)
{
}

/**--------------------------------------------------------------------------**/
Method::~Method() {
  while (vars.size()>0){
	  delete vars.back();
	  vars.pop_back();
  }
}

/**--------------------------------------------------------------------------**/
bool Method::contains(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->getName().compare(var)==0) return true;
	}
	return false;
}

/**--------------------------------------------------------------------------**/
Fonction* Method::getFonction(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->getName().compare(var)==0) return vars[i];
	}
	return NULL;
}

/**--------------------------------------------------------------------------**/
void Method::visit(Visitor& visitor) const {
  return visitor.visitMethod(this);
}
