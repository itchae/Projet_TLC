SRC= $(wildcard structure/*.cc)
OBJ= $(SRC:structure/*.cc=.o)

EXEC=test
NAME=TLC_Gpe_14_Grammaire
FFLAGS = -lfl

all: $(EXEC)

test: main.cc $(NAME)_v2.tab.c lex.yy.c $(OBJ)
	$(CXX) -o $@ $^ $(FFLAGS)

TLC_Gpe_14_Grammaire_v2.tab.c: $(NAME)_v2.y
	bison -d $<

lex.yy.c: $(NAME).l
	flex $<

.PHONY: clean

clean:
	rm -rf $(NAME)_v2.tab.c $(NAME)_v2.tab.h lex.yy.c

mrproper: clean
	rm -rf $(EXEC)
