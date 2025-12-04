module unusedpieces;

using quarto::Piece;
using quarto::UnusedPieces;

UnusedPieces::UnusedPieces()
{
	GeneratePiecesBitset();
}

Piece UnusedPieces::PickPiece(std::string_view name)
{
	//if (auto itMap{ m_piecePool.find(std::string{name}) }; itMap != m_piecePool.end())
	//{
	//	Piece piece{ std::move(itMap->second) };
	//	m_piecePool.erase(itMap);
	//	return piece;
	//}
	//else
	//	throw std::invalid_argument{ "Piece not found" };

	if (auto node{ m_piecePool.extract(std::string{name}) }; node)
		return std::move(node.mapped());
	else
		throw std::invalid_argument{ "Piece not found" };
}

std::ostream& quarto::operator<<(std::ostream& out, const UnusedPieces& unusedPieces)
{
	for (const auto& [pieceName, piece] : unusedPieces.m_piecePool)
		out << pieceName << " ";
	return out;
}

void UnusedPieces::GeneratePiecesCpp11()
{
	//const size_t kPermutationPoolSize{ 8 };
	//std::array<std::uint8_t, kPermutationPoolSize> permutationPool{ 0,0,0,0,1,1,1,1 };
	std::array permutationPool{ 0,0,0,0,1,1,1,1 };

	const size_t kPermutationSize{ 4 };
	const size_t kMaxPermutations{ 5 };

	for (size_t currentPermutation{}; currentPermutation < kMaxPermutations; ++currentPermutation)
	{
		auto itPoolBegin{ permutationPool.begin() + currentPermutation };
		auto itPoolEnd{ itPoolBegin + kPermutationSize };

		do
		{
			EmplacePiece(Piece{
				static_cast<Piece::Color>(*(itPoolBegin + 1)),
				static_cast<Piece::Body>(*itPoolBegin),
				static_cast<Piece::Shape>(*(itPoolBegin + 3)),
				static_cast<Piece::Height>(*(itPoolBegin + 2))
				});
		} while (std::next_permutation(itPoolBegin, itPoolEnd));
	}
}

void UnusedPieces::GeneratePiecesBitset()
{
	for (unsigned i{ 0 }; i < 16u; ++i)
	{
		std::bitset<4> pieceBits{ i };
		EmplacePiece(Piece{
				static_cast<Piece::Color>(pieceBits.test(3)),
				static_cast<Piece::Body>(pieceBits.test(2)),
				static_cast<Piece::Shape>(pieceBits.test(1)),
				static_cast<Piece::Height>(pieceBits.test(0))
			});
	}
}

void UnusedPieces::GeneratePiecesCpp2x()
{
	std::array permutationPool{ 0,0,0,0,1,1,1,1 };
	const size_t kPermutationSize{ 4 };
	const size_t kMaxPermutations{ 5 };

	namespace rv = std::ranges::views;

	for (auto view : rv::slide(permutationPool, kPermutationSize))
	{
		do
		{
			EmplacePiece(Piece{
				static_cast<Piece::Color>(view[0]),
				static_cast<Piece::Body>(view[1]),
				static_cast<Piece::Shape>(view[2]),
				static_cast<Piece::Height>(view[3])
				});
		} while (std::next_permutation(view.begin(), view.end()));
	}
}

void UnusedPieces::GeneratePiecesManually()
{
	using enum Piece::Color;
	using enum Piece::Body;
	using enum Piece::Shape;
	using enum Piece::Height;
	EmplacePiece(Piece{ WHITE, FULL,   ROUND, SHORT });
	EmplacePiece(Piece{ WHITE, HOLLOW, ROUND, SHORT });
	EmplacePiece(Piece{ WHITE, FULL,   SQUARE, SHORT });
	EmplacePiece(Piece{ WHITE, HOLLOW, SQUARE, SHORT });
	EmplacePiece(Piece{ WHITE, FULL,   ROUND, TALL });
	EmplacePiece(Piece{ WHITE, HOLLOW, ROUND, TALL });
	EmplacePiece(Piece{ WHITE, FULL,   SQUARE, TALL });
	EmplacePiece(Piece{ WHITE, HOLLOW, SQUARE, TALL });
	EmplacePiece(Piece{ BLACK, FULL,   ROUND, SHORT });
	EmplacePiece(Piece{ BLACK, HOLLOW, ROUND, SHORT });
	EmplacePiece(Piece{ BLACK, FULL,   SQUARE, SHORT });
	EmplacePiece(Piece{ BLACK, HOLLOW, SQUARE, SHORT });
	EmplacePiece(Piece{ BLACK, FULL,   ROUND, TALL });
	EmplacePiece(Piece{ BLACK, HOLLOW, ROUND, TALL });
	EmplacePiece(Piece{ BLACK, FULL,   SQUARE, TALL });
	EmplacePiece(Piece{ BLACK, HOLLOW, SQUARE, TALL });
}

void UnusedPieces::EmplacePiece(Piece&& piece)
{
	std::stringstream stringStream;
	stringStream << piece;
	m_piecePool.emplace(stringStream.str(), std::move(piece));
}
