#include "NPC.hpp"
#include "Dragon.hpp"
#include "WanderingKnight.hpp"
#include "Princess.hpp"
// Текстовый наблюдатель
class TextObserver : public IFightObserver {
private:
    TextObserver() {}

public:
    static std::shared_ptr<IFightObserver> get() {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override {
        if (win) {
            std::cout << std::endl
                      << "Убийство --------" << std::endl;
            attacker->print();
            defender->print();
        }
    }
};

// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is) {
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type) {
        switch (type) {
            case DragonType:
                result = std::make_shared<Dragon>(is);
                break;
            case WanderingKnightType:
                result = std::make_shared<WanderingKnight>(is);
                break;
            case PrincessType:
                result = std::make_shared<Princess>(is);
                break;
        }
    } else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());

    return result;
}


std::shared_ptr<NPC> factory(NpcType type, int x, int y) {
    std::shared_ptr<NPC> result;
    switch (type) {
        case DragonType:
            result = std::make_shared<Dragon>(x, y);
            break;
        case WanderingKnightType:
            result = std::make_shared<WanderingKnight>(x, y);
            break;
        case PrincessType:
            result = std::make_shared<Princess>(x, y);
            break;
        default:
            break;
    }
    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

// Сохранение массива в файл
void save(const set_t &array, const std::string &filename) {
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename) {
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open()) {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    } else
        std::cerr << "Ошибка: " << std::strerror(errno) << std::endl;
    return result;
}

// Вывод на экран
std::ostream &operator<<(std::ostream &os, const set_t &array) {
    for (auto &n : array)
        n->print();
    return os;
}

// Метод осуществляющий сражение с использованием паттерна Visitor
set_t fight(const set_t &array, size_t distance) {
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance))) {
                bool success = attacker->accept(defender);
                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}

int main() {
    set_t array; // монстры
    std::cout << "Генерация ..." << std::endl;
    for (size_t i = 0; i < 10; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1), std::rand() % 100, std::rand() % 100));
    std::cout << "Сохранение ..." << std::endl;

    save(array, "npc.txt");

    std::cout << "Загрузка ..." << std::endl;
    array = load("npc.txt");

    std::cout << "Бой ..." << std::endl
              << array;

    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10) {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase(d);
        std::cout << "Статистика боя ----------" << std::endl
                  << "Дистанция: " << distance << std::endl
                  << "Убито: " << dead_list.size() << std::endl
                  << std::endl << std::endl;
    }

    std::cout << "Выжившие:" << array;
    return 0;
}
