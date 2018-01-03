#include "class.hh"

Class::Class(char* n, Data* d, Method* m)
  : data(d), method(m)
{
	name = strdup(n);
}

Class::Class(Class* mere, char* n, Data* d, Method* m)
  : mere(mere), data(d), method(m)
{
	name = strdup(n);
}

Class::~Class() {
  delete name;
  delete data;
  delete method;
}

void Class::visit(Visitor& visitor) const {
  return visitor.visitBlock(this);
}
