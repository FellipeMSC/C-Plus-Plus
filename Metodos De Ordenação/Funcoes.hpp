#ifndef Funcoes_H
#define Funcoes_H
#include <iostream> 

using namespace std;

void BoubleSort(auto Lista[], int n);
void InsertionSort(auto Lista[], int n);
void SelectionSort(auto Lista[], int n);
void ShellSort(auto Lista[], int size);
void QuickSort(auto Lista[], int esquerda, int direita, unsigned long long &comp);
void merge(int arr[], int p, int q, int r, unsigned long long &comp);
void MergeSort(int arr[], int l, int r, unsigned long long &comp);
void mergestring(string arr[], int p, int q, int r, unsigned long long &comp);
void MergeSortstring(string arr[], int l, int r, unsigned long long &comp);
void Menu();
void MenuNum();
void MenuPala();
void MenuMeto();
void Arquivos(string nome, int tamanho, auto Lista[]);
void Metodos(int tamanho, string nome);
void MetodoString(int tamanho, string nome);
void Listas(int &tamanho, string &nome);
void Palavras(int &tamanho, string &nome);

#endif
