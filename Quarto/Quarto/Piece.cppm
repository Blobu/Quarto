export module piece;
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
			ROUND,
			SQUARE
		};

		enum class Body : uint8_t
		{
			HOLLOW,
			FULL
		};

		Piece(Color color, Body body, Shape shape, Height height);
		Piece(const Piece& other) = delete;
		Piece& operator=(const Piece& other) = delete;
		Piece(Piece&& other) noexcept = default;
		Piece& operator=(Piece&& other) noexcept = default;

	private:
		Color m_color : 1;
		Body m_body : 1;
		Shape m_shape : 1;
		Height m_height : 1;

	public:
		Color GetColor() const noexcept;
		Body GetBody() const noexcept;
		Shape GetShape() const noexcept;
		Height GetHeight() const noexcept;
	};

	export std::ostream& operator<<(std::ostream& os, const Piece& piece);

}