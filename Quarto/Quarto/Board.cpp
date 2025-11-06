module board;
const std::optional<Piece>& quarto::Board::operator[](const Position& position) const
{
	const auto& [line, column] = position;
	return m_board[line * kWidth + column];
}

std::optional<Piece>& quarto::Board::operator[](const Position& position)
{
	return const_cast<std::optional<Piece>&> ((*this)[position]);
}
std::ostream& quarto::operator<<(std::ostream& out, const Board& board)
{

}