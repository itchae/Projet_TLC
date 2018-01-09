#ifndef VISITOR_H
#define VISITOR_H


class Float;
class Integer;
class Operator;
class Affect;
class Decl;
class Fonction;
class Class;
class Method;

class Visitor {
public:
  virtual void visitFloat(const Float *f) = 0;
  virtual void visitInteger(const Integer *i) = 0;
  virtual void visitOperator(const Operator *o) = 0;
  virtual void visitAffect(const Affect *a) = 0;
  virtual void visitDecl(const Decl *d) = 0;
  virtual void visitFonc(const Fonction *f) = 0;
  virtual void visitMethod(const Method *m) = 0;
  virtual void visitClass(const Class *c) = 0;
};



#endif
