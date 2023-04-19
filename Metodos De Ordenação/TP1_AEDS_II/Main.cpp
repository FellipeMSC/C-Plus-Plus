#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Funcoes.hpp"
#include "Funcoes.cpp"

using namespace std;

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int op, tamanho;
  string nome;

  do{

  do{
    Menu();
    cin >> op;
    system("cls");
  }while (op < 1 || op > 3);

  
  switch(op){

    case 1:
      Listas(tamanho, nome);
      system("cls");
      Metodos(tamanho, nome);
      break;

    case 2:
      Palavras(tamanho, nome);
      system("cls");
      MetodoString(tamanho, nome);
      break;

    case 3:

      break;
  }
  }while(op != 3);
}
