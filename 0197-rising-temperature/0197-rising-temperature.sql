# Write your MySQL query statement below
SELECT t.id from Weather t join Weather y  ON t.recordDate = DATE_ADD(y.recordDate ,INTERVAL 1 DAY) WHERE t.temperature > y.temperature;