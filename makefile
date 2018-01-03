SRC= $(wildcard structure/*.cc)
OBJ= $(SRC:structure/*.cc=.o)

EXEC=test

all: $(EXEC)

test: main.cc TLC_Gpe_14_Grammaire_v2.tab.c lex.yy.c $(OBJ)
	$(CXX) -o $@ $^ -lfl

TLC_Gpe_14_Grammaire_v2.tab.c: TLC_Gpe_14_Grammaire_v2.y
	bison -d $<

lex.yy.c: TLC_Gpe_14_Grammaire.l
	flex $<

.PHONY: clean	
	
clean:
	rm -rf TLC_Gpe_14_Grammaire_v2.tab.c TLC_Gpe_14_Grammaire_v2.tab.h lex.yy.c test
