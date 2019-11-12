// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Python/Cards/Card.hpp>

#include <Python/Enums/ActionEnums.hpp>
#include <Python/Enums/AuraEnums.hpp>
#include <Python/Enums/CardEnums.hpp>
#include <Python/Enums/GameEnums.hpp>
#include <Python/Enums/TargetingEnums.hpp>
#include <Python/Enums/TaskEnums.hpp>
#include <Python/Enums/TriggerEnums.hpp>

#include <pybind11/pybind11.h>

PYBIND11_MODULE(pyRosetta, m)
{
    m.doc() =
        R"pbdoc(Hearthstone simulator with some reinforcement learning)pbdoc";

    // Cards
    AddCard(m);

    // Enums
    AddActionEnums(m);
    AddAuraEnums(m);
    AddCardEnums(m);
    AddGameEnums(m);
    AddTargetingEnums(m);
    AddTaskEnums(m);
    AddTriggerEnums(m);
}