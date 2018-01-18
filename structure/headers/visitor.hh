#ifndef VISITOR_H
#define VISITOR_H

using namespace std;

class Decl;
class Affect;
class Fonction;
class Call;

class Visitor {

  public:
    virtual void visitDecl(Decl *d)=0;
    virtual void visitAffect(Affect *a)=0;
    virtual void visitFonction(Fonction *f)=0;
    virtual void visitCall(Call *c)=0;

};



#endif
