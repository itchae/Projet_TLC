#include "headers/bloc.hh"

/**--------------------------------------------------------------------------**/
Bloc::Bloc(vector<Instruction*> i) : instructs(i){

}

/**--------------------------------------------------------------------------**/
Bloc::~Bloc(){
  for (int i=0; i<instructs.size(); i++){
    delete instructs[i];
  }
}

/**--------------------------------------------------------------------------**/
void Bloc::visit(Visitor& visitor){
  visitor.visitBloc(this);
}
