Imagine a simple database storing information for students’ grades. Design what this database might look like, and provide a SQL query to return
a list of the honor roll students (top 10%), sorted by their grade point average.

In a simplistic database, we’ll have at least these three objects: Students, Courses, and CourseEnrollment. Students will have at least the
student name and ID, and will likely have other personal information. Courses will contain the course name and ID, and will likely contain the
course description, professor, etc. CourseEnrollment will pair Students and Courses, and will also contain a field for CourseGrade. We will
assume that CourseGrade is an integer.

Our SQL query to get the list of honor roll students might look like this:

1 SELECT StudentName, GPA
2 FROM (
3 SELECT top 10 percent Avg(CourseEnrollment.Grade) AS GPA,
4 CourseEnrollment.StudentID
5 FROM CourseEnrollment
6 GROUP BY CourseEnrollment.StudentID
7 ORDER BY Avg(CourseEnrollment.Grade)) Honors
8 INNER JOIN Students ON Honors.StudentID = Students.StudentID

This database could get arbitrarily more complicated if we wanted to add in professor information, billing, etc.
