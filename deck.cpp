#include "deck.hpp"
#include <algorithm>
#include <random>
#include <iostream>

Deck::Deck() {
	cartas.clear();
std::vector<std::string> naipes ={"Paus","Copas","Ouros","Espadas"};
std::vector<std::string> valores ={"Ás","Rei","Dama","Valete","10","9","8","7","6","5","4","3","2"};

	for(const auto &naipe: naipes){
		for(const auto &valor : valores){
			Carta carta(valor, naipe);
			cartas.push_back(carta);
		}
	}
	
}

void Deck::Embaralhar() {
	
	std::random_device rd;
	std::mt19937 rng(rd());//gerador de números pseudo-aleatórios
	std::shuffle(cartas.begin(),cartas.end(),rng);
	
}//embaralhando o baralho, meio estranho essa frase

Carta Deck::puxar_carta() {
	if (cartas.empty()){
		//Embaralhar();
		Deck();
	}	
	Carta carta = cartas.back();
	cartas.pop_back();
	return carta;
}

int Deck::tam_monte() { 
	return cartas.size();
}

