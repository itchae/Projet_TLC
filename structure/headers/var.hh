#ifndef _TERM_H
#define _TERM_H

#include <iostream>
#include <string>
#include "visitor.hh"

using namespace std;

class Variable {

  private:
    string name;
    Expression* var;

  public:
    Variable(string,Expression*);
    Variable(string);
    virtual ~Variable() { }
    void visit(Visitor& visitor);

};

#endif
