#ifndef _EXPR_H
#define _EXPR_H

#include "term.hh"
#include <string>

using namespace std;

class Integer;
class Float;
class Boolean;

class Expression : public Term {

  public:
    virtual ~Expression() {}
    virtual string getType()  = 0;
    virtual void print() = 0;
    virtual Expression* calcul() {return NULL;}

    virtual Expression* operator +( Expression& val);
    virtual Expression* operator -( Expression& val);
    virtual Expression* operator * ( Expression& val);
    virtual Expression* operator /( Expression& val) ;

    virtual Expression* operator < ( Expression& val) ;
    virtual Expression* operator <=( Expression& val) ;
    virtual Expression* operator > ( Expression& val) ;
    virtual Expression* operator >=( Expression& val) ;

    virtual Expression* plus( Integer& val);
    virtual Expression* plus( Float& val);
    virtual Expression* plus( Boolean& val);

    virtual Expression* moins( Integer& val);
    virtual Expression* moins( Float& val);
    virtual Expression* moins( Boolean& val);

    virtual Expression* mult( Integer& val);
    virtual Expression* mult( Float& val);
    virtual Expression* mult( Boolean& val);

    virtual Expression* div( Integer& val);
    virtual Expression* div( Float& val);
    virtual Expression* div( Boolean& val);

    virtual Expression* pow( Integer& val);
    virtual Expression* pow( Float& val);
    virtual Expression* pow( Boolean& val);

    virtual Expression* sqrt();

    virtual Expression* neg();

    virtual Expression* inferieur( Integer& val);
    virtual Expression* inferieur( Float& val);
    virtual Expression* inferieur( Boolean& val);


    virtual Expression* inferieurEgal( Integer& val);
    virtual Expression* inferieurEgal( Float& val);
    virtual Expression* inferieurEgal( Boolean& val);


    virtual Expression* superieur ( Integer& val);
    virtual Expression* superieur ( Float& val);
    virtual Expression* superieur ( Boolean& val);


    virtual Expression* superieurEgal( Integer& val);
    virtual Expression* superieurEgal( Float& val);
    virtual Expression* superieurEgal( Boolean& val);

    virtual Expression* diff( Integer& val);
    virtual Expression* diff( Float& val);
    virtual Expression* diff( Boolean& val);

    virtual Expression* egalite( Integer& val);
    virtual Expression* egalite( Float& val);
    virtual Expression* egalite( Boolean& val);



};

#endif
