#ifndef _BLOC_H
#define _BLOC_H

#include "inst.hh"
#include <vector>
#include "visitor.hh"

class Bloc{

  private:
    vector<Instruction*> instructs;

  public:
    Bloc(vector<Instruction*> i);
    ~Bloc();
    inline vector<Instruction*> getInsts() { return instructs; }
    void visit(Visitor& visitor);
};

#endif
