#include "headers/fonc.hh"

/**--------------------------------------------------------------------------**/
Fonction::Fonction(string name, vector<Decl*> v, Instruction* i)
	: name(name), instruct(i), param(v)
{
}

/**--------------------------------------------------------------------------**/
Fonction::~Fonction() {
  while (param.size()>0){
	  delete param.back();
	  param.pop_back();
  }
  delete instruct;
}

/**--------------------------------------------------------------------------**/
bool Fonction::containsParam(string var) const{
	for (int i=0; i<param.size(); i++){
		if (param[i]->getVar().compare(var)==0) return true;
	}
	return false;
}

/**--------------------------------------------------------------------------**/
Decl* Fonction::getParam(string var) const{
	for (int i=0; i<param.size(); i++){
		if (param[i]->getVar().compare(var)==0) return param[i];
	}
	return NULL;
}

/**--------------------------------------------------------------------------**/
bool Fonction::noParam() const{
	return param.empty();
}

/**--------------------------------------------------------------------------**/
string Fonction::getType() const{
	Return* r = dynamic_cast<Return*>(instruct);
	if ( r != NULL )
	  return r->getType();
	else
	  return "void";
}

/**--------------------------------------------------------------------------**/
void Fonction::visit(Visitor& visitor) const {
  return visitor.visitFonc(this);
}
