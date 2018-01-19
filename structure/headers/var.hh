#ifndef _VAR_H
#define _VAR_H

#include <iostream>
#include <string>
#include "visitor.hh"
#include "expr.hh"

using namespace std;

class Variable {

  private:
    string name;
    Expression* var;

  public:
    Variable(string n, Expression* e);
    Variable(string n);
    ~Variable();
    inline string getName() const { return name; }
    inline Expression* getVar() const { return var; }
    void visit(Visitor& visitor);

};

#endif
