#include <iostream>
#include <string.h>
using namespace std;

class Sala {
    public: 
        int id;
    public:
        Sala();
        Sala(int comprimento, int largura, int id, Lista lista);
        int comprimento;
        int largura;
        int getCapacidade();
        bool reservado;
};

class Lista{
    public: 
        Lista();
        Sala salas[50];
        int tamanho;
};


Lista:: Lista(){
    tamanho = 0;
};


Sala:: Sala(){
    reservado = false;
};

Sala:: Sala(int comprimento, int largura, int id, Lista lista){
    this->comprimento = comprimento;
    this->largura = largura;
    this->id = id;
    this->reservado = false;
};

int Sala:: getCapacidade(){
    return comprimento * largura;
}

class Sessao {
    public:
        Sala sala;
        string filme;
        int capacidade;
        int ingressos;
        float preco;
        Sessao(float preco, string filme, Sala sala);
        void comecarFilme();
};

Sessao:: Sessao(float preco, string filme, Sala sala) {
    this->preco = 0;
    this->filme = filme;
    this->sala = sala;
    this->capacidade = sala.getCapacidade();
    this->ingressos = 0;
};


class Manager {
    private:
        string nome;
        int idManager;
    public: 
        Manager(string nome, int idManager);
        void cadastrarSala(Lista lista, Sala sala);
        Sessao criarSessao(float preco, string filme, Sala sala);
        Sala reservarSala(Lista lista, Sessao sessao);
};

Manager:: Manager(string nome, int idManager){
    this->nome = nome;
    this->idManager = idManager;
}

void Manager:: cadastrarSala(Lista lista, Sala sala){
    lista.salas[lista.tamanho] = sala;
    lista.tamanho++;
}

Sessao Manager:: criarSessao(float preco, string filme, Sala sala){
    Sessao sessao(preco, filme, sala);
    return sessao;
}

Sala Manager:: reservarSala(Lista lista, Sessao sessao){
    int i = 0;
    
    while(lista.salas[i].reservado == true){
        i++;
    }
    lista.salas[i].reservado = true;
    sessao.sala = lista.salas[i];
    return lista.salas[i];
}

class Cliente{
    public: 
        Cliente(string name, int id, float dinheiro);
        string name;
        int idCliente;
        float dinheiro;
};

Cliente:: Cliente(string name, int id, float dinheiro){
    this->name = name;
    this->idCliente = id;
    this->dinheiro = dinheiro;
}

class Vendedor {
    private:
        string name;
        int idVendedor;
    public: 
        Vendedor(string nome, int idVendedor);
        void venderIngresso(Sessao sessao, int quantidade, Cliente cliente);
};

Vendedor::Vendedor(string nome, int idVendedor){
    this->name = nome;
    this->idVendedor = idVendedor;
}


void Vendedor::venderIngresso(Sessao sessao, int quantidade, Cliente cliente){
    if(quantidade > (sessao.capacidade - sessao.ingressos)){
        cout<<"Infelizmente o senhor "<<cliente.name<<" não conseguiu comprar os ingressos pois a sessão estava lotada!"<<endl;
    } else if ((quantidade * sessao.preco) > cliente.dinheiro){
        cout<<"Infelizmente o senhor "<<cliente.name<<" não conseguiu comprar os ingressos pois não tinha dinheiro suficiente!"<<endl;
    } else {
        cout<<"O senhor "<<cliente.name<<" comprou "<<quantidade<<" ingressos para a sessão "<<sessao.filme<<"!"<<endl;
        sessao.ingressos += quantidade;
        cliente.dinheiro -= (quantidade * sessao.preco);
    }
}



int main(){
    Manager manager("Hugo", 1);
    Lista listaSalas;

    Sala sala1(5, 8, 1, listaSalas);
    Sala sala2(10, 15, 2, listaSalas);

    Sessao sessao1 = manager.criarSessao(10, "Avengers", sala1);
    Sessao sessao2 = manager.criarSessao(20, "Star Wars", sala2);

    Vendedor vendedor1("Joao", 1);
    Vendedor vendedor2("Maria", 2);

    Cliente cliente1("Lucas", 1, 20);

    manager.reservarSala(listaSalas, sessao1);

    vendedor1.venderIngresso(sessao1, 5, cliente1);
};