#define DOCTEST_CASE_IMPLEMENT_WITH_MAIN
#define DOCTEST_ANON_FUNC_0
#include "doctest.hpp"
#include "dealer.hpp"

TEST_CASE("Testando construtor de Deck") {
	Deck deck;
	CHECK(deck.tam_monte()==52);
}//Não consigo entender por que os testes não funcionam, o problema é o doctest? o copiei das notas de aula...
TEST_CASE("testando se reduz cartas do monte") {
	Deck deck;
	deck.puxar_carta();
	CHECK(deck.tam_monte()==51);
}
TEST_CASE ("testando se a mão do jogador é atualizada"){
	Jogador jogador;
	Deck deck;
	jogador.receber_carta(deck.puxar_carta());
	CHECK(jogador.cartas_em_mao()>0);
}
TEST_CASE ("testando se a mão do Dealer é atualizada") {
	Dealer dealer;
	Deck deck;
	dealer.receber_carta(deck.puxar_carta());
	CHECK(dealer.cartas_em_mao() == 1);
}
TEST_CASE ("testando se a pontuação de jogador é atualizada") {
	Jogador jogador;
	Carta carta("Ás","Paus");
	jogador.receber_carta(carta);
	CHECK(jogador.get_pontuacao()==11);
}
TEST_CASE ("testando se a pontuação de dealer é atualizada") {
	Dealer dealer;
	Carta carta("Valete","Ouros");
	dealer.receber_carta(carta);
	CHECK(dealer.get_pontuacao() == 10);
}
//não sei como fazer os test cases para o método realizar jogada, e por isso não consigo fazer um teste para averiguar se as fichas estão sendo calculadas corretamente

