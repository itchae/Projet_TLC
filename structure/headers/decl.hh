#ifndef _DECL_H
#define _DECL_H

#include "inst.hh"

using namespace std;

/**
 * Declaration des variables de classe
 */
class Decl : public Instruction {

  private:
    string var; //Nom de la variable
    string type; //Type de la variable

  public:
    Decl(string var, string type);
    ~Decl();
    inline const string getVar() const { return var; }
    inline const string getType() const { return type; }
    void visit(Visitor& visitor);
    void print(); 

};


#endif
