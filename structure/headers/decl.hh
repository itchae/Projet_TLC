#ifndef _DECL_H
#define _DECL_H

#include "inst.hh"
#include "class.hh"

class Decl : public Instruction {
private:
  string var;
  Class* type;
public:
  Decl(string var, Class* type);
  ~Decl();

  inline const string getVar() const { return var; }

  void visit(Visitor& visitor) const;

};


#endif
