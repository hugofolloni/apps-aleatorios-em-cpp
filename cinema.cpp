#include <iostream>
#include <string.h>
using namespace std;

class Sala {
    public: 
        int id;
    public:
        Sala();
        Sala(int comprimento, int largura, int id);
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

class Sessao {
    public:
        Sala sala;
        string filme;
        int capacidade;
        int ingressos;
        float preco;
        Sessao();
        Sessao(float preco, string filme, Sala sala);
        void comecarFilme();
        void showInfos();
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
        void rodarFilme(Sessao sessao);
};

class Ingresso{
    public: 
        Ingresso();
        Sala sala;
        Sessao sessao;
        string filme;
        int quantidade;
};

class listaIngressos {
    public: 
        listaIngressos();
        Ingresso ingressos[50];
        int tamanho;
        void listarIngressos(string nome);
};

class Cliente{
    public: 
        string name;
        int idCliente;
        float dinheiro;
        Cliente(string name, int id, float dinheiro);
        listaIngressos ingressosPossuidos;
        void listarIngressos();
        void showInfos();
};

class Vendedor {
    private:
        string name;
        int idVendedor;
    public: 
        Vendedor(string nome, int idVendedor);
        void venderIngresso(Sessao& sessao, int quantidade, Cliente& cliente);
};


// Methods
Lista:: Lista(){
    tamanho = 0;
};


Sala:: Sala(){
    reservado = false;
};

Sala:: Sala(int comprimento, int largura, int id){
    this->comprimento = comprimento;
    this->largura = largura;
    this->id = id;
    this->reservado = false;
};

int Sala:: getCapacidade(){
    return comprimento * largura;
}

Sessao:: Sessao(){
    preco = 0;
    filme = "";
    sala = Sala();
};

Ingresso:: Ingresso(){
    filme = "";
}


listaIngressos:: listaIngressos(){
    tamanho = 0;
};

Sessao:: Sessao(float preco, string filme, Sala sala) {
    this->preco = preco;
    this->filme = filme;
    this->sala = sala;
    this->capacidade = sala.getCapacidade();
    this->ingressos = 0;
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

Cliente:: Cliente(string name, int id, float dinheiro){
    this->name = name;
    this->idCliente = id;
    this->dinheiro = dinheiro;
    this->ingressosPossuidos = listaIngressos();

}

Vendedor::Vendedor(string nome, int idVendedor){
    this->name = nome;
    this->idVendedor = idVendedor;
}

void Vendedor::venderIngresso(Sessao& sessao, int quantidade, Cliente& cliente){
    if(quantidade > (sessao.capacidade - sessao.ingressos)){
        cout<<"Infelizmente o senhor "<<cliente.name<<" não conseguiu comprar os ingressos pois a sessão estava lotada!"<<endl;
    } else if ((quantidade * sessao.preco) > cliente.dinheiro){
        cout<<"Infelizmente o senhor "<<cliente.name<<" não conseguiu comprar os ingressos pois não tinha dinheiro suficiente!"<<endl;
    } else {
        cout<<"O senhor "<<cliente.name<<" comprou "<<quantidade<<" ingressos para a sessão "<<sessao.filme<<"!"<<endl;
        sessao.ingressos += quantidade;
        cliente.dinheiro -= quantidade * sessao.preco;
        Ingresso ingresso;
        ingresso.sessao = sessao;
        ingresso.quantidade = quantidade;
        cliente.ingressosPossuidos.ingressos[cliente.ingressosPossuidos.tamanho] = ingresso;
        cliente.ingressosPossuidos.tamanho++;
    }
};

void listaIngressos:: listarIngressos(string nome){
    for(int i = 0; i < tamanho; i++){
        cout<<endl;
        cout<<"Comprador: "<<nome<<endl;
        cout<<"Sessao: "<<ingressos[i].sessao.filme<<endl;
        cout<<"Sala: "<<ingressos[i].sessao.sala.id<<endl;
        cout<<"Capacidade: "<<ingressos[i].sessao.sala.comprimento<<"x"<<ingressos[i].sessao.sala.largura<<endl;
        cout<<"Preco: "<<ingressos[i].sessao.preco<<endl;
        cout<<"Quantidade: "<<ingressos[i].quantidade<<endl;
        cout<<"\n----------------------------------------"<<endl;
    }
};

void Cliente:: listarIngressos(){
    cout<<"\nLISTA DE INGRESSOS DE "<<name<<endl;
    ingressosPossuidos.listarIngressos(name);
};


void Manager:: rodarFilme(Sessao sessao){
    sessao.comecarFilme();
};

void Sessao:: comecarFilme(){
    cout<<"\n\nComeçando a sessão "<<filme<<" na sala "<<sala.id<<" para "<<ingressos<<" pessoas!\n"<<endl;
};

void Cliente:: showInfos(){
    cout<<endl;
    cout<<"Nome: "<<name<<endl;
    cout<<"Id: "<<idCliente<<endl;
    cout<<"Dinheiro: "<<dinheiro<<endl;
    cout<<"Ingressos: "<<ingressosPossuidos.tamanho<<endl;
    cout<<"\n----------------------------------------"<<endl;
};

void Sessao:: showInfos(){
    cout<<endl;
    cout<<"Filme: "<<filme<<endl;
    cout<<"Sala: "<<sala.id<<endl;
    cout<<"Capacidade: "<<sala.comprimento<<"x"<<sala.largura<<endl;
    cout<<"Preco: "<<preco<<endl;
    cout<<"Ingressos: "<<ingressos<<endl;
    cout<<"\n----------------------------------------"<<endl;
};


int main(){
    Manager manager("Hugo", 1);
    Lista listaSalas;

    Sala sala1(5, 8, 1);
    Sala sala2(10, 15, 2);

    manager.cadastrarSala(listaSalas, sala1);
    manager.cadastrarSala(listaSalas, sala2);


    Sessao sessao1(10, "Avengers", sala1);
    Sessao sessao2(20, "Star Wars", sala2);

    Vendedor vendedor1("Joao", 1);
    Vendedor vendedor2("Maria", 2);

    Cliente cliente1("Lucas", 1, 70);
    Cliente cliente2("Luiza", 2, 20);

    manager.reservarSala(listaSalas, sessao1);

    vendedor1.venderIngresso(sessao1, 5, cliente1);
    vendedor1.venderIngresso(sessao2, 1, cliente1);

    vendedor2.venderIngresso(sessao1, 2, cliente2);

    cliente1.showInfos();
    cliente2.showInfos();

    sessao1.showInfos();
    sessao2.showInfos();

    cliente1.listarIngressos();

    manager.rodarFilme(sessao1);
};