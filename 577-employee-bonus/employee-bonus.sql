# Write your MySQL query statement below
SELECT N.name, B.bonus FROM Employee N LEFT JOIN Bonus B ON 
N.empId=B.empId WHERE bonus<1000 OR bonus is NULL
