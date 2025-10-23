export module Piece;
import <iostream>;

namespace quarto
{
	export class Piece
	{
	public:
		enum class Color : uint8_t 
		{
			WHITE,
			BLACK
		};

		enum class Height : uint8_t
		{
			SHORT,
			TALL
		};

		enum class Shape : uint8_t
		{
			CIRCLE,
			SQUARE
		};

		enum class Body : uint8_t
		{
			HOLLOW,
			FULL
		};

		Piece(Color c, Height h, Shape s, Body b) : 
			m_color(c), m_height(h), m_shape(s), m_body(b){}

		Piece(const Piece& other) = delete;
		Piece& operator=(const Piece& other) = delete;
		Piece(Piece&& other) noexcept = default;
		Piece& operator=(Piece&& other) noexcept = default;

	private:
		Color m_color:1;
		Height m_height:1;
		Shape m_shape:1;
		Body m_body:1;

	public:
		Color GetColor() const { return m_color; }
		Height GetHeight() const { return m_height; }
		Shape GetShape() const { return m_shape; }
		Body GetBody() const { return m_body; }
	};
	
	export std::ostream& operator<<(std::ostream& os, const Piece& piece);
}