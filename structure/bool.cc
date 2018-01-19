#include "headers/bool.hh"
#include <stdexcept>

/**--------------------------------------------------------------------------**/
Boolean::Boolean(bool v) : value(v) {

}

/**--------------------------------------------------------------------------**/
Boolean::~Boolean() {

}

/**--------------------------------------------------------------------------**/
void Boolean::visit(Visitor& visitor) {
  //return visitor.visitFloat(this);
}

void Boolean::print() const{
  cout<<value<<endl;
}

Expression* Boolean::operator +(const Expression& val)const {
  return val.plus(*this);
}

Expression* Boolean::operator -(const Expression& val)const{
  return val.moins(*this);
}
Expression* Boolean::operator * (const Expression& val)const{
  return val.mult(*this);
}
Expression* Boolean::operator /(const Expression& val)const{
  return val.div(*this);
}

Expression* Boolean::operator < (const Expression& val)const{

}
Expression* Boolean::operator <=(const Expression& val)const{

}
Expression* Boolean::operator > (const Expression& val)const{

}
Expression* Boolean::operator >=(const Expression& val)const{

}

Expression* Boolean::plus(const Integer& val)const{
  throw runtime_error("Addition entre bool et float");
}

Expression* Boolean::plus(const Float& val)const{
  throw runtime_error("Addition entre bool et float");
}

Expression* Boolean::plus(const Boolean& val)const{
  throw runtime_error("Addition impossible avec des bool");
}

Expression* Boolean::moins(const Integer& val)const{
  throw runtime_error("Soustraction entre bool et int");
}

Expression* Boolean::moins(const Float& val)const{
  throw runtime_error("Soustraction entre bool et float");
}

Expression* Boolean::moins(const Boolean& val)const{
  throw runtime_error("Soustraction impossible avec des bool");
}

Expression* Boolean::mult(const Integer& val)const{
  throw runtime_error("Multiplication entre bool et int");
}

Expression* Boolean::mult(const Float& val)const{
  throw runtime_error("Multiplication entre bool et float");
}

Expression* Boolean::mult(const Boolean& val)const{
  throw runtime_error("Multiplication impossible avec des bool");
}

Expression* Boolean::div(const Integer& val)const{
  throw runtime_error("Division entre bool et int");
}

Expression* Boolean::div(const Float& val)const{
  throw runtime_error("Division entre bool et float");
}
Expression* Boolean::div(const Boolean& val)const{
  throw runtime_error("Division impossible avec des bool");
}


Expression* Boolean::pow(const Integer& val)const{
  throw runtime_error("Operation pow impossible entre bool et int");
}
Expression* Boolean::pow(const Float& val)const{
  throw runtime_error("Operation pow impossible entre bool et float");
}
Expression* Boolean::pow(const Boolean& val)const{
  throw runtime_error("Operation pow impossible entre bool et bool");
}

Expression* Boolean::sqrt(const Integer& val)const{
  throw runtime_error("Operation sqrt impossible entre bool et int");
}
Expression* Boolean::sqrt(const Float& val)const{
  throw runtime_error("Operation sqrt impossible entre bool et float");
}
Expression* Boolean::sqrt(const Boolean& val)const{
  throw runtime_error("Operation sqrt impossible entre bool et bool");
}


Expression* Boolean::inferieur(const Integer& val)const{
  throw runtime_error("Comparaison entre float et int");
}
Expression* Boolean::inferieur(const Float& val)const{
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::inferieur(const Boolean& val)const{
  return new Boolean(this->value<val.value);
}


Expression* Boolean::inferieurEgal(const Integer& val)const{
  throw runtime_error("Comparaison entre bool et int");
}
Expression* Boolean::inferieurEgal(const Float& val)const{
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::inferieurEgal(const Boolean& val)const{
  return new Boolean(this->value<=val.value);
}


Expression* Boolean::superieur (const Integer& val)const{
  throw runtime_error("Comparaison entre bool et int");
}
Expression* Boolean::superieur (const Float& val)const{
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::superieur (const Boolean& val)const{
  return new Boolean(this->value>val.value);
}


Expression* Boolean::superieurEgal(const Integer& val)const{
  throw runtime_error("Comparaison entre float et int");
}
Expression* Boolean::superieurEgal(const Float& val)const{
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::superieurEgal(const Boolean& val)const{
  return new Boolean(this->value>=val.value);
}

Expression* Boolean::diff(const Integer& val)const{
  throw runtime_error("Comparaison entre bool et int");
}
Expression* Boolean::diff(const Float& val)const{
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::diff(const Boolean& val)const{
  throw runtime_error("Comparaison entre bool et bool");
}

Expression* Boolean::egalite(const Integer& val)const{
  throw runtime_error("Comparaison entre bool et int");
}
Expression* Boolean::egalite(const Float& val)const{
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::egalite(const Boolean& val)const{
  throw runtime_error("Comparaison entre bool et bool");
}
