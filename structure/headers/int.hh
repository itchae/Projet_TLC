#ifndef _INT_H
#define _INT_H

#include "expr.hh"
#include "float.hh"
#include "bool.hh"

using namespace std;

class Integer : public Expression {

  private:
    int value;

  public:
    Integer(int v);
    ~Integer();
    inline int getValue()  { return value; }
    Expression* calcul() { return this; }
    string getType()  { return "integer"; }
    void visit(Visitor& visitor);
    void print() ;



    Expression* operator +( Expression& val);
    Expression* operator -( Expression& val);
    Expression* operator * ( Expression& val);
    Expression* operator /( Expression& val);

    Expression* operator < ( Expression& val);
    Expression* operator <=( Expression& val);
    Expression* operator > ( Expression& val);
    Expression* operator >=( Expression& val);

    Expression* plus( Integer& val);
    Expression* plus( Float& val);
    Expression* plus( Boolean& val);

    Expression* moins( Integer& val);
    Expression* moins( Float& val);
    Expression* moins( Boolean& val);

    Expression* mult( Integer& val);
    Expression* mult( Float& val);
    Expression* mult( Boolean& val);

    Expression* div( Integer& val);
    Expression* div( Float& val);
    Expression* div( Boolean& val);

    Expression* pow( Integer& val);
    Expression* pow( Float& val);
    Expression* pow( Boolean& val);

    Expression* sqrt();

    Expression* neg();

    Expression* inferieur( Integer& val);
    Expression* inferieur( Float& val);
    Expression* inferieur( Boolean& val);


    Expression* inferieurEgal( Integer& val);
    Expression* inferieurEgal( Float& val);
    Expression* inferieurEgal( Boolean& val);


    Expression* superieur ( Integer& val);
    Expression* superieur ( Float& val);
    Expression* superieur ( Boolean& val);


    Expression* superieurEgal( Integer& val);
    Expression* superieurEgal( Float& val);
    Expression* superieurEgal( Boolean& val);

    Expression* diff( Integer& val);
    Expression* diff( Float& val);
    Expression* diff( Boolean& val);

    Expression* egalite( Integer& val);
    Expression* egalite( Float& val);
    Expression* egalite( Boolean& val);

};

#endif
