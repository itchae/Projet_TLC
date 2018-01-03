#include "int.hh"


Integer::Integer(int v) : value(v) {
  
}

Integer::~Integer() {
  
}

void Integer::visit(Visitor& visitor) const {
  return visitor.visitFloat(this);
}
