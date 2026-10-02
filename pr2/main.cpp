
// 4. Згенерувати 1000 випадкових чисел (діапазон 0-100), відфільтрувати усі
// елементи, що більші за середнє значення масиву.

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

const int RANGE_LENGTH = 1000;
const int START_RANGE = 0;
const int END_RANGE = 100;

const int NUM_OF_ALGHORITMS_TO_MEASURE_TIME_AND_MEMORY = 1e6;

void show_arr(std::string message, std::vector<int> arr) {
    std::cout << "\n" << message << "\n\n";
    for (size_t i = 0; i < arr.size(); i++) {
	std::cout << arr[i] << ' ';
    }
    std::cout << "\n\n";
}

void variant4() {
    std::srand(time(0));
   
    std::vector<int> arr;
    for (size_t i = 0; i < RANGE_LENGTH; i++) {
	int random_number = int(std::rand() % (END_RANGE - START_RANGE + 1)) - START_RANGE;
	arr.push_back(random_number);
    }

    int average = 0;
    for (size_t i = 0; i < RANGE_LENGTH; i++) {
	average = average + arr[i];
    }
    average = average / int(arr.size());

    std::vector<int> filtered;
    for (size_t i = 0; i < RANGE_LENGTH; i++) {
	if (arr[i] > average) {
	    filtered.push_back(arr[i]);
	}
    }

    // show_arr("array before filtering: ", arr);
    // show_arr("array after filtering: ", filtered);
}

int main() {
    auto start = std::chrono::steady_clock::now();

    for (size_t i = 0; i < NUM_OF_ALGHORITMS_TO_MEASURE_TIME_AND_MEMORY; i++) {
	variant4();
    }

    auto end = std::chrono::steady_clock::now();
    double time_s = std::chrono::duration<double>(end - start).count();

    std::cout << "\nTime: " << time_s << " s\n";
    
    return 0;
}


