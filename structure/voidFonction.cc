#include "headers/voidFonction.hh"

/**--------------------------------------------------------------------------**/
VoidFonction::VoidFonction(string name, vector<Decl*> v, Instruction* i)
	: name(name), instruct(i), params(v)
{
}

/**--------------------------------------------------------------------------**/
VoidFonction::~VoidFonction() {
  while (params.size()>0){
	  delete params.back();
	  params.pop_back();
  }
  delete instruct;
}

/**--------------------------------------------------------------------------**/
bool VoidFonction::containsParam(string var) const{
	for (int i=0; i<params.size(); i++){
		if (params[i]->getVar().compare(var)==0) return true;
	}
	return false;
}

/**--------------------------------------------------------------------------**/
Decl* VoidFonction::getParam(string var) const{
	for (int i=0; i<params.size(); i++){
		if (params[i]->getVar().compare(var)==0) return params[i];
	}
	return NULL;
}

/**--------------------------------------------------------------------------**/
bool VoidFonction::noParams() const{
	return params.empty();
}

/**--------------------------------------------------------------------------**/
void VoidFonction::visit(Visitor& visitor) {
  //return visitor.visitFonc(this);
}
