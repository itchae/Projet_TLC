#include "headers/int.hh"

/**--------------------------------------------------------------------------**/
Integer::Integer(int v) : value(v) {

}

/**--------------------------------------------------------------------------**/
Integer::~Integer() {

}

/**--------------------------------------------------------------------------**/
void Integer::visit(Visitor& visitor) {
  //return visitor.visitInteger(this);
}

void Integer::print() {
  cout<<value<<endl;
}

Expression* Integer::operator +( Expression& val) {
  return val.plus(*this);
}

Expression* Integer::operator -( Expression& val){
  return val.moins(*this);
}
Expression* Integer::operator * ( Expression& val){
  return val.mult(*this);
}
Expression* Integer::operator /( Expression& val){
  return val.div(*this);
}

Expression* Integer::operator < ( Expression& val){
  return val.inferieur(*this);
}
Expression* Integer::operator <=( Expression& val){
  return val.inferieurEgal(*this);
}
Expression* Integer::operator > ( Expression& val){
  return val.superieur(*this);
}
Expression* Integer::operator >=( Expression& val){
  return val.superieurEgal(*this);
}

Expression* Integer::plus( Integer& val){
  return new Integer(((int)val.value) + this->value);
}

Expression* Integer::plus( Float& val){
  throw runtime_error("Addition entre int et float");
}

Expression* Integer::plus( Boolean& val){
  throw runtime_error("Addition entre int et bool");
}

Expression* Integer::moins( Integer& val){
  return new Integer(((int)val.value) - this->value);
}

Expression* Integer::moins( Float& val){
  throw runtime_error("Soustraction entre int et float");
}

Expression* Integer::moins( Boolean& val){
  throw runtime_error("Soustraction  entre int et bool");
}

Expression* Integer::mult( Integer& val){
  return new Integer(((int)val.value) * this->value);
}

Expression* Integer::mult( Float& val){
  throw runtime_error("Multiplication entre int et float");
}

Expression* Integer::mult( Boolean& val){
  throw runtime_error("Multiplication entre int et bool");
}

Expression* Integer::div( Integer& val){
  return new Integer(((int)val.value) / this->value);
}

Expression* Integer::div( Float& val){
  throw runtime_error("Division entre int et float");
}
Expression* Integer::div( Boolean& val){
  throw runtime_error("Division entre int et bool");
}


Expression* Integer::pow( Integer& val){
  return new Integer(this->value^val.value);
}
Expression* Integer::pow( Float& val){
  throw runtime_error("Operation pow impossible entre int et float");
}
Expression* Integer::pow( Boolean& val){
  throw runtime_error("Operation pow impossible entre int et bool");
}

Expression* Integer::sqrt(){
  throw runtime_error("Operation sqrt impossible");
}

Expression* Integer::neg(){
  throw runtime_error("Operation neg impossible");
}


Expression* Integer::inferieur( Integer& val){
  return new Boolean(this->value<val.value);
}
Expression* Integer::inferieur( Float& val){
  throw runtime_error("Comparaison entre int et float");
}
Expression* Integer::inferieur( Boolean& val){
  throw runtime_error("Comparaison entre int et bool");
}


Expression* Integer::inferieurEgal( Integer& val){
  return new Boolean(this->value<=val.value);
}
Expression* Integer::inferieurEgal( Float& val){
  throw runtime_error("Comparaison entre int et float");
}
Expression* Integer::inferieurEgal( Boolean& val){
  throw runtime_error("Comparaison entre int et bool");
}


Expression* Integer::superieur ( Integer& val){
  return new Boolean(this->value>val.value);
}
Expression* Integer::superieur ( Float& val){
  throw runtime_error("Comparaison entre int et float");
}
Expression* Integer::superieur ( Boolean& val){
  throw runtime_error("Comparaison entre int et bool");
}


Expression* Integer::superieurEgal( Integer& val){
  return new Boolean(this->value>=val.value);
}
Expression* Integer::superieurEgal( Float& val){
  throw runtime_error("Comparaison entre int et float");
}
Expression* Integer::superieurEgal( Boolean& val){
  throw runtime_error("Comparaison entre int et bool");
}


Expression* Integer::diff( Integer& val){
  return new Boolean(this->value != val.value);
}
Expression* Integer::diff( Float& val){
  throw runtime_error("Comparaison entre int et float");
}
Expression* Integer::diff( Boolean& val){
  throw runtime_error("Comparaison entre int et bool");
}

Expression* Integer::egalite( Integer& val){
  return new Boolean(this->value == val.value);
}
Expression* Integer::egalite( Float& val){
  throw runtime_error("Comparaison entre int et float");
}
Expression* Integer::egalite( Boolean& val){
  throw runtime_error("Comparaison entre int et bool");
}
