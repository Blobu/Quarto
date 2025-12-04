import piece;
import board;
import unusedpieces;
import <iostream>;

int main()
{
	using quarto::Piece;
	using quarto::Board;
	using quarto::UnusedPieces;
	using enum Piece::Body;
	using enum Piece::Color;
	using enum Piece::Height;
	using enum Piece::Shape;

	Piece piece{ BLACK, FULL, SQUARE,SHORT };

	Board board;
	std::cout << board << std::endl;

	board[{0, 0}] = std::move(piece);
	std::cout << board << std::endl;

	UnusedPieces unusedPieces;

	std::cout << unusedPieces << std::endl;

	board[{2, 1}] = std::move(unusedPieces.PickPiece("1101"));

	std::cout << board << std::endl;

	std::cout << unusedPieces;
}