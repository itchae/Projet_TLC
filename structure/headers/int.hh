#ifndef _INT_H
#define _INT_H

#include "expr.hh"
#include "float.hh"
#include "bool.hh"

using namespace std;

//class Boolean;
//class Float;

class Integer : public Expression {

  private:
    int value;

  public:
    Integer(int v);
    ~Integer();
    inline int getValue() const { return value; }
    Expression* calcul() { return this; }
    string getType() const { return "integer"; }
    void visit(Visitor& visitor);
    void print() const;



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

    Expression* pow(const Integer& val)const;
    Expression* pow(const Float& val)const;
    Expression* pow(const Boolean& val)const;

    Expression* sqrt(const Integer& val)const;
    Expression* sqrt(const Float& val)const;
    Expression* sqrt(const Boolean& val)const;

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

    Expression* diff(const Integer& val)const;
    Expression* diff(const Float& val)const;
    Expression* diff(const Boolean& val)const;

    Expression* egalite(const Integer& val)const;
    Expression* egalite(const Float& val)const;
    Expression* egalite(const Boolean& val)const;

};

#endif
