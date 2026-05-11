create table customer(id number(3) primary key , nqme varchar(10), age number(2),address varchar(2),sal decimal(10,2));
insert into customer values(101,'Usdf','Google',56000);
insert into customer values(102,'Asdf','Microsoft',70000);

create trigger salarydifferencetrigger after
insert or update or delete on customer
for each row
declare
  oldsal customer.sal%type;
  newsal customer.sal%type;
diff number(3);
begin
if inserting then
dbms_output.put_line("New record inserted");
dbms_output.put_line("id: "||:new.id ||"name: "||:new.name ||"age: "||:new.age ||"address: "||:new.address ||"salary: "||:new.sal);

elsif updating then
  oldsal:= :old.sal;
  newsal:= :new.sal;
  diff:= newsal-oldsal;
dbms_output.put_line("Salary updated for id: "||:new.id ||"Old salary: "||:old.sal ||"New salary: "||:new.sal ||"Difference= "||diff);

elsif deleting then
  dbms_output.put_line("Record deleted for id: "||:old.id ||"Name: "||:old.name ||"age: "||:old.age ||"address: "||:old.address ||"salary: "||:old.sal);

endif;
end;
/
