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
    virtual ~Expression() = default;
    virtual string getType() const = 0;
    virtual void print() const = 0;
    virtual Expression* calcul();

    virtual Expression* operator +(const Expression& val)const;
    virtual Expression* operator -(const Expression& val)const;
    virtual Expression* operator * (const Expression& val)const;
    virtual Expression* operator /(const Expression& val)const;

    virtual Expression* operator < (const Expression& val)const;
    virtual Expression* operator <=(const Expression& val)const;
    virtual Expression* operator > (const Expression& val)const;
    virtual Expression* operator >=(const Expression& val)const;

    virtual Expression* plus(const Integer& val)const;
    virtual Expression* plus(const Float& val)const;
    virtual Expression* plus(const Boolean& val)const;

    virtual Expression* moins(const Integer& val)const;
    virtual Expression* moins(const Float& val)const;
    virtual Expression* moins(const Boolean& val)const;

    virtual Expression* mult(const Integer& val)const;
    virtual Expression* mult(const Float& val)const;
    virtual Expression* mult(const Boolean& val)const;

    virtual Expression* div(const Integer& val)const;
    virtual Expression* div(const Float& val)const;
    virtual Expression* div(const Boolean& val)const;


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
