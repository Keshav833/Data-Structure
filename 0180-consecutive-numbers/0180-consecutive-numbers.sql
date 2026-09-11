# Write your MySQL query statement below
select distinct a.num as consecutiveNums 
from Logs a 
 JOIN Logs b  ON  a.id+1 = b.id
 JOIN Logs c  ON  b.id+1 = c.id
where a.num = b.num AND b.num = c.num;
