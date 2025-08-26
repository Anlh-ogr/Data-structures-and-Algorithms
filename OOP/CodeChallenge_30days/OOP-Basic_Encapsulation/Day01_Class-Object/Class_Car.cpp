#include "iostream"
#include "string"

class Car {
    public:
        std::string hangxe, bienso;
        int tocdo;

    void drive() {
        std::cout << hangxe << " is driving at " << tocdo << " km/h." << std::endl;
    }

    void canhbao() {
        if (tocdo > 100)
            std::cout << "Qua toc do" << std::endl;
        else if (tocdo > 70)
            std::cout << "Rat nhanh" << std::endl;
        else
            std::cout << "An toan" << std::endl;
    }
};

int main() {
    Car car1;
    car1.hangxe = "Audi";
    car1.tocdo = 140;
    car1.drive();
    car1.canhbao();

    Car car2;
    car2.hangxe = "Mercedes";
    car2.tocdo = 80;
    car2.drive();
    car2.canhbao();

    Car car3;
    car3.hangxe = "BMW";
    car3.tocdo = 60;
    car3.drive();
    car3.canhbao();

    return 0;
}
