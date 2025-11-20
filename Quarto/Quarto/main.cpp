import piece;
import board;
import <iostream>;

int main()
{
	using quarto::Piece;
	using quarto::Board;
	using enum Piece::Body;
	using enum Piece::Color;
	using enum Piece::Height;
	using enum Piece::Shape;

	Piece piece{ BLACK, FULL, SQUARE,SHORT };

	Board board;
	std::cout << board << std::endl;

	board[{0, 0}] = std::move(piece);
	std::cout << board << std::endl;
}