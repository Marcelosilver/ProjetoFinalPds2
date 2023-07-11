#ifndef CARTA_H
#define CARTA_h

#include <string>

class Carta {

	private:

		std::string valor;
		std::string naipe;
	public:

	Carta(const std::string &valor, const std::string &naipe){
		this-> valor = valor;
		this-> naipe = naipe;
	}

	std::string get_valor() const{
		
		return valor;
	}

	std::string get_naipe() const{
		
		return naipe;
	}

	std::string nome_carta() const{
		
		return valor +" "+ "de" + " " + naipe;
	}
};

#endif

