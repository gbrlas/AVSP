#include "tttt.hpp"
#include <iostream>
#include <map>
#include <vector>

enum class Outcome { X_WON, O_WON, DRAW, NOT_COMPLETE };

std::map<Outcome, std::string> outcomes = {
	{ Outcome::X_WON, "X won" }, { Outcome::O_WON, "O won" }, { Outcome::DRAW, "Draw" }, { Outcome::NOT_COMPLETE, "Game has not completed" }
};

bool analyze(const Grid& g, Square winner, std::vector<coord> coords) {
	for (int i = 0; i < coords.size(); ++i) {
		const Square& s = g(coords[i]);
		if (s != Square::T && s != winner) return false;
	}
	return true;
}

bool analyzeRow(const Grid& g, Square winner, int y) {
	return analyze(g, winner, {{0, y}, {1, y}, {2, y}, {3, y}});
}

bool analyzeColumn(const Grid& g, Square winner, int x) {
	return analyze(g, winner, {{x, 0}, {x, 1}, {x, 2}, {x, 3}});
}

bool analyzeDiag1(const Grid& g, Square winner) {
	return analyze(g, winner, {{0, 0}, {1, 1}, {2, 2}, {3, 3}});
}

bool analyzeDiag2(const Grid& g, Square winner) {
	return analyze(g, winner, {{3, 0}, {2, 1}, {1, 2}, {0, 3}});
}

bool allSquaresFull(const Grid& g) {
	for (int y = 0; y < 4; ++y)
		for (int x = 0; x < 4; ++x)
			if (g(x, y) == Square::E) return false;
	return true;
}

bool analyzeWinner(const Grid& g, Square s) {
	for (int i = 0; i < 4; ++i) {
		if (analyzeRow(g, s, i) || analyzeColumn(g, s, i)) return true;
	}
	if (analyzeDiag1(g, s) || analyzeDiag2(g, s)) return true;
	return false;
}

Outcome analyze(const Grid& g) {
	if (analyzeWinner(g, Square::X)) return Outcome::X_WON;
	if (analyzeWinner(g, Square::O)) return Outcome::O_WON;

	if (allSquaresFull(g)) return Outcome::DRAW;

	return Outcome::NOT_COMPLETE;
}

int main(int argc, char* argv[]) {
	size_t n; std::cin >> n;

	Grid g;

	for (size_t i = 1; i <= n; ++i) {
		std::cin >> g;
		std::cout << "Case #" << i << ": " << outcomes[analyze(g)] << std::endl;
	}
}
