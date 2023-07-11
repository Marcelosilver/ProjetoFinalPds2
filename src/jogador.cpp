#include "dealer.hpp"
#include <iostream>
#include <sstream>//melhor forma que achei de descartar a linha da entrada inválida

Jogador::Jogador(){
	
	fichas = 10;
	pontuacao = 0;
}
int Jogador::cartas_em_mao(){
	return mao.size();
}
unsigned int Jogador::get_pontuacao() const{
	
		return pontuacao;
}
void Jogador::descartar_mao(){
	mao.clear();
}
unsigned int Jogador::get_fichas() const{
	
	return fichas;
}

void Jogador::set_pontuacao(unsigned int valor){
	
	pontuacao = valor;
}
void Jogador::set_fichas(unsigned int valor){
	fichas = valor;
}
void Jogador::receber_carta(const Carta &carta){
	
	mao.push_back(carta);
	calcular_pontuacao();
	
}

void Jogador::mostrar_mao() {
	
	std::cout<<"Sua mão é: "<<std::endl;
	for(const auto &carta : mao){
		std::cout<< carta.nome_carta()<<std::endl;
	}
	std::cout<<"Sua pontuação é: ";
	std::cout<< get_pontuacao()<<std::endl;
	
}

void Jogador::calcular_pontuacao(){
	
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
void Jogador::regras_da_casa() {
	
std::cout<<"O objetivo do jogo é ter uma mão com valor mais próximo possível de 21,desde que não ultrapasse este(burst out)."<<std::endl;
std::cout<<"Cada carta númerica possui valor igual ao seu número.Valete,Dama e Rei valem dez pontos, e Ás vale 11(neste jogo)."<<std::endl;
std::cout<<"O jogador recebe duas cartas inicialmente, depois ele realiza uma aposta com suas fichas.Como opções de jogada ele pode optar entre receber mais cartas(Hit) ou manter sua mão atual(Stand)."<<std::endl;
std::cout<<"Após a vez do jogador é a vez do dealer. O dealer continua a receber cartas até atingir 17 ou mais."<<std::endl;
std::cout<<"Portanto,você estará jogando contra o dealer, e, aquele que ao final de uma rodada tiver pontuação mais próxima de 21 vence a rodada e recebe fichas de acordo com a aposta inicial."<<std::endl;
std::cout<<std::endl;
}
////////////////////////////////////////////////////////////////////
void Jogador::realizar_jogada(Dealer &dealer) {
	dealer.preparar_rodada(*this);
	char jogada;
	int aposta = 0;
	bool faliu = 0;
	std::string entrada;
	while (faliu == 0) {
		if(aposta == 0) {	
	std::cout<<"Por favor,faça sua aposta."<<std::endl;
	std::cout<<"Você possui "<<get_fichas()<<" fichas"<<std::endl;
	std::cin.clear();
	while(std::getline(std::cin,entrada)){
		std::istringstream iss(entrada);
		if(iss>>aposta && aposta>0 && aposta<=fichas && iss.eof()){
			break;	
		}
		else {
		std::cout<<"Por favor,faça uma aposta válida."<<std::endl;
		}
	}

	fichas -= aposta;
}
std::cout<<"Escolha sua jogada/opção:"<<std::endl;
std::cout<<"Digite h para: receber mais uma carta"<<std::endl;
std::cout<<"Digite s para: não receber mais cartas"<<std::endl;
std::cout<<"Digite r para: para ler sobre as regras do jogo"<<std::endl;
		while(std::getline(std::cin,entrada)) {
			if(entrada.size()==1){
				jogada = entrada[0];
				if(jogada=='r'||jogada=='s'|| jogada=='h'){
					break;
				}
			}
		std::cout<<"Entrada inválida,por favor escolha uma jogada"<<std::endl;
		}

		
	switch (jogada) {	
	case 'h':
		receber_carta(dealer.Hit_carta());
		mostrar_mao();
		if(pontuacao > 21){
			std::cout<<"Sua mão estourou,você perdeu!"<<std::endl;
			mao.clear();
			set_pontuacao(0);
			dealer.set_pontuacao(0);
			aposta = 0;
			if(fichas == 0  ){
				faliu = 1;
			}
			else{
				dealer.preparar_rodada(*this);;
			}
		}
	break;

	case 's':
		calcular_pontuacao();
		while(dealer.get_pontuacao()<17){
			dealer.receber_carta(dealer.Hit_carta());
			dealer.calcular_pontuacao();
		}
		dealer.mostrar_mao();
		if(dealer.get_pontuacao()>21){
			std::cout<<"A mão do dealer estourou,você ganhou!"		<<std::endl;
			fichas += aposta*2;
			aposta = 0;
			mao.clear();
			set_pontuacao(0);
			dealer.set_pontuacao(0);
			dealer.preparar_rodada(*this);
			break;
		}
		if(get_pontuacao()>dealer.get_pontuacao()){
			std::cout<<"Parabéns,você ganhou!"<<std::endl;
			fichas += aposta*3;
			aposta = 0;
			mao.clear();
			set_pontuacao(0);
			dealer.set_pontuacao(0);
			dealer.preparar_rodada(*this);
			break;
			}
		else if (get_pontuacao()<dealer.get_pontuacao()) {
			std::cout<<"Infelizmente você perdeu..."							<<std::endl;
			mao.clear();
			set_pontuacao(0);
			dealer.set_pontuacao(0);
			aposta = 0;
			if(fichas == 0  ) {
				faliu = 1;
			}
			else{
				dealer.preparar_rodada(*this);;
			}
			break;
		}
		else {
			std::cout<<"Um empate!"<<std::endl;
			fichas += aposta;
			aposta = 0;
			mao.clear();
			set_pontuacao(0);
			dealer.set_pontuacao(0);
			dealer.preparar_rodada(*this);
			break;
			
		}//finalizar rodada e resetar rodada
	
	case 'r':
		regras_da_casa();
		break;
			}
		}
	if(fichas==0){
			std::cout<<"Você faliu, mais sorte na próxima vez."<<std::endl;
			
		}
}

//aparenta estar certo, alguns resultados inesperados com entradas invalidas
