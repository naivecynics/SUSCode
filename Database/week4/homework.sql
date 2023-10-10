--one
select station_id,english_name,chinese_name,district from stations
    where lower(english_name) like '%north%'
    or lower(english_name) like '%south%'
    or lower(english_name) like '%east%'
    or lower(english_name) like '%west%'
;

--two
select district, round((max(latitude)-min(latitude))*111) as 南北跨度km from stations
    where latitude is not null
    group by district
;

--three
select distinct station_id from bus_lines
    where bus_line = '103'
    or bus_line = '104'
    order by station_id desc
;

--four
select distinct station_id from bus_lines
    where bus_line = '103'
    and station_id in (
        select station_id from bus_lines
        where bus_line = '104'
        )
;

--five
select bus_line, count(*) as cnt from bus_lines
    group by bus_line
    having count(*) >= 10
    order by cnt desc, bus_line desc
;

--six
select station_id, count(distinct bus_line) as cnt from bus_lines
    group by station_id
    order by cnt desc
    limit 1
;

--seven
select bus_line, count(distinct station_id) as cnt from bus_lines
    group by bus_line
;

--eight
select count(distinct station_id) as max from bus_lines
    group by bus_line
    order by max desc
    limit 1
;

--nine
select bus_line as bs, count(station_id) as cnt from bus_lines
    group by bus_line
    order by cnt desc
    limit 1
;

--ten
select bus_line, count(station_id) as cnt,
    case
        when bus_line like 'N%' then '夜班公交'
        when bus_line like 'M%' then '主干线公交'
        else ''
    end as 备注
    from bus_lines
    group by bus_line
    having count(station_id) >= 10
;