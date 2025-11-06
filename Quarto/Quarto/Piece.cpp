module piece;

#include <format>;

using quarto::Piece;
using enum Piece::Body;
using enum Piece::Color;
using enum Piece::Height;
using enum Piece::Shape;
quarto::Piece::Piece() :
	m_body {NO_BODY}, m_color {NO_COLOR}, m_height {NO_HEIGHT}, m_shape{NO_SHAPE}
{}

Piece::Piece(Color color, Body body, Shape shape, Height height) :
	m_body{ body }, m_color{ color }, m_height{ height }, m_shape{ shape }
{
	static_assert(sizeof(*this) <= 1, "This class should be 1 byte in size");
}

quarto::Piece::Piece(const Piece& other) : 
	Piece(other.m_color, other.m_body,other.m_shape, other.m_height)
{
	
}

Piece& quarto::Piece::operator=(Piece other)
{
	this->swap(other);
	return *this;
}

quarto::Piece::Piece(Piece&& other) noexcept
{
	this->swap(other);
}

void quarto::Piece::swap(Piece& other) noexcept
{
	Color tmp{ other.m_color };
	Body btmp{ other.m_body };
	Height htmp{ other.m_height };
	Shape stmp{ other.m_shape };
	other.m_color = m_color;
	m_color = tmp;
	other.m_shape = m_shape;
	m_shape = stmp;
	other.m_body = m_body;
	m_body = btmp;
	other.m_height = m_height;
	m_height = htmp;
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