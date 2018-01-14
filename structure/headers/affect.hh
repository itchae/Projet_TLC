#ifndef _AFFECT_H
#define _AFFECT_H

#include <vector>
#include "inst.hh"
#include "expr.hh"
#include "symbolTable.hh"

using namespace std;

/**
 * Affectation d'une valeur à une variable déclarée
 */
class Affect : public Instruction {

  private:
    vector<Decl*> vars;
    vector<Expression*> exprs;
    /**
     * Renvoie vrai si les declarations et les expressions ont le meme type
     * @return vrai si les declarations et les expressions ont le meme type
     */
    bool memeType(vector<Decl*> v, vector<Expression*> e);

  public:
    Affect(Decl* v, vector<Expression*> e);
    Affect(Decl* v, Expression* e);
    Affect(vector<Decl*> v, vector<Expression*> e);
    ~Affect();
    bool operator==(Affect* rhs);
    inline vector<Decl*> getVars() const { return vars; }
    inline const vector<Expression*> getExprs() const { return exprs; }
    void visit(Visitor& visitor) const;

};


#endif
