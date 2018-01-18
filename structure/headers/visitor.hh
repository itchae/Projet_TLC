#ifndef VISITOR_H
#define VISITOR_H

using namespace std;

class Decl;
class Affect;
class Fonction;
class Call;

class Visitor {

  public:
    virtual void visitDecl(const Decl *d)=0;
    virtual void visitAffect(const Affect *a)=0;
    virtual void visitFonction(const Fonction *f)=0;
    virtual void visitCall(const Call *c)=0;

};



#endif
