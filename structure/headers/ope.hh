#ifndef _OPE_H
#define _OPE_H

#include "expr.hh"

using namespace std;

enum OperatorSymbol {
  PLUS,
  MOINS,
  MULT,
  DIV,
  INF,
  SUP,
  INFEG,
  SUPEG,
  EGALITE,
  DIFF,
  SQRT,
  POW
};

/**
 * Classe représentant une opération (+,-,/,*)
 */
class Operator : public Expression {

  private:
    const Expression *left;
    OperatorSymbol symbol;
    const Expression *right;

  public:
    Operator(OperatorSymbol symbol, Expression *left, Expression *right);
    ~Operator();
    inline const Expression* getLeft() const { return left; }
    inline const Expression* getRight() const { return right; }
    inline const OperatorSymbol getSymbol() const { return symbol;}
    string getType() const;
    void visit(Visitor& visitor);
    Expression* calculOperation();
    void print() const;

};

#endif
