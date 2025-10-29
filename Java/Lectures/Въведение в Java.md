# Въведение в Java – Примитивни типове и променливи, оператори, вход/изход, цикли и масиви

## Примитивни типове и променливи

Основна градивна единица на езиците за програмиране са променливите. Известни от математиката, а и от C, променливите служат за временно съхранение на данни в дадена програма.  
В частност – в Java променливите се делят на два типа – **примитивни** и **референтни**. Различават се главно по това къде стоят в паметта и по сложността си.

Примитивните типове данни в езика Java са:

- `byte`, `short`, `int`, `long` – целочислени типове  
- `float`, `double` – реални типове с плаваща запетая  
- `boolean` – булев (логически) тип  
- `char` – символен тип  
- `Object` – обектен тип  
- `String` – символни низове  

Последните два типа са **референтни**.

---

### 🧠 Пример:

```java
byte x = 68;
int i = 123456;
char ch = 'W';
boolean result = false;
Object obj = 172;
String str = "Java is easy to learn";
```

При референтния тип в стека се съхранява **адрес**, който сочи към обекта в heap-а. Този адрес се нарича **референция** (аналогично на указателите в C).

---

## Стандартни обхвати на примитивните типове в Java

| Тип | Минимална стойност | Максимална стойност | Размер |
|-----|--------------------|--------------------|--------|
| byte | -128 | 127 | 8 бита |
| short | -32,768 | 32,767 | 16 бита |
| int | -2,147,483,648 | 2,147,483,647 | 32 бита |
| long | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | 64 бита |
| float | ~1.4e-45 | ~3.4e38 | 32 бита |
| double | ~4.9e-324 | ~1.8e308 | 64 бита |
| boolean | true / false | — | 1 бит |
| char | '\u0000' | '\uffff' | 16 бита |

---

### Важни моменти

- Използвайте тип, заемащ по-малко памет, когато е възможно.  
- Внимавайте при числа с плаваща запетая (възможна загуба на точност).  
- Символният тип (`char`) представлява 16-битов Unicode символ.

---

## Оператори и изрази

### Унарни оператори
- `++` – инкрементиране с 1  
- `--` – декрементиране с 1  
- `+` / `-` – положително/отрицателно число  
- `~` – побитово инвертиране  
- `!` – логическо отрицание  
- `(тип)` – преобразуване на тип  

### Аритметични оператори
`+`, `-`, `*`, `/`, `%`

### Оператори за сравнение
`<`, `<=`, `>`, `>=`, `==`, `!=`

### Логически оператори
`&&` – логическо "и"  
`||` – логическо "или"

### Побитови оператори
`&`, `|`, `^`, `<<`, `>>`, `>>>`

---

## Цикли в Java

Циклите се използват за повторение на съвкупност от операции.

### For цикъл
```java
for(int i = 0; i < 10; i++) {
    System.out.println("i is: " + i);
}
```

### While и Do-While
```java
int counter = 0;
while(counter < 10) {
    System.out.println("counter: " + counter);
    counter++;
}
```

### For-Each цикъл
```java
String[] strings = {"one", "two", "three"};
for(String s : strings) {
    System.out.println(s);
}
```

---

## Масиви в Java

### Дефиниране
```java
int[] arr2;       // стандартна форма
int arr1[];       // C-стил
```

### Инициализиране
```java
arr2 = new int[10];
String[] stringArray = new String[10];
```

### Примери
```java
int[] ints2 = {1,2,3,4,5,6,7,8,9,10};
String[] strings = {"one", "two", "three"};
```

### Достъп до елемент
```java
arr2[6] = 0;
int sixth = arr2[6];
```

---

## Обхождане на масив

```java
String[] stringArray = new String[10];
for(int i = 0; i < stringArray.length; i++) {
    stringArray[i] = "String no " + i;
}
for(int i = 0; i < stringArray.length; i++) {
    System.out.println(stringArray[i]);
}
```

---

## Многомерни масиви

```java
int[][] intArray = new int[10][20];
intArray[0][2] = 129;
```

---

## Стандартен вход и изход

### Изход (конзола)
```java
System.out.print("Some text.");
System.out.println("Some text.");
System.out.println("text 1 " + "text 2");
System.out.println("x = " + x);
System.out.format("%s", "Hello World\n");
```

---

### Вход (чете от клавиатура)

#### Пример с `System.in.read()`:
```java
import java.io.IOException;

public class MyFirstProgram {
    public static void main(String[] args) throws IOException {
        int input;
        do {
            input = System.in.read();
            System.out.print((char) input);
        } while (input != '\n');
    }
}
```

#### Пример с `Scanner`:
```java
import java.util.Scanner;

Scanner scanner = new Scanner(System.in);
String name = scanner.nextLine();
int age = scanner.nextInt();
double value = scanner.nextDouble();
```

[Документация за Scanner](https://docs.oracle.com/javase/7/docs/api/java/util/Scanner.html)

---

## Структура на Java програма

Обикновеният Java проект представлява директория, съдържаща `.java` файлове (сорс код).  
След компилация се генерират `.class` файлове – байт код, който се изпълнява от **Java Virtual Machine (JVM)**.

**IDE примери:** Eclipse, NetBeans, IntelliJ IDEA, DrJava.

### Основен метод
```java
public static void main(String[] args) {
    // entry point
}
```

---

## Как се създава проект

1. `File -> New Project -> Java Project`  
2. `File -> New Class`  
3. `Run -> Run as Java Application`

---

## Задачи за изпълнение

1. **Прочитане на данни:**  
   Създайте проект `myFirstProject` и клас `myFirstClass` с метод `main()`.  
   Прочетете име, години и рожденна дата чрез `Scanner` и отпечатайте ги.

2. **Правоъгълник:**  
   Програма, която изчислява лицето на правоъгълник по зададени страни (въведени от стандартния вход).

3. **Низове:**  
   Програма, която чете 5 низа, разделени с интервал, записва ги в масив и отпечатва на екрана.
