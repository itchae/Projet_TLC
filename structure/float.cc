#include "headers/float.hh"

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



Expression* Float::operator +(const Expression& val)const {
  return val.plus(*this);
}

Expression* Float::operator -(const Expression& val)const{
  return val.moins(*this);
}
Expression* Float::operator * (const Expression& val)const{
  return val.mult(*this);
}
Expression* Float::operator /(const Expression& val)const{
  return val.div(*this);
}

Expression* Float::operator < (const Expression& val)const{

}
Expression* Float::operator <=(const Expression& val)const{

}
Expression* Float::operator > (const Expression& val)const{

}
Expression* Float::operator >=(const Expression& val)const{

}

Expression* Float::plus(const Integer& val)const{
  throw "Addition entre float et int";
}

Expression* Float::plus(const Float& val)const{
  return new Float(((float)val.value) + this->value);
}

Expression* Float::plus(const Boolean& val)const{
  throw "Addition entre float et bool";
}

Expression* Float::moins(const Integer& val)const{
  throw "Soustraction entre float et int";
}

Expression* Float::moins(const Float& val)const{
  return new Float(((float)val.value) - this->value);
}

Expression* Float::moins(const Boolean& val)const{
  throw "Soustraction  entre float et bool";
}

Expression* Float::mult(const Integer& val)const{
  throw "Multiplication entre float et int";
}

Expression* Float::mult(const Float& val)const{
  return new Float(((float)val.value) * this->value);
}

Expression* Float::mult(const Boolean& val)const{
  throw "Multiplication entre float et bool";
}

Expression* Float::div(const Integer& val)const{
  throw "Division entre float et int";
}

Expression* Float::div(const Float& val)const{
  return new Float(((float)val.value) / this->value);
}
Expression* Float::div(const Boolean& val)const{
  throw "Division entre float et bool";
}




Expression* Float::inferieur(const Integer& val)const{
  throw "Comparaison entre float et int";
}
Expression* Float::inferieur(const Float& val)const{
  return new Boolean(this->value<val.value);
}
Expression* Float::inferieur(const Boolean& val)const{
  throw "Comparaison entre float et bool";
}


Expression* Float::inferieurEgal(const Integer& val)const{
  throw "Comparaison entre float et int";
}
Expression* Float::inferieurEgal(const Float& val)const{
  return new Boolean(this->value<=val.value);
}
Expression* Float::inferieurEgal(const Boolean& val)const{
  throw "Comparaison entre float et bool";
}


Expression* Float::superieur (const Integer& val)const{
  throw "Comparaison entre float et int";
}
Expression* Float::superieur (const Float& val)const{
  return new Boolean(this->value>val.value);
}
Expression* Float::superieur (const Boolean& val)const{
  throw "Comparaison entre float et bool";
}


Expression* Float::superieurEgal(const Integer& val)const{
  throw "Comparaison entre float et int";
}
Expression* Float::superieurEgal(const Float& val)const{
  return new Boolean(this->value>=val.value);
}
Expression* Float::superieurEgal(const Boolean& val)const{
  throw "Comparaison entre float et bool";
}
