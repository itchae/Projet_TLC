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

void Boolean::print() {
  cout<<value<<endl;
}

Expression* Boolean::operator +( Expression& val) {
  return val.plus(*this);
}

Expression* Boolean::operator -( Expression& val){
  return val.moins(*this);
}
Expression* Boolean::operator * ( Expression& val){
  return val.mult(*this);
}
Expression* Boolean::operator /( Expression& val){
  return val.div(*this);
}

Expression* Boolean::operator < ( Expression& val){

}
Expression* Boolean::operator <=( Expression& val){

}
Expression* Boolean::operator > ( Expression& val){

}
Expression* Boolean::operator >=( Expression& val){

}

Expression* Boolean::plus( Integer& val){
  throw runtime_error("Addition entre bool et float");
}

Expression* Boolean::plus( Float& val){
  throw runtime_error("Addition entre bool et float");
}

Expression* Boolean::plus( Boolean& val){
  throw runtime_error("Addition impossible avec des bool");
}

Expression* Boolean::moins( Integer& val){
  throw runtime_error("Soustraction entre bool et int");
}

Expression* Boolean::moins( Float& val){
  throw runtime_error("Soustraction entre bool et float");
}

Expression* Boolean::moins( Boolean& val){
  throw runtime_error("Soustraction impossible avec des bool");
}

Expression* Boolean::mult( Integer& val){
  throw runtime_error("Multiplication entre bool et int");
}

Expression* Boolean::mult( Float& val){
  throw runtime_error("Multiplication entre bool et float");
}

Expression* Boolean::mult( Boolean& val){
  throw runtime_error("Multiplication impossible avec des bool");
}

Expression* Boolean::div( Integer& val){
  throw runtime_error("Division entre bool et int");
}

Expression* Boolean::div( Float& val){
  throw runtime_error("Division entre bool et float");
}
Expression* Boolean::div( Boolean& val){
  throw runtime_error("Division impossible avec des bool");
}


Expression* Boolean::pow( Integer& val){
  throw runtime_error("Operation pow impossible entre bool et int");
}
Expression* Boolean::pow( Float& val){
  throw runtime_error("Operation pow impossible entre bool et float");
}
Expression* Boolean::pow( Boolean& val){
  throw runtime_error("Operation pow impossible entre bool et bool");
}

Expression* Boolean::racineCarree(){
  throw runtime_error("Operation sqrt impossible");
}

Expression* Boolean::neg(){
  throw runtime_error("Operation neg impossible");
}


Expression* Boolean::inferieur( Integer& val){
  throw runtime_error("Comparaison entre float et int");
}
Expression* Boolean::inferieur( Float& val){
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::inferieur( Boolean& val){
  return new Boolean(this->value<val.value);
}


Expression* Boolean::inferieurEgal( Integer& val){
  throw runtime_error("Comparaison entre bool et int");
}
Expression* Boolean::inferieurEgal( Float& val){
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::inferieurEgal( Boolean& val){
  return new Boolean(this->value<=val.value);
}


Expression* Boolean::superieur ( Integer& val){
  throw runtime_error("Comparaison entre bool et int");
}
Expression* Boolean::superieur ( Float& val){
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::superieur ( Boolean& val){
  return new Boolean(this->value>val.value);
}


Expression* Boolean::superieurEgal( Integer& val){
  throw runtime_error("Comparaison entre float et int");
}
Expression* Boolean::superieurEgal( Float& val){
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::superieurEgal( Boolean& val){
  return new Boolean(this->value>=val.value);
}

Expression* Boolean::diff( Integer& val){
  throw runtime_error("Comparaison entre bool et int");
}
Expression* Boolean::diff( Float& val){
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::diff( Boolean& val){
  return new Boolean(this->value != val.value);;
}

Expression* Boolean::egalite( Integer& val){
  throw runtime_error("Comparaison entre bool et int");
}
Expression* Boolean::egalite( Float& val){
  throw runtime_error("Comparaison entre bool et float");
}
Expression* Boolean::egalite( Boolean& val){
  return new Boolean(this->value == val.value);;
}
