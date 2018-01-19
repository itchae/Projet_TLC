#include "headers/fonc.hh"

/**--------------------------------------------------------------------------**/
Fonction::Fonction(string name, vector<Decl*> v, Instruction* i)
	: name(name), instruct(i), params(v)
{
}

/**--------------------------------------------------------------------------**/
Fonction::~Fonction() {
  while (params.size()>0){
	  delete params.back();
	  params.pop_back();
  }
  delete instruct;
}

/**--------------------------------------------------------------------------**/
bool Fonction::containsParam(string var) const{
	for (int i=0; i<params.size(); i++){
		if (params[i]->getVar().compare(var)==0) return true;
	}
	return false;
}

/**--------------------------------------------------------------------------**/
Decl* Fonction::getParam(string var) const{
	for (int i=0; i<params.size(); i++){
		if (params[i]->getVar().compare(var)==0) return params[i];
	}
	return NULL;
}

/**--------------------------------------------------------------------------**/
bool Fonction::noParams() const{
	return params.empty();
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
void Fonction::visit(Visitor& visitor) {
  //return visitor.visitFonc(this);
}

void Fonction::print() const{
	cout<<name<<endl; 
}
