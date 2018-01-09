#ifndef _PRINTER_H
#define _PRINTER_H


#include "visitor.hh"
#include "affect.hh"
#include "decl.hh"
#include "float.hh"
#include "ope.hh"
#include "fonc.hh"
#include "method.hh"
#include "int.hh"


class Printer : public Visitor {
public:
  void visitFloat(const Float *f);
  void visitInteger(const Integer *i);
  void visitOperator(const Operator *o);
  void visitAffect(const Affect *a);
  void visitDecl(const Decl *d);
  void visitClass(const Class *c);
  void visitFonc(const Fonction *f);
  void visitMethod(const Method *m);
};


#endif
