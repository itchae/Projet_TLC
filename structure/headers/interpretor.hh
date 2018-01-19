#ifndef _INTERPRETOR_H
#define _INTERPRETOR_H

#include "affect.hh"
#include "decl.hh"
#include "fonc.hh"
#include "call.hh"
#include "visitor.hh"
#include "voidFonction.hh"
#include "bloc.hh"

using namespace std;

//réalise les instructions
//ajoute les variables et déclarations à la table des symboles
class Interpretor : public Visitor{

  public:
    void visitDecl(Decl *d);
    void visitAffect(Affect *a);
    void visitFonction(Fonction *f);
    void visitCall(Call *c);
    void visitBloc(Bloc *b);

};


#endif
