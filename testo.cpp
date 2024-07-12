#include <iostream>

// String library functions(syntax)
#include <cstring>

using namespace std;

// Pointer to a function.
void ptr2Function() {
    cout << "1.) Pointer to Function" << endl;
}

// Pointer to structure.
struct ptr2Structure {
    int x, y;
};

// Static variable and difference between (const char *p,char const *p,const char* const p).
void staticVarTesto() {
    static int count = 0;  
    count++;
    cout << "3-" << count << ".) Static Variable -> Count: " << count << endl;
}

// Pass by value & reference.
void passByValue(int a) {
    a = 10;
}

void passByReference(int &a) {
    a = 10;
}

// Write a program to compare two strings without using the strcmp() function.
bool compareTwoStrings(const char* strA, const char* strB) {
    while (*strA && (*strA == *strB)) {
        strA++;
        strB++;
    }
    return *(unsigned char*)strA - *(unsigned char*)strB == 0;
}

// Write a program to concatenate two strings.
void concatenateStrings(char* dest, const char* src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// Write programs for String Reversal & Palindrome check.
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        swap(str[i], str[len - i - 1]);
    }
}

bool isPalindrome(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Write a program to find the Factorial of a number.
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Write a program to generate the Fibinocci Series.
void fibonacci(int n) {
    int a = 0, b = 1, next;
    for (int i = 0; i < n; ++i) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

// Searching and sorting algorithms with complexities - Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Searching and sorting algorithms with complexities - Binary Search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) return mid;

        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}





int main() {

    // Pointer to a function.
    void (*funcPtr)() = ptr2Function;  
    funcPtr();  

    // Pointer to structure.
    ptr2Structure pt = {10, 20};
    ptr2Structure *ptr = &pt; 

    cout << "2.) Pointer to Structure -> x: " << ptr->x << ", y: " << ptr->y << endl;

    const char *p1 = "Hello";     
    char const *p2 = "World";     
    const char* const p3 = "C++";    

    staticVarTesto();
    staticVarTesto();

    // Pass by value & reference.
    int x = 5;
    passByValue(x);
    cout << "4-1.) Pass by Value: " << x << endl;  

    passByReference(x);
    cout << "4-2.) Pass by Reference: " << x << endl; 

    // String library functions(syntax)
    char str1[] = "Hello";
    char str2[] = "World";

    cout << "5-1.) Length of str1: " << strlen(str1) << endl;
    char str3[10];
    strcpy(str3, str1);
    cout << "5-2.) Copied str1 to str3: " << str3 << endl;
    strcat(str1, str2);
    cout << "5-3.) Concatenated str1 and str2: " << str1 << endl;
    cout << "5-4.) Comparison result: " << strcmp(str1, str2) << endl;

    // Write a program to compare two strings without using the strcmp() function.
    char strA[] = "Hello";
    char strB[] = "Hello";
    char strC[] = "World";

    cout << "6-1.) strA == strB: " << (compareTwoStrings(strA, strB) ? "true" : "false") << endl; 
    cout << "6-2.) strA == strC: " << (compareTwoStrings(strA, strC) ? "true" : "false") << endl; 

    // Write a program to concatenate two strings.
    char straa[20] = "Hello ";
    char strbb[] = "World";

    concatenateStrings(straa, strbb);
    cout << "7.) Concatenated String: " << straa << endl;

    // Write a program to interchange 2 variables without using the third one.
    int varA = 5, varB = 10;
    cout << "8-1.) Variable A: " << varA << ", Variable B: " << varB << endl; 

        varA = varA + varB;
        varB = varA - varB;
        varA = varA - varB;

    cout << "8-2.) Variable A: " << varA << ", Variable B: " << varB << endl;

    // Write programs for String Reversal & Palindrome check .
    char strR[] = "testo";
    char strP[] = "madam";

    reverseString(str1);
    cout << "9-1.) Reversed String: " << strR << endl; 

    cout << "9-2.) Is strP Palindrome: " << (isPalindrome(strP) ? "true" : "false") << endl; 

    // Write a program to find the Factorial of a number.
    int num = 5;
    cout << "10.) Factorial of " << num << " is " << factorial(num) << endl; 

    // Write a program to generate the Fibinocci Series.
    int noOfTerms = 10;
    cout << "11.) First " << noOfTerms << " terms of Fibonacci series: ";
    fibonacci(noOfTerms);

    // Searching and sorting algorithms with complexities - Linear Search
    int arrLin[] = {2, 4, 0, 1, 9};
    int sizeLin = sizeof(arrLin)/sizeof(arrLin[0]);
    int keyLin = 1;

    int resultLin = linearSearch(arrLin, sizeLin, keyLin);
    cout << "12-1.) Element found at index: " << resultLin << endl; 
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    // Searching and sorting algorithms with complexities - Binary Search
    int arrBin[] = {1, 2, 3, 4, 5};
    int sizeBin = sizeof(arrBin)/sizeof(arrBin[0]);
    int keyBin = 3;

    int resultBin = binarySearch(arrBin, 0, sizeBin - 1, keyBin);
    cout << "12-2.) Element found at index: " << resultBin << endl; 
    // Time Complexity: O(log n)
    // Space Complexity: O(1)


    return 0;

}
