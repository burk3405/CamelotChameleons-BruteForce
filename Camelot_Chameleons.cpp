#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


//13 Green
//15 Blue
//17 Red

class Chameleon {
public:
    int Color;
    // 111 = green
    // 222 = blue
    // 333 = red

    // Constructor
    Chameleon(int color) {
        Color = color;
    }

    // Function to change color when two different chameleons meet
    void changeColor(Chameleon& other) {
        if (this->Color == other.Color) {
            return; // No change if they are the same color
        }

        if ((this->Color == 111 && other.Color == 222) ||
            (this->Color == 222 && other.Color == 111)) {
            this->Color = 333; // Green + Blue ? Red
            other.Color = 333;
        }
        else if ((this->Color == 111 && other.Color == 333) ||
            (this->Color == 333 && other.Color == 111)) {
            this->Color = 222; // Green + Red ? Blue
            other.Color = 222;
        }
        else if ((this->Color == 222 && other.Color == 333) ||
            (this->Color == 333 && other.Color == 222)) {
            this->Color = 111; // Blue + Red ? Green
            other.Color = 111;
        }
    }
};

bool isUniformColor(const vector<Chameleon>& chameleons) {
    int firstColor = chameleons[0].Color;
    for (const auto& c : chameleons) {
        if (c.Color != firstColor) {
            return false; // If any chameleon has a different color, return false
        }
    }
    return true; // All chameleons have the same color
}

int main() {
    srand(time(0)); // Seed for randomization

    vector<Chameleon> chameleons;

    // Create 13 Green Chameleons
    for (int i = 0; i < 13; i++) {
        chameleons.push_back(Chameleon(111));
    }

    // Create 15 Blue Chameleons
    for (int i = 0; i < 15; i++) {
        chameleons.push_back(Chameleon(222));
    }

    // Create 17 Red Chameleons
    for (int i = 0; i < 17; i++) {
        chameleons.push_back(Chameleon(333));
    }

    int rounds = 0;

    // Continue until all chameleons are the same color
    while (!isUniformColor(chameleons)) {
        rounds++;

        // Shuffle chameleons randomly to simulate random meetings
        for (size_t i = 0; i < chameleons.size(); i++) {
            int j = rand() % chameleons.size();
            swap(chameleons[i], chameleons[j]);
        }

        // Pairwise meetings
        for (size_t i = 0; i < chameleons.size() - 1; i += 2) {
            chameleons[i].changeColor(chameleons[i + 1]);
        }

        // Count the number of each color
        int greenCount = 0, blueCount = 0, redCount = 0;
        for (const auto& c : chameleons) {
            if (c.Color == 111) greenCount++;
            else if (c.Color == 222) blueCount++;
            else if (c.Color == 333) redCount++;
        }

        // Output current status
        cout << "Round " << rounds << ":\n";
        cout << "Green Chameleons: " << greenCount << "\n";
        cout << "Blue Chameleons: " << blueCount << "\n";
        cout << "Red Chameleons: " << redCount << "\n\n";
    }

    cout << "All chameleons are now the same color after " << rounds << " rounds!\n";
    return 0;
}
