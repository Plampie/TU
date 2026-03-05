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



