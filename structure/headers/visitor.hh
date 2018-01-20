#ifndef VISITOR_H
#define VISITOR_H

using namespace std;

class Bloc;
class Decl;
class Affect;
class Fonction;
class Call;
class CallExp;
class DeclClass;

class Visitor {

  public:
    virtual void visitDecl(Decl *d)=0;
    virtual void visitAffect(Affect *a)=0;
    virtual void visitFonction(Fonction *f)=0;
    virtual void visitCall(Call *c)=0;
    virtual void visitBloc(Bloc *b)=0;
    virtual void visitDeclClass(DeclClass *c)=0;
    virtual void visitCallExp(CallExp *c)=0;

};



#endif
