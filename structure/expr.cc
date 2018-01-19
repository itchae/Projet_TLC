#include "headers/expr.hh"


Expression* Expression::operator +( Expression& val){
  throw runtime_error("Operation + impossible");
}
Expression* Expression::operator -( Expression& val){
  throw runtime_error("Operation - impossible");
}
Expression* Expression::operator * ( Expression& val){
  throw runtime_error("Operation * impossible");
}
Expression* Expression::operator /( Expression& val){
  throw runtime_error("Operation / impossible");
}

Expression* Expression::operator < ( Expression& val){
  throw runtime_error("Operation < impossible");
}
Expression* Expression::operator <=( Expression& val){
  throw runtime_error("Operation <= impossible");
}
Expression* Expression::operator > ( Expression& val){
  throw runtime_error("Operation > impossible");
}
Expression* Expression::operator >=( Expression& val){
  throw runtime_error("Operation >= impossible");
}

Expression* Expression::plus( Integer& val){
  throw runtime_error("Operation plus impossible");
}
Expression* Expression::plus( Float& val){
  throw runtime_error("Operation plus impossible");
}
Expression* Expression::plus( Boolean& val){
  throw runtime_error("Operation plus impossible");
}

Expression* Expression::moins( Integer& val){
  throw runtime_error("Operation moins impossible");
}
Expression* Expression::moins( Float& val){
  throw runtime_error("Operation moins impossible");
}
Expression* Expression::moins( Boolean& val){
  throw runtime_error("Operation moins impossible");
}

Expression* Expression::mult( Integer& val){
  throw runtime_error("Operation mult impossible");
}
Expression* Expression::mult( Float& val){
  throw runtime_error("Operation mult impossible");
}
Expression* Expression::mult( Boolean& val){
  throw runtime_error("Operation mult impossible");
}

Expression* Expression::div( Integer& val){
  throw runtime_error("Operation div impossible");
}
Expression* Expression::div( Float& val){
  throw runtime_error("Operation div impossible");
}
Expression* Expression::div( Boolean& val){
  throw runtime_error("Operation div impossible");
}


Expression* Expression::pow( Integer& val){
  throw runtime_error("Operation pow impossible");
}
Expression* Expression::pow( Float& val){
  throw runtime_error("Operation pow impossible");
}
Expression* Expression::pow( Boolean& val){
  throw runtime_error("Operation pow impossible");
}

Expression* Expression::sqrt( Integer& val){
  throw runtime_error("Operation sqrt impossible");
}
Expression* Expression::sqrt( Float& val){
  throw runtime_error("Operation sqrt impossible");
}
Expression* Expression::sqrt( Boolean& val){
  throw runtime_error("Operation sqrt impossible");
}


Expression* Expression::inferieur( Integer& val){
  throw runtime_error("Operation inferieur impossible");
}
Expression* Expression::inferieur( Float& val){
  throw runtime_error("Operation inferieur impossible");
}
Expression* Expression::inferieur( Boolean& val){
  throw runtime_error("Operation inferieur impossible");
}


Expression* Expression::inferieurEgal( Integer& val){
  throw runtime_error("Operation inferieurEgal impossible");
}
Expression* Expression::inferieurEgal( Float& val){
  throw runtime_error("Operation inferieurEgal impossible");
}
Expression* Expression::inferieurEgal( Boolean& val){
  throw runtime_error("Operation inferieurEgal impossible");
}


Expression* Expression::superieur ( Integer& val){
  throw runtime_error("Operation superieur impossible");
}
Expression* Expression::superieur ( Float& val){
  throw runtime_error("Operation superieur impossible");
}
Expression* Expression::superieur ( Boolean& val){
  throw runtime_error("Operation superieur impossible");
}


Expression* Expression::superieurEgal( Integer& val){
  throw runtime_error("Operation superieurEgal impossible");
}
Expression* Expression::superieurEgal( Float& val){
  throw runtime_error("Operation superieurEgal impossible");
}
Expression* Expression::superieurEgal( Boolean& val){
  throw runtime_error("Operation superieurEgal impossible");
}

Expression* Expression::diff( Integer& val){
  throw runtime_error("Operation diff impossible");
}
Expression* Expression::diff( Float& val){
  throw runtime_error("Operation diff impossible");
}
Expression* Expression::diff( Boolean& val){
  throw runtime_error("Operation diff impossible");
}

Expression* Expression::egalite( Integer& val){
  throw runtime_error("Operation egalité impossible");
}
Expression* Expression::egalite( Float& val){
  throw runtime_error("Operation egalité impossible");
}
Expression* Expression::egalite( Boolean& val){
  throw runtime_error("Operation egalité impossible");
}
