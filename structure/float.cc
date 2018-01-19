#include "headers/float.hh"
#include <math.h>

/**--------------------------------------------------------------------------**/
Float::Float(double v) : value(v) {

}

/**--------------------------------------------------------------------------**/
Float::~Float() {

}

/**--------------------------------------------------------------------------**/
void Float::visit(Visitor& visitor) {
  //return visitor.visitFloat(this);
}

void Float::print() {
  cout<<value<<endl;
}

Expression* Float::operator +( Expression& val) {
  return val.plus(*this);
}

Expression* Float::operator -( Expression& val){
  return val.moins(*this);
}
Expression* Float::operator * ( Expression& val){
  return val.mult(*this);
}
Expression* Float::operator /( Expression& val){
  return val.div(*this);
}

Expression* Float::operator < ( Expression& val){

}
Expression* Float::operator <=( Expression& val){

}
Expression* Float::operator > ( Expression& val){

}
Expression* Float::operator >=( Expression& val){

}

Expression* Float::plus( Integer& val){
  throw runtime_error("Addition entre float et int");
}

Expression* Float::plus( Float& val){
  return new Float(((float)val.value) + this->value);
}

Expression* Float::plus( Boolean& val){
  throw runtime_error("Addition entre float et bool");
}

Expression* Float::moins( Integer& val){
  throw runtime_error("Soustraction entre float et int");
}

Expression* Float::moins( Float& val){
  return new Float(((float)val.value) - this->value);
}

Expression* Float::moins( Boolean& val){
  throw runtime_error("Soustraction  entre float et bool");
}

Expression* Float::mult( Integer& val){
  throw runtime_error("Multiplication entre float et int");
}

Expression* Float::mult( Float& val){
  return new Float(((float)val.value) * this->value);
}

Expression* Float::mult( Boolean& val){
  throw runtime_error("Multiplication entre float et bool");
}

Expression* Float::div( Integer& val){
  throw runtime_error("Division entre float et int");
}

Expression* Float::div( Float& val){
  return new Float(((float)val.value) / this->value);
}
Expression* Float::div( Boolean& val){
  throw runtime_error("Division entre float et bool");
}


Expression* Float::pow( Integer& val){
  throw runtime_error("Operation pow impossible entre float et int");
}
Expression* Float::pow( Float& val){
  throw runtime_error("Operation pow impossible entre float et float");
}
Expression* Float::pow( Boolean& val){
  throw runtime_error("Operation pow impossible entre float et bool");
}

Expression* Float::racineCarree(){
  return new Float(sqrt(this->value));
}

Expression* Float::neg(){
  return new Float(-(this->value));
}

Expression* Float::inferieur( Integer& val){
  throw runtime_error("Comparaison entre float et int");
}
Expression* Float::inferieur( Float& val){
  return new Boolean(this->value<val.value);
}
Expression* Float::inferieur( Boolean& val){
  throw runtime_error("Comparaison entre float et bool");
}


Expression* Float::inferieurEgal( Integer& val){
  throw runtime_error("Comparaison entre float et int");
}
Expression* Float::inferieurEgal( Float& val){
  return new Boolean(this->value<=val.value);
}
Expression* Float::inferieurEgal( Boolean& val){
  throw runtime_error("Comparaison entre float et bool");
}


Expression* Float::superieur ( Integer& val){
  throw runtime_error("Comparaison entre float et int");
}
Expression* Float::superieur ( Float& val){
  return new Boolean(this->value>val.value);
}
Expression* Float::superieur ( Boolean& val){
  throw runtime_error("Comparaison entre float et bool");
}


Expression* Float::superieurEgal( Integer& val){
  throw runtime_error("Comparaison entre float et int");
}
Expression* Float::superieurEgal( Float& val){
  return new Boolean(this->value>=val.value);
}
Expression* Float::superieurEgal( Boolean& val){
  throw runtime_error("Comparaison entre float et bool");
}


Expression* Float::diff( Integer& val){
  throw runtime_error("Comparaison entre float et int");
}
Expression* Float::diff( Float& val){
  return new Boolean(this->value != val.value);;
}
Expression* Float::diff( Boolean& val){
  throw runtime_error("Comparaison entre float et bool");
}

Expression* Float::egalite( Integer& val){
  throw runtime_error("Comparaison entre float et int");
}
Expression* Float::egalite( Float& val){
  return new Boolean(this->value == val.value);
}
Expression* Float::egalite( Boolean& val){
  throw runtime_error("Comparaison entre float et bool");
}
