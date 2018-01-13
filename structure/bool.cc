#include "headers/bool.hh"

/**--------------------------------------------------------------------------**/
Boolean::Boolean(bool v) : value(v) {

}

/**--------------------------------------------------------------------------**/
Boolean::~Boolean() {

}

/**--------------------------------------------------------------------------**/
void Boolean::visit(Visitor& visitor) const {
  //return visitor.visitFloat(this);
}
