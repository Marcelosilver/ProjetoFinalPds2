#ifndef DECK_H
#define DECK_H

#include "carta.hpp"
#include <vector>
#include <string>

class Deck {
private:

    std::vector<Carta> cartas;
	
public:
    Deck();
	int tam_monte();
    void Embaralhar();// queria nomear shuffle mas já existe esse método
    Carta puxar_carta();//entrega uma carta ao jogador ou dealer,reutilizado em dealer.cpp
	
};

#endif 
