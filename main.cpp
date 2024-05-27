#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class Container {
private:
    std::vector<T> data;

public:
    Container(size_t size) : data(size) {}

    void fill() {
        std::cout << "Enter " << data.size() << " elements:" << std::endl;
        for (size_t i = 0; i < data.size(); ++i) {
            std::cin >> data[i];
        }
    }

    T findMinAbs() const {
        T minAbs = std::abs(data[0]);
        T minElement = data[0];
        for (const T& element : data) {
            if (std::abs(element) < minAbs) {
                minAbs = std::abs(element);
                minElement = element;
            }
        }
        return minElement;
    }

    T sumAbsAfterFirstNegative() const {
        bool foundNegative = false;
        T sum = 0;
        for (const T& element : data) {
            if (foundNegative) {
                sum += std::abs(element);
            } else if (element < 0) {
                foundNegative = true;
            }
        }
        return sum;
    }

    void compress(T a, T b, T fillValue) {
        size_t newSize = 0;
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] < a || data[i] > b) {
                data[newSize++] = data[i];
            }
        }
        for (size_t i = newSize; i < data.size(); ++i) {
            data[i] = fillValue;
        }
    }

    void print() const {
        for (const T& element : data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    size_t size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    Container<int> container(size);
    container.fill();

    int minAbsElement = container.findMinAbs();
    std::cout << "Minimum element by absolute value: " << minAbsElement << std::endl;

    int sumAbsAfterNeg = container.sumAbsAfterFirstNegative();
    std::cout << "Sum of absolute values after the first negative element: " << sumAbsAfterNeg << std::endl;

    int a, b, fillValue;
    std::cout << "Enter the interval [a, b]: ";
    std::cin >> a >> b;
    std::cout << "Enter the value to fill the empty spaces: ";
    std::cin >> fillValue;

    container.compress(a, b, fillValue);
    std::cout << "Array after compression: ";
    container.print();

    return 0;
}
