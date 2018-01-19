#include "headers/data.hh"

/**--------------------------------------------------------------------------**/
Data::Data(vector<Decl*> v) : vars(v)
{
}

/**--------------------------------------------------------------------------**/
Data::~Data() {
  while (vars.size()>0){
	  delete vars.back();
	  vars.pop_back();
  }
}

/**--------------------------------------------------------------------------**/
bool Data::contains(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->getVar().compare(var)==0) return true;
	}
	return false;
}

/**--------------------------------------------------------------------------**/
Decl* Data::getDecl(string var) const{
	for (int i=0; i<vars.size(); i++){
		if (vars[i]->getVar().compare(var)==0) return vars[i];
	}
	return NULL;
}

/**--------------------------------------------------------------------------**/
void Data::visit(Visitor& visitor) {
  //return visitor.visitFonc(this);
}
