export module unusedpieces;
import std;

export import piece;

namespace quarto
{
	export class UnusedPieces
	{
	public:
		UnusedPieces();
		Piece PickPiece(std::string_view name);

		friend std::ostream& operator<< (std::ostream& out, const UnusedPieces& unusedPieces);

	private:
		void GeneratePiecesCpp11();
		void GeneratePiecesBitset();
		void GeneratePiecesCpp2x();
		void GeneratePiecesManually();
		void EmplacePiece(Piece&& piece);

	private:
		std::unordered_map<std::string, Piece> m_piecePool;
	};

}