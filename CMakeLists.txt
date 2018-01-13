cmake_minimum_required(VERSION 3.8)
project(Projet_TLC)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        structure/headers/affect.hh
        structure/headers/bool.hh
        structure/headers/class.hh
        structure/headers/data.hh
        structure/headers/decl.hh
        structure/headers/expr.hh
        structure/headers/float.hh
        structure/headers/fonc.hh
        structure/headers/inst.hh
        structure/headers/int.hh
        structure/headers/interpretor.hh
        structure/headers/method.hh
        structure/headers/ope.hh
        structure/headers/symbolTable.hh
        structure/headers/term.hh
        structure/headers/visitor.hh
        structure/headers/vivacite.hh
        structure/affect.cc
        structure/bool.cc
        structure/class.cc
        structure/data.cc
        structure/decl.cc
        structure/float.cc
        structure/fonc.cc
        structure/int.cc
        structure/interpretor.cc
        structure/method.cc
        structure/ope.cc
        structure/symbolTable.cc
        lex.yy.c
        main.cc
        TLC_Gpe_14_Grammaire_v2.tab.cc
        TLC_Gpe_14_Grammaire_v2.tab.hh)

add_executable(Projet_TLC ${SOURCE_FILES})