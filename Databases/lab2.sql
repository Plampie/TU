-- Lab 2

drop database 95_a_2026;
create database 95_a_2026;

create table students(
id INT auto_increment primary key,
name varchar(50) not null,
eng varchar(10) not null,
adress varchar(100) not null,
phone varchar(20) null default null,
class varchar(2) null default null);

create table coaches(
id INT auto_increment primary key,
name varchar(50) not null,
egn varchar(10) not null,
phone varchar(20) null default null
);

create table sport(
id INT auto_increment primary key, 
name varchar(50) not null,
coach_id int not null,
foreign key (coach_id) references coaches(id)
);

alter table sport drop foreign key sport_ibfk_1;
alter table sport drop column coach_id;
alter table sport add unique (name);
alter table coaches add unique (egn);

create table sportGroup (
    id int auto_increment primary key,
    location varchar(30) not null,
    dayOfWeek enum('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday') not null,
    hourOfTraining time not null,
    sport_id int not null,
    coach_id int not null, 
    unique key (location, dayOfWeek, hourOfTraining),
    foreign key (sport_id) references sport(id),
    foreign key (coach_id) references coaches(id)
);

use 95_a_2026;
insert into sport (name) values
('Football'),
('Tennis'),
('Volleyball'),
('Climbing');

insert into coaches (name, egn, phone) values
('Petar Petrov', '8504121234', '0888123456'),
('Ivan Tetov', '7802257845', '0888373456'),
('Stefan Nikolov', '7510251122', null),
('Gergana Ilieva', '9308184455', '0898112233'),
('Maria Shumenova', '9011234321', '0899654321');

insert into students (name, eng, adress, phone, class) values
('Plamena Georgieva', '0541123456', 'Sofia, Vitosha 12', '0877111222', '10'),
('Mihaela Cholakova', '0652234567', 'Sofia, Lulin 3', null, '11'),
('Viktoria Marinova', '0851237766', 'Varna, bul. Slivnitsa 12', null, '10'),
('Aleksandar Borisov', '0945561122', 'Sofia, Nadezhda 2', '0899334455', '9'),
('Simona Krumova', '0658892233', 'Burgas, Lazur 5', '0877556677', '12'),
('Nikola Vasilev', '0741123344', 'Sofia, Mladost 1', null, '11'),
('Ivan Ivanov', '0412126438', 'Sofia, Studenstli grad ', null, '12');

insert into sportGroup (location, dayOfWeek, hourOfTraining, sport_id, coach_id) values
('Stadium Sofia', 'Monday', '16:00:00', 1, 1),     
('Tennis Club', 'Tuesday', '17:30:00', 2, 5),  
('Sports Hall A', 'Wednesday', '18:00:00', 3, 4),
('Climbing Gym', 'Thursday', '19:00:00', 4, 3),
('Stadium Sofia', 'Friday', '15:00:00', 1, 2);