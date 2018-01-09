#include "printer.hh"
#include <iostream>

using namespace std;


void Printer::visitFloat(const Float *f) {
  cout<<f->getValue();
}

void Printer::visitInteger(const Integer *i) {
  cout<<i->getValue();
}

void Printer::visitOperator(const Operator *o) {
  cout<<"(";
  o->getLeft()->visit(*this);
  switch(o->getSymbol()) {
  case PLUS: cout<<"+"; break;
  case MOINS: cout<<"-"; break;
  case MULT: cout<<"*"; break;
  case DIV: cout<<"/"; break;
  case INF: cout<<"<"; break;
  case SUP: cout<<">"; break;
  case EGALITE: cout<<"=="; break;
  case DIFF: cout<<"!="; break;
  }
  o->getRight()->visit(*this);
  cout<<")";
}

void Printer::visitAffect(const Affect *a) {
  //TODO For each
  //cout<<a->getVars()<<" = ";
  //TODO for each expr
  //a->getExprs()->visit(*this);
  cout<<";"<<endl;
}

void Printer::visitDecl(const Decl *d) {
  cout<<"var "<<d->getVar()<<";"<<endl;
}

void Printer::visitClass(const Class *c) {
  //cout<<"Class " << c->getName();
  //TODO affichage element classe
}

void Printer::visitFonc(const Fonction *f) {
  cout<<"fonction " << f->getName();
  //affichage parametres
  cout<<"(";
  if (!f->noParam()){
    //TODO affichage parametre
  }
  //f->getInst()->visit();
  cout << "\n}";
}

void Printer::visitMethod(const Method *m) {
  //TODO affichage methode
}
