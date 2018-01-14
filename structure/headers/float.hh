#ifndef _FLOAT_H
#define _FLOAT_H

#include "expr.hh"

using namespace std;

class Float : public Expression {

  private:
    double value;

  public:
    Float(double v);
    ~Float();
    inline double getValue() const { return value; }
    void visit(Visitor& visitor) const;

};

#endif
