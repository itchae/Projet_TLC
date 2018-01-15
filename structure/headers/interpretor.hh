#ifndef _INTERPRETOR_H
#define _INTERPRETOR_H

#include "affect.hh"
#include "decl.hh"
#include "fonc.hh"

using namespace std;

class Interpretor {

  public:
    void visitDecl(const Decl *d);
    void visitAffect(const Affect *a);
    void visitFonction(const Fonction *f);
    
};


#endif
