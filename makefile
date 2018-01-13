SRC= $(wildcard structure/*.cc) $(NAME)_v2.tab.cc lex.yy.c main.cc
OBJ= $(SRC:structure/*.cc=.o)
CFLAGS =  -W -Wall -g
EXEC=test
NAME=TLC_Gpe_14_Grammaire
FFLAGS = -lfl

.PHONY: clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(FFLAGS)

%.o : %.cc
	$(CC) -I $(CFLAGS) -o $@ -c $<

$(NAME)_v2.tab.cc: $(NAME)_v2.yy
	bison -d $< -v

lex.yy.cc: $(NAME).ll $(NAME)_v2.tab.cc
	flex $<

clean:
	rm -rf $(NAME)_v2.tab.cc $(NAME)_v2.tab.hh lex.yy.c

mrproper: clean
	rm -rf $(EXEC)
