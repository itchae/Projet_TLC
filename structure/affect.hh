#ifndef _AFFECT_H
#define _AFFECT_H

#include <vector>
#include "inst.hh"
#include "expr.hh"

class Affect : public Instruction {
private:
  vector<string> vars;
  vector<Expression*> exprs;
public:
  Affect(vector<string> v, vector<Expression*> e)
  ~Affect();

  inline vector<string> getVars() const { return vars; }
  inline const vector<Expression*> getExprs() const { return exprs; }

  void visit(Visitor& visitor) const;
};


#endif
