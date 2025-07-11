#include <string>

int main() {
    int a = 0; // C-like initialization
    int b {0}; // Uniform initialization. Does not allow narrowing conversions.
    int c(0); // Constructor initialization
    char greeting_a[6] = {'H','e','l','l','o','\0'};
    char greeting_b[] = "Hello";
    char* greeting_c = "Hello";
    std::string greeting_d = "Hello";


    printf("%s\n", greeting_a);
    printf("%s\n", greeting_b);


    return 0;
}