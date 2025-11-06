export module board;
import std;
import piece;
namespace quarto {
	export class Board
	{
	public:
		using Position = std::pair<size_t, size_t>;
		static const size_t kHeight{ 4 };
		static const size_t kWidth{ 4 };

		Board() = default;

		const std::optional<Piece>& operator[](const Position& position) const;
		std::optional<Piece>& operator[](const Position& position);

	private:
		static const size_t kArraySize = kHeight * kWidth;
		std::array < std::optional<Piece>, kArraySize> m_board;
	};

	export std::ostream& operator<< (std::ostream& out, const Board& board);
}