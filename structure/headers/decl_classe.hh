#ifndef _DECLCLASSE_H
#define _DECLCLASSE_H

#include "inst.hh"
#include "class.hh"

using namespace std;

/**
 * Declaration des variables de classe
 */
class DeclClass : public Instruction {

  private:
    Class* classe;

  public:
    DeclClass(Class* c);
    ~DeclClass();
    inline Class* getClass() { return classe; }
    void visit(Visitor& visitor);

};


#endif
