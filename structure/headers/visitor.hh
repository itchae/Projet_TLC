#ifndef VISITOR_H
#define VISITOR_H

using namespace std;

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
    virtual void visitDecl(const Decl *d)=0;
    virtual void visitAffect(const Affect *a);
    virtual void visitFonction(const Fonction *f);

};



#endif
