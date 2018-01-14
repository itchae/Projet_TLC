#ifndef _AFFECT_H
#define _AFFECT_H

#include <vector>
#include "inst.hh"
#include "expr.hh"

using namespace std;

/**
 * Affectation d'une valeur à une variable déclarée
 */
class Affect : public Instruction {

  private:
    Decl* var;
    vector<Expression*> exprs;

  public:
    Affect(Decl* v, vector<Expression*> e);
    Affect(Decl* v, Expression* e);
    ~Affect();
    inline Decl* getVar() const { return var; }
    inline const vector<Expression*> getExprs() const { return exprs; }
    void visit(Visitor& visitor) const;

};


#endif
