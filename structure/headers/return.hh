#ifndef _RETURN_H
#define _RETURN_H

#include "inst.hh"
#include "expr.hh"

using namespace std;

/**
 * Return des fonctions
 */
class Return : public Instruction, public Expression {

  private:
    Expression* expr;

  public:
    Return(Expression* e);
    ~Return();
    string getType() const;
    inline const Expression* getExpr() const { return expr; }
    void visit(Visitor& visitor);

};


#endif
