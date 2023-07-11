#ifndef JOGADOR_H
#define JOGADOR_H
#include "deck.hpp"
#include <vector>

//inclusão circular

class Dealer;

class Jogador {

private:
	std::vector<Carta> mao;
	unsigned int pontuacao;
	unsigned int fichas;

public:
Jogador();
	void calcular_pontuacao();
	int cartas_em_mao();//fins de doctest
	void mostrar_mao();
	void descartar_mao();
	unsigned int get_pontuacao() const;
	void set_pontuacao(unsigned int valor);
	void receber_carta(const Carta &carta);
	unsigned int get_fichas() const;
	void set_fichas(unsigned int valor);
	void realizar_jogada(Dealer &dealer);
	void regras_da_casa();
	
};
#endif
