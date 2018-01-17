#ifndef _EXPR_H
#define _EXPR_H

#include "term.hh"
#include <string>

using namespace std;

class Expression : public Term {

  public:
    ~Expression() { }
    virtual string getType() const = 0;


    /*virtual Expression* operator +(const Expression& val)const = 0;
    virtual Expression* operator -(const Expression& val)const = 0;/
    virtual Expression* operator * (const Expression& val)const = 0;
    virtual Expression* operator /(const Expression& val)const = 0;

    virtual Expression* operator < (const Expression& val)const = 0;
    virtual Expression* operator <=(const Expression& val)const = 0;/
    virtual Expression* operator > (const Expression& val)const = 0;
    virtual Expression* operator >=(const Expression& val)const = 0;

    virtual Expression* plus(const Integer& val)const = 0;
    virtual Expression* plus(const Float& val)const = 0;
    virtual Expression* plus(const Boolean& val)const = 0;

    virtual Expression* moins(const Integer& val)const = 0;
    virtual Expression* moins(const Float& val)const = 0;
    virtual Expression* moins(const Boolean& val)const = 0;

    virtual Expression* mult(const Integer& val)const = 0;
    virtual Expression* mult(const Float& val)const = 0;
    virtual Expression* mult(const Boolean& val)const = 0;

    virtual Expression* div(const Integer& val)const = 0;
    virtual Expression* div(const Float& val)const = 0;
    virtual Expression* div(const Boolean& val)const = 0;


    virtual Expression* inferieur(const Integer& val)const = 0;
    virtual Expression* inferieur(const Float& val)const = 0;
    virtual Expression* inferieur(const Boolean& val)const = 0;


    virtual Expression* inferieurEgal(const Integer& val)const = 0;
    virtual Expression* inferieurEgal(const Float& val)const = 0;
    virtual Expression* inferieurEgal(const Boolean& val)const = 0;


    virtual Expression* superieur (const Integer& val)const = 0;
    virtual Expression* superieur (const Float& val)const = 0;
    virtual Expression* superieur (const Boolean& val)const = 0;


    virtual Expression* superieurEgal(const Integer& val)const = 0;
    virtual Expression* superieurEgal(const Float& val)const = 0;
    virtual Expression* superieurEgal(const Boolean& val)const = 0;*/

};

#endif
