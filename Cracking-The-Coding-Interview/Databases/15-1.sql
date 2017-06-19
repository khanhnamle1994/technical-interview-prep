Write a method to find the number of employees in each department.

This problem uses a straight-forward join of Departments and Employees. Note that we use a left join instead of an inner join
because we want to include Departments with 0 employees.

1 select Dept_Name, Departments.Dept_ID, count(*) as ‘num_employees’
2 from Departments
3 left join Employees
4 on Employees.Dept_ID = Departments.Dept_ID
5 group by Departments.Dept_ID, Dept_Name
