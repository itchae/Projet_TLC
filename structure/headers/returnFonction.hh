#ifndef _RETURNFONCTION_H
#define _RETURNFONCTION_H
#include "expr.hh"
#include "fonc.hh"

class ReturnFonction : public Fonction {

private:
  Expression* retour;

public:
  Expression* calcul() const;
  string getTypeRetour() const;




};

#endif