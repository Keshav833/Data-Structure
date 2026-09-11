# Write your MySQL query statement below
Select 
x , y , z , 
case 
    when 
    x<(y + z) AND
    z<(y + x) AND
    y<(x + z) then 'Yes'
    else 'No'
end as triangle  
from Triangle ;