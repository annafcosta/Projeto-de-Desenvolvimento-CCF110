cmake_minimum_required(VERSION 3.26)
project(Projeto_de_Desenvolvimento_CCF110 C)

set(CMAKE_C_STANDARD 11)

add_executable(Projeto_de_Desenvolvimento_CCF110
        arquivos.h
        arquivos.c
        sistema_de_vendas.c
        vendas.h
        vendas.c
        produtos.c)
