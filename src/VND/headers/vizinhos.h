#ifndef SOURCE_H
#define SOURCE_H

#include <vector>
#include <string.h>

struct VND
{
    double melhorSolucao;
    double tempo;
    double gap;
};

struct Heuristica {
    std::string nomeInstancia;
    double tempo;
    double gap;
};

struct Resultados
/* vai guarda todos os resultados da instancia n60A.... */

{
    int instacia;
    struct VND vnd;
    struct Heuristica;

};


struct Pedido {
    int indice;
    int tempoProducao;
    int prazo;
    int multaPorMinuto; 
};

class Fruta {
private:
    int n;
    std::vector<int> t;
    std::vector<int> p;
    std::vector<int> m;
    std::vector<std::vector<int>> matriz;



public:
    Fruta(int n, const std::vector<int>& t, const std::vector<int>& p, const std::vector<int>& m, const std::vector<std::vector<int>>& matriz);

    void producion();
    int calcularCusto(const std::vector<Pedido>& ordemPedidos, const std::vector<std::vector<int>>& matriz) const;
    bool movimentoMulta(std::vector<Pedido>& pedidos, const std::vector<std::vector<int>>& matriz, int& melhorCusto);
    bool movimentoSwap(std::vector<Pedido>& pedidos, const std::vector<std::vector<int>>& matriz, int& melhorCusto);
    bool movimento2Opt(std::vector<Pedido>& pedidos, const std::vector<std::vector<int>>& matriz, int& melhorCusto);
    bool movimentoReinsertion(std::vector<Pedido>& pedidos, const std::vector<std::vector<int>>& matriz, int& melhorCusto);


};

#endif
