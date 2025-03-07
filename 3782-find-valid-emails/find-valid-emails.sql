# Write your MySQL query statement below
# copied 
SELECT *
FROM Users
WHERE REGEXP_LIKE(email, '^[a-zA-Z0-9_]+@[a-zA-Z]+\.com')