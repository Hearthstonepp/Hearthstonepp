// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Python/Enums/GameEnums.hpp>
#include <Rosetta/Enums/GameEnums.hpp>

#include <pybind11/pybind11.h>

using namespace RosettaStone;

void AddGameEnums(pybind11::module& m)
{
    pybind11::enum_<PlayerType>(m, "PlayerType")
        .value("INVALID", PlayerType::INVALID)
        .value("RANDOM", PlayerType::RANDOM)
        .value("PLAYER1", PlayerType::PLAYER1)
        .value("PLAYER2", PlayerType::PLAYER2);
}
