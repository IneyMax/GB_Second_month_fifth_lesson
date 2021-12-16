#include <iostream>
 
template <class T>
class Pair1
{
    T m_a;
    T m_b;
 
public:
    Pair1(const T& a, const T& b)
        : m_a(a), m_b(b)
    {
    }
 
    T& first() { return m_a;  }
    const T& first() const { return m_a; }
    T& second() { return m_b; }
    const T& second() const { return m_b; }
};

 
template <class T, class S>
class Pair2
{
    T m_a;
    S m_b;
 
public:
    Pair2(const T& a, const S& b)
        : m_a(a), m_b(b)
    {
    }
 
    T& first() { return m_a; }
    const T& first() const { return m_a; }
    S& second() { return m_b; }
    const S& second() const { return m_b; }
};
 
template <class S>
class StringValuePair : public Pair2<std::string, S>
{
public:
    StringValuePair(const std::string& key, const S& value)
        : Pair2<std::string, S>(key, value)
    {
    }
};


int main()
{
    {   // task 1
        Pair1<int> p1(6, 9);
        std::cout << "Pair1: " << p1.first() << ' ' << p1.second() << '\n';
 
        const Pair1<double> p2(3.4, 7.8);
        std::cout << "Pair1: " << p2.first() << ' ' << p2.second() << '\n';
    }

    {   // task 2
        Pair2<int, double> p1(6, 7.8);
        std::cout << "Pair2: " << p1.first() << ' ' << p1.second() << '\n';
 
        const Pair2<double, int> p2(3.4, 5);
        std::cout << "Pair2: " << p2.first() << ' ' << p2.second() << '\n';
    }

    {   // task 3
        StringValuePair<int> svp("Amazing", 7);
        std::cout << "StringValuePair: " << svp.first() << ' ' << svp.second() << '\n';
    }
    return 0;
}
