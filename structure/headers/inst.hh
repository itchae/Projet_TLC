#ifndef _INST_H
#define _INST_H

#include "term.hh"

using namespace std;

class Instruction : public Term {

  public:
    virtual ~Instruction() { }
    virtual void visit(Visitor& visitor) = 0;

};

#endif
