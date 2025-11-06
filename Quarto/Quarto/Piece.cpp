module piece;

#include <format>;

using quarto::Piece;

Piece::Piece(Color color, Body body, Shape shape, Height height) :
	m_body{ body }, m_color{ color }, m_height{ height }, m_shape{ shape }
{
	static_assert(sizeof(*this) <= 1, "This class should be 1 byte in size");
}

Piece::Body quarto::Piece::GetBody() const noexcept
{
	return m_body;
}

Piece::Color quarto::Piece::GetColor() const noexcept
{
	return m_color;
}

Piece::Height quarto::Piece::GetHeight() const noexcept
{
	return m_height;
}

Piece::Shape quarto::Piece::GetShape() const noexcept
{
	return m_shape;
}

std::ostream& quarto::operator<<(std::ostream& os, const Piece& piece)
{
	return os << std::format("{}{}{}{}",
		static_cast<int>(piece.GetBody()),
		static_cast<int>(piece.GetColor()),
		static_cast<int>(piece.GetHeight()),
		static_cast<int>(piece.GetShape())
	);
}