#include <vector>
#include <iostream>

#include "../assertions/assertions.h"

using namespace std;

class HashTable {
private:
    const static int INTERNAL_ARRAY_SIZE = 5000;
    vector<int> **array;
public:

    HashTable() {
        array = new vector<int> *[INTERNAL_ARRAY_SIZE];
    }

    ~HashTable() {
        delete[] array;
    }

    void put(int value) {
        int bucket_pos;

        if (value < 0) {
            bucket_pos = (-value) % INTERNAL_ARRAY_SIZE;
        } else {
            bucket_pos = value % INTERNAL_ARRAY_SIZE;
        }

        vector<int> *v = array[bucket_pos];
        if (v == nullptr) {
            vector<int> *head = new vector<int>;
            head->push_back(value);
            array[bucket_pos] = head;
        } else {
            v->push_back(value);
        }
    };

    bool contains(int value) {
        int bucket_pos;

        if (value < 0) {
            bucket_pos = (-value) % INTERNAL_ARRAY_SIZE;
        } else {
            bucket_pos = value % INTERNAL_ARRAY_SIZE;
        }
        vector<int> *v = array[bucket_pos];
        if (v == nullptr) {
            return false;
        } else {
            for (int i = 0; i < v->size(); i++) {
                int val = v->at(i);
                if (val == value) {
                    return true;
                }
            }
            return false;
        }
    }
};

// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// 4 byte * 100 000 => 400 000 bytes => ~0.4 mb
//
// litcode fails with heap-buffer-overflow 40000-byte region (my limit i guess)
//
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        HashTable *table = new HashTable();

        for (int i = 0; i < nums.size(); i++) {
            if (table->contains(nums[i])) {
                return true;
            } else {
                table->put(nums[i]);
            }
        }
        return false;
    }
};


void assertTrue(bool actual) {
    if (!actual) {
        std::cout << "ERROR actual value is " << actual << std::endl;
    } else {
        std::cout << "OK" << std::endl;
    }
}

void assertFalse(bool actual) {
    if (actual) {
        std::cout << "ERROR actual value is " << actual << std::endl;
    } else {
        std::cout << "OK" << std::endl;
    }
}


int main() {
    Solution solution;

    vector<int> nums;
    bool res = solution.containsDuplicate(nums);
    assertFalse(res);

    nums.push_back(1);
    res = solution.containsDuplicate(nums);
    assertFalse(res);

    nums.push_back(1);
    res = solution.containsDuplicate(nums);
    assertTrue(res);

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    res = solution.containsDuplicate(nums);
    assertTrue(res);

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    res = solution.containsDuplicate(nums);
    assertFalse(res);


}