// class pessoa
// aluno -> faz prova
// professor -> faz aula, corrige prova
// diretor -> matricula aluno, contrata professor
// pai -> ve nota apenas do filho

/* 11) Student Management System
This might be something that most people already have seen in their daily lives. You see your teacher recording your attendance on a sheet, putting in feedback, uploading assignments, etc. Combine everything, and everything should be part of one sweet project to add to your portfolio! A project as big as this should have its functionality split into three main parts depending on the type of user (which is identified at the time of authentication). These users include:-

Students: Students are designed to be consumers. They login to access their data, download assignments, upload solutions and projects, respond to feedback provided, and so on.
Teachers: Teachers are designed to be providers. They login to provide details about students like feedback, update attendance, communicate with the students, upload assignments, and so on.
Administrator: Administrators are designed to be the hierarchical elements that form the interconnecting bridge between teachers and students. They are the masters of the system – creating and editing account details, managing the mass inflow of information, checking the status of any submissions, and so on.
This project can be highly customizable, and only gets more vibrant once more features are added to improve it. The more, the better.

*/

#include <iostream>
#include <string.h>
using namespace std;


class Pessoa {
    public:
        string name;
        int id;
        Pessoa();
};

Pessoa:: Pessoa(){
}

class Aluno : public Pessoa {
    public:
        int turma;
        Aluno(string name);
        void fazProva();
        int veNota();
};

class Professor : public Pessoa {
    public:
        string materia;
        int turma;
        Professor(string name, string materia);
        void fazAula();
        void corrigeProva();
};

class Diretor : public Pessoa {
    public:
        Diretor(string name);
        Aluno matriculaAluno();
        Professor contrataProfessor();
};

class Pai : public Pessoa {
    public:
        Aluno filho;
        Pai(string name);
        int veNota();
};

Aluno:: Aluno (string name) {
    this->name = name;
    this->turma = 0;
}




