#ifndef _INST_H
#define _INST_H

#include "term.hh"

using namespace std;

class Instruction : public Term {

  public:
    ~Instruction() { }
    virtual void visit(Visitor& visitor) const = 0;

};

#endif
