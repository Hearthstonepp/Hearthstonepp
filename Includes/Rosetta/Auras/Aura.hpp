// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_AURA_HPP
#define ROSETTASTONE_AURA_HPP

#include <Rosetta/Auras/AuraUpdateInstruction.hpp>
#include <Rosetta/Auras/IAura.hpp>
#include <Rosetta/Cards/Card.hpp>
#include <Rosetta/Conditions/SelfCondition.hpp>
#include <Rosetta/Enchants/Enchant.hpp>
#include <Rosetta/Enums/AuraEnums.hpp>

#include <queue>
#include <string>

namespace RosettaStone
{
class Entity;

//!
//! \brief Aura class.
//!
//! This class represent aura. Auras can affect entities and change the applied
//! entities attack, cost and so on. Aura must be activated first to affect
//! entities.
//!
class Aura : public IAura
{
 public:
    //! Default constructor.
    Aura() = default;

    //! Constructs aura with given \p type and \p effects.
    //! \param type The type of aura.
    //! \param effects A list of effect.
    Aura(AuraType type, std::vector<IEffect*> effects);

    //! Constructs aura with given \p type and \p enchantmentID.
    //! \param type The type of aura.
    //! \param enchantmentID The enchantment card ID.
    Aura(AuraType type, std::string&& enchantmentID);

    //! Default virtual destructor.
    virtual ~Aura() = default;

    //! Apply this aura to the target entities or remove this aura
    //! if the owner is nullified.
    void Update() override;

    //! Create new Aura instance to the owner's game.
    //! \param owner An owner of aura.
    //! \param cloning The flag to indicate that it is cloned.
    void Activate(Entity* owner, bool cloning = false) override;

    //! Removes this effect from the game to stop affecting entities.
    void Remove() override;

    //! Clones aura effect to \p clone.
    //! \param clone The entity to clone aura effect.
    void Clone(Entity* clone) override;

    //! Removes entity to update a list of entities.
    //! \param entity An entity to remove.
    void RemoveEntity(Entity* entity);

    //! Applies aura's effect(s) to target entity.
    //! \param entity An entity to apply aura's effect(s).
    void Apply(Entity* entity);

    //! Disapplies aura's effect(s) to target entity.
    //! \param entity An entity to disapply aura's effect(s).
    void Disapply(Entity* entity);

    //! Returns the type of aura.
    //! \return The type of aura.
    AuraType GetAuraType() const;

    //! Returns the effect of aura.
    //! \return The effect of aura.
    std::vector<Effect*> GetEffects() const;

    //! Returns the applied entities affected by the aura.
    //! \return The applied entities affected by the aura.
    std::vector<Entity*> GetAppliedEntities() const;

    SelfCondition* condition = nullptr;
    bool restless = false;

 protected:
    //! Constructs aura with given \p prototype and \p owner.
    //! \param prototype An aura for prototype.
    //! \param owner An owner of aura.
    Aura(Aura& prototype, Entity& owner);

    //! Adds aura to the game.
    //! \param owner An owner of aura.
    //! \param aura The dynamically allocated Aura instance.
    void AddToGame(Entity& owner, Aura& aura);

    AuraType m_type = AuraType::INVALID;
    Entity* m_owner = nullptr;

    std::priority_queue<AuraUpdateInstruction> m_auraUpdateInstQueue;
    std::vector<int> m_appliedEntityIDs;

    std::vector<IEffect*> m_effects;

    bool m_turnOn = true;

 private:
    //! Adds aura to battlefield.
    void AddToField();

    //! Internal method of Update().
    void UpdateInternal();

    //! Internal method of Remove().
    void RemoveInternal();

    //! Renews the condition of the applied entities.
    void RenewAll();

    Card* m_enchantmentCard = nullptr;

    std::vector<Entity*> m_tempList;
};
}  // namespace RosettaStone

#endif  // ROSETTASTONE_AURA_HPP
