#include "printer.hh"
#include <iostream>

using namespace std;


void Printer::visitFloat(const Float *f) {
  cout<<f->getValue();
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
  cout<<a->getVar()<<" = ";
  a->getExpr()->visit(*this);
  cout<<";"<<endl;
}

void Printer::visitBlock(const Block *b) {
  cout<<"{"<<endl;
  b->getBody()->visit(*this);
  cout<<"}"<<endl;
}

void Printer::visitCond(const Cond *c) {
  cout<<"if(";
  c->getCond()->visit(*this);
  cout<<")"<<endl;
  c->getCons()->visit(*this);
  if(c->getAlt() != NULL){ 	
  	cout<<endl<<"else"<<endl;
  	c->getAlt()->visit(*this);
  }
}

void Printer::visitDecl(const Decl *d) {
  cout<<"var "<<d->getVar()<<";"<<endl;
}

void Printer::visitWhile(const While *w) {
  cout<<"while(";
  w->getCond()->visit(*this);
  cout<<")"<<endl;
  w->getBody()->visit(*this);
}

void Printer::visitSeq(const Sequence *s) {
  //cout<<"ATTENTION Inversion possible (en fct de votre algo)!"<<endl;
  SeqItem *t = s->getFirst();
  while(t != NULL) {
    t->getInst()->visit(*this);
    t = t->getNext();
  }
  //cout<<"ATTENTION Inversion possible (en fct de votre algo)!"<<endl;
}
