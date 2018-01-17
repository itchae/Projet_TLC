#include "headers/affect.hh"

/**--------------------------------------------------------------------------**/
bool Affect::memeType(vector<Decl*> v, vector<Expression*> e){
	if (v.size()!=e.size()) return false;
	for (int i = 0; i < v.size(); i++){
		//si les types sont differents
		if (v[i]->getType().compare(e[i]->getType())!=0) return false;
	}
	return true;
}

/**--------------------------------------------------------------------------**/
Affect::Affect(Decl* v, vector<Expression*> e)
	: exprs(e)
{
	SymbolTable& s = SymbolTable::Instance();
	Class* c = s.findClass(v->getType());
	if (c==NULL) throw invalid_argument("type inexistant");
	vars = c->getData()->getDecls();
	if (!memeType(vars,exprs)) throw invalid_argument("types incompatibles");
}

/**--------------------------------------------------------------------------**/
Affect::Affect(Decl* v, Expression* e){
	if (v->getType().compare(e->getType())!=0) throw invalid_argument("types incompatibles");
	exprs.push_back(e);
	vars.push_back(v);
}

/**--------------------------------------------------------------------------**/
Affect::Affect(vector<Decl*> v, vector<Expression*> e)
	: vars(v), exprs(e)
{
	if (!memeType(v,e)) throw invalid_argument("types incompatibles");
}

/**--------------------------------------------------------------------------**/
Affect::~Affect() {
	for (int i = 0; i < vars.size(); i++){
		delete vars[i];
	}
	for (int i = 0; i < exprs.size(); i++){
		delete exprs[i];
	}
}

/**--------------------------------------------------------------------------**/
bool Affect::operator==(Affect* rhs) {
	if (rhs->getVars().size()!=vars.size()) return false;
	for (int i = 0; i < vars.size(); i++){
		if (rhs->getVars()[i]->getType().compare(vars[i]->getType())!=0) return false;
	}
	return true;
}

/**--------------------------------------------------------------------------**/
void Affect::visit(Visitor& visitor) const {
  //return visitor.visitAffect(this);
}
