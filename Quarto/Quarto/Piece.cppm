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
			BLACK,
			NO_COLOR
		};

		enum class Height : uint8_t
		{
			SHORT,
			TALL,
			NO_HEIGHT
		};

		enum class Shape : uint8_t
		{
			ROUND,
			SQUARE,
			NO_SHAPE
		};

		enum class Body : uint8_t
		{
			HOLLOW,
			FULL,
			NO_BODY
		};

		Piece();
		Piece(Color color, Body body, Shape shape, Height height);
		Piece(const Piece& other);
		Piece& operator=(Piece other);
		Piece(Piece&& other) noexcept;
		void swap(Piece& other) noexcept;

	private:
		Color m_color : 2;
		Body m_body : 2;
		Shape m_shape : 2;
		Height m_height : 2;

	public:
		Color GetColor() const noexcept;
		Body GetBody() const noexcept;
		Shape GetShape() const noexcept;
		Height GetHeight() const noexcept;
	};

	export std::ostream& operator<<(std::ostream& os, const Piece& piece);

}