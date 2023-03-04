
// enum essentially integers
// but integers can't give you type safety
// you can pass any other integer outside defined by you

int A = 0;
int B = 1;
int C = 2;

enum Example {
    X, Y, Z
};

// you can start with other int and then others will be +1
enum Example2 {
    XX = 5, YY, ZZ
};

// you can change type of this integers
enum Example3 : unsigned char {
    CH, CH2
};

//enum Example4: float {};  // you can not use float, only integers allowed

void test(Example val) {

}

int main() {

    int value = B;
    value = 101;
    if (value == B) {
        // do something
    }

    Example ex_value = X;
//    Example ex_value = B;  // now you can not assine other values

    // remember, they are still integers and you can check this values with integers
    if (X == 0) {

    }

    test(X);
//    test(1); // but you can not pass int
}