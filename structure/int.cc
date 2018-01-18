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


Expression* Integer::operator +(const Expression& val)const {
  return val.plus(*this);
}

Expression* Integer::operator -(const Expression& val)const{
  return val.moins(*this);
}
Expression* Integer::operator * (const Expression& val)const{
  return val.mult(*this);
}
Expression* Integer::operator /(const Expression& val)const{
  return val.div(*this);
}

Expression* Integer::operator < (const Expression& val)const{
  return val.inferieur(*this);
}
Expression* Integer::operator <=(const Expression& val)const{
  return val.inferieurEgal(*this);
}
Expression* Integer::operator > (const Expression& val)const{
  return val.superieur(*this);
}
Expression* Integer::operator >=(const Expression& val)const{
  return val.superieurEgal(*this);
}

Expression* Integer::plus(const Integer& val)const{
  return new Integer(((int)val.value) + this->value);
}

Expression* Integer::plus(const Float& val)const{
  throw "Addition entre int et float";
}

Expression* Integer::plus(const Boolean& val)const{
  throw "Addition entre int et bool";
}

Expression* Integer::moins(const Integer& val)const{
  return new Integer(((int)val.value) - this->value);
}

Expression* Integer::moins(const Float& val)const{
  throw "Soustraction entre int et float";
}

Expression* Integer::moins(const Boolean& val)const{
  throw "Soustraction  entre int et bool";
}

Expression* Integer::mult(const Integer& val)const{
  return new Integer(((int)val.value) * this->value);
}

Expression* Integer::mult(const Float& val)const{
  throw "Multiplication entre int et float";
}

Expression* Integer::mult(const Boolean& val)const{
  throw "Multiplication entre int et bool";
}

Expression* Integer::div(const Integer& val)const{
  return new Integer(((int)val.value) / this->value);
}

Expression* Integer::div(const Float& val)const{
  throw "Division entre int et float";
}
Expression* Integer::div(const Boolean& val)const{
  throw "Division entre int et bool";
}

Expression* Integer::inferieur(const Integer& val)const{
  return new Boolean(this->value<val.value);
}
Expression* Integer::inferieur(const Float& val)const{
  throw "Comparaison entre int et float";
}
Expression* Integer::inferieur(const Boolean& val)const{
  throw "Comparaison entre int et bool";
}


Expression* Integer::inferieurEgal(const Integer& val)const{
  return new Boolean(this->value<=val.value);
}
Expression* Integer::inferieurEgal(const Float& val)const{
  throw "Comparaison entre int et float";
}
Expression* Integer::inferieurEgal(const Boolean& val)const{
  throw "Comparaison entre int et bool";
}


Expression* Integer::superieur (const Integer& val)const{
  return new Boolean(this->value>val.value);
}
Expression* Integer::superieur (const Float& val)const{
  throw "Comparaison entre int et float";
}
Expression* Integer::superieur (const Boolean& val)const{
  throw "Comparaison entre int et bool";
}


Expression* Integer::superieurEgal(const Integer& val)const{
  return new Boolean(this->value>=val.value);
}
Expression* Integer::superieurEgal(const Float& val)const{
  throw "Comparaison entre int et float";
}
Expression* Integer::superieurEgal(const Boolean& val)const{
  throw "Comparaison entre int et bool";
}
