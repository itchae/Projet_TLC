#ifndef _BOOL_H
#define _BOOL_H

#include "expr.hh"


class Boolean : public Expression {
private:
  bool value;
public:
  Boolean(bool v);
  ~Boolean();

  inline bool getValue() const { return value; }

  void visit(Visitor& visitor) const;
};

#endif
