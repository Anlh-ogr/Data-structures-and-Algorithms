// sử dụng kiểu dữ liệu cấu trúc trong C, hãy xây dựng CTDL để
// lưu trữ trong bộ nhớ RAM trạng thái của các cột đèn giao thông
// (có 3 đèn: đỏ, vàng, xanh). Với cấu trúc dữ liệu đã được xây
// dựng, trình bày thuật toán để chuyển trạng thái của các cột
// đèn và mô tả trạng thái của các cột đèn sau mỗi lần chuyển.

#include <iostream>

// CTDL lưu trữ trạng thái của các cột đèn giao thông
typedef struct {
    int red_light;      // (1: on, 0: off)
    int yellow_light;   // (1: on, 0: off)
    int green_light;    // (1: on, 0: off)
} TrafficLight;

// Khởi tạo trạng thái ban đầu của các cột đèn giao thông
void initTrafficLight(TrafficLight *light_traffic) {
    light_traffic -> red_light = 1;    // đèn đỏ bật
    light_traffic -> yellow_light = 0; // đèn vàng tắt
    light_traffic -> green_light = 0;  // đèn xanh tắt
}

// Chuyển trạng thái của các cột đèn giao thông
void changeTrafficLight(TrafficLight *traffic_light) {
    // Nếu đèn đỏ bật thì chuyển sang đèn xanh
    if(traffic_light -> red_light == 1) {
        traffic_light -> red_light = 0;
        traffic_light -> green_light = 1;
    }
    
    // Nếu đèn xanh bật thì chuyển sang đèn vàng
    else if(traffic_light -> green_light == 1) {
        traffic_light -> green_light = 0;
        traffic_light -> yellow_light = 1;
    }

    // Nếu đèn vàng bật thì chuyển sang đèn đỏ
    else if(traffic_light -> yellow_light == 1) {
        traffic_light -> yellow_light = 0;
        traffic_light -> red_light = 1;
    }
}

// In ra trạng thái của các cột đèn giao thông
void outputTrafficLight(TrafficLight *traffic_light) {
    if(traffic_light -> red_light == 1) {
        std::cout << "=========================" << std::endl;
        std::cout << "Red light is on" << std::endl;
        std::cout << "Green light is off" << std::endl;
        std::cout << "Yellow light is off" << std::endl;
        std::cout << std::endl;
    }
    if(traffic_light -> yellow_light == 1) {
        std::cout << "=========================" << std::endl;
        std::cout << "Red light is off" << std::endl;
        std::cout << "Green light is off" << std::endl;
        std::cout << "Yellow light is on" << std::endl;
        std::cout << std::endl;
    }
    if(traffic_light -> green_light == 1) {
        std::cout << "=========================" << std::endl;
        std::cout << "Red light is off" << std::endl;
        std::cout << "Green light is on" << std::endl;
        std::cout << "Yellow light is off" << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    TrafficLight traffic_lights;

    initTrafficLight(&traffic_lights);

    outputTrafficLight(&traffic_lights);

    for(int i = 0; i < 6; i++) {
        changeTrafficLight(&traffic_lights);
        outputTrafficLight(&traffic_lights);
    }

    return 0;
}
