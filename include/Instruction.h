// Instruction.h
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <memory>
#include <vector>

// Example of an Instruction class
class Instruction {
public:
    virtual ~Instruction() = default;
    // Virtual methods for handling instruction behavior
};

// Derived classes for specific instructions can be added here

#endif // INSTRUCTION_H
