#ifndef _DECL_H
#define _DECL_H

#include "inst.hh"
//#include "class.hh"

class Decl : public Instruction {
private:
  string var;
  string type;
public:
  Decl(string var, string type);
  ~Decl();

  inline const string getVar() const { return var; }

  void visit(Visitor& visitor) const;

};


#endif
