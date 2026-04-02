-- Lab 4

use school_sport_clubs;

SELECT * FROM students;

-- 5.1. Извлечете списьк с всички студенти и техните класове
SELECT nameStudents, class FROM students;

-- 5.2. Извлечете всички спортни групи, които имат тренировки в петьк
SELECT * FROM sportGroups WHERE dayOfWeek = 'Friday';

-- 5.3. Намерете всички треньори, чието име започва с "Иван"
SELECT * FROM coaches WHERE name LIKE 'Ivan%';

-- 5.4. Покажете всички студенти, които живеят в квартал "Младост"
SELECT * FROM students WHERE address LIKE '%Mladost%';


-- Задача 1. Изведете списьк с всички ученици от 10-ти клас и ID на спортните групи, 
-- в които са записан Ако ученикт не е записан в група, вместо ID на групата трябва да се покаже NULL. Използвайте LEFT J
SELECT students.name, student_sport.sportGroup_id
FROM students
LEFT JOIN student_sport ON students.id = student_sport.student_id
WHERE students.class LIKE '10%';

-- Задача 2. Изведете всички спортни групи по футбол, като включите и тези, които нямат записани ученик
-- Използвайте RIGHT JOIN.
SELECT sports.name, sportGroups.id
FROM student_sport
RIGHT JOIN sportGroups ON student_sport.sportGroup_id = sportGroups.id
JOIN sports ON sportGroups.sport_id = sports.id
WHERE sports.name = 'Football';

-- Задача 3. Изведете имената на учениците, класовете им, имената на треньорите и спорта, 
-- който тренир но само за ученици, които имат телефонен номер. Използвайте INNER JOIN.
SELECT students.name, students.class, coaches.name, sports.name
FROM students
INNER JOIN student_sport ON students.id = student_sport.student_id
INNER JOIN sportGroups ON student_sport.sportGroup_id = sportGroups.id
INNER JOIN coaches ON sportGroups.coach_id = coaches.id
INNER JOIN sports ON sportGroups.sport_id = sports.id
WHERE students.phone IS NOT NULL;

-- Задача 4. Изведете имената на учениците и номерата на групите, в които тренират, 
-- но само ако тренират в сьщата група като ученик с име "Iliyan Ivanov". Използвайте вложен SELECT.
SELECT students.name, student_id
FROM students
JOIN student_sport ON students.id = student_sport.student_id
WHERE student_sport.sportGroup_id IN (
    SELECT sportGroup_id 
    FROM student_sport 
    JOIN students ON student_sport.student_id = students.id
    WHERE students.name = 'Alex Dimitrov'
);

-- Задача 5. След като ги направите, искам сьщите задачи да ги направите с JOIN на всяка таблица.
-- Без вложени селекти, RIGHT JOIN, LEFT JOIN или INNER JOIN.
SELECT students.name, student_sport.sportGroup_id
FROM students, student_sport
WHERE students.id = student_sport.student_id AND students.class LIKE '10%';

SELECT sports.name, sportGroups.id
FROM sportGroups, sports
WHERE sportGroups.sport_id = sports.id AND sports.name = 'Football';

SELECT students.name, students.class, coaches.name, sports.name
FROM students, student_sport, sportGroups, coaches, sports
WHERE students.id = student_sport.student_id 
AND student_sport.sportGroup_id = sportGroups.id
AND sportGroups.coach_id = coaches.id
AND sportGroups.sport_id = sports.id
AND students.phone IS NOT NULL;

SELECT DISTINCT students.name, student_sport.sportGroup_id
FROM students, student_sport, students AS students2, student_sport AS student_sport2
WHERE students.id = student_sport.student_id 
AND students2.id = student_sport2.student_id
AND student_sport.sportGroup_id = student_sport2.sportGroup_id
AND students2.name = 'Alex Dimitrov';