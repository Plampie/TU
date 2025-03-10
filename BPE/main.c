//#include <stdio.h>
//#include <stdlib.h>
//
//void NumbersAsText(int num)
//{
//    switch(num)
//    {
//        case 1: printf("one\n"); break;
//        case 2: printf("two\n"); break;
//        case 3: printf("three\n"); break;
//        case 4: printf("four\n"); break;
//        case 5: printf("five\n"); break;
//        case 6: printf("six\n"); break;
//        case 7: printf("seven\n"); break;
//        case 8: printf("eight\n"); break;
//        case 9: printf("nine\n"); break;
//        case 10: printf("ten\n"); break;
//        default: printf("Invalid number\n");
//    }
//}
//

void printFrame(char symbol)
{
    int width = 15, height = 10;
   for(int i = 0; i < height; i++) {
       for(int j = 0; j < width; j++) {
         if(i == 0 || j == 0 || i == height - 1 || j == width - 1) {
              printf("%c", symbol);
            } else {
             printf(" ");
                } 
        }
        printf("\n");
    }
}
//
//
//void NumberSum()
//{
//    int a, b;
//    printf("Enter number 1: ");
//    scanf("%d", &a);
//    printf("Enter number 2: ");
//    scanf("%d", &b);
//
//    int sum = a + b;
//    int difference = a - b;
//    int multiplication = a * b;
//    float division = (float) a / b;
//
//    printf("Sum is %d\n", sum);
//    printf("Difference is %d\n", difference);
//    printf("Multiplication is %d\n", multiplication);
//    printf("Division is %.2f\n", division);
//}
//
//void EvenNumber()
//{
//    int number;
//    printf("Enter number: ");
//    scanf("%d", &number);
//    if (number % 2 == 0){
//        printf("Even \n");
//    } else {
//        printf("Odd \n");
//    }
//}
//
//void SumNumFour()
//{
//    int numb;
//    printf("Enter number (4 digits): ");
//    scanf("%d", &numb);
//
//    int sum = 0;
//    sum += numb % 10;
//    numb /= 10;
//    sum += numb % 10;
//    numb /= 10;
//    sum += numb % 10;
//    numb /= 10;
//    sum += numb % 10;
//}
//
//int main()
//{
//    for(int i = 1; i <= 10; i++) {
//        NumbersAsText(i);
//    }
//
//    char s;
//    printf("Enter symbol for pattern: ");
//    scanf(" %c", &s);
//    int n = 55;
//    for(int i = 1; i <= n; i++) {
//        for(int j = 1; j <= i; j++) {
//            if(i == n || i == j || j == 1) {
//                printf("%c", s);
//            } else {
//                printf(" ");
//            }
//        }
//        printf("\n");
//    }
//
//
//    char symbol;
//    printf("Enter symbol for frame: ");
//    scanf(" %c", &symbol);
//    printf("Output:\n");
//    printFrame(symbol);
//
//    NumberSum();
//
//    EvenNumber();
//
//    return 0;
//}
