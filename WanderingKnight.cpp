#include "WanderingKnight.hpp"
#include "Princess.hpp"
#include "Dragon.hpp"

WanderingKnight::WanderingKnight(int x, int y) : NPC(WanderingKnightType, x, y) {}
WanderingKnight::WanderingKnight(std::istream &is) : NPC(WanderingKnightType, is) {}

void WanderingKnight::print()
{
    std::cout << *this;
}

void WanderingKnight::save(std::ostream &os)
{
    os << WanderingKnightType << std::endl;
    NPC::save(os);
}

bool WanderingKnight::visitDragon(std::shared_ptr<Dragon> other){
    fight_notify(other, true);
    return true;
}

bool WanderingKnight::accept(std::shared_ptr<NPC> attacker){
    return attacker->visitWanderingKnight(std::dynamic_pointer_cast<WanderingKnight>(shared_from_this()));
}

std::ostream &operator<<(std::ostream &os, WanderingKnight &knight)
{
    os << "WanderingKnight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}