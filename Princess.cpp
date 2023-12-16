#include "Princess.h"
#include "dragon.h"
#include "WanderingKnight.h"
Princess::Princess(int x, int y) : NPC(PrincessType, x, y) {}
Princess::Princess(std::istream &is) : NPC(PrincessType, is) {}

bool Princess::accept(const std::shared_ptr<NPC> attacker) {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Princess> defender = std::dynamic_pointer_cast<Princess>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}
void Princess::print()
{
    std::cout << *this;
}

void Princess::save(std::ostream &os)
{
    os << PrincessType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Princess &knight)
{
    os << "black knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}