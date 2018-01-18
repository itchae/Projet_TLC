#ifndef _FLOAT_H
#define _FLOAT_H

#include "expr.hh"
#include "bool.hh"
#include "int.hh"

using namespace std;

//class Integer;
//class Boolean;

class Float : public Expression {

  private:
    double value;

  public:
    Float(double v);
    ~Float();
    inline double getValue() const { return value; }
    string getType() const { return "float"; }
    void visit(Visitor& visitor);


    Expression* operator +(const Expression& val)const;
    Expression* operator -(const Expression& val)const;
    Expression* operator * (const Expression& val)const;
    Expression* operator /(const Expression& val)const;

    Expression* operator < (const Expression& val)const;
    Expression* operator <=(const Expression& val)const;
    Expression* operator > (const Expression& val)const;
    Expression* operator >=(const Expression& val)const;

    Expression* plus(const Integer& val)const;
    Expression* plus(const Float& val)const;
    Expression* plus(const Boolean& val)const;

    Expression* moins(const Integer& val)const;
    Expression* moins(const Float& val)const;
    Expression* moins(const Boolean& val)const;

    Expression* mult(const Integer& val)const;
    Expression* mult(const Float& val)const;
    Expression* mult(const Boolean& val)const;

    Expression* div(const Integer& val)const;
    Expression* div(const Float& val)const;
    Expression* div(const Boolean& val)const;


    Expression* inferieur(const Integer& val)const;
    Expression* inferieur(const Float& val)const;
    Expression* inferieur(const Boolean& val)const;


    Expression* inferieurEgal(const Integer& val)const;
    Expression* inferieurEgal(const Float& val)const;
    Expression* inferieurEgal(const Boolean& val)const;


    Expression* superieur (const Integer& val)const;
    Expression* superieur (const Float& val)const;
    Expression* superieur (const Boolean& val)const;


    Expression* superieurEgal(const Integer& val)const;
    Expression* superieurEgal(const Float& val)const;
    Expression* superieurEgal(const Boolean& val)const;
};

#endif
