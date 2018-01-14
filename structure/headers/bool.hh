#ifndef _BOOL_H
#define _BOOL_H

#include "expr.hh"

using namespace std;

/**
 * Classe représentant un boolean
 */
class Boolean : public Expression {

  private:
    bool value;

  public:
    Boolean(bool v);
    ~Boolean();
    inline bool getValue() const { return value; }
    string getType() const { return "boolean"; }
    void visit(Visitor& visitor) const;

};

#endif
