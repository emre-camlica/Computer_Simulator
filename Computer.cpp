/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include <iostream>
#include "Computer.h"
#include <string>
using namespace std;

CUDA :: CUDA(const int num) : numCores (num) // The constant numCores value is initialized in the member initializer list.
{
   cout << "CUDA is ready\n";
}

CUDA :: CUDA() : numCores (0)          // The default constructor of cuda. 
{

}

CUDA :: ~CUDA()                        // The default destructor of cuda.
{

} 

const string CUDA :: render() const
{
   return "Video is rendered\n";
}

const string CUDA :: trainModel() const
{
   return "AI Model is trained\n";
}

ALU :: ALU(const int num) : numPerCores (num)   // The constant numPerCores value is initialized in the member initializer list.
{                                         
   cout << "ALU is ready\n";
}

ALU :: ALU(): numPerCores (0)        // The default constructor of alu.
{

}

ALU :: ~ALU()                        // The default destructor of alu.
{

}

const int ALU :: add(const int p1, const int p2) const // A constant function that adds and returns two values
{
   return p1+p2;
}

const int ALU :: subtract(const int p1, const int p2) const // A constant function that subtracts and returns two values
{
   return p1-p2;
}

const int ALU :: multiply(const int p1, const int p2) const // A constant function that multiplies and returns two values
{
   return p1*p2;
}

GPU :: GPU(const int num) : cuda (num)         // In the member initializer list, the constructor of cuda is called with its initial value.  
{
   cout << "GPU is ready\n";
}

GPU :: GPU() : cuda (0)                  // The default constructor of GPU.
{

}

GPU :: ~GPU()                            // The default destructor of GPU.
{

}

/*
   The execute method of GPU which takes an operation name as input, sends this to the cuda and returns the string value it
   obtained using the methods of cuda to the computer.
*/
const string GPU :: execute(const string operation) const 
{
   if(operation == "render")
   return this->cuda.render();

   else if(operation == "trainModel")
   return this->cuda.trainModel();

   else return "-1";
}

CPU :: CPU(const int num) : alu (num)     // In the member initializer list, the constructor of alu is called with the initial value.
{
   cout << "CPU is ready\n";
}

CPU :: CPU() : alu (0)              // The default constructor of CPU.
{

}

CPU :: ~CPU()                       // The default destructor of CPU.
{

}

/*
   The execute method of CPU which takes an operation name as input, takes two input integers, and depending on the type of 
   operation, sends it to the methods of alu, and returns the result of the corresponding arithmetic operation to the computer.
*/
const int CPU :: execute(const string operation) const
{
   int p1, p2;
   cout << "Enter two integers\n";
   cin >> p1 >> p2;

   if(operation == "add")
   return this->alu.add(p1, p2);

   else if(operation == "subtract")
   return this->alu.subtract(p1, p2);

   else if(operation == "multiply")
   return this->alu.multiply(p1, p2);

   else return -1;
}

/*
   The default constructor of the computer where a member initializer list is used to initialize the CPU and GPU pointers
   that will be attached later.
*/
Computer :: Computer() : attachedCPU {NULL}, attachedGPU {NULL} 
{
   cout << "Computer is ready\n";
}

/*
   The default destructor of the computer that first checks if the attached CPU and GPU pointers are deleted, if not deletes them.
*/
Computer :: ~Computer() 
{  
   if(attachedCPU!=NULL){
   attachedCPU = NULL;
   }

   if(attachedGPU!=NULL){
   attachedGPU = NULL;
   }
}

/*
   The "+" operator overloaded to be used to "attach" CPU and GPU objects to the computer. Since only one CPU or GPU is allowed
   to be attached to the computer, the functions first check if there is already an attached CPU or GPU, if so, generates the
   corresponding negative messages on the screen and do not allow the new objects to be attached. If there is currently no
   attached objects, the functions accept the given references of CPU or GPU and attach them to computer.
*/

void Computer :: operator+(const CPU& CPU) 
{
   if(attachedCPU != NULL){
      cout << "There is already a CPU\n";
      return;
   }
   attachedCPU = &CPU;
   cout << "CPU is attached\n";
}

void Computer :: operator+(const GPU& GPU) 
{
   if(attachedGPU != NULL){
      cout << "There is already a GPU\n";
      return;
      }
   attachedGPU = &GPU;
   cout << "GPU is attached\n";
}

/*
   The execute method of computer that takes an operation name as string, sends the operation to either the CPU or the GPU 
   depending on the operation name. Then, it prints either the integer value returned by the CPU operations or the String/sentence
   returned by the GPU on the screen.
*/
void Computer :: execute(const string operation) const
{
   if(operation == "add" || operation == "subtract" || operation == "multiply")
   cout << this->attachedCPU->execute(operation) << "\n";
   else if(operation == "render" || operation == "trainModel")
   cout << this->attachedGPU->execute(operation) << "\n";
}







