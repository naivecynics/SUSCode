-- T1
SELECT station_id,english_name,chinese_name,district
FROM stations
WHERE   lower(english_name) LIKE '%east'
        OR lower(english_name) LIKE '%west'
        OR lower(english_name) LIKE '%north'
        OR lower(english_name) LIKE '%south'
        OR lower(english_name) LIKE '%east station'
        OR lower(english_name) LIKE '%west station'
        OR lower(english_name) LIKE '%north station'
        OR lower(english_name) LIKE '%south station'
;
-- T2
select district,round((max(latitude)-min(latitude))*111) as 南北跨度km
from stations
where latitude is not null
group by district;

-- T3
SELECT DISTINCT station_id
FROM bus_lines
WHERE bus_line IN ('103', '104')
ORDER BY station_id DESC;

-- T4
select distinct station_id
from bus_lines
where bus_line='103' and
      station_id in
      (
          select station_id
          from bus_lines
          where bus_line='104'
          );

-- T5
select bus_line,count(*) as station_count
from bus_lines
group by bus_line
having count(*)>=10
order by station_count desc , bus_line desc

-- T6
select station_id,count(distinct bus_line) as cnt
from bus_lines
group by station_id
having count(distinct bus_line) =(
           select max(bus_line_count2)
           from (
               select count(distinct bus_line) as bus_line_count2
               from bus_lines
               group by station_id
                ) as counts
           );

-- T7
select bus_line,count(distinct station_id) as count
from bus_lines
group by bus_line

-- T8
select count(distinct station_id) as max
from bus_lines
group by bus_line
having count(distinct station_id) =(
    select max(station_num)
    from(
        select count(distinct station_id) as station_num
        from bus_lines
        group by bus_line
        ) as ff
    );
--也可以
SELECT max(station_count) AS max
FROM (
    SELECT bus_line, COUNT(DISTINCT station_id) AS station_count
    FROM bus_lines
    group by bus_line
) AS counts;

-- T9
select bus_line as bs ,count(distinct station_id) as max
from bus_lines
group by bus_line
having count(distinct station_id) =(
    select max(station_num)
    from(
        select count(distinct station_id) as station_num
        from bus_lines
        group by bus_line
        ) as ff
    )
order by bus_line

-- T10
select bus_line,count(distinct station_id) as cnt,
       case
            when bus_line like 'N%' then '夜班公交'
            when bus_line like 'M%' then '主干线公交'
            else ''
        end as 备注
from bus_lines
group by bus_line
having count(distinct station_id)>=10
