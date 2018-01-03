#ifndef _PRINTER_H
#define _PRINTER_H


#include "visitor.hh"
#include "while.hh"
#include "affect.hh"
#include "block.hh"
#include "cond.hh"
#include "decl.hh"
#include "float.hh"
#include "ope.hh"
#include "seq.hh"


class Printer : public Visitor {
public:
  void visitFloat(const Float *f);
  void visitOperator(const Operator *o);
  void visitAffect(const Affect *a);
  void visitBlock(const Block *b);
  void visitCond(const Cond *c);
  void visitDecl(const Decl *d);
  void visitWhile(const While *w);
  void visitSeq(const Sequence *s);
};


#endif
