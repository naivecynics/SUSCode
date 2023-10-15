CREATE TABLE if not exists films (
    No INT  not null  primary key ,
    Title VARCHAR(255) not null,
    Description TEXT ,
    Director TEXT ,
    Genre VARCHAR(255),
    Language VARCHAR(255),
    Year integer not null,
    "cast" TEXT
);

copy films from 'C:\SUSCode\Database\project 1\filmData.csv' delimiter ','  csv header;
