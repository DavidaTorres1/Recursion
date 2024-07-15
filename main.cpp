#include <iostream>
#include <string>

using namespace std;

//reverse a string
string reverseStr(const string& str){
    
    //if empty, return as is
    if (str.length() <= 1)
        return str;
        
    //self call. reverse w/ substring
    return reverseStr(str.substr(1)) + str[0];
}


//palindrome
int isPalindrome(const string& str) {
    //one from the beginning, one from the end
    int left = 0;
    int right = str.length() - 1;

    //checking outer char towards the center
    while (left < right) {
        // Ignore non-alphanumeric characters by moving the left pointer
        while (!isalnum(str[left]) && left < right) {
            left++;
        }
        // Ignore non-alphanumeric characters by moving the right pointer
        while (!isalnum(str[right]) && left < right) {
            right--;
        }
        //convert chars to lower
        char leftChar = tolower(str[left]);
        char rightChar = tolower(str[right]);
        //if char dont match. no palindrome
        if (leftChar != rightChar) {
            cout << str << " is not a palindrome." << endl;
            return 0;
        }
        //move to center
        left++;
        right--;
    }
    //if loop fin w/o finding mismatche string is a palindrome
    cout << str << " is a palindrome." << endl;
    return 0;
}

//multiplication func
int multiply(int x, int y) {
    // if x or y is 0, return 0
    if (x == 0 || y == 0)
        return 0;
    //if y is 1, return x
    if (y == 1)
        return x;
    //add x to the product of (x, y-1)
    return x + multiply(x, y - 1);
}

int main() {
    
    //test reverse(it can only do one word I don't rlly know why)
    string originalStr;
    cout << "Give me a word: ";
    cin >> originalStr;

    string reversedStr = reverseStr(originalStr);
    cout << "Reversed word: " << reversedStr << endl;
    
    //test palindrome
    string palindromeStr;
    cout << "Give me a word: ";
    cin >> palindromeStr;
    isPalindrome(palindromeStr);
    
    //testing multiplicating thingy
    int num1;
    int num2;
    cout << "Give me the first number: " ;
    cin >> num1;
    cout << "Give me the second number: " ;
    cin >> num2;
    cout << "Product of " << num1 << " and " << num2 << " is: " << multiply(num1, num2) << endl;


    return 0;
}