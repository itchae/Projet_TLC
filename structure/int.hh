#ifndef _INT_H
#define _INT_H

#include "expr.hh"


class Integer : public Expression {
private:
  int value;
public:
  Integer(int v);
  ~Integer();

  inline int getValue() const { return value; }

  void visit(Visitor& visitor) const;
};

#endif
