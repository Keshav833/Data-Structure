# Write your MySQL query statement below
select a.name from Employee a JOIN Employee b ON a.id = b.managerId GROUP BY a.id , a.name having COUNT(*) >=5;