SRC= $(wildcard structure/*.cc) $(NAME)_v2.tab.cc lex.yy.c main.cc
OBJ= $(SRC:structure/*.cc=.o)
CFLAGS = -std=c++11
EXEC=test
NAME=TLC_Gpe_14_Grammaire
FFLAGS = -lfl

.PHONY: clean

all: $(EXEC)


$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(FFLAGS) $(CFLAGS)


%.o : %.cc
	$(CXX) -I $(CFLAGS) -o $@ -c $<


$(NAME)_v2.tab.cc: $(NAME)_v2.yy
	bison -d $< -v

lex.yy.c: $(NAME).ll $(NAME)_v2.tab.cc
	flex $<

clean:
	rm -rf $(NAME)_v2.tab.cc $(NAME)_v2.tab.hh $(NAME)_v2.output lex.yy.c

mrproper: clean
	rm -rf $(EXEC)
