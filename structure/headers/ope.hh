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
  EGALITE,
  DIFF,
};

/**
 * Classe représentant une opération (+,-,/,*)
 */
class Operator : public Expression {

  private:
    Expression *left;
    OperatorSymbol symbol;
    Expression *right;

  public:
    Operator(OperatorSymbol symbol, Expression *left, Expression *right);
    ~Operator();
    inline const Expression* getLeft() const { return left; }
    inline const Expression* getRight() const { return right; }
    inline const OperatorSymbol getSymbol() const { return symbol;}
    string getType() const;
    void visit(Visitor& visitor);
    void calcul();
    void print() const;

};

#endif
