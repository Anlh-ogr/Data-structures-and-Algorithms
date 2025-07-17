#include "iostream"

class UpperOrLower {
    private:
        char c; // c: character
    public:
        // Constructor
        UpperOrLower( char character ) : c(character) {}

        // Enter character
        void EnterCharacter() {
            std::cout << "Enter a character: "; std::cin >> c;
        }

        // Method
        void UpOrLow() {
            // c >= 65 && c <= 90 (Ascii)
            if (c >= 'a' && c <= 'z')
                std::cout << "The character " << c << " is Lowercase." << std::endl;
            // c >= 97 && c <= 122 (Ascii)
            else if (c >= 'A' && c <= 'Z')
                std::cout << "The character " << c << " is Uppercase" << std::endl;
            else
                std::cout << "The character " << c << " is neither Uppercase nor Lowercase." << std::endl;
        }
};

int main() {
    UpperOrLower uol(' '); // Initialize with a space character
    uol.EnterCharacter();
    uol.UpOrLow();
    
    return 0;
}