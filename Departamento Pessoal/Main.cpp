#include <iostream>
#include <windows.h>
#include <cstring>
#include <fstream>
#include "Lista.hpp"
#include "Funcoes.cpp"

using namespace std;

void menu(){ //Menu de informação para o usuario, somente para visual.
    system("cls");
    cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "|            DEPARTAMENTO PESSOAL           |\n";
    cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "|  1. Incluir funcionário                   |\n";
    cout<<  "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "|  2. Cadastrar projeto de um funcionário   |\n";
    cout<<  "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "|  3. Excluir projeto de um funcionário     |\n";
    cout<<  "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "|  4. Excluir funcionários sem projetos     |\n";
    cout<<  "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "|  5. Consultar funcionário                 |\n";
    cout<<  "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "|  6. Imprimir contra-cheque                |\n";
    cout<<  "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "|  7. Sair                                  |\n";
    cout<<  "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
    TipoLista lista;
    TipoItem func;
    int op, d, p, ret, id, opp;
    
     Leitura_Arquivo(&lista);

    CriaListaVazia(&lista); //Cria uma lista de funcionário para poder serem cadastrados.

do{

    menu();
    cout<<"Selecione uma opção: ";
    cin>>op; 

    system("cls");

    switch(op){
        
        case 1://Cadastra um funcionário, pede as informações do funcionário.

        if(!ListaCriada){
            cout<<"Lista não foi iniciada";
            system("pause");
            break;
        }//Verifica se a lista foi criada ou não.
        
        cout<<"Digite o nome do funcionário: ";
        cin>>func.nome;
        
        cout<<"Digite o ID do funcionário (Apenas numeros): ";
        cin>>func.id;
        cin.ignore();
        
        cout<<"Digite sua cidade: ";
        cin.getline(func.endereco.cidade, 40);
        
        cout<<"Digite seu bairro: ";
        cin.getline(func.endereco.bairro, 40);
        
        cout<<"Digite sua rua: ";
        cin.getline(func.endereco.rua, 40);
        
        cout<<"Digite o numero de sua casa (Apenas numeros): ";
        cin>>func.endereco.numcasa;
        
        cout<<"Digite a quantidade de dependentes (Apenas numeros): ";
        cin>>func.dependentes;

        system("cls");
        
        cout<<"1. Sim\n2. Não\nDeseja cadastrar um projeto: ";
        cin>>d;

        CriaListaVaziaSeq(&func.projetos);

        do{
            if(d == 1){
                TProjetos projeto;
                
                system("cls");
                
                cout<<"Digite o nome do projeto: ";
                cin>>projeto.nome;
                
                cout<<"Digite as horas trabalhadas nesse projeto (Apenas numeros): ";
                cin>>projeto.horas;
                
                cout<<"Digite o codigo desse projeto (Apenas numeros): ";
                cin>>projeto.codigo;
                
                InsereItem(&func.projetos, projeto);//Insere um projeto cadastrado para o funcionário
                system("cls");

                cout<<"1. Sim \n2. Não \nDeseja cadastrar outro projeto: ";
                cin>>d;
            }
        
        }while(d != 2); //Pergunta se um funcionário deseja cadastrar um projeto no inicio das suas informações.

        InsereListaUltimo(&lista, &func);//Adiciona o funcionáro no ultimo da lista encadeada, e aumenta o tamanho da lista.
        break;

        case 2: 
        if(!ListaCriada){
            cout<<"Lista não foi iniciada";
            break;
        }
        
        int id;

        cout << "Informe o Id do funcionario para incluir projeto: ";
        cin >> id;

        system("cls");

        TApontador proj;
        TProjetos projeto;
        
        proj = PesquisaItemTwo(&lista, id);
        
        cout<<"Digite o nome do projeto: ";
        cin>>projeto.nome;
                
        cout<<"Digite as horas trabalhadas nesse projeto (Apenas numeros): ";
        cin>>projeto.horas;
                
        cout<<"Digite o codigo desse projeto (Apenas numeros): ";
        cin>>projeto.codigo;
        
        InsereItem(&proj->item.projetos, projeto);//Cadastra um projeto caso o funcionário queira e verifica se o ID do funcionário é compativel com algum ID ja cadastrado.
        break;

        case 3:
        
        if(!ListaCriada){
            cout<<"Lista não foi iniciada";
            system("pause");
            break;
        }

        cout<<"Digite o ID do funcionário: ";
        cin>>id;

        ExcluirProjeto(&lista, id);//Exclui um projeto de um funcionário caso o ID for compativel com alguem ID ja cadastrado.
        break;

        case 4:
        
        
        if(!ListaCriada){
            cout<<"Lista não foi iniciada";
            system("pause");
            break;
        }

        
        cout<<"1. Excluir todos os funcionarios \n2. Excluir apenas um funcionário \nDigite uma opção: ";
        cin>>opp;//Selecionar uma opção de exclusão de funcionários sem projetos.
        system("cls");

        ExcluirFuncSP(&lista, opp);//Exclui um ou todos funcionários caso ele não tenha projetos.
        break;

        case 5: 

        if(!ListaCriada){
            cout<<"Lista não foi iniciada";
            system("pause");
            break;
        }

        cout<<"Digite o ID do funcionario: ";
        cin>>p;

        ret = PesquisaItem(&lista, p);//Verifica caso tenha alguem cadastrado com o ID.

        if(ret == -1){
            cout<<"Funcionário não encontrado ";
            Sleep(2000);
            break;
        }//Retorno caso não ache alguem com o mesmo ID.
        ImprimeItem(&lista, ret);//Caso encontre vai imprimir os dados do funcionário.

        break;
        
        case 6:

        if(!ListaCriada){
            cout<<"Lista não foi iniciada";
            system("pause");
            break;
        }

        ImprimeContraCheque(&lista);//Imprime o contra-cheque de todos os funcionários da empresa.
        break;

    }       

}while(op != 7);

    //  Inclui_Arquivo(&lista);

return 0;
}

