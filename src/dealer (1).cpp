#include "dealer.hpp"
#include <iostream>

Dealer::Dealer() {
	
	baralho.Embaralhar();
	
}
int Dealer::cartas_em_mao() {
	return mao.size();
}
void Dealer::descartar_mao(){
	mao.clear();
}
Carta Dealer::Hit_carta(){
	
	return baralho.puxar_carta();
}
void Dealer::mostrar_mao() {
	
	std::cout<< "Mão do Dealer: "<<std::endl;
	for(const auto &carta : mao){
		std::cout<< carta.nome_carta()<<std::endl;
	}
	std::cout<<"Pontuação do Dealer é: ";
	std::cout<< get_pontuacao()<<std::endl;
	
}
void Dealer::receber_carta(const Carta &carta) {
	
	mao.push_back(Hit_carta());
	calcular_pontuacao();
	
	
}
void Dealer::preparar_rodada(Jogador &jogador) {
	std::cout<<std::endl;
	std::cout<<"Começando a rodada"<<std::endl;
	std::cout<<std::endl;
	descartar_mao();
	jogador.descartar_mao();
	baralho.Embaralhar();
	mao.push_back(Hit_carta());
	calcular_pontuacao();
	jogador.receber_carta(Hit_carta());
	jogador.receber_carta(Hit_carta());
	jogador.mostrar_mao();
	if(jogador.get_pontuacao()==21){
		std::cout<<"Blackjack!"<<std::endl;
		unsigned int aux = jogador.get_fichas();
		std::cout<<"Você recebeu "<<4*aux<<" fichas"<<std::endl;
		jogador.set_fichas(aux*5);
	}
	if(jogador.get_pontuacao() > 21){
		preparar_rodada(jogador);
	}
	mostrar_mao();
}

unsigned int Dealer::get_pontuacao() const{
	
	return pontuacao;
}
void Dealer::set_pontuacao(unsigned int valor){
	pontuacao = valor;
}
void Dealer::calcular_pontuacao() {
	unsigned int pontuacao = 0;
	
	for (const auto &carta : mao) {
		if (carta.get_valor() == "Ás") {
            pontuacao += 11;
            
        } else if (carta.get_valor() == "Valete" || carta.get_valor() == "Dama" || carta.get_valor() == "Rei") {
            pontuacao += 10;
        } else {
            pontuacao += std::stoi(carta.get_valor());
        }
	}
	set_pontuacao(pontuacao);	
}

