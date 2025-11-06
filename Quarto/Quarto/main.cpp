import piece;
import <iostream>;

int main()
{
	using quarto::Piece;
	using enum Piece::Body;
	using enum Piece::Color;
	using enum Piece::Height;
	using enum Piece::Shape;

	Piece piece{ BLACK, FULL, SQUARE,SHORT };

	std::cout << piece;
}