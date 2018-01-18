#include "headers/expr.hh"


Expression* Expression::operator +(const Expression& val)const{
  throw runtime_error("Operation + impossible");
}
Expression* Expression::operator -(const Expression& val)const{
  throw runtime_error("Operation - impossible");
}
Expression* Expression::operator * (const Expression& val)const{
  throw runtime_error("Operation * impossible");
}
Expression* Expression::operator /(const Expression& val)const{
  throw runtime_error("Operation / impossible");
}

Expression* Expression::operator < (const Expression& val)const{
  throw runtime_error("Operation < impossible");
}
Expression* Expression::operator <=(const Expression& val)const{
  throw runtime_error("Operation <= impossible");
}
Expression* Expression::operator > (const Expression& val)const{
  throw runtime_error("Operation > impossible");
}
Expression* Expression::operator >=(const Expression& val)const{
  throw runtime_error("Operation >= impossible");
}

Expression* Expression::plus(const Integer& val)const{
  throw runtime_error("Operation plus impossible");
}
Expression* Expression::plus(const Float& val)const{
  throw runtime_error("Operation plus impossible");
}
Expression* Expression::plus(const Boolean& val)const{
  throw runtime_error("Operation plus impossible");
}

Expression* Expression::moins(const Integer& val)const{
  throw runtime_error("Operation moins impossible");
}
Expression* Expression::moins(const Float& val)const{
  throw runtime_error("Operation moins impossible");
}
Expression* Expression::moins(const Boolean& val)const{
  throw runtime_error("Operation moins impossible");
}

Expression* Expression::mult(const Integer& val)const{
  throw runtime_error("Operation mult impossible");
}
Expression* Expression::mult(const Float& val)const{
  throw runtime_error("Operation mult impossible");
}
Expression* Expression::mult(const Boolean& val)const{
  throw runtime_error("Operation mult impossible");
}

Expression* Expression::div(const Integer& val)const{
  throw runtime_error("Operation div impossible");
}
Expression* Expression::div(const Float& val)const{
  throw runtime_error("Operation div impossible");
}
Expression* Expression::div(const Boolean& val)const{
  throw runtime_error("Operation div impossible");
}


Expression* Expression::inferieur(const Integer& val)const{
  throw runtime_error("Operation inferieur impossible");
}
Expression* Expression::inferieur(const Float& val)const{
  throw runtime_error("Operation inferieur impossible");
}
Expression* Expression::inferieur(const Boolean& val)const{
  throw runtime_error("Operation inferieur impossible");
}


Expression* Expression::inferieurEgal(const Integer& val)const{
  throw runtime_error("Operation inferieurEgal impossible");
}
Expression* Expression::inferieurEgal(const Float& val)const{
  throw runtime_error("Operation inferieurEgal impossible");
}
Expression* Expression::inferieurEgal(const Boolean& val)const{
  throw runtime_error("Operation inferieurEgal impossible");
}


Expression* Expression::superieur (const Integer& val)const{
  throw runtime_error("Operation superieur impossible");
}
Expression* Expression::superieur (const Float& val)const{
  throw runtime_error("Operation superieur impossible");
}
Expression* Expression::superieur (const Boolean& val)const{
  throw runtime_error("Operation superieur impossible");
}


Expression* Expression::superieurEgal(const Integer& val)const{
  throw runtime_error("Operation superieurEgal impossible");
}
Expression* Expression::superieurEgal(const Float& val)const{
  throw runtime_error("Operation superieurEgal impossible");
}
Expression* Expression::superieurEgal(const Boolean& val)const{
  throw runtime_error("Operation superieurEgal impossible");
}
