# Методи в Java – деклариране, имплементация и извикване. Видове методи.

## Какво е метод?

Методът е обособена част от програмата, която решава конкретна задача. В ООП методите описват действията, които един обект може да извършва.

## Защо използваме методи?

- Подобряват четимостта на кода
- Улесняват поддръжката и откриването на грешки
- Позволяват повторно използване на код (code reusing)
- Разделят големи задачи на по-малки

## Деклариране на метод

Метод се пише в тялото на класа, но не в друг метод или конструктор.

```java
[access_modifier] [static] return_type method_name(parameter_list)
```

| Елемент | Описание | Пример |
|---------|----------|--------|
| access modifier | Видимост (public, private, protected) | public |
| static (по избор) | Ако присъства → методът принадлежи на класа, не на обект | static |
| return type | Тип на резултата (или `void`, ако няма връщане) | int |
| method name | Малка буква, съдържа глагол, camelCase | getSum |
| parameters | Формални параметри в скоби, разделени със запетая | (int a, int b) |

### Пример:

```java
private void printInfo(String inf) {
    System.out.println(inf);
}
```

**Методът може да приема final параметри (непроменяеми в рамките на метода).**

#### Сигнатура на метод
- Състои се от име + списък с параметри.

```java
Сигнатура = f(name, parameter_list);
```
- Типът на връщаната стойност НЕ е част от сигнатурата. Защото не може да определи кои метод се изивква при наличие на дупликация в имената, променливите в метода.

#### Имплементация
- Тялото на метода е между { } и съдържа логиката.
- Метод може да се остави и като неимплементиран, ако е абстрактен.

#### Локални променливи
- Съществуват само в рамките на метода или блок { }.

## Извикване на метод

| Характеристика | Описание |
|----------------|----------|
| Синтаксис | `methodName(arguments);` |
| Скобите `()` | Задължителни – с или без параметри |
| Къде може да се извика | В други методи, в конструктори, в блокове `{ }` |
| Рекурсия | Метод може да извика сам себе си |

Може да бъде извикван в:
- друг метод
- конструктор
- който и да е програмен блок { }
- **самия себе си → рекурсия**

## Разлика между параметри и аргументи

| Етап | Термин | Описание |
|------|--------|----------|
| При декларация |  **Параметри** (формални) | Тип + име (без стойност) - декларация в сигнатурата|
| При извикване | **Аргументи** (фактически) | Реални стойности, подадени при извикване на метода |
| Задължително | Типовете на аргументите трябва да съвпадат с формалните |
| Изискване | Аргументите трябва да са инициализирани |

---

## Контрол над изпълнението на програмата

При декларативното програмиране кодът се изпълнява последователно.  
При ООП методите често се извикват един друг, което води до **по-сложна логика и взаимодействия между обектите**.

### Пример:

```java
public class Example {
    public void callSum(int a, int b) {
        int theSum = add(a, b);
        System.out.print(theSum);
    }

    public int add(int value1, int value2) {
        return value1 + value2;
    }

    public static void main(String[] args) {
        System.out.println("We will call callSum() method to calculate 2+3:");
        callSum(2,3);
        System.out.println("The method callSum() finished and the main begins.");
    }
}
```

### Какво се случва?

- Стартира `main()`  
- Извежда съобщение  
- Извиква `callSum(2,3)`  
- `callSum()` извиква `add()`  
- `add()` връща резултат и управлението се връща към `callSum()`  
- `callSum()` отпечатва резултата  
- Управлението се връща към `main()` и се извежда заключителното съобщение

## Подаване на аргументи – примитивни и референтни типове

В **Java аргументите се предават по стойност (pass by value)**.

### Примитивен тип

```java
public static void main (String[] args){
int a = 5;
System.out.println(“Before invoking modifyMethod() a = ”+a);
modifyMethod(a);
System.out.println(“After invoking modifyMethod() a = ”+a);

}
public static void modifyMethod(int number){
number = 1000;
System.out.println(“ModifyMethod modifying a = ”+number);
}
```

**Резултат:**

```
Before invoking modifyMethod() a = 5
ModifyMethod modifying a = 1000
After invoking modifyMethod() a = 5
```

Методът модифицира **копие**, не оригиналната стойност.

---

### Референтен тип

*Копира се не обектът, а референцията (адресът към обекта).*

```java
public class Main{
public static void main(String[] args){
Foo f = new Foo("f");
changeReference(f); // It won't change the reference!
modifyReference(f); // It will modify the object that the reference variable "f" refers to!
}
public static void changeReference(Foo a){
Foo b = new Foo("b");
a = b;
}
public static void modifyReference(Foo c){
c.setAttribute("c");
}
}
```

- `changeReference()` променя локалното копие на референцията.  
- `modifyReference()` променя самия обект → промяната се вижда извън метода.


#### Подробно обяснение на кода и влиянието върху паметта (heap)

1. Декларираме обект от тип Foo с име f и го инициализираме с конструктора на класа Foo с атрибут “f”.
Foo f = new Foo(“f”);

![Декларация](http://javac.bg/wp-content/uploads/2015/10/picture14.jpg)

2. Методът public static void changeReference(Foo a) декларира локален параметър a от тип Foo. Преди извикване, стойността на a е null. При извикване, референцията към подадения обект се копира в a.

![Декларация](http://javac.bg/wp-content/uploads/2015/10/picture15.jpg)

3. Вътре в метода се създава нов обект и се инициализира нова локална референция: Foo b = new Foo(“b”);.
- Резултат: В паметта се създава втори обект (с атрибут "b"), а променливата b сочи към него.
- Ключово: До този момент, f и a продължават да сочат към първия обект ("f"), а b сочи към втория ("b").

![Декларация](http://javac.bg/wp-content/uploads/2015/10/picture16.jpg)

4. Деклариране на обект от тип Foo, който се казва „b“ и се инициализира с нов обект от същия тип, чрез конструктора му, с атрибут „b“.
Foo b = new Foo(“b”);

![Декларация](http://javac.bg/wp-content/uploads/2015/10/picture17.jpg)

5. В рамките на метода, извършваме пренасочване: a = b;

| Аспект | Описание на Стъпка a = b; | Извод за f |
|--------|---------------------------|------------|
| Действие | "Локалната променлива a получава копие на референцията от b и започва да сочи към новия обект (""b"")." |  |
| Резултат за Оригинала | "Промяната е локална за метода. Оригиналната променлива f запазва първоначалната си референция и продължава да сочи към първия обект (""f"")." | "Обектът, към който сочи f, остава непроменен." |
| Заключение | Пренасочването на локалния параметър (a = b;) не може да модифицира оригиналната променлива f. | Принципът Pass-by-Value се запазва. |

![Декларация](http://javac.bg/wp-content/uploads/2015/10/picture18.jpg)

6. Когато извикаме метод modifyReference (Foo c), обект „с“ се създава и в променливата „с“ се копира стойността на предадения аргумент „f“.
modifyReference(f);

![Декларация](http://javac.bg/wp-content/uploads/2015/10/picture19.jpg)

7. Извикването на c.setAttribute(“c”); върху обекта „с“ ще модифицира оригиналния обект, към който сочи и „f“.

![Декларация](http://javac.bg/wp-content/uploads/2015/10/picture20.jpg)

---

## Методи с променлив брой аргументи (var-args)

```java
public static void main(String ... args) { }
```

### Правила:

- `тип ... име`  
- var-arg параметърът **винаги е последен**  
- в списък може да има **само един var-arg параметър**

### Пример:

```java
static double avg(double ... numbers) {
    double total = 0;
    for (double n : numbers) total += n;
    return total / numbers.length;
}
```

```java
public class VarArgsExample
{
public static void main (String [] args)
{
System.out.println ("Average: " +
avg (20.3, 3.1415, 32.3));
System.out.println ("Concatenation: " +
concat ("Hello", " ", "World"));
System.out.println ("Maximum: " +
max (30, 22.3, -9.3, 173.2));
System.out.println ("Minimum: " +
min (30, 22.3, -9.3, 173.2));
System.out.println ("Sum: " +
sum (20, 30));
}

static double avg (double ... numbers)
{
double total = 0;
for (int i = 0; i < numbers.length; i++)
total += numbers [i];
return total / numbers.length;
}

static String concat (String ... strings)
{
StringBuilder sb = new StringBuilder ();
for (int i = 0; i < strings.length; i++)
sb.append (strings [i]);
return sb.toString ();
}

static double max (double ... numbers)
{
double maximum = Double.MIN_VALUE;
for (int i = 0; i < numbers.length; i++) if (numbers [i] > maximum)
maximum = numbers [i];
return maximum;
}

static double min (double ... numbers)
{
double minimum = Double.MAX_VALUE;
for (int i = 0; i < numbers.length; i++)
if (numbers [i] < minimum)
minimum = numbers [i];
return minimum;
}

static int sum (int ... numbers)
{
int total = 0;
for (int i = 0; i < numbers.length; i++)
total += numbers [i];
return total;
}
}
```

---

## Статични методи

- Известни още като „методи на класа“  
- Извикват се без инстанция: `ClassName.method()`  
- Вътре могат да достъпват само **статични** полета и методи

```java
public class Bicycle {
    private static int numberOfBicycles = 0;
    private int id;

    public Bicycle(int startCadence, int startSpeed, int startGear) {
        id = ++numberOfBicycles;
    }

    public int getID() { return id; }
}
```

---

## Overloading (претоварване на методи)

Методи със **също име, но различна сигнатура (параметри)**.

```java
public void disp(char c) { }
public void disp(char c, int num) { }
```

### Невалидни примери

```java
int myMethod(int a, int b, float c)
int myMethod(int var1, int var2, float var3)   // само имената са различни

int myMethod(int a, int b)
float myMethod(int a, int b)                   // само типът на връщане е различен
```

---

