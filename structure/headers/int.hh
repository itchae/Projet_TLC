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
    string getType() const { return "integer"; }
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


    virtual Expression* inferieur(const Integer& val)const;
    virtual Expression* inferieur(const Float& val)const;
    virtual Expression* inferieur(const Boolean& val)const;


    virtual Expression* inferieurEgal(const Integer& val)const;
    virtual Expression* inferieurEgal(const Float& val)const;
    virtual Expression* inferieurEgal(const Boolean& val)const;


    virtual Expression* superieur (const Integer& val)const;
    virtual Expression* superieur (const Float& val)const;
    virtual Expression* superieur (const Boolean& val)const;


    virtual Expression* superieurEgal(const Integer& val)const;
    virtual Expression* superieurEgal(const Float& val)const;
    virtual Expression* superieurEgal(const Boolean& val)const;

};

#endif
