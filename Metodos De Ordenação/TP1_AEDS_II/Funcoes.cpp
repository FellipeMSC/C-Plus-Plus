#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Funcoes.hpp"
using namespace std;

void BoubleSort(auto Lista[], int n)
{
  auto aux = Lista[0];
  int troca;
  unsigned long long totalc = 0;
  
  for (int i = 0; i < n - 1; i++)
  {
    troca = 0;
    for (int j = 1; j < n - 1; j++)
    {
      totalc++;
      if (Lista[j] < Lista[j - 1]){
        aux = Lista[j];
        Lista[j] = Lista[j - 1];
        Lista[j - 1] = aux;
        troca = 1;
      }
    }
    if (troca == 0)
    {
      break;
    }
  }
  system("cls");
  cout<<"Número de comparações: "<<totalc<<endl;
}

void InsertionSort(auto Lista[], int n)
{
  int j;
  unsigned long long c = 0;
  auto chave =Lista[0];

  for (int i = 1; i < n; i++){
    chave = Lista[i];
    j = i - 1;

    c++;
    while (j >= 0 && Lista[j] > chave){
      
      Lista[j + 1] = Lista[j];
      j--;
      c++;
    }
    Lista[j + 1] = chave;
  }
  system("cls");
  cout<<"Número de comparações: "<<c<<endl;
}

void SelectionSort(auto Lista[], int n)
{
  int min;
  unsigned long long co = 0;
  auto aux = Lista[0];

  for (int i = 0; i < n - 1; i++)
  {
    min = i;

    for (int j = i + 1; j < n; j++)
    {

      co++;
      if (Lista[j] < Lista[min])
      {
        min = j;
      }
    }
    aux = Lista[i];
    Lista[i] = Lista[min];
    Lista[min] = aux;
  }
  system("cls");
  cout<<"Número de comparações: "<<co<<endl;
}

void ShellSort(auto Lista[], int size)
{
  int i, j;
  unsigned long long com = 0;
  auto value = Lista[0];

  int h = 1;
  while (h < size)
  {
    h = 3 * h + 1;
  }

  while (h > 0)
  {
    for (i = h; i < size; i++)
    {
      value = Lista[i];
      j = i;
      com++;

      while (j > h - 1 && value <= Lista[j]){

        com++;
        j = j - h;
      }
      Lista[j] = value;
    }
    h = h / 3;
  }
  system("cls");
  cout<<"Número de comparações: "<<com<<endl;
}

void QuickSort(auto Lista[], int esquerda, int direita, unsigned long long &comp)
{
  auto tmp =Lista[0], pivo = Lista[(esquerda + direita) / 2];
  int i = esquerda, j = direita;

  while (i <= j){
    comp++;
    while (Lista[i] < pivo){
      i++;
      comp++;
    }
    comp++;
    while (Lista[j] > pivo){
      j--;
      comp++;
    }

    if (i <= j){
      tmp = Lista[i];
      Lista[i] = Lista[j];
      Lista[j] = tmp;
      i++;
      j--;
    }
  };

  if (esquerda < j){
    QuickSort(Lista, esquerda, j, comp);
  }
  if (i < direita){
    QuickSort(Lista, i, direita, comp);
  }
}

void merge(int arr[], int p, int q, int r, unsigned long long &comp)
{

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  
  int* M = new int[n2];
  int* L = new int[n1];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2){

    comp++;
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void MergeSort(int arr[], int l, int r, unsigned long long &comp)
{
  if (l < r)
  {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    MergeSort(arr, l, m, comp);
    MergeSort(arr, m + 1, r, comp);

    // Merge the sorted subarrays
    merge(arr, l, m, r, comp);
  }
}

void mergestring(string arr[], int p, int q, int r, unsigned long long &comp)
{

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  string* L = new string[n1];
  string* M = new string[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2)
  {
    comp++;
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }

}

void MergeSortstring(string arr[], int l, int r, unsigned long long &comp)
{
  if (l < r)
  {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    MergeSortstring(arr, l, m, comp);
    MergeSortstring(arr, m + 1, r, comp);

    // Merge the sorted subarrays
    mergestring(arr, l, m, r, comp);
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void Menu()
{
  cout << "|--------------------------------|" << endl;
  cout << "|      Menu De Instâncias        |" << endl;
  cout << "|--------------------------------|" << endl;
  cout << "| 1. Números                     |" << endl;
  cout << "|--------------------------------|" << endl;
  cout << "| 2. Grupo de Palavras           |" << endl;
  cout << "|--------------------------------|" << endl;
  cout << "| 3. Sair                        |" << endl;
  cout << "|--------------------------------|" << endl
       << endl;
  cout << "Selecione uma opção: ";
}

void MenuNum()
{
  cout << "|------------------------------------------|" << endl;
  cout << "|             Menu de Números              |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 1. Lista Aleatoria-1000                  |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 2. Lista Aleatoria-10000                 |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 3. Lista Aleatoria-100000                |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 4. Lista Aleatoria-1000000               |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 5. Lista Ordenada-1000                   |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 6. Lista Ordenada-10000                  |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 7. Lista Ordenada-100000                 |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 8. Lista Ordenada-1000000                |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 9. Lista Quase Ordenada-1000             |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 10. Lista Quase Ordenada-10000           |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 11. Lista Quase Ordenada-100000          |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 12. Lista Quase Ordenada-1000000         |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 13. Lista Inversamente Ordenada-1000     |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 14. Lista Inversamente Ordenada-10000    |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 15. Lista Inversamente Ordenada-100000   |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 16. Lista Inversamente Ordenada-1000000  |" << endl;
  cout << "|------------------------------------------|" << endl;
  cout << "| 17. Sair                                 |" << endl;
  cout << "|------------------------------------------|" << endl
       << endl;
  cout << "Selecione uma opção: ";
}

void MenuPala()
{
  cout << "|----------------------------------------------------|" << endl;
  cout << "|                 Menu De Palavras                   |" << endl;
  cout << "|----------------------------------------------------|" << endl;
  cout << "| 1. Dicionario Ordenado-29855                       |" << endl;
  cout << "|----------------------------------------------------|" << endl;
  cout << "| 2. Dicionario Ordenado-261791                      |" << endl;
  cout << "|----------------------------------------------------|" << endl;
  cout << "| 3. Dicionario Aleatorio-29855                      |" << endl;
  cout << "|----------------------------------------------------|" << endl;
  cout << "| 4. Dicionario Aleatorio-261791                     |" << endl;
  cout << "|----------------------------------------------------|" << endl;
  cout << "| 5. Dicionario Inversamente Ordenado-29855          |" << endl;
  cout << "|----------------------------------------------------|" << endl;
  cout << "| 6. Dicionario Inversamente Ordenado-261791         |" << endl;
  cout << "|----------------------------------------------------|" << endl;
  cout << "| 7. Sair                                            |" << endl;
  cout << "|----------------------------------------------------|" << endl
       << endl;
  cout << "Selecione uma opção: ";
}

void MenuMeto()
{
  cout << "|----------------------------------------|" << endl;
  cout << "|     Menu Dos Metodos De Ordenação      |" << endl;
  cout << "|----------------------------------------|" << endl;
  cout << "| 1. Bouble Sort                         |" << endl;
  cout << "|----------------------------------------|" << endl;
  cout << "| 2. Insertion Sort                      |" << endl;
  cout << "|----------------------------------------|" << endl;
  cout << "| 3. Selection Sort                      |" << endl;
  cout << "|----------------------------------------|" << endl;
  cout << "| 4. Shell Sort                          |" << endl;
  cout << "|----------------------------------------|" << endl;
  cout << "| 5. Quick Sort                          |" << endl;
  cout << "|----------------------------------------|" << endl;
  cout << "| 6. Merge Sort                          |" << endl;
  cout << "|----------------------------------------|" << endl;
  cout << "| 7. Sair                                |" << endl;
  cout << "|----------------------------------------|" << endl
       << endl;
}

void Arquivos(string nome, int tamanho, auto Lista[]){

  auto cont = Lista[0];

  ifstream arquivo("./Instancias-TP1/"+nome+"-"+to_string(tamanho)+".txt");

  for(int i = 0; i < tamanho; i++){
    arquivo >> cont;
    Lista[i] = cont; 
  }

  arquivo.close();
}

void Metodos(int tamanho, string nome){
  int opmeto;
  int* Lista = new int[tamanho];
  unsigned long long comp = 0;

  Arquivos(nome, tamanho, Lista);
  MenuMeto();

  do{
  cout<<"Selecione o metodo de ordenação: ";
  cin>>opmeto;
  system("cls");
  cout<<"Ordenando lista..."<<endl;
  }while(opmeto < 1 || opmeto > 7);

  double temp = clock();
  
  switch(opmeto){
    
    case 1:

      BoubleSort(Lista, tamanho);
      break;

    case 2:

      InsertionSort(Lista, tamanho);
      break;

    case 3:

      SelectionSort(Lista, tamanho);
      break;

    case 4: 

      ShellSort(Lista, tamanho);
      break;

    case 5:
      
      QuickSort(Lista, 0, tamanho -1, comp);
      system("cls");
      cout<<"Número de comparações: "<<comp<<endl;
      break;

    case 6:
      

      MergeSort(Lista, 0, tamanho -1, comp);
        system("cls");
        cout<<"Número de comparações: "<<comp<<endl;
      break;

    case 7:

    break;
      
  }
  
  double fim = (clock()- temp) / CLOCKS_PER_SEC;
  
  cout<<"Duração do programa: " << fim << endl;
  system("pause");
  system("cls");

  delete[] Lista;
}

void MetodoString(int tamanho, string nome){
  int opmeto;
  string* Lista = new string[tamanho];
  unsigned long long comp = 0;

  Arquivos(nome, tamanho, Lista);
  MenuMeto();

  do{
  cout<<"Selecione o metodo de ordenação: ";
  cin>>opmeto;
  system("cls");
  cout<<"Ordenando lista..."<<endl;
  }while(opmeto < 1 || opmeto > 7);

  double temp = clock();

  switch(opmeto){
    
    case 1:

      BoubleSort(Lista, tamanho);
      break;

    case 2:

      InsertionSort(Lista, tamanho);
      break;

    case 3:

      SelectionSort(Lista, tamanho);
      break;

    case 4: 
    
      ShellSort(Lista, tamanho);
      break;

    case 5:

      QuickSort(Lista, 0, tamanho -1, comp);
      system("cls");
      cout<<"Número de comparações: "<<comp<<endl;
      break;

    case 6:

      MergeSortstring(Lista, 0, tamanho -1, comp);
      system("cls");
      cout<<"Número de comparações: "<<comp<<endl;
      break;

    case 7:

    break;
      
  }
  double fim = (clock()- temp) / CLOCKS_PER_SEC;
  cout<<"Duração do programa: " << fim << endl;
  system("pause");
  system("cls");

  delete[] Lista;
}

void Listas(int &tamanho, string &nome){
  int oplistas;

  do{
  MenuNum();
  cin>>oplistas;
  }while(oplistas < 1 || oplistas > 17);
  
  switch (oplistas){
  case 1: 
    tamanho = 1000;
    nome = "ListaAleatoria";
    break;
  
  case 2:
    tamanho = 10000;
    nome = "ListaAleatoria";
    break;

  case 3:
    tamanho = 100000;
    nome = "ListaAleatoria";
    break;

  case 4:
    tamanho = 1000000;
    nome = "ListaAleatoria";
    break;

  case 5:
    tamanho = 1000;
    nome = "ListaOrdenada";
    break;

  case 6:
    tamanho = 10000;
    nome = "ListaOrdenada";
    break;

  case 7:
    tamanho = 100000;
    nome = "ListaOrdenada";
    break;

  case 8:
    tamanho = 1000000;
    nome = "ListaOrdenada";
    break;

  case 9:
    tamanho = 1000;
    nome = "ListaQuaseOrdenada";
    break;

  case 10:
    tamanho = 10000;
    nome = "ListaQuaseOrdenada";
    break;

  case 11:
    tamanho = 100000;
    nome = "ListaQuaseOrdenada";

    break;

  case 12:
    tamanho = 1000000;
    nome = "ListaQuaseOrdenada";
    break;

  case 13:
    tamanho = 1000;
    nome = "ListaInversamenteOrdenada";
    break;

  case 14:
    tamanho = 10000;
    nome = "ListaInversamenteOrdenada";
    break;

  case 15:
    tamanho = 100000;
    nome = "ListaInversamenteOrdenada";
    break;

  case 16:
    tamanho = 1000000;
    nome = "ListaInversamenteOrdenada";
    break;

  default:
    break;
  
  }
}

void Palavras(int &tamanho, string &nome){
  int oplistas;

  do{
  MenuPala();
  cin>>oplistas;
  }while(oplistas < 1 || oplistas > 17);
  
  switch (oplistas){
  case 1: 
    tamanho = 29855;
    nome = "DicionarioOrdenado";
    break;
  
  case 2:
    tamanho = 261791;
    nome = "DicionarioOrdenado";
    break;
  
  case 3:
    tamanho = 29855;
    nome = "DicionarioAleatorio";
    break;
  
  case 4:
    tamanho = 261791;
    nome = "DicionarioAleatorio";
    break;
  
  case 5:
    tamanho = 29855;
    nome = "DicionarioInversamenteOrdenado";
    break;

  case 6:
    tamanho = 261791;
    nome = "DicionarioInversamenteOrdenado";
    break;

  default:

    break;
  }
}
