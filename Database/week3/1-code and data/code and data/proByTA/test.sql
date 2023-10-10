select Kolja from movies;
select 2793 from movies;

select * from movies where country = 'us';

show databases;

show movies;

select *
from (select * from movies
where country = 'fr') us_movies
where year_released between 1949 and 1955;

select *
from movies
where (country = 'us'
  or country = 'fr')
  and year_released between 1950 and 1951
--and priority > or priority


select *
from movies
where country = 'us'
and year_released between 1940 and 1949

select * from movies
where (country = 'cn'
and year_released between 1940
and 1949)
or (country = 'us'
and year_released between 1950
and 1959)

select * from movies
where title  like '%A%'
and title  like '%a%'

select * from movies
where upper(title)
not like '%A%'

select * from forum_posts where post_date>= '2018-03-12';
select * from forum_posts where post_date>=date('2018-03-12');
select * from forum_posts where post_date>=date('12 March, 2018');

select m.title,c.country_name country,c.continent ,m.runtime
  from movies m
  join countries c on m.country=c.country_code
                where m.movieid = 2769;

select continent from countries group by continent

select * from movies where year_released = 1994