#ifndef Fila.h
#define Fila.h
#include <ctime>

#define MAXTAM 5

using namespace std;

typedef struct{
    char salvaResposta[18];
}Triagem;

typedef struct{
    char nome[20], rua[20], bairro[20], sexo[10];
    int idade, prioridade, n;
    bool atendido = false;
    time_t Chegada, Saida;
    Triagem triagem;
    
}Paciente;

typedef struct{
    string nome, area, CRM;
    bool disponivel = true;
    time_t tempo;
    Paciente paciente;
}Medico;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento{
    Medico medico;
    Paciente paciente;
    Apontador prox;
};

typedef struct{
    Apontador primeiro, ultimo;
    int tamanho = 0;
}TipoFila;

typedef struct{
    Medico medico[MAXTAM];
    int pacientes = 0, qntMedico = 0;

}DadosUPA;



void InicializaFila(TipoFila *fila);
bool VerificaFilaVazia(TipoFila *fila);
void Enfileira(TipoFila *fila, Paciente paciente);
void Desenfileira(TipoFila *fila, Paciente *paciente);
void inserePacientePrimeiro(TipoFila* fila, Paciente paciente);
void insereAposElemento(Apontador anterior, Apontador novo);
void EnfileiraComPrioridade(TipoFila* fila, Paciente paciente);
int Menu();
void TriagemPaciente(Triagem *RespostasTriagem);
void Cadastro_Medico(Medico med[]);
int FilaPacientes(Triagem RespostasTriagem);
void CadastraPaciente(TipoFila *fila);
void AtualizaMedico(TipoFila *fila, DadosUPA *upa);
void ImprimeFila(TipoFila *fila);

#endif
