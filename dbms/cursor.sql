create table employee(
  e_id int primary key,
  e_name varchar(10),
  age int,
  salary decimal(10,2)
);
desc employee;
insert into employee values(101,"Ramkumar",32,45000);
insert into employee values(102,"Samkumar",35,55000);
insert into employee values(103,"Joekumar",38,65000);

commit;

select * from employee;

declare
e_id employee.e_id%type;
e_name employee.e_name%type;
age employee.age%type;
salary employee.salary%type;
--declare cursor
begin
cursor employee_cursor is
select e_id, e_name, age, salary
from employee;
--oopen the cursor
begin
open employee_cursor;
--fetch from cursor
loop
fetch employee_cursor into e_id,e_name,age,salary;
exit when employee_cursor%notfound;
--output or use fetched values
dbms_output.put_line('employee id:'||e_id||',Name:'||e_name||',Age:'||age||',Salary'||salary);
end loop;
--close cursor 
close employee_cursor;
end;
/
