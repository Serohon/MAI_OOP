#include "Princess.hpp"
#include "Dragon.hpp"
#include "WanderingKnight.hpp"

Princess::Princess(int x, int y) : NPC(PrincessType, x, y) {}
Princess::Princess(std::istream &is) : NPC(PrincessType, is) {}

void Princess::print()
{
    std::cout << *this;
}

void Princess::save(std::ostream &os)
{
    os << PrincessType << std::endl;
    NPC::save(os);
}

bool Princess::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, false);
    return false;
}

bool Princess::fight(std::shared_ptr<WanderingKnight> other)
{
    fight_notify(other, false);
    return false;
}

bool Princess::fight(std::shared_ptr<Princess> other)
{
    fight_notify(other, false);
    return false;
}

bool Princess::accept(std::shared_ptr<NPC> attacker){
    return attacker->fight(std::dynamic_pointer_cast<Princess>(shared_from_this()));
}

std::ostream &operator<<(std::ostream &os, Princess &knight)
{
    os << "Princess: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}
