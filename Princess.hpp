#pragma once
#include "NPC.hpp"

struct Princess : public NPC
{
    Princess(int x, int y);
    Princess(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool accept(std::shared_ptr<NPC> attacker) override;
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<WanderingKnight> other) override;
    bool fight(std::shared_ptr<Princess> other) override;
    friend std::ostream &operator<<(std::ostream &os, Princess &knight);
};