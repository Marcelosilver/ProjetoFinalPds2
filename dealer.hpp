#ifndef DEALER_H
#define DEALER_H
#include "deck.hpp"
#include "jogador.hpp"
//provavelmente uma má prática, esta inclusão circular...,único jeito que pensei e acho que deu certo

class Dealer {

private:
	std::vector<Carta> mao;
	unsigned int pontuacao;
	Deck baralho;
	

public:
	Dealer();
	int cartas_em_mao();//fins de doctest
	void descartar_mao();
	void mostrar_mao();
	void calcular_pontuacao();
	void preparar_rodada(Jogador &jogador);
	void receber_carta(const Carta &carta);
	unsigned int get_pontuacao() const;
	void set_pontuacao(unsigned int valor);
	Carta Hit_carta();
};

#endif
