/* Objetivos:
    
    Cria escola
    Cria Diretor
    Criar turma
    Criar aluno
    Criar professor

    Escola contrata diretor 
    Diretor matricula aluno
    Diretor contrata professor

    Professor vê alunos da turma
    Diretor vê alunos da turma

    Professor cria prova
    Aluno fazer prova
    Professor corrigir prova
    Aluno ver a nota da prova
    Pai ver nota apenas do filho
    Aluno receber boolean passou ou não

*/

#include <iostream>
#include <string.h>
using namespace std;

// Classes

class Prova {
    public:
        int nota;
        string materia;
        void setNota(int nota) {
            this->nota = nota;
        }
        int getNota() {
            return nota;
        }
        Prova();
        Prova(string materia);
};

class Aluno {
    public: 
        string nome;
        string matricula;
        Prova prova;
        Aluno();
        Aluno(string nome, string matricula);
        void fazProva(Prova prova);
        int verNota();
};

class Pai{
    public: 
        string nome;
        Aluno filho;
        Pai();
        Pai(string nome, Aluno filho);
        int verNota(Aluno filho);
};

class Turma {
    public: 
        Aluno alunos[100];
        string materia;
        int quantidadeDeAluno;
        Turma();
        Turma(string materia);
        void addAluno(Aluno aluno);
};


class Professor {
    public:
        string nome;
        string materia;
        Turma turma;
        Professor();
        Professor(string nome, string materia, Turma turma);
        int corrigeProva(Prova prova, Aluno &aluno, int nota);
        Prova criaProva(string materia);
        void veAlunos(Turma turma);
};

class Diretor {
    public:
        string nome;
        Diretor();
        Diretor(string nome);
        Professor contrataProfessor(Professor professor, Turma turma);
        Aluno matriculaAluno(Aluno aluno, Turma &turma);
        Turma criaTurma(string materia);
        void veAlunos(Turma turma);
};

class Escola {
    public:
        string nome;
        string endereco;
        string telefone;
        Diretor diretor;
        Escola();
        Escola (string nome, string endereco, string telefone);
        Diretor contrataDiretor(Diretor diretor);
};

// Construtores

Prova:: Prova(){
    this->nota = 0;
    this->materia = "";
}

Prova:: Prova(string materia) {
    this->materia = materia;
    this->nota = 0;
}

Aluno:: Aluno(){
    this->nome = "";
    this->matricula = "";
}

Aluno:: Aluno(string nome, string matricula){
    this->nome = nome;
    this->matricula = matricula;
}

Pai:: Pai(){
    this->nome = "";
    this->filho = Aluno();
}

Pai:: Pai(string nome, Aluno filho){
    this->nome = nome;
    this->filho = filho;
}

Turma:: Turma(){
    this->materia = "";
    this->quantidadeDeAluno = 0;
}

Turma:: Turma(string materia){
    this->materia = materia;
    this->quantidadeDeAluno = 0;
}

Professor:: Professor(){
    this->nome = "";
    this->materia = "";
    this->turma = Turma();
}

Professor:: Professor(string nome, string materia, Turma turma) {
    this->nome = nome;
    this->materia = materia;
    this->turma = turma;
}

Escola:: Escola(){
    this->nome = "";
    this->endereco = "";
    this->telefone = "";
}

Escola:: Escola (string nome, string endereco, string telefone){
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
}

Diretor:: Diretor(){
    this->nome = "";
}

Diretor:: Diretor(string nome) {
    this->nome = nome;
}


// Métodos

Diretor Escola:: contrataDiretor(Diretor diretor) {
    this->diretor = diretor;
    cout<<"Diretor "<<diretor.nome<<" contratado"<<endl;
    return diretor;
};

Turma Diretor:: criaTurma(string materia) {
    Turma turma = Turma(materia);
    cout<<"Turma  de"<<turma.materia<<" criada"<<endl;
    return turma;
};

Aluno Diretor:: matriculaAluno(Aluno aluno, Turma &turma){
    turma.addAluno(aluno);
    turma.quantidadeDeAluno++;
    cout<<"Aluno "<<aluno.nome<<" matriculado na turma de "<<turma.materia<<endl;
    return aluno;
};
    
Professor Diretor:: contrataProfessor(Professor professor, Turma turma) {
    professor.turma = turma;
    cout<<"Professor "<<professor.nome<<" contratado"<<endl;
    return professor;
};

void Turma:: addAluno(Aluno aluno){
    this->alunos[quantidadeDeAluno] = aluno;
};

void Professor:: veAlunos(Turma turma) {
    cout<<"\nA turma de "<<turma.materia<<" tem "<<turma.quantidadeDeAluno<<" alunos"<<endl;
    for (int i = 0; i < turma.quantidadeDeAluno; i++) {
        cout << turma.alunos[i].nome << endl;
    }
    cout<<endl;
};

void Diretor:: veAlunos(Turma turma) {
    cout<<"\nA turma de "<<turma.materia<<" tem "<<turma.quantidadeDeAluno<<" alunos"<<endl;
    for (int i = 0; i < turma.quantidadeDeAluno; i++) {
        cout << turma.alunos[i].nome << endl;
    }
    cout<<endl;
};

Prova Professor:: criaProva(string materia) {
    Prova prova = Prova(materia);
    cout<<"Prova de "<<prova.materia<<" criada pelo professor "<<nome<<endl;
    return prova;
};

void Aluno:: fazProva(Prova prova) {
    cout<<"Aluno "<<nome<<" faz a prova de "<<prova.materia<<endl;
    this->prova = prova;
};

int Professor:: corrigeProva(Prova prova, Aluno &aluno, int nota) {
    aluno.prova.setNota(nota);
    cout<<"Professor "<<nome<<" corrige a prova de "<<prova.materia<<" do aluno "<<aluno.nome<<endl;
    return nota;
};

int Aluno:: verNota(){
    return prova.getNota();
};

int Pai:: verNota(Aluno filho){
    return filho.verNota();
};

int main () {
    string materia = "História";

    Diretor diretor("Daniel");
    Escola escola = Escola("Escola", "Rua 1", "12345-6789");
    Turma turma = Turma(materia);
    Aluno aluno = Aluno("Pedro", "12345");
    Professor professor = Professor("Felipe", materia, turma);
    Pai pai = Pai("Hugo", aluno);

    escola.contrataDiretor(diretor);

    diretor.matriculaAluno(aluno, turma);
    diretor.contrataProfessor(professor, turma);

    professor.veAlunos(turma);
    diretor.veAlunos(turma);

    Prova prova = professor.criaProva("História");
    aluno.fazProva(prova);

    int notaProfessor = professor.corrigeProva(prova, aluno, 6);

    int notaFilho = aluno.verNota();
    int notaPai = pai.verNota(aluno);

    cout<<"O professor "<<professor.nome<<" deu "<<notaProfessor<<" na prova de "<<prova.materia<<" do "<<aluno.nome<<endl;
    cout<<"O filho "<<aluno.nome<<" tirou "<<notaFilho<<" na prova de "<<prova.materia<<endl;
    cout<<"O pai "<<pai.nome<<" viu a nota "<<notaPai<<" do "<<pai.filho.nome<<" na prova de "<<prova.materia<<endl;

    bool alunoPassou = notaFilho >= 5;

    if (alunoPassou) {
        cout<<aluno.nome<<" passou!"<< endl;
    } else {
         cout<<aluno.nome<<" não passou!"<< endl;
    }

};