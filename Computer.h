/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include <string>
#include <iostream>
using namespace std;

class CUDA{
    public:
    CUDA();
    CUDA(int);                            // The constructor of cuda that takes an integer to initialize the numcores.
    ~CUDA();

    const string render() const;                // The two constant functions of cuda both do not take any value but return the
    const string trainModel() const;            // desired sentence as a string back to the GPU.

    private:
    const int numCores;
};

class ALU{
    public:
    ALU();
    ALU(int);                           // The constructor of alu that takes an integer to initialize the numpercores.
    ~ALU();

    const int add(const int, const int) const;            // The three constant functions of alu both take two integers and return the result
    const int subtract(const int, const int) const;       // of the corresponding arithmetic operations.
    const int multiply(const int, const int) const;

    private:
    const int numPerCores;
};

class GPU{
    public:
    GPU();
    GPU(int);                           // Constructor of CPU that takes an integer to initialize the numcores of the cuda.
    ~GPU();

    const string execute(const string) const;       // execute function, a constant function that takes a string.

    private:
    const CUDA cuda;                    // A constant cuda object.
};

class CPU{
    public:
    CPU();
    CPU(int);                           // Constructor of CPU that takes an integer to initialize the numpercores of the alu.
    ~CPU();

    const int execute(const string) const;          // execute function, a constant function that takes a string and returns an integer.
    private:
    mutable ALU alu;                    // A constant alu object.
};

/*
    The computer class with the necessary functions.
*/
class Computer{
    public:
    Computer();
    ~Computer();
    
    void operator+(const CPU&);         // Operator overloading, a constant function that takes a reference to a constant CPU object.
    void operator+(const GPU&);         // Operator overloading, a constant function that takes a reference to a constant GPU object.
    void execute(string) const;         // execute function, doesn't return anything but prints something on the screen.        

    private:
    const CPU* attachedCPU;             // A pointer to a constant CPU object.
    const GPU* attachedGPU;             // A pointer to a constant GPU object.
};







