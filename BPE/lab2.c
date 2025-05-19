#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

void EvenNumber(int number)
{
    if (number % 2 == 0){
        printf("Even \n");
    } else {
        printf("Odd \n");
    }
}

void Positive(int number)
{
    if (number > 0) {
        printf("Positive number \n");
    }
    else if (number < 0) {
        printf("Negative number \n");
    }
    else printf("Zero \n");
}

void Divisibility(int number)
{
    if (number % 3 == 0 && number % 5 == 0) {
        printf("Number is divisible by 3 and 5. \n");
    }
    else printf("Number is NOT divisible by 3 and 5. \n");
}

void checktrisizes(int a, int b, int c)
{
    printf("Sides: %d, %d, %d \n", a, b, c);

    if (a + b > c && c + b > a && c + a > b) {
        printf(" The numbers can form a triangle \n");
        if (a==b && b==c) {
            printf("Equilateral triangle \n");
        }
        else if ( a==b || b == c || a == c) {
            printf("Isosceles triange \n");
        }
        else printf("Scalene triangle \n");
    }
    else printf(" The numbers CANNOT form a triangle \n");
}

void displaymonthseason(int month)
{
    const char* months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"}
    const char* seasons[] = {"", "Winter", "Winter", "Spring", "Spring", "Spring", "Summer", "Summer", "Summer", "Autumn", "Autumn", "Autumn", "Winter"}

    if (month < 1 || month > 12) {
        printf("Invalid value");
    }
    else printf("Month: %s, Season: %s \n", months[month], seasons[month]);
}

bool isPrime(int num) {
    if (num <= 1) return false; // Check for numbers less than 2
    if (num == 2) return true;  // Check the number 2
    if (num % 2 == 0) return false; // Eliminate even numbers
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isPalindrome(int n)
{
    int reverse = 0;
    int temp = abs(n);
    while (temp != 0) {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse == abs(n));
}

int SumBetween(int a, int b)
{
    int sum = 0;
    for (int i = a + 1; i < b; i++) {
        sum += 1;
    }
    return sum;
}

int maxdigit(int num)
{
    int maxd = 0;
    while(num > 0) {
        int digit = num % 10;
        if (digit > maxd) maxd = digit;
        num /= 10;
    }
    return maxd;
}

int main ()
{
    // Exercise One
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    EvenNumber(number);
    Positive(number);
    Divisibility(number);

    // Exercise Two
    int a, b, c;
    printf("Triangle check: \n");
    printf("Enter 3 numbers separated by spacesS: \n");
    scanf("%d %d %d", &a, &b, &c);
    checktrisizes(a, b, c);

    // Exercise Three
    int month;
    printf("Enter a month number: \n");
    scanf("%d", &month);
    displaymonthseason(month);

    // Exercise Four
    int num;
    printf("Enter a number: \n");
    scanf("%d", &num);
    if (isPrime(num)) {
        printf("Number is prime. \n");
    } else printf("Number is NOT prime. \n");

    // Exercise Five
    if (isPalindrome(num)) {
        printf("Number is palindrome. \n");
    } else printf("Number is NOT palindrome. \n");

    // Exercise Six
    int num1, num2;
    printf("Enter 2 numbers separated by spacesS: \n");
    scanf("%d %d %d", &num1, &num2);
    SumBetween(num1, num2);

    // Exercise Seven
    int numb;
    printf("Enter a number: \n");
    scanf("%d", &num);
    maxdigit(numb);

    return 0;
}

