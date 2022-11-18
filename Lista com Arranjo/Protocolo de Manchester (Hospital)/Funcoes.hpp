#ifndef Fila.h
#define Fila.h

#define MAXTAM 5

typedef TipoElemento *Apontador;

typedef struct{
    string nome, area, CRM;
    bool disponivel = true;
}Medico;

typedef struct{
    char salvaResposta[18];
}Triagem;

typedef struct{
    Medico medico[MAXTAM];
    int pacientes = 0, qntMedico = 0;

}DadosUPA;

typedef struct{
    char nome[20], rua[20], bairro[20], sexo[10];
    int idade, prioridade;
    bool atendido = false;
    time_t Chegada, Saida;
    Triagem triagem;
    
}Paciente;



typedef struct{
    Medico medico;
    Paciente paciente;
    Apontador prox;
}TipoElemento;

typedef struct{
    Apontador primeiro, ultimo;
    int tamanho = 0;
}TipoFila;

void InicializaFila(TipoFila *fila);
bool VerificaFilaVazia(TipoFila *fila);
void Enfileira(TipoFila *fila, Paciente paciente);
void Desenfileira(TipoFila *fila, Paciente *paciente);
void EnfileiraPrioridade(TipoFila *fila, Paciente paciente);
int Menu();
void TriagemPaciente(Triagem *RespostasTriagem);
void Cadastro_Medico(Medico medico[]);

#endif
