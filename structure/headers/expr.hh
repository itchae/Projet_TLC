#ifndef _EXPR_H
#define _EXPR_H

#include "term.hh"
#include <string>

using namespace std;

class Expression : public Term {

  public:
    ~Expression() { }
    virtual string getType() const = 0;
};

#endif
