-- Lab 3

drop database UniversityBD;

create database UniversityBD;
use UniversityBD;

create table Students ( 
id int auto_increment primary key,
name varchar(50) not null,
faculty_number int(10) not null,
email varchar(100) unique not null,
phone varchar(20) null default null
);

create table Courses ( 
id int auto_increment primary key,
course_name varchar(50) not null,
credits int not null
);

create table Student_Profiles (
id int auto_increment primary key,
student_id int unique not null, 
semester int not null, 
avg_uspeh decimal(3,2) default 0.00,
credits int default 0,
foreign key (student_id) references Students(id) on delete cascade
);

create table Student_Courses (
id int auto_increment primary key,
student_id int not null,
course_id int not null,
grade decimal(3,2),
foreign key (student_id) references Students(id) on delete cascade,
foreign key (course_id) references Courses(id) on delete cascade
);

insert into Students (name, faculty_number, email, phone) values
('Plamena Georgieva', '381224060', 'plamigeor.135@gmail.com', '0877111222'),
('Mihaela Cholakova', '381224063', 'misheto06@gmail.com', '098876534'),
('Viktoria Marinova', '381224756', 'viktoriasese67@gmail.com', '099878653'),
('Aleksandar Borisov', '381224890', 'alekks78@gmail.com', '0899334455'),
('Ivan Ivanov', '381224050', 'ivanivanov@gmail.com', '087765453211');

insert into Courses (course_name, credits) values
('SQL Databases', '50'),
('Microcontrollers', '60'),
('Cloud Technologies', '20'),
('IOT', '35'),
('COmputer Networks', '25');

insert into Student_Profiles (student_id, semester) values
(1, 4), 
(2, 4), 
(3, 2),
(4, 6),
(5, 8);

update Students
set email = 'plamena_email@gmail.com'
where id = 1;

update Courses
set credits = 60
where id = 1;

insert into Student_Courses (student_id, course_id, grade) 
values (1, 1, 5.50);

delete from Student_Courses
where student_id = 1 and course_id = 1;
delete from Courses
where id = 5;
delete from Students
where id = 5;