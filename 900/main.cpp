#include <iostream>
#include <stdexcept>

#define EAX 0
#define EBX 1
#define ECX 2
#define EDX 3

/**
 * 32 bit stack
 */
class Stack {
private:
    int *st;
    unsigned int size_st;
    unsigned int head;
public:

    explicit Stack(unsigned int size) {
        if (size <= 0) {
            throw std::runtime_error("Stack size zero or less!");
        }
        st = new int[size];
        size_st = size;
        head = size - 1;
    }

    void Push(int val) {
        head--;
        st[head] = val;
    }

    int Pop() {
        int ret = st[head];
        head++;
        return ret;
    }

    void Print() {
        printf("==============\n");
        for (int i = 0; i < size_st; i++) {
            if (i == head) {
                printf("\x1B[93m[%02d] %d\033[0m\n", i * 4, st[i]);
            } else {
                printf("[%02d] %d\n", i * 4, st[i]);
            }
        }
    }

};

class Processor {
private:
    int *regs;
    int regs_size;

private:
    void CheckReg(int reg) {
        if (reg < 0 || reg >= regs_size) {
            throw std::runtime_error("Unknown register");
        }
    }
public:
    Processor() {
        regs_size = 4;
        regs = new int[regs_size];
    }

    void MovVal(int reg, int val) {
        CheckReg(reg);
        regs[reg] = val;
    }

    void MovReg(int left, int right) {
        CheckReg(left);
        CheckReg(right);
        regs[left] = regs[right];
    }

    void SubVal(int reg, int val) {
        CheckReg(reg);
        regs[reg] = regs[reg] - val;
    }

    void SubReg(int left, int right) {
        CheckReg(left);
        CheckReg(right);
        regs[left] = regs[left] - regs[right];
    }

    void AddVal(int reg, int val) {
        CheckReg(reg);
        regs[reg] = regs[reg] + val;
    }

    void AddReg(int left, int right) {
        CheckReg(left);
        CheckReg(right);
        regs[left] = regs[left] + regs[right];
    }

    void DivReg(int reg) {
        CheckReg(reg);
        regs[EAX] = regs[EAX] / regs[reg];
        regs[EDX] = regs[EAX] % regs[reg];
    }

    void DivVal(int val) {
        regs[EAX] = regs[EAX] / val;
        regs[EDX] = regs[EAX] % val;
    }

    void MulReg(int reg) {
        CheckReg(reg);
        regs[EAX] = regs[EAX] * regs[reg];
        // todo: save higher order bytes of multiplication result
//        regs[EDX] = regs[EAX] % regs[reg];
    }

    void MulVal(int val) {
        regs[EAX] = regs[EAX] * val;
//        regs[EDX] = regs[EAX] % val;
    }

    void Print() {
        printf("[eax]=%i ", regs[EAX]);
        printf("[ebx]=%i ", regs[EBX]);
        printf("[ecx]=%i ", regs[ECX]);
        printf("[edx]=%i ", regs[EDX]);
    }

};

int main() {
    Processor p;

    p.MovVal(EAX, 10);
    p.MovVal(EBX, 3);
    p.DivReg(EBX);

    p.Print();


//    Stack s(4);
//
//    s.Push(1);
//    s.Push(2);
//    s.Push(3);
//
//    s.Print();
//
//    int res = s.Pop();
//
//    s.Print();
//    if (res == 3) {
//        printf("good");
//    }

    return 0;
}