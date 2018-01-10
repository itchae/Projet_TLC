#ifndef _DECL_H
#define _DECL_H

#include "inst.hh"

enum Type {
  BOOLEAN,
  FLOAT,
  INTEGER,
};

class Decl : public Instruction {
private:
  string var;
  Type type;
public:
  Decl(string var, Type type);
  ~Decl();

  inline const string getVar() const { return var; }

  void visit(Visitor& visitor) const;

};


#endif
