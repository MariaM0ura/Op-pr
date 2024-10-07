#ifndef SOURCE_H
#define SOURCE_H

#include <vector>
#include <string>  // Alterado para <string> para suportar std::string

struct VND {
    double melhorSolucao;
    double tempo;
    double gap;
};


struct Resultados {
    std::string instancia;  // std::string usado corretamente
    double solucaoOtima;
    VND vnd;
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
    std::vector<Pedido> pedidos;
    
    double producion();
    void guloso();
    int calcularCusto(const std::vector<Pedido>& ordemPedidos, const std::vector<std::vector<int>>& matriz) const;
    bool movimentoSwap(std::vector<Pedido>& pedidos, const std::vector<std::vector<int>>& matriz, int& melhorCusto);
    int calcularCustoSwapIncremental(const Pedido& pedido1, const Pedido& pedido2, const std::vector<std::vector<int>>& matriz);
    bool movimento2Opt(std::vector<Pedido>& pedidos, const std::vector<std::vector<int>>& matriz, int& melhorCusto);
    bool movimentoReinsertion(std::vector<Pedido>& pedidos, const std::vector<std::vector<int>>& matriz, int& melhorCusto);
};

#endif
