#ifndef _OPE_H
#define _OPE_H

#include "expr.hh"
#include "bool.hh"
#include "int.hh"
#include "float.hh"

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
  POW,
  NEGA
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
    Operator(OperatorSymbol symbol, Expression *left);
    ~Operator();
    inline const Expression* getLeft() const { return left; }
    inline const Expression* getRight() const { return right; }
    inline const OperatorSymbol getSymbol() const { return symbol;}
    string getType();
    void visit(Visitor& visitor);
    Expression* calculOperation();
    void print();

};

#endif
