toto: main.cc grammaire.tab.c lex.yy.c
	$(CXX) -o $@ $^ -lfl

calc.tab.cc: grammaire.y
	bison -d $<

lex.yy.c : grammaire.l
	flex $<

clean :
	rm -fr grammaire.tab.c grammaire.tab.h lex.yy.c toto
