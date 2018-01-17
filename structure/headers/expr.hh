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

    virtual Expression* plus(const IntValue& val)const = 0;
    virtual Expression* plus(const FloatValue& val)const = 0;
    virtual Expression* plus(const BoolValue& val)const = 0;

    virtual Expression* moins(const IntValue& val)const = 0;
    virtual Expression* moins(const FloatValue& val)const = 0;
    virtual Expression* moins(const BoolValue& val)const = 0;

    virtual Expression* mult(const IntValue& val)const = 0;
    virtual Expression* mult(const FloatValue& val)const = 0;
    virtual Expression* mult(const BoolValue& val)const = 0;

    virtual Expression* div(const IntValue& val)const = 0;
    virtual Expression* div(const FloatValue& val)const = 0;
    virtual Expression* div(const BoolValue& val)const = 0;


    virtual Expression* inferieur(const IntValue& val)const = 0;
    virtual Expression* inferieur(const FloatValue& val)const = 0;
    virtual Expression* inferieur(const BoolValue& val)const = 0;


    virtual Expression* inferieurEgal(const IntValue& val)const = 0;
    virtual Expression* inferieurEgal(const FloatValue& val)const = 0;
    virtual Expression* inferieurEgal(const BoolValue& val)const = 0;


    virtual Expression* superieur (const IntValue& val)const = 0;
    virtual Expression* superieur (const FloatValue& val)const = 0;
    virtual Expression* superieur (const BoolValue& val)const = 0;


    virtual Expression* superieurEgal(const IntValue& val)const = 0;
    virtual Expression* superieurEgal(const FloatValue& val)const = 0;
    virtual Expression* superieurEgal(const BoolValue& val)const = 0;*/

};

#endif
