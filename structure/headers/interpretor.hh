#ifndef _INTERPRETOR_H
#define _INTERPRETOR_H

#include "affect.hh"
#include "decl.hh"
#include "fonc.hh"
#include "call.hh"

using namespace std;

//réalise les instructions
//ajoute les variables et déclarations à la table des symboles
class Interpretor {

  public:
    void visitDecl(const Decl *d);
    void visitAffect(const Affect *a);
    void visitFonction(const Fonction *f);
    void visitCall(const Call *c);

};


#endif
