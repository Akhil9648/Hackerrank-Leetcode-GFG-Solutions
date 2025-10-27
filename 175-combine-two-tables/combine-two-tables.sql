# Write your MySQL query statement below
SELECT firstName,LastName,city,state from Person
LEFT OUTER JOIN Address on Person.personId=Address.PersonId