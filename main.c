//Ex1
// Напишете функция, която получава две числа и връща по – голямото от
// тях. Направете същото и за по - малкото. Демонстрирайте работата на
// функциите като четете множество числа до въвеждане на 0 и изкарате
// най – голямото въведено и най-малкото въведено число.
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b; // If true return a, if false - b
}

int main() {
    int num, maxnum, minnum;
    
    printf("Enter num: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Invalid.\n");
        return 0;
    }

    maxnum = minnum = num; // Enter the loop with equal values

    while (1) {
        printf("Enter numbber: ");
        scanf("%d", &num);
        if (num == 0) break;

        maxnum = max(maxnum, num);
        minnum = min(minnum, num);
    }

    printf("Max is: %d\n", maxnum);
    printf("Min is: %d\n", minnum);

    return 0;
}




// Ex6
// Напишете програма, която проверява дали точка {x, y} се намира вътре
// в правоъгълник {x1, y1} – {x2, y2}. Входните данни се четат от
// конзолата и се състоят от 6 реда, въведени от потребителя: десетичните
// числа x1, y1, x2, y2, x и y (като се гарантира, че x1 < x2 и y1 < y2). Една
// точка е вътрешна за даден правоъгълник, ако се намира някъде във
// вътрешността му или върху някоя от страните му. Отпечатайте “Inside”
// или “Outside”.
#include <stdio.h>

int main() {
    double x1, y1, x2, y2, x, y;
    
    printf("Enter x1:\n");
    scanf("%lf", &x1);
    printf("Enter y1:\n");
    scanf("%lf", &y1);
    printf("Enter x2:\n");
    scanf("%lf", &x2);
    printf("Enter y2:\n");
    scanf("%lf", &y2);
    printf("Enter x:\n");
    scanf("%lf", &x);
    printf("Enter y:\n");
    scanf("%lf", &y);
    
    if (x1 >= x2 || y1 >= y2) {
        printf("Invalid rectangle coordinates. \n");
        return 1;
    }
    
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        printf("Inside. \n");
    } else {
        printf("Outside. \n");
    }
    
    return 0;
}



//Ex3
// Да се напише програма, която чете 3 числа и отпечатва дали са еднакви
// (yes / no).
#include <stdio.h>

int main() {
    int a, b, c;
    
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}



//Ex8
// Басейн с обем V(кубични метра) има две тръби от които се пълни.
// Всяка тръба има определен дебит (литрите вода минаващи през една
//  тръба за един час). Работникът пуска тръбите едновременно и излиза
// за N часа. Напишете програма, която изкарва състоянието на басейна, в
// момента, когато работникът се върне. 
#include <stdio.h>
#include <stdlib.h>

int main()
{

  float V, D1, D2, N;

  printf("Enter V: \n");
  scanf("%f", &V); //обем
  printf("Enter D1: \n");
  scanf("%f", &D1); //дебит на 1 тръба
  printf("Enter D2: \n");
  scanf("%f", &D2); // /дебит на 2 тръба
  printf("Enter N: \n");
  scanf("%f", &N); //часове

  float all_water = (D1 + D2) * N;

  if (all_water <= V) {
    float waterper = (all_water * 100) / V;
    float remaining = V - all_water;
    float pipe1per = (D1 * N * 100) / all_water;
    float pipe2per = (D2 * N * 100) / all_water;

    printf("The pool is %.2f%% full. \n", waterper);
    printf("Remaining water to full: %.2f \n", remaining);
    printf("Pipe 1 work: %.2f%% \n ", pipe1per);
    printf("Pipe 2 work: %.2f%% \n ", pipe2per);
  } else { printf("Overflow with %.2f water\n", all_water - V); }

    return 0;
}



//Ex12
// Да се напише програма, която прочита от конзолата цяло число n,
// въведено от потребителя, и чертае пеперуда с ширина 2 * n - 1 колони и
// височина 2 * (n - 2) + 1 реда като в примерите по-долу. Лявата и
// дясната ѝ част са широки n - 1.
#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int width = 2 * n - 1;
    int height = 2 * (n - 2) + 1;

    // Upper part 
    for (int i = 0; i < n - 1; i++) {
        // Left 
        for (int j = 0; j < n - 1; j++) {
            if (j <= i) {
                if (i % 2 == 0)
                    printf("*");
                else
                    printf("-");
            }
        }
        
        printf("\\ /");
        
        // Right 
        for (int j = 0; j < n - 1; j++) {
            if (j <= i) {
                if (i % 2 == 0)
                    printf("*");
                else
                    printf("-");
            }
        }
        printf("\n");
    }
    

    for (int i = 0; i < n; i++) printf(" ");
    printf("@\n");
    
    // Lower part 
    for (int i = n - 2; i >= 0; i--) {
        // Left wing
        for (int j = 0; j < n - 1; j++) {
            if (j <= i) {
                if (i % 2 == 0)
                    printf("*");
                else
                    printf("-");
            }
        }


        printf("/ \\");
        
        // Right 
        for (int j = 0; j < n - 1; j++) {
            if (j <= i) {
                if (i % 2 == 0)
                    printf("*");
                else
                    printf("-");
            }
        }
        printf("\n");
    }
    
    return 0;
}




