#pragma once

class Entity {
public:
    virtual ~Entity() = default;

    // Operator de afișare (virtual pentru a putea fi suprascris)
    virtual void Print(std::ostream& os) const = 0;

    // Operator de citire (virtual pentru a putea fi suprascris)
    virtual void Read(std::istream& is) = 0;
};

// Operator de afișare pentru clase derivate
inline std::ostream& operator<<(std::ostream& os, const Entity& entity) {
    entity.Print(os);
    return os;
}

// Operator de citire pentru clase derivate
inline std::istream& operator>>(std::istream& is, Entity& entity) {
    entity.Read(is);
    return is;
}
