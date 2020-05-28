#include <cassert>

#include <GAME/engine/behaviour/BaseUnitMoveBehaviour.hpp>
#include <GAME/engine/Unit.hpp>
#include <GAME/utils/Utils.hpp>
#include <GAME/engine/GameBoard.hpp>
#include <GAME/engine/Cell.hpp>

void BaseUnitMoveBehaviour::computeAvailableCells() {
	PathSearcher searcher;
	Unit& unit = provide();
	searcher.computePaths(
		unit.getOccupiedCell(),
		[&unit](sf::Vector2i& cellPosition) {
			if (!unit.getBoard()->hasCell(cellPosition))
				return false;

			for (auto &object : unit.getBoard()->getCell(cellPosition).objects())
				if (object->isTangible())
					return false;

			return true;
		},
		unit.getSpeed()
		);
	VectorsSet<int> points;

	for (auto point : *searcher.getPaths())
		points.insert(point->coords);

	_availableCells = points;
}

VectorsSet<int>& BaseUnitMoveBehaviour::availableCells() {
	return _availableCells;
}

bool BaseUnitMoveBehaviour::move(sf::Vector2i &cell) {
	assert(isAttached());

	if (cell == provide().getOccupiedCell())
		return false;

	computeAvailableCells();

	if (availableCells().count(cell) == 0)
		return false;

	for (auto& object : provide().getBoard()->getCell(cell).objects()) {
		if (object->isTangible())
			return false;
	}

	provide().setOccupiedCell(cell);
	return true;
}