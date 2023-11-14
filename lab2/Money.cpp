#include <cstring>
#include "Money.hpp"

// Default Constructor
Money::Money(): _size(1)
{
    _array = new unsigned char [1];
    _array[0] = '0';
}

// Initializer list constructor
Money::Money(const std::initializer_list<unsigned char> &t)
{
    _array = new unsigned char[t.size()];
    int i{0};
    for (auto elem : t)
        _array[i++] = elem;
    _size = t.size();
}

// Copy string constructor
Money::Money(const std::string &t)
{
    _array = new unsigned char[t.size()];
    _size  = t.size();

    for(int i{0}; i<_size; ++i) _array[i] = t[i];
}

// Copy constructor
Money::Money(const Money &other)
{
    _size  = other._size;
    _array = new unsigned char[_size];

    for(int i{0};i<_size;++i) _array[i] = other._array[i];
}

// Rvalue constructor
Money::Money(Money &&other) noexcept
{
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

// Размер 
int Money::get_size(){
    return _size;
}

// Get Arrays
unsigned char* Money::get_array(){
    return _array;
}

// Равенство двух объектов
bool Money::equals(const Money &other){
    if (_size != other._size){
        return false;
    }
    else{
        for(int i{_size-1};i>=0;--i){
            if(_array[i] != other._array[i])
                return false;
        }
    }
    return true;
}

// Сравнение (true если данный объект больше)
bool Money::bigger(const Money &other){
    if (_size > other._size){
        return true;
    }
    else if(_size < other._size){
        return false;
    }
    else{
        for(int i{_size-1};i>=0;--i){
            if(_array[i] > other._array[i])
                return true;
        }
    }
    return false;
}

// Сложение
Money Money::add(const Money &other)
{
    // При сложении может меняться размерность массива
    _size = std::max(_size,other._size);
    unsigned char* _new_array = new unsigned char [_size];
    memcpy(_new_array,_array,_size);

    int tranf{0}; // Остаток

    for(int i{0}; i < _size; ++i){

        if( _new_array[i] < '0' or _new_array[i] > '9') { _new_array[i] = '0';}
        if( other._array[i] < '0' or other._array[i] > '9'){ other._array[i] = '0';}

        int s = (_new_array[i] - '0') + (other._array[i] - '0') + tranf;
        tranf = s/10;
        _new_array[i] = '0' + s%10;
    }

    if(tranf){
        // Если остался остаток, то у числа увелчится разряд
        _array = new unsigned char [_size+1];
        memcpy(_array,_new_array,_size);
        _size++;
        _array[_size-1] = '0' + tranf;
    }
    else{
        _array = new unsigned char [_size+1];
        memcpy(_array,_new_array,_size);
    }

    delete[] _new_array;

    return *this;
}

// Вычитание
Money Money::remove(const Money &other){
    if( this->equals(other)){
        _array[0] = '0';
        _size = 1;
    }
    else if(!this->bigger(other)){
        throw std::logic_error("negative balance");;
    }
    else{
        unsigned char* _new_array = new unsigned char [_size];
        memcpy(_new_array,other._array, other._size);
    
        for(int i{0}; i<_size; i++){

            if(_new_array[i] < '0' or _new_array[i] > '9') {_new_array[i] = '0';}
            
            if(_array[i] >= _new_array[i]){
                // Если уменьшаемое больше вычитаемого
                _array[i] = (_array[i] - _new_array[i]) + '0'; 
            }
            else{
                // Если уменьшаемое меньше вычитаемого
                int tmp_id {i+1};

                while(_array[tmp_id] == '0'){
                    tmp_id++;
                }

                _array[tmp_id] = '0' + (_array[tmp_id] - '1');
                --tmp_id;

                _array[i] = (((_array[i] - '0') - (_new_array[i] - '0')) + 10) + '0';

                while(tmp_id != i){
                    _array[tmp_id] = '9';
                    --tmp_id;
                }
            }
        }

        delete[] _new_array;
        
        while(_array[_size - 1] == '0' and _size > 0){
            --_size;
        }
    }
    return *this;
}

// Печать
void Money::print(){
    if(_size == 1){
        std::cout << "0.0" << _array[0];
    }
    else{
        for(int i{_size-1};i>=0; i--){
            if(i == 1){
                std::cout << '.';
            }
            std::cout<<_array[i];
        }
    }
    std::cout << std::endl;
}

// Деструктор
Money::~Money() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}