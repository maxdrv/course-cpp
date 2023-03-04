#include <iostream>
#include <string>
#include <cstdlib>


int main() {
//    using namespace std::string_literals;

    "Max";  // 4 characters Max + \0
    char *name = "M\0ax";  // now we just broke behaviour
    std::cout << name << std::endl;
    std::cout << strlen(name) << std::endl;  // only counts until null ternimator

    const char *name2 = "M";
    //
//    name2[1] = 's';  // compiler time error: trying to modify read only data


    const wchar_t *name3 = L"Max3";  // string liternal made of wide characters
//    const char16_t *name4 = u"Max4";  // c++ 11 types
//    const char32_t *name5 = U"Max5";

    const char *name4 = R"(Line1
    line2
line3
)";
    std::cout << name4 << std::endl;

}