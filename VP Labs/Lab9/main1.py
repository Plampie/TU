# Въвеждане на данни от потребителя
input_data = input("Въведете имена и оценки във формат 'име:оценка', разделени със запетая: ")

# Преобразуване на входните данни в речник
students = {}
for entry in input_data.split(","):
    name, grade = entry.split(":")
    students[name.strip()] = float(grade.strip())

# Показване на оригиналния речник
print("Оригинален речник:", students)

# Показване на имената на учениците с оценка над 4.50
high_achievers = [name for name, grade in students.items() if grade > 4.5]
print("Ученици с оценка над 4.50:", high_achievers)

# Добавяне на нов ученик
students["Никола"] = 6
print("Речник след добавяне на Никола:", students)

# Премахване на ученика с най-ниска оценка
lowest_grade = min(students.values())
for name, grade in list(students.items()):
    if grade == lowest_grade:
        del students[name]
        break
print("Речник след премахване на ученика с най-ниска оценка:", students)