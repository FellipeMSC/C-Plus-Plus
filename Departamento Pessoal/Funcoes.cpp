#include <iostream>
#include "Lista.hpp"

#define maxtam 5
#define inicio 1

using namespace std;


void CriaListaVazia(TipoLista *lista){//Cria uma lista sem cadastros.
    if (!ListaCriada){
        lista->primeiro = new TipoElemento;
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
        cout << "Lista criada com sucesso!";
        ListaCriada = true;
    }
    else{
        cout << "Lista já existe!";
    }
    
}

bool VerificaListaVazia(TipoLista *lista){//Verifica se a lista possui ou não possui cadastros.
    return (lista->primeiro == lista->ultimo);
}

void InsereListaPrimeiro(TipoLista *lista, TipoItem *item){
    TApontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new TipoElemento;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    lista->tamanho++;

}

void AtualizaUltimo(TipoLista *lista){//Atualiza o ultimo funcionário da lista.
    TApontador aux;
    aux = lista->primeiro;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void ImprimeListaSeq(TListaSequencial lista){//Imprime os projetos de um funcionário.
    
    for (int i = 0; i < lista.tamanho; i++){
        cout<<endl;
        
        cout << "Codigo do projeto: "<< lista.item[i].codigo<< endl;
        cout << "Nome do projeto: "<< lista.item[i].nome<< endl;
        cout <<"Horas do projeto: "<< lista.item[i].horas<<endl;
    }
    system("pause");
}

void ImprimeItem(TipoLista *lista, int id){

    TApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            cout<<"Nome: "<< aux->item.nome <<" \nID: "<<aux->item.id<<" \nCidade: "<<aux->item.endereco.cidade<<" \nBairro: "<<aux->item.endereco.bairro<<endl;
            cout<<"Rua: "<<aux->item.endereco.rua<<" \nNumero da casa: "<<aux->item.endereco.numcasa<<" \nDependentes: "<<aux->item.dependentes<<endl;

            ImprimeListaSeq(aux->item.projetos);
            break;
        }
        aux = aux->prox;
    }
}

int PesquisaItem(TipoLista *lista, int id){//Pesquisa o funcionário.
    TApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            return aux->item.id;
        }
        aux = aux->prox;
    }
    return -1;
}

TApontador PesquisaItemTwo(TipoLista *lista, int id){//Pesquisa o funcionário.
TApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item){//Insere um funcionário ao final da lista.
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

void RemoveItemPorId(TipoLista *lista, int id){//Busca pelo ID do funcionário, se encontrar, vai exclui-lo e diminuir o tamanho da lista.

    TApontador aux, anterior, x;

    x = lista->primeiro;

    while (x != NULL){
        if (x->prox->item.id == id){
            anterior = x;
            break;
        }

        x = x->prox;
    }

    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
    AtualizaUltimo(lista);
}

int RemoveItem(TListaSequencial *lista, int id){//Remove um funcionário e deminui o tamanho da lista.
    int l;
    for(int j = 0; j < lista->tamanho;j++){
        if(lista->item[j].codigo == id){
            l = j;
            
            for(int i = l; i < lista->tamanho; i++) {
            lista->item[i] = lista->item[i+1];
        }   
        lista->tamanho--;
        return 0;
        }
    } 
        return -1;
}

int InsereItem(TListaSequencial *lista, TProjetos item){//Insere um funcionário.
    
    lista->item[lista->ultimo] = item;
    lista->tamanho++;
    lista->ultimo++;
    return 1; 
}

void CadastraProjeto(TipoLista *projetos, int id){//Pesquisa o ID do funcionário, caso encontre, cadastra um projeto novo para o funcionário.
    
    TApontador aux = projetos->primeiro->prox;
    int t = 0;
    system ("cls");

        while (aux != NULL){
        if (aux->item.id == id){
            t = aux->item.projetos.tamanho; 
            cout << "Insira nome do projeto: ";
            cin >> aux->item.projetos.item[t].nome;
            cout << "Insira ID do projeto: ";
            cin >> aux->item.projetos.item[t].codigo;
            cout << "Insira horas trabalhadas no projeto: ";
            cin >> aux->item.projetos.item[t].horas;
            aux->item.projetos.tamanho++;
        }
        aux = aux->prox;
    }
}

void ExcluirProjeto(TipoLista *lista, int id){//Verifica o ID do funcionário, se encontrar, exclui um projeto.
    
    TApontador aux;
    int rec;

    aux = lista->primeiro->prox;

    while(aux != NULL){
        if(aux->item.id == id){
            
            ImprimeItem(lista, id);
            
            cout<<"Qual projeto voçê deseja excluir: ";
            cin>>id;
            rec = RemoveItem(&aux->item.projetos, id);
            if(rec == -1){
            cout<<"Seu projeto não foi encontrado"<<endl;
            }
            
        }
        aux = aux->prox;
    }
}

void ExcluirFuncSP(TipoLista *lista, int opp){//Função de verificar se o funcionário tem algum projeto, caso não tenha, será excluído.
    
    TApontador aux;

    if(opp == 1){
        
        aux = lista->primeiro->prox;
        
        while(aux != NULL){
            if(aux->item.projetos.tamanho == 0){
                RemoveItemPorId(lista, aux->item.id);
            }
            aux = aux -> prox;
        }
    }

    if(opp == 2){
        
        int id;
        
        cout<<"Digite o ID do funcionário: ";
        cin>>id;

        aux = PesquisaItemTwo(lista, id);
       
        if(aux == NULL){
            cout<<"Não há funcionário com esse ID";
        }
        
        if(aux->item.projetos.tamanho == 0){
            cout<<"Não há projetos cadastrado";
            RemoveItemPorId(lista, id);
        }
        else{
        cout<<"Funcionário tem cadastro de projetos";
        }
    }
    
    
}

void ImprimeContraCheque(TipoLista *lista){//Imprimir o contra-cheque dos funcionários da empresa.
    TApontador aux;
    
    aux = lista->primeiro->prox;

    float INSS = 0.0, imp = 0.0,bruto = 0.0, liquido = 0.0, caux = 0.0;
    
    while(aux != NULL){

        cout<<"Funcionário: "<<aux->item.nome<<" \nID: "<<aux->item.id;

        for(int i = 0; i < aux->item.projetos.tamanho; i++){ 
            
            caux += aux->item.projetos.item[i].horas;
        }

        bruto = 45 * caux + aux->item.dependentes * 35;
        imp = bruto * 0.15;
        INSS = bruto * 0.085;
        liquido = bruto - INSS - imp;

        cout<<"Informações do funcionário \nHoras de trabalho: "<<caux<<"\nSalario bruto: "<<bruto<<"\nImposto: "<<imp<<"\nINSS: <<endl";
    }
}

void Leitura_Arquivo(TipoLista *lista) // Lê o arquivo e caso exista a função inclui todos os funcionarios na bin.
{
    FILE *file = fopen("Departamento_Pessoal.bin", "r");
    TipoItem item;
    if (file != NULL){
        while (fread(&item, sizeof(TipoItem), 1, file)){

            InsereListaUltimo(lista, &item);
        }
    }
}

void Inclui_Arquivo(TipoLista *lista) // Salva os funcionários dentro do arquivo bin.
{
    FILE *file = fopen("Departamento_Pessoal.bin", "w");
    TApontador aux = lista->primeiro->prox;
    while (aux != NULL){
        fwrite(&aux->item, sizeof(TipoItem), 1, file);
        aux = aux->prox;
    }
}
